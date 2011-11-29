////////////////////////////////////////////////////////////////
//
// Ear.cpp - function to draw the pig's ear
//
// Author: Vasileios Spyridakis & Simon Walker
//
// Invocation: call drawEar()
//
////////////////////////////////////////////////////////////////

#include <GL/glut.h>
#include "drawV.h"

void drawEar()
{
	glPushMatrix();
	
	glTranslatef(0,1.8,0);
	glRotatef(180,1,0,0);
	
	glPushMatrix();
		glTranslatef(0,0.93,0);
		glScalef(0.5,0.5, 0.5);
		drawV();
	glPopMatrix();

	float inc = 0.28;
	// Move it by a small increment in every iteration
	for(int i = 0; i < 8; i++)
	{
		glPushMatrix();
			glTranslatef(0, 0.85 + (i*inc), 0.09);
			glScalef(0.4,0.4, 0.25);
			drawV();
		glPopMatrix();
	}
	glPopMatrix();
}


