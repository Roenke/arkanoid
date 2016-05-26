#include "gl_helpers.h"
#include <gl/freeglut.h>
#include <iostream>

static size_t SCREEN_WIDTH = 800;
static size_t SCREEN_HEIGHT = 600;

static void (*display_callback_internal)();

static void idle_callback() {
    glutPostRedisplay();
}

static void display_callback() {
    glClear(GL_COLOR_BUFFER_BIT);
    display_callback_internal();
    glutSwapBuffers();
}

static void reshape_callback(GLint width, GLint height) {
	SCREEN_WIDTH = width;
	SCREEN_HEIGHT = height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, height, 0, 0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

static void mouse_callback(GLint mouse_button, GLint current_state, GLint x, GLint y) {
	std::cout << "Mouse click: " << mouse_button << ", x = " << x << " , y = " << y << std::endl;
}

void init_gl(int argc, char* argv[], gl_config const& config) {
    glutInit(&argc, argv);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutInitWindowPosition(500, 200);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("arkanoid");
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glutKeyboardFunc(config.key_pressed_callback);
    glutKeyboardUpFunc(config.key_up_callback);

    display_callback_internal = config.display;
    glutDisplayFunc(display_callback);
    glutIdleFunc(idle_callback);
    glutReshapeFunc(reshape_callback);
	glutMouseFunc(mouse_callback);

    glutMainLoop();
}

void draw_string(const char* text, glm::vec2 const& pos, glm::vec3 const& color, void* font) {
    glColor3f(color.r, color.g, color.b);
    glRasterPos2i(pos.x, pos.y);
    glutBitmapString(font, reinterpret_cast<const unsigned char*>(text));
}

void draw_rectangle(glm::vec2 const& up_left, float width, float height, glm::vec3 const& color) {
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POLYGON);
        glVertex2f(up_left.x, up_left.y);
        glVertex2f(up_left.x + width, up_left.y);
        glVertex2f(up_left.x + width, up_left.y + height);
        glVertex2f(up_left.x, up_left.y + height);
    glEnd();
    glFinish();
}
