#pragma once
#include <glm/glm.hpp>
#include <gl/freeglut.h>
#include "drawable.h"

class ball : public drawable {
public:
    explicit ball(glm::vec2 const& pos);

    void render() override;
    void reverse();
    void inverse_vertical();
    void inverse_horizontal();

    void negate_vertical();
    void negate_horizontal();
    void positive_vertical();
    void positive_horizontal();

    glm::vec2 get_new_pos(float elapsed_time) const;
    GLint get_radius() const;

    ~ball() override;
    void process(float elapsed_time);
private:
    glm::vec2 pos_;
    glm::vec2 direction_;
    glm::vec3 color_;
    GLint radius_;
    GLint speed_;
};
