#pragma once
#include <glm/glm.hpp>
#include <gl/freeglut.h>
#include "ball.h"
#include "drawable.h"


class block : public drawable {
public:
    block(glm::vec2 const pos, GLint width, GLint height);

    bool collide(ball& b, float ellapsed_time) const;
    ~block() override;
    void render() override;
private:
    glm::vec2 pos_;
    GLint width_;
    GLint height_;
    int live_points_;
};
