#include "game_border.h"
#include "gl_helpers.h"
game_border::game_border(GLint width, GLint height)
    : width_(width - 300)
    , height_(height) {}

game_border::~game_border() {}

void game_border::render() {
    draw_frame({ 1, 1 }, width_, height_, { 1, 0, 1 });
}
