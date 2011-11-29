////////////////////////////////////////////////////////////////
//
// drawT.cpp - function to draw the letter T
//
// Author: Vasileios Spyridakis
//
// Invocation: call drawT()
//
////////////////////////////////////////////////////////////////

#include <GL/glut.h>
#include "drawT.h"
#include "3DCurve.h"
#include "Cube.h"

void drawT()
{
	// Draw stem of t
	glPushMatrix();
		glTranslatef(0,-0.5,0);
		glScalef(0.5,3,0.5);
		cube();
	glPopMatrix();

	// Draw curve of t
	glPushMatrix();
		glTranslatef(0.75,-2,0);
		glScalef(1,1,0.5);
		draw3Dcurve  (1.0,          //depth  
					  0.5,          //inner radius
					  1.0,          //outer radius
					  180.0,        //start angle
					  315,  		//stop angle
					  5.0);         //anular increments
	glPopMatrix();

	// Draw left cross of t
	glPushMatrix();
		glTranslatef(-0.75,0,0);
		glScalef(1,0.5,0.5);
		cube();
	glPopMatrix();

	// Draw right cross of t
	glPushMatrix();
		glTranslatef(0.75,0,0);
		glScalef(1,0.5,0.5);
		cube();
	glPopMatrix();
}
