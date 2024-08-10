#include <iostream>
#include <GL/glut.h>

using namespace std;

int screenWidth = 640, screenHeight = 480;

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // background color
    glFlush();
}

void drawDot(int xx, int yy)
{
    glColor3f(0.6f, 0.4f, 0.2f);
    glBegin(GL_POINTS);
    glVertex2i(xx, yy);
    glEnd();
    glFlush();
}

void myMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        drawDot(mx, screenHeight - my); // Adjust y-coordinate and draw dot
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }
    glutPostRedisplay();
} // end mouse Click Event Handler

void myInit()
{
    glClearColor(0.9f, 0.9f, 0.9f, 0.0); // set background color
    glColor3f(1, 0, 0);                  // set Foreground Color
}

void myReshape(int w, int h)
{
    screenWidth = w;
    screenHeight = h;
    glViewport(0, 0, w, h); // Set the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void myKeys(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'q':
        exit(0);
    case 's':
        break;
    }
    glutPostRedisplay();
}

void mouseMove(int x, int y)
{
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(30, 30);
    glutCreateWindow("Experimment with images");
    myInit();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(myDisplay); // Register display function as callback
    glutKeyboardFunc(myKeys);
    glutMouseFunc(myMouse);
    glutMotionFunc(mouseMove);
    glutMainLoop(); // GUI loop that waits for events to occur
    return 0;
}
