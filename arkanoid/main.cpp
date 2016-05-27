#include "gl_helpers.h"
#include "game.h"
#include <iostream>
#include <chrono>
#include <string>
#include <gl/freeglut.h>
#include <algorithm>
game* game_ptr;
static const GLint GAME_FIELD_WIDTH = 724;
static const GLint GAME_FIELD_HEIGHT = 768;

using time_point = std::chrono::high_resolution_clock::time_point;
static GLint screen_width = 1024;
static GLint screen_height = 768;

static void reshape_callback(GLint width, GLint height) {
    screen_width = std::max(GAME_FIELD_WIDTH, width);
    screen_height = std::max(GAME_FIELD_HEIGHT, height);
    glutReshapeWindow(screen_width, screen_height);
    glViewport(0, 0, screen_width, screen_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, screen_width, screen_height, 0, 0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void on_key_down_callback(unsigned char ch, int a, int b) {
    std::cout << "Key pressed: " << ch << " " << a << " " << b << std::endl;
}

void on_key_up_callback(unsigned char ch, int a, int b) {
    std::cout << "Key up: " << ch << " " << a << " " << b << std::endl;
}

void fps_counter() {
    static auto start_time = std::chrono::high_resolution_clock::now();
    static size_t frames;
    static size_t fps = 0;
    ++frames;
    draw_string(std::to_string(fps).c_str(), { 5, 20 }, { 1., 1., 0. }, GLUT_BITMAP_HELVETICA_18);
    auto now = std::chrono::high_resolution_clock::now();
    auto diff = now - start_time;
    if (now - start_time >= std::chrono::milliseconds(50)) {
        fps = static_cast<size_t>(frames / (std::chrono::duration_cast<std::chrono::milliseconds>(diff).count() / 1000.));
        frames = 0;
        start_time = now;
    }
}

void display() {
	fps_counter();
    game_ptr->render();
}

int main(int argc, char* argv[]) {
    gl_config config{ on_key_down_callback, on_key_up_callback, display, reshape_callback, screen_width, screen_height };

    game_ptr = new game{ GAME_FIELD_WIDTH, GAME_FIELD_HEIGHT };

    init_gl(argc, argv, config);

    delete game_ptr;
    return 0;
}
