////////////////////////////////////////////////////////////////
//
// drawEyes.cpp - function to draw the eyes of the pig
//
// Author: Vasileios Spyridakis & Simon Walker
//
// Invocation: call drawEyes()
//
////////////////////////////////////////////////////////////////

#include <GL/glut.h>
#include "drawS.h"

void drawEyes()
{
	glPushMatrix();

	glRotatef(90,0,0,1);
	
	int steps = 18;
	for(int i = 0; i<steps;i++)
	{
		glPushMatrix();
			// Rotate by a small increment in each iteration
			glRotatef((360/steps) * i, 0,1,0);
			drawS();
		glPopMatrix();
	}
	glPopMatrix();
}
