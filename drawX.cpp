#include <GL/glut.h>
#include "drawX.h"
#include "3DCurve.h"
#include "Cube.h"

void drawX()
{
	glPushMatrix();
		glTranslatef(0,0,0);
		//glRotatef(45,0,0,1);
		glScalef(0.3,0.3,0.3);
		cube();
	glPopMatrix();
	
	glPushMatrix();
		//glTranslatef(0,1.3,0);
		glRotatef(45,0,0,1);
		glScalef(0.75,0.75,0.5);
		draw3Dcurve  (1.0,          //depth  
					  1.5,      //inner radius
					  2.0,      //outer radius
					  0.0,      //start angle
					  150,      //stop angle
					  5.0);     //anular increments
	glPopMatrix();

	
	
}
