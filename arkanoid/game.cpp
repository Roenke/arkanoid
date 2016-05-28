#include "game.h"
#include "config.h"
#include "gl_helpers.h"
#include <sstream>
#include "safe_line.h"

game::game(GLint width, GLint height)
    : is_game_over(false)
    , player_()
    , field_()
    , border_()
    , score_(0)
    , lives_(3)
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
    field_.process(elapsed_time);
    field_.collide(player_.get_ball(), elapsed_time, this);
    player_.process(elapsed_time);
    player_.collide_with_ball(elapsed_time);

    if (player_.get_ball().is_game_over()) {
        is_game_over = true;
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

void game::render_score_and_lifes() const {
    std::stringstream ss;
    ss << "score: " << score_;
    draw_string(ss.str().c_str(), { SCORE_STRING_H_OFFFSET, SCORE_STRING_V_OFFSET }, { 1, 1, 1 }, SCORE_FONT);
    ss.str("");
    ss << "lives: " << lives_;
    draw_string(ss.str().c_str(), { LIVES_STRING_H_OFFSET, LIVES_STRING_V_OFFSET }, { 1,1,1 }, LIVES_FONT);
}
