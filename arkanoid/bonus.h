#pragma once
#include "drawable.h"
#include <glm/glm.hpp>
#include <utility>
class legend;
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
    virtual glm::vec3 get_color() = 0;
    virtual const char* get_description() const = 0;

    std::pair<glm::vec2, glm::vec2> get_vertical_component() const;
    void process(float elapsed_time);
    void render() override;

    friend legend;
protected:
    glm::vec2 pos_;
};
