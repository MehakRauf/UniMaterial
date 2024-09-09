#include <GL/glut.h>
#include <cmath>

const float PI = 3.142;

void ngon(int n, double cx, double cy, double radius, double rotAngle)
{
    // to draw a polygon we need atleast 3 points
    if (n < 3)
    {
        return;
    }

    // increment angle
    double angleInc = 2 * PI / n;
    // starting angle according to the rotating angle
    double angle = rotAngle * (PI / 180);

    glBegin(GL_POLYGON);

    for (int k = 0; k < n; k++)
    {
        // x and y coordinates calculation
        double x = radius * cos(angle) + cx;
        double y = radius * sin(angle) + cy;
        glVertex2f(x, y);
        // increment it for the next polygon
        angle += angleInc;
    }

    glEnd();
}
void displayTriangles()
{
    glClearColor(0.0314, 0.0392, 0.3216, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 0.0);

    // Draw the circle
    ngon(60, 0.0, 0.0, 2.0, 0.0);

    // Draw triangles
    // number of triangles to be drawn
    int numTriangles = 15;
    // angle increment calculation for space between the triangles
    double angleInc = 2 * PI / numTriangles;
    // initiliaze angle
    double angle = 0.0;
    // height of triangle (distance from the sun)
    double triangleHeight = 3.0;
    // base of eachtriangle
    double triangleBase = 0.3; // Half of the base width of each triangle

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < numTriangles; i++)
    {
        // Calculate the base center on the circle's edge (part that touch the triangle)
        // radius of circle is 2
        double xBaseCenter = 2.0 * cos(angle); // cos for x
        double yBaseCenter = 2.0 * sin(angle); // sin for y

        // Calculate the vertices of the triangle
        double x1 = xBaseCenter + triangleBase * cos(angle + PI / 2); // vertex 1
        double y1 = yBaseCenter + triangleBase * sin(angle + PI / 2);

        double x2 = xBaseCenter - triangleBase * cos(angle + PI / 2); // vertex 2
        double y2 = yBaseCenter - triangleBase * sin(angle + PI / 2);

        double xTip = (2.0 + triangleHeight) * cos(angle);
        double yTip = (2.0 + triangleHeight) * sin(angle);

        // Defining the vertices
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        // corner of the triangle
        glVertex2f(xTip, yTip);

        // increment the angle for next triangle
        angle += angleInc;
    }
    glEnd();

    glFlush();
}

void displayLines()
{
    glClearColor(0.0314, 0.0392, 0.3216, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 0.0);

    // Draw the circle
    ngon(60, 0.0, 0.0, 2.0, 0.0);

    // Draw rays as lines
    // number of rays
    int numRays = 20;
    // length of ray
    double rayLength = 2.0;
    // angle calculation for space between the lines
    double angleInc = 2 * PI / numRays;
    // initiliaze it
    double angle = 0.0;

    // to begin drawing lines (rays)
    glBegin(GL_LINES);
    // iterate until all rays are drawn
    for (int i = 0; i < numRays; i++)
    {
        // starting point of the ray (x,y)
        // cos for y
        double xStart = 2.0 * cos(angle); // circumference of the circle
        // sin for x
        double yStart = 2.0 * sin(angle);

        // ending point of the ray(x,y)
        double xEnd = (2.0 + rayLength) * cos(angle); // sum the length of the ray
        double yEnd = (2.0 + rayLength) * sin(angle);
        // assigning the vertices
        glVertex2f(xStart, yStart);
        glVertex2f(xEnd, yEnd);

        // updating the angle for next ray
        angle += angleInc;
    }
    glEnd();
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
    glutCreateWindow("Lab Activity (6): Sun using Polygon and Lines");

    glutDisplayFunc(displayLines);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
