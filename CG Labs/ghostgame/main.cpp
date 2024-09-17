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
