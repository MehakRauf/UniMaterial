// #include <GL/glut.h>
// #include <cmath>

// const float PI = 3.14159265f;

// struct Point2 {
//     float x, y;
// };

// void Rosette(int N, float radius) {
//     if (N < 3) return; // Ensure there are enough points to form a rosette

//     // Create an array to hold the vertices
//     Point2* pt = new Point2[N];

//     // Calculate the vertices
//     double angleInc = 2 * PI / N;
//     for (int i = 0; i < N; i++) {
//         double angle = i * angleInc;
//         pt[i].x = radius * cos(angle);
//         pt[i].y = radius * sin(angle);
//     }

//     // Draw lines connecting each pair of vertices
//     glBegin(GL_LINES);
//     for (int i = 0; i < N - 1; i++) {
//         for (int j = i + 1; j < N; j++) {
//             glVertex2f(pt[i].x, pt[i].y);
//             glVertex2f(pt[j].x, pt[j].y);
//         }
//     }
//     glEnd();

//     // Clean up
//     delete[] pt;
// }

// void display() {
//     glClearColor(0.0314f, 0.0392f, 0.3216f, 1.0f);
//     glClear(GL_COLOR_BUFFER_BIT);

//     // Draw the first rosette with 16 points at position (-10, 0)
//     glColor3f(0.9294f, 0.1294f, 0.5333f); // Set color
//     glPushMatrix(); // Save current matrix
//     glTranslatef(-10.0f, 0.0f, 0.0f); // Move to position (-10, 0)
//     Rosette(16, 5.0f);
//     glPopMatrix(); // Restore previous matrix

//     // Draw the second rosette with 11 points at position (0, 0)
//     glColor3f(0.1f, 0.9f, 0.1f); // Set a different color
//     glPushMatrix(); // Save current matrix
//     // No translation needed, already at (0, 0)
//     Rosette(11, 5.0f);
//     glPopMatrix(); // Restore previous matrix

//     // Draw the third rosette with 5 points at position (10, 0)
//     glColor3f(0.1f, 0.1f, 0.9f); // Set a different color
//     glPushMatrix(); // Save current matrix
//     glTranslatef(10.0f, 0.0f, 0.0f); // Move to position (10, 0)
//     Rosette(5, 5.0f);
//     glPopMatrix(); // Restore previous matrix

//     glFlush();
// }

// void reshape(int width, int height) {
//     glViewport(0, 0, width, height);
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     glOrtho(-20.0, 20.0, -10.0, 10.0, -1.0, 1.0);
//     glMatrixMode(GL_MODELVIEW);
//     glLoadIdentity();
// }

// int main(int argc, char** argv) {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//     glutInitWindowSize(800, 600);
//     glutCreateWindow("Lab Activity (6): Circle using Polygon");

//     glutDisplayFunc(display);
//     glutReshapeFunc(reshape);

//     glutMainLoop();
//     return 0;
// }

#include <GL/glut.h>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "pixMap.h"

using namespace std;

int screenWidth = 800;
int screenHeight = 600;
int score = 0;
bool gameOver = false;
RGBApixmap bgImage;

class Player
{
public:
    float x, y;
    float size;

    Player()
    {
        x = screenWidth / 2;
        y = screenHeight / 2;
        size = 150.0f;
    }

    void render()
    {
        glColor3f(1.0f, 1.0f, 0.0f);

        glBegin(GL_TRIANGLES);
        glVertex2f(x - size / 8, y + size / 2);
        glVertex2f(x, y + size / 2 + size / 4);
        glVertex2f(x + size / 8, y + size / 2);
        glEnd();
    }

    void move(float dx, float dy)
    {
        x += dx;
        y += dy;
    }
};

class Ghost
{
public:
    float x, y;
    float size;
    float speedX, speedY;

    Ghost()
    {
        size = 20.0f;
        x = rand() % screenWidth;
        y = rand() % screenHeight;
        speedX = (rand() % 5 + 1) / 2.0f *3.0f;
        speedY = (rand() % 5 + 1) / 2.0f *3.0f;
    }

    void render()
    {
        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(x - size / 2, y);
        glVertex2f(x + size / 2, y);
        glVertex2f(x + size / 2, y - size / 2);
        glVertex2f(x - size / 2, y - size / 2);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex2f(x - size / 2, y - size / 2);
        glVertex2f(x - size / 4, y - size);
        glVertex2f(x - size / 4, y - size / 2);

        glVertex2f(x - size / 4, y - size / 2);
        glVertex2f(x + size / 4, y - size);
        glVertex2f(x, y - size / 2);

        glVertex2f(x, y - size / 2);
        glVertex2f(x + size / 4, y - size);
        glVertex2f(x + size / 2, y - size / 2);
        glEnd();
    }

    void move()
    {
        x += speedX;
        y += speedY;

        if (x < 0 || x > screenWidth)
            speedX *= -1;
        if (y < 0 || y > screenHeight)
            speedY *= -1;
    }
};

Player player;
Ghost ghost;

void handleSpecialKeypress(int key, int x, int y)
{
    float moveSpeed = 10.0f;
    switch (key)
    {
    case GLUT_KEY_UP:
        player.move(0, moveSpeed);
        break;
    case GLUT_KEY_DOWN:
        player.move(0, -moveSpeed);
        break;
    case GLUT_KEY_LEFT:
        player.move(-moveSpeed, 0);
        break;
    case GLUT_KEY_RIGHT:
        player.move(moveSpeed, 0);
        break;
    }
}

bool checkCollision(Player p, Ghost g)
{
    float distanceX = p.x - g.x;
    float distanceY = p.y - g.y;
    float distance = sqrt(distanceX * distanceX + distanceY * distanceY);

    float collisionDistance = (p.size / 2) + (g.size / 2);
    return distance < collisionDistance;
}

void drawBackground()
{
    bgImage.mDraw();
    glPixelZoom(2.7f, 2.5f);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawBackground();

    if (gameOver)
    {
        glRasterPos2f(screenWidth / 2 - 40, screenHeight / 2);
        PlaySound(TEXT("die.wav"), NULL, SND_FILENAME | SND_SYNC);
        const char *message = "Game Over!";
        for (const char *c = message; *c != '\0'; c++)
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
        }
        PlaySound(TEXT("ghost.wav"), NULL, SND_ASYNC | SND_LOOP);
        cout << "Your score: " << score << endl;
    }
    else
    {
        player.render();
        ghost.render();
    }

    glutSwapBuffers();
}

void update(int value)
{
    if (!gameOver)
    {
        ghost.move();
        if (checkCollision(player, ghost))
        {
            gameOver = true;
        }
        else
        {
            score++;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, update, 0);
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    bgImage.readBMPFile("bg.bmp", 1);
    glLoadIdentity();
    gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);
}

int main(int argc, char **argv)
{
    srand(static_cast<unsigned int>(time(0)));

    glutInit(&argc, argv);
    gluOrtho2D(0.0, screenWidth, screenHeight, 0.0);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow("Ghost Game");

    init();

    glutDisplayFunc(display);
    glutSpecialFunc(handleSpecialKeypress); 
    glutTimerFunc(1000 / 60, update, 0);
    PlaySound(TEXT("ghost.wav"), NULL, SND_ASYNC | SND_LOOP);

    glutMainLoop();
    return 0;
}
