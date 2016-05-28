#include "random_bonus_factory.h"
#include <chrono>
#include "extend_bonus.h"
#include "squeeze_bonus.h"
#include "speed_up_bonus.h"
#include "speed_down_bonus.h"

random_bonus_factory::random_bonus_factory()
    : generator_(std::chrono::system_clock::now().time_since_epoch().count())
    , distribution_(0, BONUSES_COUNT)
{}

bonus* random_bonus_factory::get_random_bonus(glm::vec2 const& pos) {
    if(distribution_(generator_) < BONUSES_COUNT / 2) {
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
    default:
        return nullptr;
    }
}
