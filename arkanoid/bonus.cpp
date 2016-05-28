#include "bonus.h"
#include "config.h"
#include "gl_helpers.h"

bonus::bonus(glm::vec2 const& pos)
    : pos_(pos)
{}

std::pair<glm::vec2, glm::vec2> bonus::get_vertical_component() const {
    auto offset = BONUS_HEIGHT / 2;
    return{ { pos_.x, pos_.y - offset }, { pos_.x, pos_.y + offset } };
}

void bonus::process(float elapsed_time) {
    pos_.y += elapsed_time * BONUS_FALL_SPEED;
}

void bonus::render() {
    draw_diamond(pos_, BONUS_WIDTH, BONUS_HEIGHT, get_color());
}
