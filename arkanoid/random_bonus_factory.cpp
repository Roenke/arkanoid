#include "random_bonus_factory.h"
#include <chrono>
#include "extend_bonus.h"
#include "squeeze_bonus.h"
#include "speed_up_bonus.h"
#include "speed_down_bonus.h"
#include "stick_bonus.h"
#include "unstick_bonus.h"
#include "crazy_ball_bonus.h"
#include "config.h"
#include "safe_line_bonus.h"

random_bonus_factory::random_bonus_factory()
    : generator_(static_cast<uint32_t>(std::chrono::system_clock::now().time_since_epoch().count()))
    , distribution_(0, BONUSES_COUNT)
{}

std::vector<bonus*> random_bonus_factory::get_all_bonuses() {
    glm::vec2 pos = { 0, 0 };
    return {
        new extend_bonus(pos),
        new squeeze_bonus(pos),
        new speed_up_bonus(pos),
        new speed_down_bonus(pos),
        new stick_bonus(pos),
        new unstick_bonus(pos),
        new crazy_ball_bonus(pos),
        new safe_line_bonus(pos)
    };
}

bonus* random_bonus_factory::get_random_bonus(glm::vec2 const& pos) {
    if(!(rand() < RAND_MAX / 10)) {
        return nullptr;
    }

    switch (distribution_(generator_)) {
    case 0: 
        return new extend_bonus(pos);
    case 1:
        return new squeeze_bonus(pos);
    case 2:
        return new speed_up_bonus(pos);
    case 3:
        return  new speed_down_bonus(pos);
    case 4:
        return new stick_bonus(pos);
    case 5:
        return new unstick_bonus(pos);
    case 6:
        return new crazy_ball_bonus(pos);
    case 7:
        return new safe_line_bonus(pos);
    default:
        return nullptr;
    }
}
