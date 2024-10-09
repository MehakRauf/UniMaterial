#include <GL/glut.h>

void starMotif() {
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glVertex2f(3, 3);
    glVertex2f(0, 8);
    glVertex2f(-3, 0);
    glVertex2f(-2, -1);
    glVertex2f(0, 5);
    glVertex2f(2, 3);
    glVertex2f(3, 3);
    glEnd();
    glPopMatrix();
}

void drawStar() {
    for (int i = 0; i < 5; i++) {
        starMotif();
        glRotatef(72.0, 0.0, 0.0, 1.0);
    }
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glLoadIdentity();
    drawStar();
    glutSwapBuffers();
}

const int screenWidth = 640;
const int screenHeight = 480;
void myInit(void)
{
    glViewport(0, 0, screenWidth, screenHeight);
    glMatrixMode(GL_PROJECTION);
    glPointSize(1.0);
    glLoadIdentity();
    gluOrtho2D(-15, 15, -15, 15);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Drawing Star motif");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
    return 0;
}