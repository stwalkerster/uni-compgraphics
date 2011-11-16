#include "drawHead.h"
#include "drawOval.h"
#include "drawT.h"
#include <GL/glut.h>

void drawBody()
{glPushMatrix();
	glPushMatrix();
		glRotatef(90,1,0,0);
		drawOval();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,1,3);
		glScalef(0.7,0.7,0.7);
		drawHead();
	glPopMatrix();
glPopMatrix();}
