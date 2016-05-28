#define _USE_MATH_DEFINES
#include "crazy_ball_bonus.h"
#include <math.h>
#include "ball.h"
#include "config.h"
void crazy_ball_bonus::visit(ball& ball) {
    float random_angle = 2 * M_PI * (static_cast<float>(rand()) / RAND_MAX);
    ball.direction_ = { cos(random_angle), sin(random_angle) };
}

glm::vec3 crazy_ball_bonus::get_color() {
    return CRAZY_BALL_BONUS_COLOR;
}

const char* crazy_ball_bonus::get_description() const {
    return CRAZY_BALL_BONUS_DESCRIPTION;
}
