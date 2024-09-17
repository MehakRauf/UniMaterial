#include <gl/glut.h>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include "pixMap.h"

using namespace std;

int screenWidth = 640;
int screenHeight = 480;
int score;
RGBApixmap bgImage;

class Point2
{
public:
	Point2()
	{
		x = y = 0.0f;
	}
	Point2(float xx, float yy)
	{
		x = xx;
		y = yy;
	}
	void set(float xx, float yy)
	{
		x = xx;
		y = yy;
	}
	float getX() { return x; }
	float getY() { return y; }
	void draw(void)
	{
		glPointSize(2.0);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
		glEnable(GL_POINT_SMOOTH);

		glBegin(GL_POINTS);
		glVertex2f((GLfloat)x, (GLfloat)y);
		glEnd();

		glDisable(GL_POINT_SMOOTH);
	}

private:
	float x, y;
};

class Spider
{
private:
	enum State
	{
		ALIVE,
		DEAD
	} state;
	RGBApixmap pix[2];

public:
	float pos_X, pos_Y;
	bool isMoving;
	float spiderSpeed;
	float moveSpeed = 2.0f;
	float moveDirectionX = 1.0f;
	float moveDirectionY = 0.5f;

	Spider() {}

	Spider(Point2 pos)
	{
		isMoving = true;
		spiderSpeed = 400.0f;
		this->pos_X = pos.getX();
		this->pos_Y = pos.getY();

		string fname[2] = {"C:\\Users\\Excalibur\\testing\\spider\\images\\spider.bmp", "C:\\Users\\Excalibur\\testing\\spider\\images\\mak3.bmp"}; // Replace with actual image filenames
		for (int i = 0; i < 2; i++)
		{
			pix[i].readBMPFile(fname[i], 1);
			pix[i].setChromaKey(255, 255, 255);
		}
	}
	void setState(int i)
	{
		if (i == 1)
			this->state = DEAD;
		else
		{
			this->state = ALIVE;
		}
	}

	int getState()
	{
		if (this->state == DEAD)
		{
			return 1;
		}
		return 0;
	}

	void changePosition(float dx, float dy)
	{
		this->pos_X += dx;
		this->pos_Y += dy;
	}

	void die();
	void render();
	void updatePosition();
};
Spider spider(Point2(300, 220));

void Spider::die()
{
	score += 1;
	this->isMoving = false;
	this->state = DEAD;
	PlaySound(TEXT("die.wav"), NULL, SND_FILENAME | SND_SYNC);
	cout << score << endl;
	PlaySound(TEXT("C:\\Users\\Excalibur\\testing\\spider\\shoot - folder\\shoot.wav"), NULL, SND_ASYNC | SND_LOOP);
}

void timer(int value)
{
	spider.updatePosition();
	glutPostRedisplay();
	glutTimerFunc(6, timer, 0);
}

void Spider::updatePosition()
{
	if (this->isMoving)
	{
		pos_X += moveDirectionX * moveSpeed;

		if (pos_X <= 0 || pos_X >= screenWidth)
		{
			moveDirectionX *= -1;
		}
	}
}
void Spider::render()
{
	glRasterPos2f(this->pos_X, this->pos_Y);

	if (this->isMoving)
	{
		pix[0].mDraw();
	}
	else
	{
		pix[1].mDraw();
	}
}

bool isBulletFired = false;
bool isBulletMoving = false;
float bulletX = screenWidth / 2;
float bulletY = 40.0f;
float bulletSpeed = 5.0f;

class Bullet
{
public:
	float x, y;
	Bullet(float initialX, float initialY) : x(initialX), y(initialY) {};

	void render()
	{
		glPushMatrix();
		glTranslatef(x, y, 0.0);

		glColor3f(1, 1, 1);
		glBegin(GL_TRIANGLES);
		glVertex2f(0, 0);
		glVertex2f(-3, -5);
		glVertex2f(3, -5);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(3, -5);
		glVertex2f(-3, -5);
		glVertex2f(-3, -15);
		glVertex2f(3, -15);
		glEnd();
		glPopMatrix();
	};

	void setPosition(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	void changePosition(float dx, float dy)
	{
		x += dx;
		y += dy;
	};
};

Bullet bullet(bulletX, bulletY);

void updateBullet()
{
	if (isBulletMoving)
	{
		bulletY += bulletSpeed;

		if (bulletY >= screenHeight)
		{
			isBulletMoving = false;
		}
	}
}

void bullet_movement(int y)
{
	const float SPIDER_WIDTH = 100;
	const float SPIDER_HEIGHT = 100;
	bullet.changePosition(0, 10);
	glutPostRedisplay();
	if ((bullet.x >= spider.pos_X && bullet.x <= spider.pos_X + SPIDER_WIDTH) &&
		(bullet.y >= spider.pos_Y && bullet.y <= spider.pos_Y + SPIDER_HEIGHT))
	{
		bullet.setPosition(bulletX, 20);
		spider.die();
		glutPostRedisplay();
		isBulletMoving = false;
	}
	if (bullet.y < 480 && isBulletMoving)
	{
		glutTimerFunc(5, bullet_movement, y);
	}
	else if (bullet.y >= 480)
	{
		bullet.setPosition(bulletX, 20);
		glutPostRedisplay();
	}
}

void pressKeySpecial(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		if (isBulletMoving)
		{
		}
		else
		{
			isBulletMoving = true;
			if (spider.getState() == 1)
			{
				spider.setState(0);
				spider.isMoving = true;
				spider.render();
			}
			isBulletMoving = true;
			isBulletFired = true;
			bullet_movement(0);
		}
		break;
	}
}

void drawBackground()
{
	float x_scale = 2.3f;
	float y_scale = 2.7f;

	glPixelZoom(x_scale, y_scale);
	glRasterPos2i(0, 0);
	bgImage.mDraw();
	glPixelZoom(1.0f, 1.0f);
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	updateBullet();
	drawBackground();

	spider.render();
	bullet.render();
	glFlush();
}

void myInit(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glViewport(0, 0, screenWidth, screenHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, screenWidth, 0, screenHeight);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	bgImage.readBMPFile("C:\\Users\\Excalibur\\testing\\spider\\bg .bmp", 1);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_EQUAL, 1.0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Spider Game");

	glutDisplayFunc(myDisplay);
	glutSpecialFunc(pressKeySpecial);

	PlaySound(TEXT("C:\\Users\\Excalibur\\testing\\spider\\shoot - folder\\shoot.wav"), NULL, SND_ASYNC | SND_LOOP);
	myInit();
	glutIdleFunc(myDisplay);
	glutTimerFunc(0, timer, 0); 
	glutMainLoop();
}