#include "game.h"
#include "config.h"
game::game(GLint width, GLint height)
    : player_({ START_ROCKET_H_OFFSET, height - ROCKET_BOTTOM_OFSET }
            , START_ROCKET_SIZE, START_ROCKET_HEIGHT)
    , field_(width, height)
    , border_(width, height)
    , ball_({width / 2, height / 2}, {1, 1}, BALL_COLOR, BALL_RADIUS)
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
