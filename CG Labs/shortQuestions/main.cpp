#include <GL/glut.h>
#include <cmath>

float x = 0.0f, y = 0.0f; // turtle position
float angle = 0.0f;       // turtle angle

// degrees to radians
float toRadians(float degrees)
{
    return degrees * M_PI / 180.0f;
}

void forward(float distance)
{
    float newX = x + distance * cos(toRadians(angle));
    float newY = y + distance * sin(toRadians(angle));
    glVertex2f(x, y); // from current to new position
    glVertex2f(newX, newY);
    x = newX;
    y = newY;
}

void right(float degrees)
{
    angle -= degrees;
}

void left(float degrees)
{
    angle += degrees;
}

void setPosition(float newX, float newY)
{
    x = newX;
    y = newY;
}

void setAngle(float newAngle)
{
    angle = newAngle;
}

void polygonAlgo(int n, int l)
{
    for (int i = 0; i < n; i++)
    {
        forward(l);
        right(360 / n);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
    polygonAlgo(3, 50);
    glEnd();
    glFlush();
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Turtle Graphics Patterns");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
