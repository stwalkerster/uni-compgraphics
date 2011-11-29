////////////////////////////////////////////////////////////////
//
// drawHead.cpp - function to draw the pig's head
//
// Author: Vasileios Spyridakis & Simon Walker
//
// Invocation: call drawHead()
//
////////////////////////////////////////////////////////////////

#include "drawNose.h"
#include "drawOval.h"
#include "Ear.h"
#include "drawEyes.h"
#include <GL/glut.h>


void drawHead()
{
	// Draw the head
	glPushMatrix();
	glColor3f(1,0.5,0.5);
		glTranslatef(0,0,0);
		glRotatef(90,1,0,0);
		glScalef(1,0.5,1);
		drawOval();
	glPopMatrix();
	
	// Draw the eyes
	glPushMatrix();
	glColor3f(0,0,0);
		glTranslatef(0,0.8,1.5);
		glRotatef(0,0,0,1);
		glScalef(0.3,0.3,0.3);
		drawEyes();
	glPopMatrix();
	
	// Draw the nose
	glPushMatrix();
	glColor3f(1,0.5,0.5);
		glTranslatef(0,-0.4,1.5);
		glScalef(0.4,0.3,1.8);
		drawNose();
	glPopMatrix();
	
	float ear_angle = 35;
	
	// Draw left ear
	glPushMatrix();
		glRotatef(ear_angle,0,0,1);
		glTranslatef(0,1.6,0);
		glScalef(0.4,0.4,0.4);
		drawEar();
	glPopMatrix();
	
	// Draw right ear
	glPushMatrix();
		glRotatef(-ear_angle,0,0,1);
		glTranslatef(0,1.6,0);
		glScalef(0.4,0.4,0.4);
		drawEar();
	glPopMatrix();
	
}
