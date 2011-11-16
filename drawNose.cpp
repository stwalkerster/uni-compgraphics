#include <GL/glut.h>
#include "drawU.h"

void drawNose()
{glPushMatrix();
	glTranslatef(0,-0.5,-0.25);
	glRotatef(-90,0,1,0);
	
	drawU();
	
	int steps = 24;
	for(int i = 0; i<steps;i++)
	{
		glPushMatrix();
			glRotatef((360/steps) * i, 1,0,0);
			drawU();
		glPopMatrix();
	}

glPopMatrix();}
