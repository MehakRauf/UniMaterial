#include <iostream>
#include <GL/glut.h>
#include <windows.h>
#include <mmsystem.h>
#include <cstdlib> // For rand()

using namespace std;

int screenWidth = 640, screenHeight = 480;
float colorR = 1.0f, colorG = 0.0f, colorB = 0.0f; // Initial foreground color

float minX = -10, minY = -10, maxX = 10, maxY = 10;
int VP_bottom = 0, VP_left = 0, VPWidth = 640, VPHeight = 480;

void bitmap_output(int x, int y, string s, void *font)
{
    int len = s.length();
    glRasterPos2f(x, y);
    for (int i = 0; i < len; i++)
    {
        glutBitmapCharacter(font, s[i]);
    }
}

void drawAxis()
{
    glBegin(GL_LINES);
    glVertex2f(minX, 0);
    glVertex2f(maxX, 0);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0, minY);
    glVertex2f(0, maxY);
    glEnd();
}

void drawMountains()
{
    glBegin(GL_TRIANGLES);

    // First mountain
    glVertex2f(-10.0f, -10.0f); // Left base
    glVertex2f(-8.0f, 0.0f);    // Peak
    glVertex2f(-6.0f, -10.0f);  // Right base

    // Second mountain
    glVertex2f(-6.0f, -10.0f); // Left base
    glVertex2f(-4.0f, 2.0f);   // Peak
    glVertex2f(-2.0f, -10.0f); // Right base

    // Third mountain
    glVertex2f(-2.0f, -10.0f); // Left base
    glVertex2f(0.0f, 5.0f);    // Peak
    glVertex2f(2.0f, -10.0f);  // Right base

    // Fourth mountain
    glVertex2f(2.0f, -10.0f); // Left base
    glVertex2f(4.0f, 3.0f);   // Peak
    glVertex2f(6.0f, -10.0f); // Right base

    // Fifth mountain
    glVertex2f(6.0f, -10.0f);  // Left base
    glVertex2f(8.0f, 1.0f);    // Peak
    glVertex2f(10.0f, -10.0f); // Right base

    glEnd();
}

void PlayBackgroundSound()
{
    // Play the sound in a loop (SND_LOOP) without waiting for it to finish (SND_ASYNC)
    PlaySound(TEXT("background.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void PlayForegroundSound()
{
    // Play the sound once, wait until it finishes (SND_SYNC)
    PlaySound(TEXT("foreground.wav"), NULL, SND_FILENAME | SND_SYNC);
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen with background color
    glViewport(VP_bottom, VP_left, VPWidth, VPHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(minX, maxX, minY, maxY); // Set up orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drawAxis(); // Draw the axis

    glColor3f(1, 0, 0); // Set text color to red
    bitmap_output(-8, 5, "This is written in a GLUT bitmap font", GLUT_BITMAP_TIMES_ROMAN_24); // Adjusted position
    bitmap_output(-8, 4, "Helvetica is yet another bitmap font", GLUT_BITMAP_HELVETICA_18); // Adjusted position

    glFlush(); // Ensure all OpenGL commands are executed
}

void myMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        drawAxis(); // Draw the axis
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
        glFlush();
    }
    glutPostRedisplay();
}

void myInit()
{
    glClearColor(0.9f, 0.9f, 0.9f, 0.0); // Set background color
    glColor3f(1, 0, 0);                  // Set initial Foreground Color
    PlayBackgroundSound();               // Start playing background sound
}

void myReshape(int w, int h)
{
    screenWidth = w;
    screenHeight = h;
    glViewport(0, 0, w, h); // Set the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(minX, maxX, minY, maxY); // Adjust orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void myKeys(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'f':                                           // Change foreground color
        colorR = static_cast<float>(rand()) / RAND_MAX; // Random R
        colorG = static_cast<float>(rand()) / RAND_MAX; // Random G
        colorB = static_cast<float>(rand()) / RAND_MAX; // Random B
        glColor3f(colorR, colorG, colorB);              // Update color
        glutPostRedisplay();
        break;
    case 'm':                        // Draw mountains
        glColor3f(0.3f, 0.3f, 0.3f); // Set mountain color
        drawMountains();             // Draw mountains on top of the existing content
        glFlush();                   // Ensure drawing is completed
        break;
    case 'c':                         // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT); // Clear the screen buffer
        glutPostRedisplay();          // Request display update
        break;
    case 'p': // Play foreground sound
        PlayForegroundSound();
        break;
    case 'q': // Quit
        exit(0);
    }
}


void mouseMove(int x, int y)
{
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(30, 30);
    glutCreateWindow("Experiment with Images");
    myInit();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(myDisplay); // Register display function as callback
    glutKeyboardFunc(myKeys);
    glutMouseFunc(myMouse);
    glutMotionFunc(mouseMove);
    glutMainLoop(); // GUI loop that waits for events to occur
    return 0;
}
