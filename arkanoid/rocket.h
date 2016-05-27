#pragma once
#include <glm/glm.hpp>
#include <gl/freeglut.h>
#include "drawable.h"
#include "config.h"
class squeeze_bonus;
class extend_bonus;
class ball;

class rocket : public drawable {
public:
    rocket()
        : pos_({ START_ROCKET_H_OFFSET, DEFAULT_GAME_HEIGHT - ROCKET_BOTTOM_OFSET })
        , size_(START_ROCKET_SIZE)
        , height_(START_ROCKET_HEIGHT)
    {}

    void collide(ball& ball, float elapsed_time) const;

    void process(float elapsed_time);
    ~rocket() override;
    void render() override;

    // bonuses
    friend extend_bonus;
    friend squeeze_bonus;
private:
    glm::vec2 pos_;
    GLint size_;
    GLint height_;
};
