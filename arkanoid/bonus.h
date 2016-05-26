#pragma once

class rocket;
class game_field;
class game;
class ball;

class bonus {
public:
    virtual ~bonus() {}

    virtual void visit(ball& ball) = 0;
    virtual void visit(game& game) = 0;
    virtual void visit(game_field& field) = 0;
    virtual void visit(rocket& player) = 0;
};
