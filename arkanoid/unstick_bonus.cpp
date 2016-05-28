#include "unstick_bonus.h"
#include "rocket.h"
#include "config.h"

void unstick_bonus::visit(rocket& player) {
    player.with_ball_ = false;
}

glm::vec3 unstick_bonus::get_color() {
    return UNSTICK_BONUS_COLOR;
}

const char* unstick_bonus::get_description() const {
    return UNSTICK_DOWN_BONUS_DESCRIPTION;
}
