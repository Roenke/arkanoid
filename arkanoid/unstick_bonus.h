#pragma once
#include "bonus.h"

class unstick_bonus : public bonus {
public:
    explicit unstick_bonus(glm::vec2 const& pos)
        : bonus(pos) {}

    void visit(ball& ball) override {};
    void visit(game& game) override {};
    void visit(game_field& field) override {};
    void visit(rocket& player) override;
    glm::vec3 get_color() override;
    const char* get_description() const override;
};
