#pragma once
#include "drawable.h"
#include "rocket.h"
#include "game_field.h"
#include "ball.h"
#include <gl/freeglut.h>
#include "game_border.h"

class game : public drawable {
public:
    game(GLint width, GLint height);
    ~game() override;
    void render() override;

private:
    rocket player_;
    game_field field_;
    game_border border_;
    ball ball_;

    int score_;
    int lives_;
};
