#pragma once
#include "drawable.h"
#include <list>
#include "block.h"
#include "bonus.h"
#include "random_bonus_factory.h"

class game_field : public drawable {
public:
    game_field();
    void render() override;
    ~game_field() override;
    void collide(ball& b, float ellapsed_time, game* game_ptr);
    void process(float ellapsed_time);

private:
    std::list<block> blocks_;
    std::list<bonus*> bonuses_;

    random_bonus_factory bonus_factory_;
};
