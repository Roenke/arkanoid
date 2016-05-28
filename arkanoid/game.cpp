#include "game.h"
#include "config.h"
#include "gl_helpers.h"
#include <sstream>
#include "safe_line.h"

game::game()
    : is_game_over(false)
    , player_()
    , field_()
    , border_()
    , score_(0)
    , lifes_(3)
    , save_line_count(0) {}

game::~game() {}

void game::render() {
    if(is_game_over) {
        draw_string("GAME OVER", { DEFAULT_GAME_WIDTH / 2, DEFAULT_GAME_HEIGHT / 2 }, { 1, 1, 1 }, GLUT_BITMAP_TIMES_ROMAN_24);
        border_.render();
        field_.render();
        legend_.render();
        render_score_and_lifes();
        return;
    }

    border_.render();
    player_.render();
    field_.render();
    legend_.render();

    render_score_and_lifes();

    for (int i = 0; i < save_line_count; ++i) {
        safe_line::render(i);
    }
}

void game::process(float elapsed_time) {
    if (is_game_over) {
        return;
    }

    auto& ball = player_.get_ball();
    field_.process(elapsed_time);
    field_.collide(ball, elapsed_time, this);
    player_.process(elapsed_time);
    player_.collide_with_ball(elapsed_time);

    if(save_line_count > 0 && ball.get_new_pos(elapsed_time).y > SAFE_LINE_BEGIN_Y) {
        ball.inverse_vertical();
        --save_line_count;
    }

    if (player_.get_ball().is_game_over()) {
        --lifes_;
        if(lifes_ == 0) {
            is_game_over = true;
        }
        else {
            player_ = rocket();
        }
    }
}

void game::apply_bonus(bonus* bonus) {
    bonus->visit(*this);

    player_.apply_bonus(bonus);
}

rocket& game::get_rocket() {
    return player_;
}

void game::release_ball() {
    player_.release_ball();
}

void game::change_score(int delta) {
    score_ += delta;
}

void game::render_score_and_lifes() const {
    std::stringstream ss;
    ss << "score: " << score_;
    draw_string(ss.str().c_str(), { SCORE_STRING_H_OFFFSET, SCORE_STRING_V_OFFSET }, { 1, 1, 1 }, SCORE_FONT);
    ss.str("");
    ss << "lives: " << lifes_;
    draw_string(ss.str().c_str(), { LIVES_STRING_H_OFFSET, LIVES_STRING_V_OFFSET }, { 1,1,1 }, LIVES_FONT);
}
