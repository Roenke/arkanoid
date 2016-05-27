#include "block.h"
#include "gl_helpers.h"
block::block(glm::vec2 const pos, GLint width, GLint height)
    : pos_(pos)
    , width_(width)
    , height_(height)
{}

block::~block() {}

void block::render() {
    draw_rectangle(pos_, width_, height_, {0, 1, 1});
}
