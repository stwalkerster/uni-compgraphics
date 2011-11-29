////////////////////////////////////////////////////////////////
//
// drawOval.cpp - function to draw the oval
//
// Author: Vasileios Spyridakis & Simon Walker
//
// Invocation: call drawOval()
//
////////////////////////////////////////////////////////////////

#include <GL/glut.h>
#include "drawU.h"
void drawOvalHalf();

void drawOval()
{
	glPushMatrix();
		drawOvalHalf();
		glScalef(1,-1,1);
		drawOvalHalf();
	glPopMatrix();	
}

void drawOvalHalf()
{
	glPushMatrix();
		glTranslatef(0,-2,0);
		
		int steps = 30;
		// Rotate by a small increment in each iteration
		for(int i = 0; i<steps;i++)
		{
			glPushMatrix();
				glRotatef((360/steps) * i, 0,1,0);
				drawU();
			glPopMatrix();
		}
	glPopMatrix();
}
