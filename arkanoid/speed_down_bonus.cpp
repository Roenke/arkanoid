#include "speed_down_bonus.h"
#include "gl_helpers.h"
#include "config.h"
#include "ball.h"
#include <algorithm>


void speed_down_bonus::visit(ball& ball) {
    ball.speed_ = std::max(ball.speed_ - SPEED_DOWN_BONUS_DECREASE_VALUE, MIN_BALL_SPEED);
}

glm::vec3 speed_down_bonus::get_color() {
    return SPEED_DOWN_BONUS_COLOR;
}

const char* speed_down_bonus::get_description() const {
    return SPEED_DOWN_BONUS_DESCRIPTION;
}
