////////////////////////////////////////////////////////////////
//
// drawFoot.cpp - function to draw a pig's foot
//
// Author: Vasileios Spyridakis & Simon Walker
//
// Invocation: call drawFoot()
//
////////////////////////////////////////////////////////////////

#include "drawX.h"
#include <GL/glut.h>
#include "test.h"

void drawFoot()
{
	glScalef(0.3,0.3,0.3);
	glPushMatrix();
		glTranslatef(0,-0.1,-1.25);
		glRotatef(90,0,0,1);
		glScalef(0.99,0.99,0.99);
		glTranslatef(0,0,0.005);
		glColor3f(0,0,0);
		// Move the x's across
		for(int j = 0;j<3;j++)
		{
			glTranslatef(0.35,0,0);
			glPushMatrix();
				drawX();
				// Move the x's up
				for(int i = 0; i<5;i++)
				{
					glTranslatef(0,0,0.5);
					drawX();
				}
			glPopMatrix();
		}
	glPopMatrix();
	
	glColor3f(1,0.5,0.5);
	
	glPushMatrix();
		glScalef(1,3,1.05);
		glTranslatef(0,1.6,0);
		glRotatef(90,0,1,0);
		// Draw the leg without the hoof
		test();
	glPopMatrix();
}
