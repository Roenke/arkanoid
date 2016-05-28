#include "bonus.h"
#include "config.h"

bonus::bonus(glm::vec2 const& pos)
    : pos_(pos)
{}


std::pair<glm::vec2, glm::vec2> bonus::get_vertical_component() const {
    auto offset = BONUS_HEIGHT / 2;
    return{ { pos_.x, pos_.y - offset }, { pos_.x, pos_.y + offset } };
}

void bonus::process(float ellapsed_time) {
    pos_.y += ellapsed_time * BONUS_FALL_SPEED;
}
