#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <GL/glut.h>


using namespace std;
int screenWidth = 640;
int screenHeight = 480;

float minX = -10, minY = -10, maxX = 10, maxY = 10;
int VP_bottom = 0, VP_left = 0, VPWidth = 640, VPHeight = 480;

void drawAxis() {
  glBegin(GL_LINES);
  glVertex2f(minX, 0);
  glVertex2f(maxX, 0);
  glEnd();

  glBegin(GL_LINES);
  glVertex2f(0, minY);
  glVertex2f(0, maxY);
  glEnd();
}
void bitmap_output(int x, int y, string s, void* font) {
  int len, i;
  glRasterPos2f(x, y);
  len = s.length();
  for (i = 0; i < len;i++) {
    glutBitmapCharacter(font, s[i]);
  }
}
void myDisplay(void) //user defined display function
{
  glClear(GL_COLOR_BUFFER_BIT); //clears fb with bg color
  glViewport(VP_bottom, VP_left, VPWidth, VPHeight);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(minX, maxX, minY, maxY);
  drawAxis();
  glColor3f(1, 0, 0);
  bitmap_output(-9.0, 7.0, "First bitmap text", GLUT_BITMAP_TIMES_ROMAN_24);
  glColor3f(0, 0, 1);
  bitmap_output(-9.0, -7.0, "Second bitmap text", GLUT_BITMAP_9_BY_15);
  glColor3f(0, 1, 0);
  bitmap_output(2.0, 7.0, "Third bitmap text", GLUT_BITMAP_HELVETICA_18);
  glColor3f(0, 1, 1);
  bitmap_output(2.0, -7.0, "Fourth bitmap text", GLUT_BITMAP_HELVETICA_18);
  glFlush(); //send buffer pixels to display
}

void drawDot(int x, int y) {
  // glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 1000, 0, 1000);
  // Draw
  glPointSize(10.0);
  glColor3f(0.9294, 0.1294, 0.5333);
  glBegin(GL_POINTS);
  glVertex2f(x, 1000 - y);
  glEnd();
  glFlush();
}
void myMouse(int button, int state, int x, int y) {
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    //glutPostRedisplay(); //call redisplay
    drawDot(x, screenHeight - y);
  }
  if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
  }
} //mouse click handler end

void myinit() {
  glClearColor(0.9f, 0.5f, 0.9f, 0.0);
  glColor3f(1, 0, 0);
  PlaySound("bgaudio.wav", NULL, SND_LOOP);
}

void myReshape(int w, int h) {
  screenWidth = w; screenHeight = h;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void mouseMove(int x, int y) {
  glutPostRedisplay();
}
void drawMountainRange() {
  glBegin(GL_TRIANGLES);
  glColor3f(0.6f, 0.3f, 0.0f);
  // Mountain 1
  glVertex2f(-5.0, -5.0);
  glVertex2f(0.0, 5.0);
  glVertex2f(5.0, -5.0);
  // Mountain 2
  glVertex2f(-2.5, -5.0);
  glVertex2f(4.5, 3.5);
  glVertex2f(8, -5.0);
  // Mountain 3
  glVertex2f(-8.0, -5.0);
  glVertex2f(-3.5, 3.5);
  glVertex2f(6.0, -5.0);
  glEnd();
  glFlush();
}

void myKeys(unsigned char key, int x, int y) {
  switch (key)
  {
  case 'q': exit(0);
  case 's': break;
  case 'f': glClearColor(0, 1, 1, 0); break;
  case 'm': glutDisplayFunc(drawMountainRange); break;
  case 'c': glClear(GL_COLOR_BUFFER_BIT); break;
  case 'p': PlaySound("fgaudio.wav", NULL, SND_LOOP); break;
  }
  glutPostRedisplay();
}


int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(screenWidth, screenHeight);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("First OGL Program");
  myinit();
  glutReshapeFunc(myReshape);
  glutDisplayFunc(myDisplay); //register display function as callback
  glutKeyboardFunc(myKeys);
  glutMouseFunc(myMouse);
  glutMotionFunc(mouseMove);
  glutMainLoop(); //gui loop that waits for event to occur
  return 0;
}