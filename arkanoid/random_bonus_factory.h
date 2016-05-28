#pragma once
#include <random>
#include "bonus.h"

class random_bonus_factory {
public:
    random_bonus_factory();

    bonus* get_random_bonus(glm::vec2 const& pos);
private:
    std::default_random_engine generator_;
    std::uniform_int_distribution<int> distribution_;
};
