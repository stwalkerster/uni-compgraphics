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
		glTranslatef(0,0.8,1.5);
		glRotatef(0,0,0,1);
		glScalef(0.3,0.3,0.3);
		drawEyes();
	glPopMatrix();
	
	//nose
	glPushMatrix();
		glTranslatef(0,-0.4,1.5);
		//glRotatef(0,0,0,1);
		glScalef(0.4,0.3,1.8);
		drawNose();
	glPopMatrix();
	
	float ear_angle = 35;
	
	//lear
	glPushMatrix();
		glRotatef(ear_angle,0,0,1);
		glTranslatef(0,1.6,0);
		//glRotatef(0,0,0,1);
		glScalef(0.4,0.4,0.4);
		drawEar();
	glPopMatrix();
	
	//rear
	glPushMatrix();
		glRotatef(-ear_angle,0,0,1);
		glTranslatef(0,1.6,0);
		//glRotatef(0,0,0,1);
		glScalef(0.4,0.4,0.4);
		drawEar();
	glPopMatrix();
	
}
