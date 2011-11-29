////////////////////////////////////////////////////////////////
//
// drawV.cpp - function to draw the letter V 
//
// Author: Vasileios Spyridakis
//
// Invocation: call drawV()
//
////////////////////////////////////////////////////////////////

#include <GL/glut.h>
#include "drawV.h"
#include "3DCurve.h"
#include "Cube.h"

void drawV()
{
	// Draw the left line of the V
	glPushMatrix();
		glTranslatef(-1.05,0,0);
		glRotatef(15,0,0,1);
		glScalef(0.4,4,0.5);
		cube();
	glPopMatrix();
	
	// Draw the curve on the bottom
	glPushMatrix();
		glTranslatef(0,0,0);
		glScalef(0.5,1.4,0.49);
		draw3Dcurve  (1.0,          //depth  
					  1.5,          //inner radius
					  2.0,          //outer radius
					  225.0,        //start angle
					  315,  		//stop angle
					  5.0);         //anular increments
	glPopMatrix();
	
	// Draw the right line of the V
	glPushMatrix();
		glTranslatef(1.05,0,0);
		glRotatef(-15,0,0,1);
		glScalef(0.4,4,0.5);
		cube();
	glPopMatrix();		  
}
