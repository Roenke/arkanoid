#include "game_field.h"
#include "config.h"
#include "game.h"
#include <random>
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

void game_field::collide(ball& b, float ellapsed_time, game* game_ptr) {
    auto it = blocks_.begin();
    while(it != blocks_.end()) {
        if (it->collide(b, ellapsed_time)) {
            bonus* bonus = bonus_factory_.get_random_bonus(it->get_pos());
            if(bonus) {
                bonuses_.push_back(bonus);
            }
            it = blocks_.erase(it);
            break;
        }

        ++it;
    }

    auto player = game_ptr->get_rocket();
    auto bonus_it = bonuses_.begin();
    while(bonus_it != bonuses_.end()) {
        if(player.collide(*bonus_it, ellapsed_time)) {
            game_ptr->apply_bonus(*bonus_it);
            bonus_it = bonuses_.erase(bonus_it);
        }
        else {
            ++bonus_it;
        }
    }
}

void game_field::process(float ellapsed_time) {
    for(auto bonus : bonuses_) {
        bonus->process(ellapsed_time);
    }
}
