#include <iostream>
#include <fstream>
#include <GL/glut.h>

// Function to display the Big Dipper
void DisplayBigDipper(void)
{
    GLint stars[][2] = {
        {5, 5},
        {10, 15},
        {15, 17},
        {20, 20},
        {25, 15},
        {35, 25},
        {36, 35}};

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Background color black
    glColor3f(1.0f, 1.0f, 1.0f);          // Foreground color white

    // Draw stars
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    for (int i = 0; i < 7; ++i)
    {
        glVertex2iv(stars[i]);
    }
    glEnd();

    // Draw lines connecting the stars
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 7; ++i)
    {
        glVertex2iv(stars[i]);
    }
    glEnd();

    glFlush();
}

// Function to display the wired house
void DisplayWiredHouse(void)
{
    glClear(GL_COLOR_BUFFER_BIT);         // Clears fb with bg color
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Background color black
    glColor3f(1.0f, 1.0f, 1.0f);          // Foreground color white

    // Main body of the house
    glBegin(GL_POLYGON);
    glVertex2f(10, 10);
    glVertex2f(10, 40);
    glVertex2f(15, 46);
    glVertex2f(14, 60);
    glVertex2f(20, 60);
    glVertex2f(20, 54);
    glVertex2f(25, 60);
    glVertex2f(40, 40);
    glVertex2f(40, 10);
    glVertex2f(10, 10);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.2f, 0.2f);
    glVertex2f(15, 10);
    glVertex2f(15, 25);
    glVertex2f(20, 25);
    glVertex2f(20, 10);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.2f, 0.2f);
    glVertex2f(30, 30);
    glVertex2f(30, 35);
    glVertex2f(35, 35);
    glVertex2f(35, 30);
    glVertex2f(30, 30);
    glEnd();

    glFlush(); // Sends buffer pixels to display screen
}

int screenWidth = 640, screenHeight = 480;

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(30, 30);
    glutCreateWindow("Practice Questions");

    gluOrtho2D(0, 70, 0, 90);           // Set the coordinate system
    glutDisplayFunc(DisplayWiredHouse); // Register display function
    glutMainLoop();                     // Main loop that waits for events

    return 0;
}
