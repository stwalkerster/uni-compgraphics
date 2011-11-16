#include <GL/glut.h>
#include "drawV.h"

void drawEar()
{glPushMatrix();
	
	glTranslatef(0,1.8,0);
	glRotatef(180,1,0,0);
	
	glPushMatrix();
		glTranslatef(0,0.93,0);
		//r
		glScalef(0.5,0.5, 0.5);
		drawV();
	glPopMatrix();

	float inc = 0.28;
	for(int i = 0; i < 8; i++)
	{
		glPushMatrix();
			glTranslatef(0, 0.85 + (i*inc), 0.09);
			//r
			glScalef(0.4,0.4, 0.25);
			drawV();
		glPopMatrix();
	}



glPopMatrix();}


