#include "gl_helpers.h"
#include "game.h"
#include <iostream>
#include <chrono>
#include <string>
#include <gl/freeglut.h>
game* game_ptr;

using time_point = std::chrono::high_resolution_clock::time_point;

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
    draw_rectangle({10, 20}, 10, 10, {1, 1, 1});
}

int main(int argc, char* argv[]) {
    gl_config config{ on_key_down_callback, on_key_up_callback, display };

    game_ptr = new game{};

    init_gl(argc, argv, config);

    delete game_ptr;
    return 0;
}
