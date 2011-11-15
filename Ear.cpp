#include <GL/glut.h>
#include "drawV.h"

void drawEar()
{
	glPushMatrix();
		glTranslatef(0,0.93,0);
		glRotatef(180,1,0,0);
		glScalef(0.5,0.5, 0.5);
		drawV();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0,0.85,0.09);
		glRotatef(180,1,0,0);
		glScalef(0.4,0.4, 0.25);
		drawV();
	glPopMatrix();


}


