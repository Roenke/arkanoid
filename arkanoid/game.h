#pragma once
#include "drawable.h"
#include "rocket.h"
#include "game_field.h"
#include "ball.h"

class game : public drawable {
public:
    game() = default;
    ~game() override;
    void render() override;

private:
    rocket player_;
    game_field field_;
    ball ball_;

    int score_;
    int lives_;
};
