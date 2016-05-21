#pragma once
#include <gl/freeglut.h>
struct gl_config {
    void(*key_pressed_callback)(unsigned char, int, int);
    void(*key_up_callback)(unsigned char, int, int);
    void(*display)();
};

void init_gl(int argc, char* argv[], gl_config const& config);
