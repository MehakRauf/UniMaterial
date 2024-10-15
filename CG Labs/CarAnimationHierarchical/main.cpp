#include <GL/glut.h>
#include <cmath>

int width = 640, height = 480;
float frameNumber = 0;
bool animationRunning = false;

const float PI = 3.14159;
const int numVertices = 100;

// Function to draw a filled circle (used for tyres)
void drawCircle(float radius, float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < numVertices; ++i)
    {
        float angle = 2.0f * PI * i / numVertices;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

// Function to draw the tyre with white circles inside
void drawTyre(float radius)
{
    drawCircle(radius, 0, 0, 0); // Black tyre

    // Four white circles inside the tyre
    float innerRadius = radius * 0.3;
    float offset = radius * 0.6;

    // Left, right, top, bottom circles
    glPushMatrix();
    glTranslatef(-offset, 0, 0);
    drawCircle(innerRadius, 1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(offset, 0, 0);
    drawCircle(innerRadius, 1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -offset, 0);
    drawCircle(innerRadius, 1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, offset, 0);
    drawCircle(innerRadius, 1, 1, 1);
    glPopMatrix();
}

// Function to draw an arc (used for the rounded sides of the car)
void drawArc(float radius, float startAngle, float sweepAngle)
{
    int numSegments = 50;
    float angleIncrement = sweepAngle * PI / (180.0f * numSegments);

    glBegin(GL_POLYGON);
    for (int i = 0; i <= numSegments; ++i)
    {
        float angle = (startAngle + i * (sweepAngle / numSegments)) * PI / 180.0f;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

// Function to draw the car body (rectangle with arcs on the sides)
void drawBody()
{
    glColor3f(1, 0, 0); // Red color for the body

    // Middle rectangle of the car
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);    // Bottom-left
    glVertex2f(120, 0);  // Bottom-right
    glVertex2f(120, 60); // Top-right
    glVertex2f(0, 60);   // Top-left
    glEnd();

    // Left arc (front of the car)
    glPushMatrix();
    glTranslatef(0, 30, 0); // Position the arc
    drawArc(30, 90, 180);   // Draw a half-circle arc
    glPopMatrix();

    // Right arc (back of the car)
    glPushMatrix();
    glTranslatef(120, 30, 0); // Position the arc
    drawArc(30, 270, 180);    // Draw a half-circle arc
    glPopMatrix();
}

// Function to draw the car roof
void drawRoof()
{
    glColor3f(0, 0, 0); // Black color for the roof

    glBegin(GL_POLYGON);
    glVertex2f(10, 60);  // Bottom-left of roof
    glVertex2f(110, 60); // Bottom-right of roof
    glVertex2f(90, 90);  // Top-right
    glVertex2f(30, 90);  // Top-left
    glEnd();
}

// Function to draw the door handles
void drawHandles()
{
    glColor3f(0.5, 0.5, 0.5); // Grey handles

    // Left door handle
    glBegin(GL_POLYGON);
    glVertex2f(25, 35); // Top-left
    glVertex2f(35, 35); // Top-right
    glVertex2f(35, 30); // Bottom-right
    glVertex2f(25, 30); // Bottom-left
    glEnd();

    // Right door handle
    glBegin(GL_POLYGON);
    glVertex2f(75, 35); // Top-left
    glVertex2f(85, 35); // Top-right
    glVertex2f(85, 30); // Bottom-right
    glVertex2f(75, 30); // Bottom-left
    glEnd();
}

// Function to draw the car
void drawCar()
{
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glPushMatrix();
    // Draw the car body
    drawBody();

    // Draw the car roof
    drawRoof();
    glTranslatef(1, 1, 0);
    glPushMatrix();
    // Draw door handles
    drawHandles();
    // // Draw the left tyre
    glTranslatef(-1.5, -1, 0);
    glPushMatrix();

    drawTyre(20);
    glPopMatrix();

    // Draw the right tyre
    glTranslatef(110, 0, 0);
    glPushMatrix();
    drawTyre(20);
    glPopMatrix();

    glPopMatrix(); // Restore the transformation stack
    glPopMatrix();
    glPopMatrix();
}

// Function to draw the road
void drawRoad()
{
    glColor3f(0.3, 0.3, 0.3); // Grey road
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(width, 0);
    glVertex2f(width, 60);
    glVertex2f(0, 60);
    glEnd();

    // White dashed line
    glColor3f(1, 1, 1);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(0, 30);
    glVertex2f(width, 30);
    glEnd();
}

// Function to draw the sky
void drawSky()
{
    glColor3f(0.6, 0.8, 1.0); // Light blue sky
    glBegin(GL_QUADS);
    glVertex2f(0, 60);
    glVertex2f(width, 60);
    glVertex2f(width, height);
    glVertex2f(0, height);
    glEnd();
}

// Timer function for animation
void timer(int)
{
    frameNumber += 1;
    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}

// Menu handling function
void menu(int option)
{
    switch (option)
    {
    case 1: // Start animation
        if (!animationRunning)
        {
            glutTimerFunc(0, timer, 0);
            animationRunning = true;
        }
        break;
    case 2: // Restart animation
        frameNumber = 0;
        break;
    case 3: // Exit the program
        exit(0);
        break;
    }
    glutPostRedisplay();
}

// Display function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawSky();
    drawRoad();

    // Animate the car along the road
    glPushMatrix();
    glTranslatef(-(640 - frameNumber * 6), 70, 0); // Move the car
    drawCar();
    glPopMatrix();

    glFlush();
}

// Initialization function
void init()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
}

// Main function
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("2D Hierarchical Car Model");

    init();

    // Create the menu
    glutCreateMenu(menu);
    glutAddMenuEntry("Start", 1);
    glutAddMenuEntry("Restart", 2);
    glutAddMenuEntry("Exit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON); // Right-click for menu

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
