#include <chrono>
#include <string>
#include <gl/freeglut.h>
#include <algorithm>
#include "gl_helpers.h"
#include "game.h"
#include "config.h"
game* game_ptr;
static const GLint GAME_FIELD_WIDTH = DEFAULT_GAME_WIDTH;
static const GLint GAME_FIELD_HEIGHT = DEFAULT_GAME_HEIGHT;

using time_point = std::chrono::high_resolution_clock::time_point;
static GLint screen_width = 1024;
static GLint screen_height = 768;

// Shared variabled, indicate some state of game
bool right_key_pressed = false;
bool left_key_pressed = false;

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
    switch (ch) {
    case 'd': case 226:
        right_key_pressed = true;
        break;
    case 'a': case 244:
        left_key_pressed = true;
        break;
    }
}

void on_key_up_callback(unsigned char ch, int a, int b) {
    switch (ch) {
    case 'd': case 226:
        right_key_pressed = false;
        break;
    case 'a': case 244:
        left_key_pressed = false;
        break;
    }
}

void fps_counter(time_point now) {
    static auto start_time = std::chrono::high_resolution_clock::now();
    static size_t frames;
    static size_t fps = 0;
    ++frames;
    draw_string(std::to_string(fps).c_str(), { 5, 20 }, { 1., 1., 0. }, GLUT_BITMAP_HELVETICA_18);
    auto diff = now - start_time;
    if (now - start_time >= std::chrono::milliseconds(50)) {
        fps = static_cast<size_t>(frames / (std::chrono::duration_cast<std::chrono::milliseconds>(diff).count() / 1000.));
        frames = 0;
        start_time = now;
    }
}

void display() {
    static time_point old_time = std::chrono::high_resolution_clock::now();
    auto now = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(now - old_time).count() / 1000.;
    game_ptr->process(elapsed_time);
    fps_counter(now);
    game_ptr->render();

    old_time = now;
}

int main(int argc, char* argv[]) {
    gl_config config{ on_key_down_callback, on_key_up_callback, display, reshape_callback, screen_width, screen_height };

    game_ptr = new game{ GAME_FIELD_WIDTH, GAME_FIELD_HEIGHT };

    init_gl(argc, argv, config);

    delete game_ptr;
    return 0;
}
