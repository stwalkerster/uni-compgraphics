#include <GL/glut.h>
#include "drawS.h"

void drawEyes()
{glPushMatrix();
	glTranslatef(0,-0.5,-0.25);
	glRotatef(-90,0,1,0);
	
	drawS();
	
	int steps = 30;
	for(int i = 0; i<steps;i++)
	{
		glPushMatrix();
			glRotatef((360/steps) * i, 0,1,0);
			drawS();
		glPopMatrix();
	}

glPopMatrix();}
