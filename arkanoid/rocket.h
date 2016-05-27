#pragma once
#include <glm/glm.hpp>
#include <gl/freeglut.h>
#include "drawable.h"
#include "config.h"
class ball;

class rocket : public drawable {
public:
    rocket(GLint field_width, GLint field_height)
        : pos_({ START_ROCKET_H_OFFSET, field_height - ROCKET_BOTTOM_OFSET })
        , size_(START_ROCKET_SIZE)
        , height_(START_ROCKET_HEIGHT)
    {}

    void collide(ball& ball, float elapsed_time) const;

    void process(float elapsed_time);
    ~rocket() override;
    void render() override;
private:
    glm::vec2 pos_;
    GLint size_;
    GLint height_;
};
