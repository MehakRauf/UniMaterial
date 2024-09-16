#pragma once
#include <iostream>
#include<GL/glut.h>
#include "pixMap.h"

class Point2
{
public:
	Point2() { x = y = 0.0f; } // constructor 1
	Point2(float xx, float yy) { x = xx; y = yy; } // constructor 2
	void set(float xx, float yy) { x = xx; y = yy; }
	float getX() { return x; }
	float getY() { return y; }
	void draw(void)
	{
		glPointSize(2.0);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
		glEnable(GL_POINT_SMOOTH);

		glBegin(GL_POINTS); // draw this point
		glVertex2f((GLfloat)x, (GLfloat)y);
		glEnd();

		glDisable(GL_POINT_SMOOTH);

	}// end draw
private:
	float x, y;
}; // end class Point2
class Mario
{
public:

	RGBApixmap pix[5]; // make six empty pixmaps, one for each side of cube (DIFFERENT STATES OF MARIO)
	enum State { STANDING, RUNNING1, RUNNING2, RUNNING3, JUMPING, DIE, GROUND }state;
	enum ModeType { STAY, RUN, R, JUMP, DEAD, GROUNDED } mode;
	float pos_X, pos_Y;

	Mario(Point2 pos)
	{
		pix[0].readBMPFile("C:\\Users\\Excalibur\\testing\\mario\\imgs\\MarioStanding.bmp", 1);
		pix[1].readBMPFile("C:\\Users\\Excalibur\\testing\\mario\\imgs\\MarioJump.bmp", 1);
		pix[2].readBMPFile("C:\\Users\\Excalibur\\testing\\mario\\imgs\\MarioRun1.bmp", 1);
		pix[3].readBMPFile("C:\\Users\\Excalibur\\testing\\mario\\imgs\\MarioRun2.bmp", 1);
		pix[4].readBMPFile("C:\\Users\\Excalibur\\testing\\mario\\imgs\\MarioRun3.bmp", 1);

		for (int i = 0;i < 5;i++)
			pix[i].setChromaKey(192, 192, 192);

		this->pos_X = pos.getX();
		this->pos_Y = pos.getY();


	};
	void changePosition(float dx, float dy)
	{
		if (this->pos_X > 600)this->pos_X = 0.0; // greater than screen width
		this->pos_X += dx;  this->pos_Y += dy;
	}

	void render();
	void changeMode(ModeType m);
	void run();
	void stay();
	void jump();
	void die();
	void grounded();
};
void Mario::render()
{
	switch (mode)
	{
	case STAY:
		stay();
		break;

	case RUN:

		run();
		break;

	case JUMP:

		jump();
		break;
	case GROUNDED:
		grounded();
		break;
	}
}
void Mario::stay()
{
	glRasterPos2i(this->pos_X, this->pos_Y);
	if (this->pos_Y > 0) {
		state = JUMPING;
		changePosition(0.10, -(0.30));
	}
	if (this->pos_Y <= 0) {
		state = STANDING;
	}
	pix[state].mDraw();
}
void Mario::run()
{
	switch (state)
	{
	case RUNNING1:

		state = RUNNING2;
		break;

	case RUNNING2:

		state = RUNNING3;
		break;

	case RUNNING3:

		state = RUNNING1;
		break;

	}
	changePosition(0.15, 0);
	glRasterPos2i(this->pos_X, this->pos_Y);
	pix[state].mDraw();
	if (this->pos_Y > 0) {
		state = JUMPING;
		changePosition(0.10, -(0.30));
		pix[state].mDraw();
	}
}
void Mario::changeMode(ModeType m)
{
	if (mode == m)
		return;
	switch (m)
	{
	case STAY:
		state = STANDING;
		break;
	case RUN:
		state = RUNNING1;
		break;
	case JUMP:
		state = JUMPING;
		break;
	case GROUNDED:
		state = GROUND;
		break;
	}
	mode = m;
}
void Mario::jump()
{
	changePosition(0.10, 0.10);
	glRasterPos2i(this->pos_X, this->pos_Y);
	pix[state].mDraw();
}
void Mario::grounded()
{
	if (this->pos_Y > 0) {
		state = JUMPING;
		changePosition(0.10, -(0.30));
	}
	glRasterPos2i(this->pos_X, this->pos_Y);
	pix[state].mDraw();
	if (this->pos_Y <= 0) {
		state = STANDING;
	}
}
