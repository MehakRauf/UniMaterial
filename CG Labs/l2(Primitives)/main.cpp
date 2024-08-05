#include <iostream>
#include <fstream>
#include <GL/glut.h>

// Function to display various primitives
void DisplayPrimitives(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Background color black
    glColor3f(1.0f, 1.0f, 1.0f);          // Foreground color white

    // GL_POINTS
    GLint points[][2] = {
        {5, 5},
        {6, 8},
        {8, 7},
        {10, 3}};

    glPointSize(5.0f);
    glBegin(GL_POINTS);
    for (int i = 0; i < 4; ++i)
    {
        glVertex2iv(points[i]);
    }
    glEnd();

    // GL_LINES
    glBegin(GL_LINES);
    glVertex2i(20, 10);
    glVertex2i(30, 20);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(29, 17);
    glVertex2i(35, 10);
    glEnd();

    // GL_LINE_STRIP
    glBegin(GL_LINE_STRIP);
    glVertex2i(48, 11);
    glVertex2i(44, 15);
    glVertex2i(45, 10);
    glVertex2i(52, 22);
    glVertex2i(44, 18);
    glVertex2i(52, 13);
    glVertex2i(49, 7);
    glEnd();

    // GL_LINE_LOOP
    glBegin(GL_LINE_LOOP);
    glVertex2i(21, 30);
    glVertex2i(21, 35);
    glVertex2i(30, 42);
    glVertex2i(38, 35);
    glVertex2i(37, 30);
    glVertex2i(29, 23);
    glEnd();

    // GL_TRIANGLES
    glColor3f(0.6f, 0.4f, 0.2f);
    glBegin(GL_TRIANGLES);
    glVertex2f(3, 30);
    glVertex2f(5, 35);
    glVertex2f(8, 30);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(7, 27);
    glVertex2f(10, 30);
    glVertex2f(14, 22);
    glEnd();

    // GL_LINE_LOOP
    glBegin(GL_LINE_LOOP);
    glVertex2i(56, 27);
    glVertex2i(45, 35);
    glVertex2i(55, 42);
    glVertex2i(50, 40);
    glVertex2i(52, 34);
    glVertex2i(61, 37);
    glEnd();

    // GL_QUADS
    glBegin(GL_QUADS);
    glVertex2i(48, 59);
    glVertex2i(55, 59);
    glVertex2i(54, 57);
    glVertex2i(45, 55);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(50, 61); // Bottom vertex
    glVertex2i(48, 64); // Left vertex
    glVertex2i(50, 68); // Top vertex
    glVertex2i(52, 64); // Right vertex
    glEnd();

    glColor3f(0.5f, 0.5f, 0.5f); // Gray color

    // GL_TRIANGLE_STRIP
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2i(3, 70);
    glVertex2i(15, 70);
    glVertex2i(5, 65);
    glVertex2i(14, 65);
    glVertex2i(4, 60);
    glVertex2i(13, 58);
    glVertex2i(12, 53);
    glVertex2i(17, 57);
    glEnd();

    // Set the color for the outline (black)
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);

    glBegin(GL_LINE_LOOP);

    glVertex2i(3, 70);
    glVertex2i(15, 70);
    glVertex2i(5, 65);
    glVertex2i(3, 70);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2i(15, 70);
    glVertex2i(14, 65);
    glVertex2i(5, 65);
    glVertex2i(4, 60);
    glVertex2i(14, 65);
    glVertex2i(13, 58);
    glVertex2i(4, 60);
    glVertex2i(12, 53);
    glVertex2i(13, 58);
    glVertex2i(17, 57);
    glVertex2i(12, 53);

    glEnd();

    // GL_QUAD_STRIP 
    glColor3f(0.5f, 0.5f, 0.5f); // Gray color

    glBegin(GL_QUAD_STRIP);

    glVertex2i(25, 70); // Vertex 1
    glVertex2i(35, 70); // Vertex 2
    glVertex2i(26, 65); // Vertex 3
    glVertex2i(34, 67); // Vertex 4
    glVertex2i(25, 63); // Vertex 5
    glVertex2i(33, 63); // Vertex 6
    glVertex2i(28, 58); // Vertex 7
    glVertex2i(34, 60); // Vertex 8

    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glLineWidth(2.0f);           // Set line width for the outline

    // Begin drawing the outline
    glBegin(GL_LINE_LOOP);
    glVertex2i(34, 67);
    glVertex2i(33, 63);
    glVertex2i(25, 63);
    glVertex2i(26, 65);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2i(33, 63);
    glVertex2i(34, 60);
    glVertex2i(28, 58);
    glVertex2i(25, 63);
    glEnd();

    // GL_TRIANGLE_FAN
    glColor3f(1.0f, 0.5f, 0.0f); // Orange color

    glBegin(GL_TRIANGLE_FAN);

    glVertex2i(51, 77); // Center of the fan

    glVertex2i(52, 81); // Vertex 1
    glVertex2i(56, 79); // Vertex 2
    glVertex2i(57, 77); // Vertex 3
    glVertex2i(58, 75); // Vertex 4
    glVertex2i(56, 72); // Vertex 5

    // Close the fan by repeating the first vertex
    glVertex2i(52, 81); // Vertex 1 again
    glEnd();

    // Set the color for the outline (black)
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);

    glBegin(GL_LINE_LOOP);

    glVertex2i(51, 77);
    glVertex2i(52, 81);
    glVertex2i(51, 77);
    glVertex2i(56, 79);
    glVertex2i(51, 77);
    glVertex2i(57, 77);
    glVertex2i(51, 77);
    glVertex2i(58, 75);
    glVertex2i(51, 77);
    glVertex2i(56, 72);
    glVertex2i(51, 77);
    glEnd();

    glFlush();
}
 
int screenWidth = 640, screenHeight = 480;

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(30, 30);
    glutCreateWindow("Primitives");

    gluOrtho2D(0, 70, 0, 90);           // Set the coordinate system
    glutDisplayFunc(DisplayPrimitives); // Register display function
    glutMainLoop();                     // Main loop that waits for events

    return 0;
}
