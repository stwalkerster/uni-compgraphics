////////////////////////////////////////////////////////////////
//
// drawU.cpp - function to draw the letter U
//
// Author: Simon Walker
//
// Invocation: call drawU()
//
////////////////////////////////////////////////////////////////

#include <GL/glut.h>
#include "drawU.h"
#include "drawW.h"

void drawU()
{
	// Draw left |
	glPushMatrix();
		glTranslatef(-1.5,1,0);
		drawStick();
	glPopMatrix();

	// Draw right |
	glPushMatrix();
		glTranslatef(0,0.5,0);
		glScalef(1,1.5,1);
		drawStick();
	glPopMatrix();

	// Draw U
	glPushMatrix();
		glTranslatef(-0.75,0,0);
		drawLoop();
	glPopMatrix();
}
