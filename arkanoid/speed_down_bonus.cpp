#include "speed_down_bonus.h"
#include "gl_helpers.h"
#include "config.h"
#include "ball.h"
#include <algorithm>

void speed_down_bonus::render() {
    draw_diamond(pos_, BONUS_WIDTH, BONUS_HEIGHT, SPEED_DOWN_BONUS_COLOR);
}

void speed_down_bonus::visit(ball& ball) {
    ball.speed_ = std::max(ball.speed_ - 50, MIN_BALL_SPEED);
}
