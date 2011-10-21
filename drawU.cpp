#include <GL/glut.h>
#include "drawU.h"
#include "drawW.h"

void drawU()
{
	// draw left |
	glPushMatrix();
		glTranslatef(-1.5,1,0);
		//r
		//s
		drawStick();
	glPopMatrix();

	// draw right |
	glPushMatrix();
		glTranslatef(0,0.5,0);
		//r
		glScalef(1,1.5,1);
		drawStick();
	glPopMatrix();

	// draw U
	glPushMatrix();
		glTranslatef(-0.75,0,0);
		//r
		//s
		drawLoop();
	glPopMatrix();
}
