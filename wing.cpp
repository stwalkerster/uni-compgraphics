#include <GL/glut.h>
#include "drawU.h"
#include "drawW.h"
#include "wing.h"

void wing()
{
	
	glScalef(0.5,0.5,0.5);
	glPushMatrix();
		glTranslatef(-1,-0.25,0);
		glRotatef(90,0,0,1);
		drawU();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-1.75,-3,0);
		drawW();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-1.75,-3.5,-0.25);
		drawW();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-1.75,-4,-0.5);
		drawW();
	glPopMatrix();
}
