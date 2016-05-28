#include "squeeze_bonus.h"
#include "rocket.h"
#include <algorithm>
#include "gl_helpers.h"

void squeeze_bonus::visit(rocket& player) {
    player.size_ = std::max(player.size_ - SQUEEZE_BONUS_VALUE, MIN_ROCKET_SIZE);
}

glm::vec3 squeeze_bonus::get_color() {
    return SQUEEZE_BONUS_COLOR;
}

const char* squeeze_bonus::get_description() const {
    return SQUEEZE_BONUS_DESCRIPTION;
}
