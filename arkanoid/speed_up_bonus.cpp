#include "speed_up_bonus.h"
#include "ball.h"
#include "config.h"
#include <algorithm>

void speed_up_bonus::visit(ball& ball) {
    ball.speed_ = std::min(ball.speed_ + SPEED_UP_BONUS_INCREASE_VALUE, MAX_BALL_SPEED);
}

glm::vec3 speed_up_bonus::get_color() {
    return SPEED_UP_BONUS_COLOR;
}

const char* speed_up_bonus::get_description() const {
    return SPEED_UP_BONUS_DESCRIPTION;
}
