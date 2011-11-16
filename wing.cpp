#include <GL/glut.h>
#include "drawU.h"
#include "drawW.h"
#include "wing.h"

void wingseg();

void wing(int segments, int angle)
{
	glPushMatrix();
		wingseg();
		if(segments != 0)
		{
			glTranslatef(-1.75,0,0);
			glRotatef(angle,1,0,0);
			wing(segments-1,angle);
		}
	glPopMatrix();
}

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

