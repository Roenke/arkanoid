#pragma once
#include <glm/glm.hpp>
#include <gl/freeglut.h>
#include "drawable.h"

class rocket : public drawable {
public:
    rocket(const glm::vec2& pos, GLint size, GLint height)
        : pos_(pos),
          size_(size),
          height_(height) 
    {}


    ~rocket() override;
    void render() override;
private:
    glm::vec2 pos_;
    GLint size_;
    GLint height_;
};
