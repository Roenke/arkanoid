#include "init_gl.h"

void (*display_callback_internal)();

static void idle_callback() {
    glutPostRedisplay();
}

static void display_callback() {
    glClear(GL_COLOR_BUFFER_BIT);
    display_callback_internal();
    glutSwapBuffers();
}

void init_gl(int argc, char* argv[], gl_config const& config) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(500, 200);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutCreateWindow("arkanoid");
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glutKeyboardFunc(config.key_pressed_callback);
    glutKeyboardUpFunc(config.key_up_callback);

    display_callback_internal = config.display;
    glutDisplayFunc(display_callback);
    glutIdleFunc(idle_callback);

    glutMainLoop();
}