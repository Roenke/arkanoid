#define _USE_MATH_DEFINES
#include <algorithm>
#include <math.h>
#include "rocket.h"
#include "gl_helpers.h"
#include "ball.h"
#include "geom_helpers.h"

extern bool right_key_pressed;
extern bool left_key_pressed;

void rocket::collide(ball& b, float elapsed_time) const {
    auto r = b.get_radius();
    auto pos = b.get_new_pos(elapsed_time);
    auto nearest = get_nearest_point(pos, { pos_,{ pos_.x + size_, pos_.y } });
    auto dist = distance_to_point(pos, nearest);
    if (dist < r) {
        b.inverse_vertical();
        auto offset = nearest.x - (pos_.x + size_ / 2);
        auto phi = M_PI_4 * (offset / (size_ / 2)) / 2;
        b.rotate_direction(phi);
    }
}

void rocket::process(float elapsed_time) {
    if(!left_key_pressed && right_key_pressed) {
        GLint new_pos = pos_.x + elapsed_time * ROCKET_SPEED;
        pos_.x = std::min(DEFAULT_GAME_WIDTH - size_, new_pos);
    }
    if(left_key_pressed && !right_key_pressed) {
        GLint new_pos = pos_.x - elapsed_time * ROCKET_SPEED;
        pos_.x = std::max(0, new_pos);
    }
}

rocket::~rocket() {}

void rocket::render() {
    draw_rectangle(pos_, size_, height_, { 0.6, 0.4, 0.2 });
}
