#include "ball.h"
#include "gl_helpers.h"
#include "config.h"

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

ball::~ball() {}

void ball::process(float elapsed_time) {

}
