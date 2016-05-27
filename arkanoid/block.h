#pragma once
#include <glm/glm.hpp>
#include <gl/freeglut.h>

#include "drawable.h"

class block : public drawable {
public:
    block(glm::vec2 const pos, GLint width, GLint height);

    ~block() override;
    void render() override;
private:
    glm::vec2 pos_;
    GLint width_;
    GLint height_;
};
