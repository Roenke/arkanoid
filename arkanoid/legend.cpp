#include "legend.h"
#include "random_bonus_factory.h"
#include "config.h"
#include "gl_helpers.h"
legend::legend()
    : bonuses_(random_bonus_factory::get_all_bonuses()) {
    glm::vec2 start_pos{ LEGEND_X_OFFSET, LEGEND_Y_OFFSET + LEGEND_NOTE_OFFSET };
    for(auto bonus_ptr : bonuses_) {
        bonus_ptr->pos_ = start_pos;
        start_pos.y += LEGEND_NOTE_OFFSET;
    }
}

void legend::render() {
    draw_string("Legend:", { LEGEND_X_OFFSET, LEGEND_Y_OFFSET }, LEGEND_COLOR, LEGEND_FONT);
    for(auto bonus_ptr : bonuses_) {
        bonus_ptr->render();
        draw_string(bonus_ptr->get_description(), bonus_ptr->pos_ + glm::vec2{ BONUS_WIDTH, BONUS_HEIGHT / 2 }, LEGEND_COLOR, LEGEND_FONT);
    }
}

legend::~legend() {
    for(auto bonus_ptr : bonuses_) {
        delete bonus_ptr;
    }
}
