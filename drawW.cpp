#include <GL/glut.h>
#include "drawW.h"
#include "3DCurve.h"
#include "Cube.h"

// prototypes cos I'm lazy and cba to put the functions in the right order
void drawStick();
void drawLoop();

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
	draw3Dcurve(0.5, 0.5, 1, 180, 360, 10);
}
