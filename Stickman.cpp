#include "Stickman.h"
#include <GL\glut.h>
//#include <iostream>
//#include <cstdio>
//#include <cstdlib>
//#include <GL\gl.h>


using namespace std;

Stickman::Stickman()
{
}

Stickman::~Stickman()
{
}
static int lleg_angle1 = 0, lleg_angle2 = 0, rleg_angle1 = 0, rleg_angle2 = 0, larm_angle1 = 0, 
	larm_angle2 = 0, rarm_angle1 = 0, rarm_angle2 = 0;
void draw_body(void)
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 3.0f, 0.0f);
	glScalef(3.0f, 6.0f, 3.0f);
	glutSolidCube(1);
	glPopMatrix();
}
void draw_head(void)
{
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f);
	glTranslatef(0.0f, 7.0f, 0.0f);
	glScalef(2.0f, 2.0f, 2.0f);
	glutSolidCube(1);
	glPopMatrix();
}
void draw_leftleg()
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.0f, 0.0f, 1.0f);
	glRotatef(lleg_angle1, 0, 0,1);
	glTranslatef(0.0f, -1.5f, 0.0f);
	glScalef(1.0f, 3.0f, 1.0f);
	glutSolidCube(1);
	glTranslatef(0.0f, -1.5f, 0.0f);
	glRotatef(lleg_angle2, 0, 0, 1);

	glScalef(1.0f, 2.0f, 1.0f);
	glTranslatef(0.0f, -1.0f, 0.0f);
	glutSolidCube(1);
	glPopMatrix();


}
void draw_rightleg()
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.0f, 0.0f, -1.0f);
	glRotatef(rleg_angle1, 0, 0, 1);
	glTranslatef(0.0f, -1.5f, 0.0f);
	glScalef(1.0f, 3.0f, 1.0f);
	glutSolidCube(1);
	glTranslatef(0.0f, -1.5f, 0.0f);
	glRotatef(rleg_angle2, 0, 0, 1);

	glScalef(1.0f, 2.0f, 1.0f);
	glTranslatef(0.0f, -1.0f, 0.0f);
	glutSolidCube(1);
	glPopMatrix();
}
void draw_leftarm()
{
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 5.0f, -2.0f);
	glRotatef(larm_angle1, 0, 0, 1);
	glTranslatef(0.0f, -0.5f, 0.0f);
	glScalef(2.0f, 3.0f, 1.0f);
	glutSolidCube(1);

	glTranslatef(0.0f, -1.6f, 0.0f);
	glRotatef(larm_angle2, 0, 0, 1);
	glTranslatef(0.0f, -1.6f, 0.0f);
	glScalef(2.0f, 3.0f, 1.0f);
	glutSolidCube(1);
	glPopMatrix();

}
void draw_rightarm()
{
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 5.0f, 2.0f);
	glRotatef(rarm_angle1, 0, 0, 1);
	glTranslatef(0.0f, -0.5f, 0.0f);
	glScalef(2.0f, 3.0f, 1.0f);
	glutSolidCube(1);

	glTranslatef(0.0f, -1.6f, 0.0f);
	glRotatef(rarm_angle2, 0, 0, 1);
	glTranslatef(0.0f, -1.6f, 0.0f);
	glScalef(2.0f, 3.0f, 1.0f);
	glutSolidCube(1);
	glPopMatrix();

}
void mydisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	draw_body();
	draw_head();
	draw_leftleg();
	draw_rightleg();
	draw_leftarm();
	draw_rightarm();
	glPopMatrix();
	glutSwapBuffers();
}
int main(int argc,char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("robot animation!");
	glutDisplayFunc(&mydisplay);
	glutMainLoop();
	return 0;
}
