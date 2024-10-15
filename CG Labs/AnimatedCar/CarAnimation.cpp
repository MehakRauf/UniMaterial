#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <cmath>

int width = 640, height = 480;
int frameNumber = 0; // For animation, increases by 1 in each frame.
bool animationRunning = false;

const float PI = 3.14;
const int numVertices = 100;

// Draw a circle (used for car tyres)
void drawCircle(float centerX, float centerY, float radius, float red = 0, float green = 0, float blue = 0)
{
    glBegin(GL_POLYGON);
    glColor3f(red, green, blue);
    for (int i = 0; i < numVertices; ++i)
    {
        float angle = 2.0 * PI * static_cast<float>(i) / numVertices;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

// Draw four white circles inside the tyre
void drawTyre(float centerX, float centerY, float radius)
{
    // Draw the black tyre
    drawCircle(centerX, centerY, radius, 0, 0, 0);

    // Draw the four white circles inside
    float innerRadius = radius * 0.2;
    float offset = radius * 0.5;
    drawCircle(centerX - offset, centerY, innerRadius, 1, 1, 1);
    drawCircle(centerX + offset, centerY, innerRadius, 1, 1, 1);
    drawCircle(centerX, centerY - offset, innerRadius, 1, 1, 1);
    drawCircle(centerX, centerY + offset, innerRadius, 1, 1, 1);
}

void drawArc(float centerX, float centerY, float radius, float startAngle, float sweep)
{
    const int n = 30;                      // Number of segments in the arc
    float angle = startAngle * PI / 180.0; // Convert to radians
    float angleInc = sweep * PI / (180.0 * n);

    glBegin(GL_POLYGON); // Changed to POLYGON to fill the arcs
    for (int i = 0; i <= n; ++i)
    {
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
        angle += angleInc;
    }
    glEnd();
}

// Draw the car body
void drawBody()
{
    glColor3f(1, 0, 0);

    // Middle rectangle for the car body
    glBegin(GL_POLYGON);
    glVertex2f(228, 130);
    glVertex2f(320, 130);
    glVertex2f(320, 212);
    glVertex2f(228, 212);
    glEnd();

    // Left arc
    drawArc(205, 170, 40.0, 90.0, 180.0);

    // Right arc
    drawArc(343, 170, 40.0, 270.0, 180.0);

    glBegin(GL_POLYGON);
    glVertex2f(200, 130);
    glVertex2f(228, 130);
    glVertex2f(228, 212);
    glVertex2f(200, 212);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(320, 130);
    glVertex2f(348, 130);
    glVertex2f(348, 212);
    glVertex2f(320, 212);
    glEnd();
}

// Draw the car roof
void drawRoof()
{
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(210, 212);
    glVertex2f(338, 212);
    glVertex2f(318, 250);
    glVertex2f(230, 250);
    glEnd();
}

// Draw the car door handles
void drawHandles()
{
    glColor3f(0.5, 0.5, 0.5);

    // Left door handle
    glBegin(GL_POLYGON);
    glVertex2f(245, 170);
    glVertex2f(255, 170);
    glVertex2f(255, 160);
    glVertex2f(245, 160);
    glEnd();

    // Right door handle
    glBegin(GL_POLYGON);
    glVertex2f(295, 170);
    glVertex2f(305, 170);
    glVertex2f(305, 160);
    glVertex2f(295, 160);
    glEnd();
}

// Draw the road
void drawRoad()
{
    glColor3f(0.5, 0.5, 0.5); // Grey road
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(width, 0);
    glVertex2f(width, 150);
    glVertex2f(0, 150);
    glEnd();

    glLineWidth(10);
    glColor3f(1, 1, 1); // Stripes on the road
    glBegin(GL_LINES);
    glVertex2f(0, 55);
    glVertex2f(width, 55);
    glEnd();
}

// Draw the sky
void drawSky()
{
    glColor3f(0.6, 0.8, 1.0); // Light blue color for the sky
    glBegin(GL_QUADS);
    glVertex2f(0, 120);
    glVertex2f(width, 120);
    glVertex2f(width, height);
    glVertex2f(0, height);
    glEnd();
}

// Draw the car
void drawCar()
{
    // Draw car body
    glPushMatrix();
    drawBody();
    glPopMatrix();

    // Draw car roof
    glTranslatef(0, 0, 0);
    glPushMatrix();
    drawRoof();
    glPopMatrix();

    // Draw car handles
    glTranslatef(1, 1, 0);
    glPushMatrix();
    drawHandles();
    glPopMatrix();

    // Draw left tyre with white circles
    glTranslatef(-0.5, 0, 0);
    glPushMatrix();
    drawTyre(200.0, 130.0, 30.0);
    glPopMatrix();

    // Draw right tyre with white circles
    glTranslatef(5, 0, 0);
    glPushMatrix();
    drawTyre(350.0, 130.0, 30.0);
    glPopMatrix();
}

// Timer function for animation
void timer(int)
{
    frameNumber += 1;
    glutPostRedisplay();
    glutTimerFunc(30, timer, 1);
}

// Display function
void display()
{
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    drawRoad();
    drawSky();

    // Move and draw the car
    glPushMatrix();
    glTranslatef(-(640 - frameNumber * 6), 15, 0); // Animate the car
    drawCar();
    glPopMatrix();

    glFlush();
}

// Initialization
void myInit(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glViewport(0, 0, width, height);
}

// Menu handling
void menu(int options)
{
    switch (options)
    {
    case 1: // Start
        if (!animationRunning)
        {
            glutTimerFunc(0, timer, 1);
            animationRunning = true;
        }
        break;
    case 2: // Restart
        frameNumber = 0;
        break;
    case 3: // Exit
        exit(0);
        break;
    }
    glutPostRedisplay();
}

// Main function
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Car with Rounded Sides");
    myInit();

    glutCreateMenu(menu);
    glutAddMenuEntry("Start", 1);
    glutAddMenuEntry("Restart", 2);
    glutAddMenuEntry("Exit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glShadeModel(GL_FLAT);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

