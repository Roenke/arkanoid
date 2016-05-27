#include "game.h"
#include "config.h"
game::game(GLint width, GLint height)
    : player_(width, height)
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
}

void game::process(float elapsed_time) {
    player_.process(elapsed_time);
    ball_.process(elapsed_time);
}
