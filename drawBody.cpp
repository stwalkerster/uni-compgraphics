#include "drawHead.h"
#include "drawOval.h"
#include "drawT.h"
#include "wing.h"
#include "main.h"
#include <GL/glut.h>

void drawBody()
{
	glPushMatrix();
	
	glScalef(0.5,0.5,0.5);
	
	glPushMatrix();
		glRotatef(90,1,0,0);
		drawOval();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,1,3);
		glScalef(0.7,0.7,0.7);
		drawHead();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,0,-2.8);
		glRotatef(-90,0,1,0);
		glRotatef(-90,0,0,1);
		glScalef(0.5,0.5,0.5);
		drawT();
	glPopMatrix();
	
	glTranslatef(0,0,1);
	
	glPushMatrix();
		glRotatef(90,1,0,0);
		glScalef(1,1,-1);
		wing(5, wingAngle);
	glPopMatrix();
	
	glPushMatrix();
		glScalef(-1,1,-1);
		glRotatef(-90,1,0,0);
		wing(5, wingAngle);
	glPopMatrix();
	
glPopMatrix();}
