#pragma once
#include "drawable.h"
#include <list>
#include "block.h"

class game_field : public drawable {
public:
    void render() override;
    ~game_field() override;

private:
    std::list<block> blocks_;
};
