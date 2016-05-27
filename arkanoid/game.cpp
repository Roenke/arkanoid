#include "game.h"

game::game(GLint width, GLint height)
    : player_({ 0., 0. }, 0.35)
    , border_(width, height)
    , score_(0)
    , lives_(3)
{}

game::~game() {}

void game::render() {
    border_.render();
}
