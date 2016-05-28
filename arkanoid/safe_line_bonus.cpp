#include "safe_line_bonus.h"
#include "config.h"
#include "game.h"
#include <algorithm>

void safe_line_bonus::visit(game& game) {
    game.save_line_count = std::min(game.save_line_count + 1, MAX_SAFE_LINE_COUNT);
}

glm::vec3 safe_line_bonus::get_color() {
    return SAFE_LINE_BONUS_COLOR;
}

const char* safe_line_bonus::get_description() const {
    return SAFE_LINE_BONUS_DESCRIPTION;
}

