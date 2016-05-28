#include "gl_helpers.h"
#include <gl/freeglut.h>
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>
#include <glm/detail/type_mat.hpp>
#include <glm/detail/type_mat.hpp>

static const int CIRCLE_PARTS = 50;


static void (*display_callback_internal)();

static void idle_callback() {
    glutPostRedisplay();
}

static void display_callback() {
    glClear(GL_COLOR_BUFFER_BIT);
    display_callback_internal();
    glutSwapBuffers();
}

static void mouse_callback(GLint mouse_button, GLint current_state, GLint x, GLint y) {
	std::cout << "Mouse click: " << mouse_button << ", x = " << x << " , y = " << y << std::endl;
}

void init_gl(int argc, char* argv[], gl_config const& config) {
    glutInit(&argc, argv);
    glutInitWindowSize(config.default_window_width, config.default_window_height);
    glutInitWindowPosition(500, 200);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("arkanoid");
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glutKeyboardFunc(config.key_pressed_callback);
    glutKeyboardUpFunc(config.key_up_callback);
    glutReshapeFunc(config.reshape_callback);

    display_callback_internal = config.display;
    glutDisplayFunc(display_callback);
    glutIdleFunc(idle_callback);
	glutMouseFunc(mouse_callback);

    glutMainLoop();
}

void draw_string(const char* text, glm::vec2 const& pos, glm::vec3 const& color, void* font) {
    glColor3f(color.r, color.g, color.b);
    glRasterPos2f(pos.x, pos.y);
    glutBitmapString(font, reinterpret_cast<const unsigned char*>(text));
}

static void draw_rectangle_internal(int draw_type, glm::vec2 const& up_left, GLint width, GLint height, glm::vec3 const& color) {
    glColor3f(color.r, color.g, color.b);
    glBegin(draw_type);
        glVertex2f(up_left.x, up_left.y);
        glVertex2f(up_left.x + width, up_left.y);
        glVertex2f(up_left.x + width, up_left.y + height);
        glVertex2f(up_left.x, up_left.y + height);
    glEnd();
    glFinish();
}

void draw_rectangle(glm::vec2 const& up_left, GLint width, GLint height, glm::vec3 const& color) {
    draw_rectangle_internal(GL_POLYGON, up_left, width, height, color);
}

void draw_frame(glm::vec2 const& up_left, GLint width, GLint height, glm::vec3 const& color) {
    draw_rectangle_internal(GL_LINE_LOOP, up_left, width, height, color);
}

void draw_circle(glm::vec2 const& center, GLint r, glm::vec3 const& color) {
    float phi = 2 * static_cast<float>(M_PI) / CIRCLE_PARTS;
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POLYGON);
        for (int i = 0; i < CIRCLE_PARTS; i++)
            glVertex2f(center.x + r * cos(i * phi), center.y + r * sin(i * phi));
    glEnd();
    glFinish();
}

void draw_diamond(glm::vec2 const& center, GLint width, GLint height, glm::vec3 const& color) {
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POLYGON);
        glVertex2f(center.x + width / 2, center.y);
        glVertex2f(center.x, center.y + height / 2);
        glVertex2f(center.x - width / 2, center.y);
        glVertex2f(center.x, center.y - height / 2);
    glEnd();
    glFinish();
}
