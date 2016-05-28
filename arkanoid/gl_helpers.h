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
void draw_rectangle(glm::vec2 const& up_left, GLint width, GLint height, glm::vec3 const& color);
void draw_frame(glm::vec2 const& up_left, GLint width, GLint height, glm::vec3 const& color);
void draw_circle(glm::vec2 const& center, GLint r, glm::vec3 const& color);
void draw_diamond(glm::vec2 const& center, GLint width, GLint height, glm::vec3 const& color);
void draw_line_with_noise(glm::vec2 const& begin, glm::vec2 const& end, GLint noise_level, GLint step_count, glm::vec3 const& color);