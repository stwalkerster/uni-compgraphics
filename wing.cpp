////////////////////////////////////////////////////////////////
//
// wing.cpp - function to draw the wing
//
// Author: Vasileios Spyridakis & Simon Walker
//
// Invocation: call wing()
//
// Arguments:
//    segments = number of segments to draw after this one
//    angle = angle to draw next segment at
////////////////////////////////////////////////////////////////

#include <GL/glut.h>
#include "drawU.h"
#include "drawW.h"
#include "wing.h"

void wingseg();

// Draw a section of wing with "segments" number of segments and at a specific angle
void wing(int segments, int angle)
{
	glPushMatrix();
		// Draw a wing segment
		wingseg();
		// Do we need to draw more segments?
		if(segments != 0)
		{
			// Yes! apply the rotation and translation needed to get it to the end of the wing
			glTranslatef(-1.75,0,0);
			glRotatef(angle,0,1,0);
			// Draw another bit of wing, with one less segment than before
			wing(segments-1,angle);
		}
	glPopMatrix();
}

// Draw a wing segment
void wingseg()
{
	glPushMatrix();
		glScalef(0.5,0.5,0.5);
		glPushMatrix();
			glTranslatef(-1,-0.25,0);
			glRotatef(90,0,0,1);
			drawU();
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(-1.75,-2,0);
			drawW();
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(-1.75,-2.5,-0.25);
			drawW();
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(-1.75,-3,-0.5);
			drawW();
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(-1.75,-3.5,-0.75);
			drawW();
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(-1.75,-4,-1);
			drawW();
		glPopMatrix();
	glPopMatrix();
}

