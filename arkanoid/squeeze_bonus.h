#pragma once
#include "bonus.h"

class squeeze_bonus : public bonus {
public:
    explicit squeeze_bonus(glm::vec2 const& pos)
        : bonus(pos) {}

    void render() override;
    ~squeeze_bonus() override {};
    void visit(ball& ball) override {};
    void visit(game& game) override {};
    void visit(game_field& field) override {};
    void visit(rocket& player) override;
};
