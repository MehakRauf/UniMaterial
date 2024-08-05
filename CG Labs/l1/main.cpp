#include <iostream>
#include <GL/glut.h>
#include <string>    

using namespace std;

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);        // Clears framebuffer with background color
    glClearColor(0.9f, 0.9f, 0.9f, 0.0); // Set background color
    glColor3f(1, 0, 0);                  // Set foreground color

    glFlush(); // Sends buffer pixels to display screen
}

int screenWidth = 640, screenHeight = 480;

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(30, 30);
    glutCreateWindow("HT First OGL Program");

    glutDisplayFunc(myDisplay); // Register display function as callback
    glutMainLoop(); // GUI loop that waits for events to occur
    return 0;
}
