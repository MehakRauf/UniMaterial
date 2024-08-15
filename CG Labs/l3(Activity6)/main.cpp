#include <GL/glut.h>
#include <cmath>

const float PI = 3.142; 

void ngon(int n, double cx, double cy, double radius, double rotAngle)
{
    if (n < 3)
    {
        return;
    }

    double angleInc = 2 * PI / n;         // Angle increment
    double angle = rotAngle * (PI / 180); // Starting angle in radians

    glBegin(GL_POLYGON); // Begin drawing the polygon

    for (int k = 0; k < n; k++)
    {
        double x = radius * cos(angle) + cx; // Calculate x coordinate
        double y = radius * sin(angle) + cy; // Calculate y coordinate
        glVertex2f(x, y);                 
        angle += angleInc;                   // Increment angle for the next vertex
    }

    glEnd(); 
}

void display()
{
    glClearColor(0.0314, 0.0392, 0.3216, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.9294, 0.1294, 0.5333);

    // Draw a circle using the ngon function with 60 sides
    ngon(60, 0.0, 0.0, 5.0, 0.0); 

    glFlush();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Lab Activity (6): Circle using Polygon");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
