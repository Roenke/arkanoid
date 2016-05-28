#define _USE_MATH_DEFINES
#include <algorithm>
#include <math.h>
#include "rocket.h"
#include "gl_helpers.h"
#include "ball.h"
#include "geom_helpers.h"
#include "bonus.h"

extern bool right_key_pressed;
extern bool left_key_pressed;

void rocket::collide_with_ball(float elapsed_time) {
    if(with_ball_) {
        return;
    }

    auto r = ball_.get_radius();
    auto pos = ball_.get_new_pos(elapsed_time);
    auto nearest = get_nearest_point(pos, { pos_,{ pos_.x + size_, pos_.y } });
    auto dist = distance_to_point(pos, nearest);
    if (dist < r) {
        ball_.inverse_vertical();
        float offset = nearest.x - (pos_.x + size_ / 2);
        float phi = static_cast<float>(M_PI_4) * (offset / (size_ / 2)) / 2;
        ball_.rotate_direction(phi);
    }
}

bool rocket::collide(bonus* bonus, float elapsed_time) const {
    auto bonus_vert = bonus->get_vertical_component();

    if (bonus_vert.first.x < pos_.x || bonus_vert.first.x > pos_.x + size_) {
        return false;
    }

    return bonus_vert.first.y <= pos_.y && bonus_vert.second.y >= pos_.y;
}

void rocket::process(float elapsed_time) {
    if(!left_key_pressed && right_key_pressed) {
        auto new_pos = static_cast<GLint>(pos_.x + elapsed_time * ROCKET_SPEED);
        pos_.x = static_cast<float>(std::min(DEFAULT_GAME_WIDTH - size_, new_pos));
    }
    if(left_key_pressed && !right_key_pressed) {
        auto new_pos = static_cast<GLint>(pos_.x - elapsed_time * ROCKET_SPEED);
        pos_.x = static_cast<float>(std::max(0, new_pos));
    }

    if(!with_ball_) {
        ball_.process(elapsed_time);
    }
    else {
        center_ball();
    }
}

rocket::~rocket() {}

void rocket::render() {
    ball_.render();
    draw_rectangle(pos_, size_, height_, { 0.6, 0.4, 0.2 });
}

void rocket::apply_bonus(bonus* bonus) {
    bonus->visit(*this);
    ball_.apply_bonus(bonus);
}

ball& rocket::get_ball() {
    return ball_;
}

void rocket::release_ball() {
    with_ball_ = false;
}

void rocket::center_ball() {
    ball_.set_position(pos_ + glm::vec2{ size_ / 2, -BALL_RADIUS });
}
