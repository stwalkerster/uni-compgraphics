#include <GL/glut.h>
#include "drawW.h"
#include "3DCurve.h"
#include "Cube.h"

void drawW()
{
	// draw left |
	glPushMatrix();
		glTranslatef(-1.5,1,0);
		//r
		//glScalef(0.5,2,0.5);
		drawStick();
	glPopMatrix();

	// draw right |
	glPushMatrix();
		glTranslatef(1.5,1,0);
		//r
		//s
		drawStick();
	glPopMatrix();

	// draw left U
	glPushMatrix();
		glTranslatef(-0.75,0,0);
		//r
		//s
		drawLoop();
	glPopMatrix();

	// draw right U
	glPushMatrix();
		glTranslatef(0.75,0,0);
		//r
		//s
		drawLoop();
	glPopMatrix();

	//draw middle |
	glPushMatrix();
		glTranslatef(0,0.5,0);
		//r
		glScalef(1,0.5,1);
		drawStick();
	glPopMatrix();
}

void drawStick()
{
                //glTranslatef(
                //r
                glScalef(0.5,2,0.5);
                cube();
}

void drawLoop()
{
	glPushMatrix();
		glScalef(1,1,0.5);
		draw3Dcurve(1, 0.5, 1, 180, 360, 10);
	glPopMatrix();
}
