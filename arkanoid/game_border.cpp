#include "game_border.h"
#include "gl_helpers.h"
#include "config.h"
game_border::~game_border() {}

void game_border::render() {
    draw_frame({ 1, 1 }, DEFAULT_GAME_WIDTH, DEFAULT_GAME_HEIGHT, { 1, 0, 1 });
}
