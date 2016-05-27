#pragma once
#include "drawable.h"
#include <list>
#include "block.h"
#include "bonus.h"

class game_field : public drawable {
public:
    game_field(GLint width, GLint height);
    void render() override;
    ~game_field() override;

private:
    std::list<block> blocks_;
    //std::list<bonus> bonuses_;
};
