#pragma once
#include "bonus.h"

class extend_bonus : public bonus {
public:
    explicit extend_bonus(glm::vec2 const& pos)
        : bonus(pos) {}

    void render() override;
    ~extend_bonus() override {};
    void visit(ball& ball) override {};
    void visit(game& game) override {};
    void visit(game_field& field) override {};
    void visit(rocket& player) override;
};
