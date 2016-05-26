#include "gl_helpers.h"
#include <gl/freeglut.h>

static const size_t SCREEN_WIDTH = 800;
static const size_t SCREEN_HEIGHT = 600;

static void (*display_callback_internal)();

static void idle_callback() {
    glutPostRedisplay();
}

static void display_callback() {
    glClear(GL_COLOR_BUFFER_BIT);
    display_callback_internal();
    glutSwapBuffers();
}

static void ignore_resize(int, int) {
    glutReshapeWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
}

void init_gl(int argc, char* argv[], gl_config const& config) {
    glutInit(&argc, argv);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutInitWindowPosition(500, 200);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutCreateWindow("arkanoid");
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glutKeyboardFunc(config.key_pressed_callback);
    glutKeyboardUpFunc(config.key_up_callback);

    display_callback_internal = config.display;
    glutDisplayFunc(display_callback);
    glutIdleFunc(idle_callback);
    glutReshapeFunc(ignore_resize);

    glutMainLoop();
}

void draw_string(const char * text) {
    glColor3f(1., 1., 0.);
    glRasterPos2f(-1, 0.93);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<const unsigned char*>(text));
}

void background_fill(glm::vec3 const& color) {
    glColor3f(color.r, color.g, color.b);
    glRectf(-1, -1, 1, 1);
}
