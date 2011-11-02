#include <GL/glut.h>
#include "drawT.h"
#include "3DCurve.h"
#include "Cube.h"

void drawT()
{
	// draw stem of t
	glPushMatrix();
		glTranslatef(0,-0.5,0);
		//r
		glScalef(0.5,3,0.5);
		cube();
	glPopMatrix();

	// draw curve of t
	glPushMatrix();
		glTranslatef(0.75,-2,0);
		//r
		glScalef(1,1,0.5);
		draw3Dcurve(1, 0.5, 1, 180, 315, 5);
	glPopMatrix();

	// draw left cross of t
	glPushMatrix();
		glTranslatef(-0.75,0,0);
		//r
		glScalef(1,0.5,0.5);
		cube();
	glPopMatrix();

	// draw right cross of t
	glPushMatrix();
		glTranslatef(0.75,0,0);
		//r
		glScalef(1,0.5,0.5);
		cube();
	glPopMatrix();
}
