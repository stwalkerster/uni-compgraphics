#include <GL/glut.h>
#include "drawU.h"
#include "drawW.h"
#include "wing.h"

void wingseg();

void wing()
{
	glPushMatrix();
		glScalef(0.5,0.5,0.5);
		wingseg();
		glTranslatef(-1.75,0,0);
		wingseg();
		glTranslatef(-1.75,0,0);
		wingseg();
		glTranslatef(-1.75,0,0);
		wingseg();
		glTranslatef(-1.75,0,0);
		wingseg();
		glTranslatef(-1.75,0,0);
		wingseg();
	glPopMatrix();
	
	glPushMatrix();
		glScalef(-1,1,1);
		glScalef(0.5,0.5,0.5);
		wingseg();
		glTranslatef(-1.75,0,0);
		wingseg();
		glTranslatef(-1.75,0,0);
		wingseg();
		glTranslatef(-1.75,0,0);
		wingseg();
		glTranslatef(-1.75,0,0);
		wingseg();
		glTranslatef(-1.75,0,0);
		wingseg();
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

