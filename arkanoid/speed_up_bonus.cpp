#include "speed_up_bonus.h"
#include "ball.h"
#include "config.h"
#include "gl_helpers.h"
#include <algorithm>

void speed_up_bonus::render() {
    draw_diamond(pos_, BONUS_WIDTH, BONUS_HEIGHT, SPEED_UP_BONUS_COLOR);
}

void speed_up_bonus::visit(ball& ball) {
    ball.speed_ = std::min(ball.speed_ + SPEED_UP_BONUS_INCREASE_VALUE, MAX_BALL_SPEED);
}
