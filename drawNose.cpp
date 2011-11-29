////////////////////////////////////////////////////////////////
//
// drawNose.cpp - function to draw the pig's nose
//
// Author: Vasileios Spyridakis & Simon Walker
//
// Invocation: call drawNose()
//
////////////////////////////////////////////////////////////////

#include <GL/glut.h>
#include "drawU.h"

void drawNose()
{
	glPushMatrix();
	glTranslatef(0,0,0.25);
	glRotatef(-90,0,1,0);
	
	drawU();
	
	int steps = 18;
	for(int i = 0; i<steps;i++)
	{
		glPushMatrix();
			// Rotate by a small increment in each iteration
			glRotatef((360/steps) * i, 1,0,0);
			drawU();
		glPopMatrix();
	}
	glPopMatrix();
}
