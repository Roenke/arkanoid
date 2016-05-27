#include "bonus.h"
#include "config.h"

bonus::bonus(glm::vec2 const& pos)
    : pos_(pos)
{}

void bonus::process(float ellapsed_time) {
    pos_.y += ellapsed_time * BONUS_FALL_SPEED;
}
