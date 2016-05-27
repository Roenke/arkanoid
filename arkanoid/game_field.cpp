#include "game_field.h"
#include "config.h"
#include "extend_bonus.h"

game_field::game_field() {
    glm::vec2 pos = { BLOCK_H_OFFSET, BLOCK_V_OFFSET };

    for(int i = 0; i < BLOCK_ROWS_COUNT; ++i) {
        while(pos.x + BLOCK_WIDTH < DEFAULT_GAME_WIDTH - BLOCK_H_OFFSET) {
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

    for(auto bonus : bonuses_) {
        bonus->render();
    }
}

game_field::~game_field() {}

void game_field::collide(ball& b, float ellapsed_time) {
    auto it = blocks_.begin();
    while(it != blocks_.end()) {
        if (it->collide(b, ellapsed_time)) {
            bonuses_.push_back(new extend_bonus{ it->get_pos() });
            it = blocks_.erase(it);
            break;
        }

        ++it;
    }
}

void game_field::process(float ellapsed_time) {
    for(auto bonus : bonuses_) {
        bonus->process(ellapsed_time);
    }
}
