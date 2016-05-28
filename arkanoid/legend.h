#pragma once
#include "drawable.h"

class legend : public drawable {
public:
    ~legend() override;
    void render() override;
};
