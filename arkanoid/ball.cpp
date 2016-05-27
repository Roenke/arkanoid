#include "ball.h"
#include "gl_helpers.h"

ball::ball(const glm::vec2& pos, const glm::vec2& direction, const glm::vec3& color, GLint radius)
    : pos_(pos)
    , direction_(direction)
    , color_(color)
    , radius_(radius) {}

void ball::render() {
    draw_circle(pos_, radius_, color_);
}

ball::~ball() {}
