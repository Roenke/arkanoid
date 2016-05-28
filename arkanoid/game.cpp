#include "game.h"
#include "config.h"
#include "gl_helpers.h"
#include <sstream>

game::game(GLint width, GLint height)
    : player_()
    , field_()
    , border_()
    , ball_({width / 2, height / 2})
    , score_(0)
    , lives_(3)
{}

game::~game() {}

void game::render() {
    border_.render();
    player_.render();
    ball_.render();
    field_.render();

    std::stringstream ss;
    ss << "score: " << score_;
    draw_string(ss.str().c_str(), { SCORE_STRING_H_OFFFSET, SCORE_STRING_V_OFFSET }, { 1, 1, 1 }, SCORE_FONT);
    ss.str("");
    ss << "lives: " << lives_;
    draw_string(ss.str().c_str(), { LIVES_STRING_H_OFFSET, LIVES_STRING_V_OFFSET }, { 1,1,1 }, LIVES_FONT);
}

void game::process(float elapsed_time) {
    player_.process(elapsed_time);
    field_.process(elapsed_time);
    player_.collide(ball_, elapsed_time);
    field_.collide(ball_, elapsed_time, this);
    ball_.process(elapsed_time);
}

void game::apply_bonus(bonus* bonus) {
    bonus->visit(*this);

    player_.apply_bonus(bonus);
    ball_.apply_bonus(bonus);
}

rocket& game::get_rocket() {
    return player_;
}
