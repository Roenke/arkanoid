#pragma once
#include "drawable.h"
#include <gl/freeglut.h>
class safe_line {
public:
    safe_line() = delete;
    static void render(GLint num);
};
