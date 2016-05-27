#pragma once
#include <glm/glm.hpp>
#include <gl/freeglut.h>
#include "drawable.h"
class ball : public drawable {
public:
    ball(const glm::vec2& pos, const glm::vec2& direction, const glm::vec3& color, GLint radius);

    void render() override;

    ~ball() override;
private:
    glm::vec2 pos_;
    glm::vec2 direction_;
    glm::vec3 color_;
    GLint radius_;
};
