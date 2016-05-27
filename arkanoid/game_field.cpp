#include "game_field.h"
#include "config.h"
game_field::game_field(GLint width, GLint height) {
    glm::vec2 pos = { BLOCK_H_OFFSET, BLOCK_V_OFFSET };

    for(int i = 0; i < BLOCK_ROWS_COUNT; ++i) {
        while(pos.x + BLOCK_WIDTH < width - BLOCK_H_OFFSET) {
            blocks_.push_back(block(pos, BLOCK_WIDTH, BLOCK_HEIGHT));
            pos.x += BLOCK_WIDTH + BETWEEN_BLOCKS_H_OFFSET;
        }

        pos.x = BLOCK_H_OFFSET;
        pos.y += BETWEEN_BLOCKS_V_OFFSET + BLOCK_HEIGHT;
    }
}

void game_field::render() {
    for(auto& b : blocks_) {
        b.render();
    }
}

game_field::~game_field() {}
