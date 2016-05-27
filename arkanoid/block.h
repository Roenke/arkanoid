#pragma once
#include "drawable.h"

class block : public drawable {

public:
    ~block() override;
    void render() override;
};
