#pragma once
#include <glm/glm.hpp>
#include <gl/freeglut.h>
#include "drawable.h"
#include "config.h"
#include "ball.h"
class unstick_bonus;
class stick_bonus;
class bonus;
class squeeze_bonus;
class extend_bonus;
class ball;

class rocket : public drawable {
public:
    rocket()
        : pos_({ START_ROCKET_H_OFFSET, DEFAULT_GAME_HEIGHT - ROCKET_BOTTOM_OFSET })
        , size_(START_ROCKET_SIZE)
        , height_(START_ROCKET_HEIGHT)
        , ball_({ 0, 0})
        , with_ball_(true) {
        center_ball();
    }

    void collide_with_ball(float elapsed_time);
    bool collide(bonus* bonus, float elapsed_time) const;

    void process(float elapsed_time);
    ~rocket() override;
    void render() override;
    void apply_bonus(bonus* bonus);
    ball& get_ball();
    void release_ball();
    // bonuses
    friend extend_bonus;
    friend squeeze_bonus;
    friend stick_bonus;
    friend unstick_bonus;

private:
    void center_ball();

    glm::vec2 pos_;
    GLint size_;
    GLint height_;

    ball ball_;

    bool with_ball_;
};
