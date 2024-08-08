#include <iostream>
#include <GL/glut.h>

using namespace std;

// Function to draw a triangle
void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

// Recursive function to draw the Sierpinski Gasket
void sierpinski(float x1, float y1, float x2, float y2, float x3, float y3, int depth) {
    if (depth == 0) {
        drawTriangle(x1, y1, x2, y2, x3, y3);
    } else {
        float mx1 = (x1 + x2) / 2.0;
        float my1 = (y1 + y2) / 2.0;
        float mx2 = (x2 + x3) / 2.0;
        float my2 = (y2 + y3) / 2.0;
        float mx3 = (x3 + x1) / 2.0;
        float my3 = (y3 + y1) / 2.0;

        sierpinski(x1, y1, mx1, my1, mx3, my3, depth - 1);
        sierpinski(x2, y2, mx1, my1, mx2, my2, depth - 1);
        sierpinski(x3, y3, mx2, my2, mx3, my3, depth - 1);
    }
}

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);        // Clears framebuffer with background color
    glClearColor(0.9f, 0.9f, 0.9f, 0.0); // Set background color
    glColor3f(1, 0, 0);                  // Set foreground color

    // Define vertices of the initial large triangle
    float x1 = 10, y1 = 10;
    float x2 = 90, y2 = 10;
    float x3 = 50, y3 = 90;

    // Draw the Sierpinski Gasket with depth 5
    sierpinski(x1, y1, x2, y2, x3, y3, 5);

    glFlush(); // Sends buffer pixels to display screen
}

int screenWidth = 640, screenHeight = 480;

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(30, 30);
    glutCreateWindow("Sierpinski Gasket");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100); 

    glutDisplayFunc(myDisplay); 
    glutMainLoop(); 
    return 0;
}
