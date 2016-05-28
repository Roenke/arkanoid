#include "extend_bonus.h"
#include "gl_helpers.h"
#include "config.h"
#include "rocket.h"
#include <algorithm>

void extend_bonus::visit(rocket& player) {
    player.size_ = std::min(player.size_ + EXTEND_BONUS_VALUE, MAX_ROCKET_SIZE);
}

glm::vec3 extend_bonus::get_color() {
    return EXTEND_BONUS_COLOR;
}

const char* extend_bonus::get_description() const {
    return EXTEND_BONUS_DESCRIPTION;
}
