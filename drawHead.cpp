#include "drawNose.h"
#include "drawOval.h"
#include "Ear.h"
#include "drawEyes.h"
#include <GL/glut.h>


void drawHead()
{
	//head
	glPushMatrix();
		glTranslatef(0,0,0);
		glRotatef(90,1,0,0);
		glScalef(1,0.5,1);
		drawOval();
	glPopMatrix();
	
	//eyes
	glPushMatrix();
		glTranslatef(0,0.7,1.5);
		glRotatef(0,0,0,1);
		glScalef(0.4,0.4,0.4);
		drawEyes();
	glPopMatrix();
	
	//nose
	glPushMatrix();
		glTranslatef(0,-0.3,1.5);
		//glRotatef(0,0,0,1);
		glScalef(0.4,0.3,0.4);
		drawNose();
	glPopMatrix();
	
	
}
