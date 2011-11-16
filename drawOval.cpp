#include <GL/glut.h>
#include "drawU.h"
void drawOvalHalf();

void drawOval()
{
glPushMatrix();
	drawOvalHalf();
	glRotatef(180,1,0,0);
	drawOvalHalf();
glPopMatrix();	
}

void drawOvalHalf()
{
glPushMatrix();

	glTranslatef(0,-2,0);
	
	int steps = 24;
	for(int i = 0; i<steps;i++)
	{
		glPushMatrix();
			glRotatef((360/steps) * i, 0,1,0);
			drawU();
		glPopMatrix();
	}

glPopMatrix();
}
