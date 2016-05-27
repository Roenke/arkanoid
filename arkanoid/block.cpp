#include "block.h"
#include "gl_helpers.h"
#include "geom_helpers.h"
block::block(glm::vec2 const pos, GLint width, GLint height)
    : pos_(pos)
    , width_(width)
    , height_(height) {
}

bool block::collide(ball& b, float ellapsed_time) {
    auto ball_pos = b.get_new_pos(ellapsed_time);
    auto r = b.get_radius();

    glm::vec2 up_left = pos_;
    glm::vec2 up_right = pos_ + glm::vec2{ width_, 0 };
    glm::vec2 bottom_left = pos_ + glm::vec2{ 0, height_ };
    glm::vec2 bottom_right = pos_ + glm::vec2{ width_, height_ };

    if (distance_to_point(ball_pos, up_left) < r) {
        b.negate_vertical(); b.negate_horizontal(); return true;
    }
    if (distance_to_point(ball_pos, up_right) < r) {
        b.negate_vertical(); b.positive_horizontal(); return true;
    }
    if (distance_to_point(ball_pos, bottom_left) < r) {
        b.positive_vertical(); b.negate_horizontal(); return true;
    }
    if (distance_to_point(ball_pos, bottom_right) < r) {
        b.positive_horizontal(); b.positive_vertical(); return true;
    }

    if (distance_to_segment(ball_pos, { up_left, bottom_left }) < r ||
        distance_to_segment(ball_pos, { up_right, bottom_right }) < r) {
        b.inverse_horizontal();
        return true;
    }

    if (distance_to_segment(ball_pos, { up_left, up_right }) < r ||
        distance_to_segment(ball_pos, { bottom_left, bottom_right }) < r) {
        b.inverse_vertical(); 
        return true;
    }

    return false;
}

block::~block() {}

void block::render() {
    draw_rectangle(pos_, width_, height_, {0, 1, 1});
}
