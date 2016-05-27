#include "extend_bonus.h"
#include "gl_helpers.h"
#include "config.h"
#include "rocket.h"
#include <algorithm>

void extend_bonus::render() {
    draw_diamond(pos_, BONUS_WIDTH, BONUS_HEIGHT, EXTEND_BONUS_COLOR);
}

void extend_bonus::visit(rocket& player) {
    player.size_ = std::min(player.size_ + 100, MAX_ROCKET_SIZE);
}
