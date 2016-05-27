#pragma once
#include <glm/glm.hpp>
#include "drawable.h"

class ball : public drawable {
public:
    void render() override;

private:
    glm::vec2 pos_;
    glm::vec2 direction_;
};
