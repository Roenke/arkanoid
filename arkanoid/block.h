#pragma once
#include <glm/glm.hpp>
#include <gl/freeglut.h>
#include "ball.h"
#include "drawable.h"


class block : public drawable {
public:
    block(glm::vec2 const pos, int strength);

    bool is_dead() const;

    bool collide(ball& b, float elapsed_time);

    glm::vec2 get_pos() const;

    ~block() override;
    void render() override;
private:
    static glm::vec3 get_color_by_strength(int strength);

    glm::vec2 pos_;
    GLint width_;
    GLint height_;
    int life_points_;
};
