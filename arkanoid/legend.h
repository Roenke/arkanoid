#pragma once
#include "drawable.h"
#include "bonus.h"
#include "block.h"
#include <vector>

class legend : public drawable {
public:
    legend();
    void render() override;

    ~legend() override;
private:
    std::vector<bonus*> bonuses_;
    std::vector<block> blocks_;
};
