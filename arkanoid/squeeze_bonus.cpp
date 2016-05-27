#include "squeeze_bonus.h"
#include "rocket.h"
#include <algorithm>
#include "gl_helpers.h"

void squeeze_bonus::render() {
    draw_diamond(pos_, BONUS_WIDTH, BONUS_HEIGHT, SQUEEZE_BONUS_COLOR);
}

void squeeze_bonus::visit(rocket& player) {
    player.size_ = std::max(player.size_ - 100, MIN_ROCKET_SIZE);
}
