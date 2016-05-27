#pragma once
#include <gl/freeglut.h>
#include <chrono>
#include "drawable.h"
#include "rocket.h"
#include "game_field.h"
#include "ball.h"
#include "game_border.h"

class game : public drawable {
public:
    game(GLint width, GLint height);
    ~game() override;
    void render() override;
    void process(float elapsed_time);

private:
    rocket player_;
    game_field field_;
    game_border border_;
    ball ball_;

    int score_;
    int lives_;
};
