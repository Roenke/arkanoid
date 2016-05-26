#include "game.h"

game::game()
    : player_({0., 0.}, 0.35)
    , score_(0)
    , lives_(3) {
    
}

game::~game() {}

void game::render() {}
