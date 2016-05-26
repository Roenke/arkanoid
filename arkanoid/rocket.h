#pragma once
#include <glm/glm.hpp>
#include "drawable.h"

class rocket : public drawable {
public:
    rocket(const glm::vec2& pos, double size)
        : pos(pos),
          size_(size) {}


    ~rocket() override;
    void render() override;
private:
    glm::vec2 pos;
    double size_;
};
