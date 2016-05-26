#pragma once
#include "drawable.h"
#include "game_object.h"
#include <list>
#include "block.h"

class game_field : public drawable, public game_object {
public:
    void render() override;
    object_type get_type() override;
    ~game_field() override;

private:
    std::list<block> blocks_;
};
