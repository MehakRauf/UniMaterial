#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265f;
const int numArcSegments = 100; // Number of segments to approximate the arc

void drawArc(float centerX, float centerY, float radius, float startAngle, float sweep)
{
    glBegin(GL_LINE_STRIP);                  // Use GL_LINE_STRIP to draw the arc as a series of connected lines
    float angleInc = sweep / numArcSegments; // Increment per segment
    float angle = startAngle;

    for (int i = 0; i <= numArcSegments; ++i)
    {
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
        angle += angleInc; // Increment angle for next segment
    }

    glEnd();
}

void display()
{
    glClearColor(0.0314f, 0.0392f, 0.3216f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.9294f, 0.1294f, 0.5333f);

    // Draw an arc centered at (0, 0) with radius 5 from 0 to 90 degrees
    float startAngle = 0.0f;             // Start angle in radians
    float endAngle = PI / 2.0f;          // End angle in radians 
    float sweep = endAngle - startAngle; // Sweep angle in radians

    drawArc(0.0f, 0.0f, 5.0f, startAngle, sweep);

    glFlush();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0f, 10.0f, -10.0f, 10.0f, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Lab Activity (6): Arc using Line Strip");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
