#pragma once
#include <glm/glm.hpp>
#include <gl/freeglut.h>
#include "drawable.h"
#include "bonus.h"
class speed_up_bonus;
class speed_down_bonus;

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
    void rotate_direction(float phi);

    glm::vec2 get_new_pos(float elapsed_time) const;
    GLint get_radius() const;

    void apply_bonus(bonus* bonus);

    ~ball() override;
    void process(float elapsed_time);

    friend speed_down_bonus;
    friend speed_up_bonus;
private:
    glm::vec2 pos_;
    glm::vec2 direction_;
    glm::vec3 color_;
    GLint radius_;
    GLint speed_;
};
