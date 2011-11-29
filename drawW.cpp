////////////////////////////////////////////////////////////////
//
// drawW.cpp - function to draw the letter W
//
// Author: Simon Walker
//
// Invocation: call drawW()
//
////////////////////////////////////////////////////////////////

#include <GL/glut.h>
#include "drawW.h"
#include "3DCurve.h"
#include "Cube.h"

void drawW()
{
	// Draw left |
	glPushMatrix();
		glTranslatef(-1.5,1,0);
		drawStick();
	glPopMatrix();

	// Draw right |
	glPushMatrix();
		glTranslatef(1.5,1,0);
		drawStick();
	glPopMatrix();

	// Draw left U
	glPushMatrix();
		glTranslatef(-0.75,0,0);
		drawLoop();
	glPopMatrix();

	// Draw right U
	glPushMatrix();
		glTranslatef(0.75,0,0);
		drawLoop();
	glPopMatrix();

	// Draw middle |
	glPushMatrix();
		glTranslatef(0,0.5,0);
		glScalef(1,0.5,1);
		drawStick();
	glPopMatrix();
}

void drawStick()
{
	glScalef(0.5,2,0.5);
	cube();
}

void drawLoop()
{
	glPushMatrix();
		glScalef(1,1,0.5);
		draw3Dcurve  (1.0,          //depth  
					  0.5,          //inner radius
					  1.0,          //outer radius
					  180.0,        //start angle
					  360,  		//stop angle
					  10.0);        //anular increments
	glPopMatrix();
}
