////////////////////////////////////////////////////////////////
//
// Ucube.cpp - function to draw one slice of the pigs foot
//
// Author: Vasileios Spyridakis & Simon Walker
//
// Invocation: call Ucube()
//
////////////////////////////////////////////////////////////////

#include <GL/glut.h>
#include "drawU.h"
#include "drawW.h"
#include "Ucube.h"

void Ucube()
{
	glPushMatrix();
		glTranslatef(1.25,-0.5,0);
		drawU();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-0.5,-1.25,0);
		glRotatef(90,0,0,-1);
		drawU();	
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.5,1.25,0);
		glRotatef(90,0,0,1);
		drawU();	
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-1.25,0.5,0);
		glRotatef(180,0,0,1);
		drawU();
	glPopMatrix();
	
}
