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

// Star Tilted
void drawStarTilted()
{
    setPosition(-40.0f, 60.0f);

    for (int i = 0; i < 37; i++)
    {
        right(-160);
        forward(25);
        left(-170);
        forward(35);
    }
}

// Spiral Shape
void drawSpiral()
{
    setPosition(-40.0f, 0.0f);
    setAngle(0.0f);
    float length = 30.0f;
    float rotation = 25;

    for (int i = 0; i < 10; i++)
    {
        forward(length);
        right(90);
        forward(length);
        right(45);
        right(rotation);
    }
    setPosition(-26.0f, -18.0f);
    for (int i = 0; i < 20; i++)
    {
        forward(20);
        left(35);
        setPosition(-28.0f, -18.0f);
    }
}

// Star Pattern
void drawStar()
{
    setPosition(0.0f, 0.0f);

    for (int i = 0; i < 5; i++)
    {
        forward(50);
        right(144);
    }
}

void drawPattern()
{
    setPosition(0.0f, 0.0f);
    setAngle(0.0f);
    x = 0.0f, y = 0.0f;
    for (int i = 0; i < 9; i++)
    {
        forward(50);
        left(-120);
        forward(15);
        left(-70);
        forward(35);
        right(30);
        forward(13);
        setPosition(x, y);
        right(60);
    }
}

// House Pattern
void drawHouse()
{
    setPosition(0.0f, -50.0f);
    setAngle(0.0f);

    // base
    for (int i = 0; i < 4; i++)
    {
        forward(50);
        right(90);
    }
    // roof
    left(45);
    forward(35);
    right(90);
    forward(35);

    // door
    setPosition(12.5f, -70.0f);
    setAngle(0.0f);

    for (int i = 0; i < 2; i++)
    {
        forward(25);
        right(90);
        forward(30);
        right(90);
    }
}

// zigzag pattern
void drawZigzag()
{
    setPosition(-20.0f, 30.0f);
    right(90);
    forward(60);
    forward(-60);
    right(-25);
    forward(60);

    for (int i = 0; i < 8; i++)
    {
        left(-90);
        forward(5);
        right(90);
        forward(30);
        right(90);
        forward(20);
        right(-90);
        forward(30);
        right(-90);
        forward(5);
        left(90);
        forward(60);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);

    // drawZigzag();
    drawStarTilted();
    // drawSpiral();
    // drawStar();
    // drawHouse();
    // drawPattern();
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

// Main function
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Turtle Graphics Patterns");
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
