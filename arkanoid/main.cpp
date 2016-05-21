#include <gl/freeglut.h>
int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(500, 200);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutCreateWindow("arkanoid");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutMainLoop();
}