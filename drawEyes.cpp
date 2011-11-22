#include <GL/glut.h>
#include "drawS.h"

void drawEyes()
{glPushMatrix();

	glRotatef(90,0,0,1);
	
		int steps = 10;
	for(int i = 0; i<steps;i++)
	{
		glPushMatrix();
			glRotatef((360/steps) * i, 0,1,0);
			drawS();
		glPopMatrix();
	}

glPopMatrix();}
