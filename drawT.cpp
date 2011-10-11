#include <GL/glut.h>
#include "drawT.h"
#include "3DCurve.h"
#include "Cube.h"

void drawT()
{
	// draw stem of t
	glPushMatrix();
		glTranslatef(0,-1,0);
		//r
		glScalef(1,3,1);
		cube();
	glPopMatrix();


	// draw curve of t
	glPushMatrix();
		//
	glPopMatrix();


	// draw left cross of t
	glPushMatrix();
		glTranslatef(-1,0,0);
		//r
		//s
		cube();
	glPopMatrix();

	// draw right cross of t
	glPushMatrix();
		glTranslatef(1,0,0);
		//r
		//s
		cube();
	glPopMatrix();
}
