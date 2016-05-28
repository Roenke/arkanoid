#include "stick_bonus.h"
#include "rocket.h"
void stick_bonus::visit(rocket& player) {
    player.with_ball_ = true;
}

glm::vec3 stick_bonus::get_color() {
    return STICK_BONUS_COLOR;
}

const char* stick_bonus::get_description() const {
    return STICK_BONUS_DESCRIPTION;
}
