#pragma once
#include <glm/glm.hpp>
struct gl_config {
    void(*key_pressed_callback)(unsigned char, int, int);
    void(*key_up_callback)(unsigned char, int, int);
    void(*display)();
};

void init_gl(int argc, char* argv[], gl_config const& config);
void draw_string(const char* text, glm::vec2 const& pos, glm::vec3 const& color, void* font);
void background_fill(glm::vec3 const& color);