////////////////////////////////////////////////////////////////
//
// drawS.cpp - function to draw the letter S
//
// Author: Vasileios Spyridakis
//
// Invocation: call drawS()
//
////////////////////////////////////////////////////////////////

#include <GL/glut.h>
#include "drawS.h"
#include "3DCurve.h"
#include "Cube.h"

void drawS()
{
	// Draw the top curve
	glPushMatrix();
		glTranslatef(0,1.3,0);
		glScalef(0.75,0.75,0.5);
		draw3Dcurve  (1.0,          //depth  
					  1.5,          //inner radius
					  2.0,          //outer radius
					  0.0,          //start angle
					  270,  		//stop angle
					  5.0);         //anular increments
	glPopMatrix();

	// Draw the cube for the end of the top curve
	glPushMatrix();
	glTranslatef(1.31,1.31,0);
	glRotatef(45,0,0,1);
	glScalef(0.26,0.26,0.5);
	cube();
	glPopMatrix();

	// Draw the bottom curve
	glPushMatrix();			  
		glTranslatef(0,-1.32,0);
		glRotatef(180,0,0,1);
		glScalef(0.75,0.75,0.5);
		draw3Dcurve  (1.0,          //depth  
					  1.5,          //inner radius
					  2.0,          //outer radius
					  0.0,          //start angle
					  270,  		//stop angle
					  5.0);
	glPopMatrix();
	
	// Draw the cube for the end of the bottom curve
	glPushMatrix();
	glTranslatef(-1.31,-1.31,0);
	glRotatef(45,0,0,1);
	glScalef(0.26,0.26,0.5);
	cube();
	glPopMatrix();
}
