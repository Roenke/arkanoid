#pragma once
#include "drawable.h"
#include <glm/glm.hpp>
class rocket;
class game_field;
class game;
class ball;

class bonus : public drawable {
public:
    explicit bonus(glm::vec2 const& pos);
    virtual ~bonus() {}

    virtual void visit(ball& ball) = 0;
    virtual void visit(game& game) = 0;
    virtual void visit(game_field& field) = 0;
    virtual void visit(rocket& player) = 0;

    void process(float ellapsed_time);

protected:
    glm::vec2 pos_;
};
