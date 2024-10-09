#include <GL/glut.h>
#include <cmath>

float turtle_x = -200.0f;
float turtle_y = 200.0f;
float turtle_angle = 0.0f;

// degrees to radians
float toRadians(float degrees)
{
    return degrees * M_PI / 180.0f;
}

void forward(float length)
{
    float angle_radians = toRadians(turtle_angle);
    float new_x = turtle_x + length * cos(angle_radians);
    float new_y = turtle_y + length * sin(angle_radians);

    glBegin(GL_LINES);
    glVertex2f(turtle_x, turtle_y);
    glVertex2f(new_x, new_y);
    glEnd();

    turtle_x = new_x;
    turtle_y = new_y;
}

void right(float angle)
{
    turtle_angle -= angle;
}

void left(float angle)
{
    turtle_angle += angle;
}

void drawSquare(float size)
{
    glBegin(GL_POLYGON);
    glVertex2f(turtle_x, turtle_y);
    glVertex2f(turtle_x + size, turtle_y);
    glVertex2f(turtle_x + size, turtle_y - size);
    glVertex2f(turtle_x, turtle_y - size);
    glEnd();

    turtle_x += size;
}

void drawChessboard()
{
    float squareSize = 50.0f;

    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if ((row + col) % 2 == 0)
            {
                glColor3f(1.0f, 1.0f, 1.0f); // White square
            }
            else
            {
                glColor3f(0.0f, 0.0f, 0.0f); // Black square
            }

            drawSquare(squareSize);
        }
        turtle_y -= squareSize; // move down
        turtle_x = -200.0f;     // x position to the left side for the new row
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    turtle_x = -200.0f;
    turtle_y = 200.0f;
    turtle_angle = 0.0f;

    drawChessboard();
    glFlush();
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200.0, 200.0, -200.0, 200.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Filled Chessboard with Turtle Graphics");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
