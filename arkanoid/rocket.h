#pragma once
#include <glm/glm.hpp>
class rocket {
public:
    rocket(const glm::vec2& pos, double size)
        : pos(pos),
          size_(size) {}


private:
    glm::vec2 pos;
    double size_;
};
