#include "legend.h"
#include "random_bonus_factory.h"
#include "config.h"
#include "gl_helpers.h"
#include <sstream>

legend::legend()
    : bonuses_(random_bonus_factory::get_all_bonuses()) {
    glm::vec2 start_pos{ LEGEND_X_OFFSET, LEGEND_Y_OFFSET + LEGEND_NOTE_OFFSET };
    for(auto bonus_ptr : bonuses_) {
        bonus_ptr->pos_ = start_pos;
        start_pos.y += LEGEND_NOTE_OFFSET;
    }

    for(int i = 1; i <= MAX_BLOCK_LIVE; ++i) {
        blocks_.emplace_back(start_pos, i);
        start_pos.y += LEGEND_NOTE_OFFSET + 3;
    }
}

void legend::render() {
    draw_string("Legend:", { LEGEND_X_OFFSET, LEGEND_Y_OFFSET }, LEGEND_COLOR, LEGEND_FONT);
    for(auto bonus_ptr : bonuses_) {
        bonus_ptr->render();
        draw_string(bonus_ptr->get_description(), bonus_ptr->pos_ + glm::vec2{ BONUS_WIDTH, BONUS_HEIGHT / 2 }, LEGEND_COLOR, LEGEND_FONT);
    }

    for (int i = 0; i < MAX_BLOCK_LIVE; ++i) {
        std::stringstream ss;
        ss << i + 1 << " strength block";
        blocks_[i].render();
        draw_string(ss.str().c_str(), blocks_[i].get_pos() + glm::vec2{ BLOCK_WIDTH, BLOCK_HEIGHT / 3}, LEGEND_COLOR, LEGEND_FONT);
    }
}

legend::~legend() {
    for(auto bonus_ptr : bonuses_) {
        delete bonus_ptr;
    }
}
