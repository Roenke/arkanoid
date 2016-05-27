#pragma once
#include <glm/glm.hpp>
#include <gl/freeglut.h>
struct gl_config {
    void(*key_pressed_callback)(unsigned char, int, int);
    void(*key_up_callback)(unsigned char, int, int);
    void(*display)();
    void(*reshape_callback)(GLint, GLint);

    GLint default_window_width;
    GLint default_window_height;
};

void init_gl(int argc, char* argv[], gl_config const& config);
void draw_string(const char* text, glm::vec2 const& pos, glm::vec3 const& color, void* font);
void draw_rectangle(glm::vec2 const& up_left, float width, float height, glm::vec3 const& color);
void draw_frame(glm::vec2 const& up_left, float width, float height, glm::vec3 const& color);
void draw_circle(glm::vec2 const& center, float r, glm::vec3 const& color);
