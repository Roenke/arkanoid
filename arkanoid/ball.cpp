#include "ball.h"
#include "gl_helpers.h"
#include "config.h"
#define _USE_MATH_DEFINES
#include <math.h>

ball::ball(glm::vec2 const& pos)
    : pos_(pos)
    , direction_(START_BALL_DIRECTION)
    , color_(BALL_COLOR)
    , radius_(BALL_RADIUS)
    , speed_(START_BALL_SPEED) 
{}

void ball::render() {
    draw_circle(pos_, radius_, color_);
}

void ball::reverse() {
    inverse_horizontal();
    inverse_vertical();
}

void ball::inverse_vertical() {
    direction_.y *= -1.;
}

void ball::inverse_horizontal() {
    direction_.x *= -1.;
}

void ball::negate_vertical() {
    direction_.y = -fabs(direction_.y);
}

void ball::negate_horizontal() {
    direction_.x = -fabs(direction_.x);
}

void ball::positive_vertical() {
    direction_.y = fabs(direction_.y);
}

void ball::positive_horizontal() {
    direction_.x = fabs(direction_.x);
}

void ball::rotate_direction(float phi) {
    auto x = direction_.x;
    auto y = direction_.y;

    direction_.x = x * cos(phi) - y * sin(phi);
    direction_.y = x * sin(phi) + y * cos(phi);
    // disallow rotate more then 30 degrees
    if(fabs(direction_.y) < 0.5) {
        direction_.x = x;
        direction_.y = y;
    }
}

glm::vec2 ball::get_new_pos(float elapsed_time) const {
    return{ pos_.x + direction_.x * elapsed_time * speed_,
            pos_.y + direction_.y * elapsed_time * speed_ };
}

GLint ball::get_radius() const {
    return radius_;
}

void ball::apply_bonus(bonus* bonus) {
    bonus->visit(*this);
}

ball::~ball() {}

void ball::process(float elapsed_time) {
    auto new_x = pos_.x + direction_.x * elapsed_time * speed_;
    auto new_y = pos_.y + direction_.y * elapsed_time * speed_;
    bool collision = false;
    if (new_x - radius_ < 0 || new_x + radius_ > DEFAULT_GAME_WIDTH) {
        inverse_horizontal(); collision = true;
    }
    if (new_y - radius_ < 0 || new_y + radius_ > DEFAULT_GAME_HEIGHT) {
        inverse_vertical(); collision = true;
    }

    if (!collision) {
        pos_.x = new_x;
        pos_.y = new_y;
    }
}
