#include "rocket.h"
#include "gl_helpers.h"
rocket::~rocket() {}

void rocket::render() {
    draw_rectangle(pos_, size_, height_, { 0.6, 0.4, 0.2 });
}
