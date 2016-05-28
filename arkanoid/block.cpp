#include "block.h"
#include "gl_helpers.h"
#include "geom_helpers.h"
#include "config.h"

block::block(glm::vec2 const pos, int strength)
    : pos_(pos)
    , width_(BLOCK_WIDTH)
    , height_(BLOCK_HEIGHT)
    , life_points_(strength) {
}

bool block::is_dead() const {
    return life_points_ <= 0;
}

bool block::collide(ball& b, float elapsed_time) {
    auto ball_pos = b.get_new_pos(elapsed_time);
    auto r = b.get_radius();

    glm::vec2 up_left = pos_;
    glm::vec2 up_right = pos_ + glm::vec2{ width_, 0 };
    glm::vec2 bottom_left = pos_ + glm::vec2{ 0, height_ };
    glm::vec2 bottom_right = pos_ + glm::vec2{ width_, height_ };
    --life_points_;

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

    ++life_points_;
    return false;
}

glm::vec2 block::get_pos() const {
    return pos_ + glm::vec2{width_ / 2, height_ / 2};
}

block::~block() {}

void block::render() {
    draw_rectangle(pos_, width_, height_, get_color_by_strength(life_points_));
}

glm::vec3 block::get_color_by_strength(int strength) {
    switch (strength) {
    case 1:
        return BLOCK_1_COLOR;
    case 2:
        return BLOCK_2_COLOR;
    case 3:
        return BLOCK_3_COLOR;
    case 4:
        return BLOCK_4_COLOR;
    case 5:
        return BLOCK_5_COLOR;
    default:
        assert(false);
    }
}
