#include "init_gl.h"
#include "game.h"
#include <iostream>
#include <chrono>
#include <string>
game* game_ptr;

using time_point = std::chrono::high_resolution_clock::time_point;

void on_key_down_callback(unsigned char ch, int a, int b) {
    std::cout << "Key pressed: " << ch << " " << a << " " << b << std::endl;
}

void on_key_up_callback(unsigned char ch, int a, int b) {
    std::cout << "Key up: " << ch << " " << a << " " << b << std::endl;
}

void draw_string(const char * text) {
    glRasterPos2f(-1, 0.93);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<const unsigned char*>(text));
}

void display() {
    static auto start_time = std::chrono::high_resolution_clock::now();
    static size_t frames;
    static size_t fps = 0;
    ++frames;
    glColor3f(1., 1., 1.);
    glRectf(-1, -1, 1, 1);
    glColor3f(0., 0., 0.);
    draw_string(std::to_string(fps).c_str());
    auto now = std::chrono::high_resolution_clock::now();
    auto diff = now - start_time;
    if(now - start_time >= std::chrono::milliseconds(50)) {
        fps = frames / (std::chrono::duration_cast<std::chrono::milliseconds>(diff).count() / 1000.);
        frames = 0;
        start_time = now;
    }
}

int main(int argc, char* argv[]) {
    gl_config config{ on_key_down_callback, on_key_up_callback, display };

    game_ptr = new game;

    init_gl(argc, argv, config);

    delete game_ptr;
    return 0;
}