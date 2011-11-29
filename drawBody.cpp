////////////////////////////////////////////////////////////////
//
// drawBody.cpp - function to draw the entire pig
//
// Author: Vasileios Spyridakis & Simon Walker
//
// Invocation: call drawBody()
//
////////////////////////////////////////////////////////////////

#include "drawHead.h"
#include "drawOval.h"
#include "drawT.h"
#include "wing.h"
#include "main.h"
#include "drawFoot.h"
#include <GL/glut.h>

void drawBody()
{
	// Scaling the whole pig to fit the screen properly
	glPushMatrix();
	glScalef(0.37,0.37,0.37);
	
	// Draw the oval
	glPushMatrix();
	glColor3f(1,0.5,0.5);
		glRotatef(90,1,0,0);
		drawOval();
	glPopMatrix();
	
	// Draw the head
	glPushMatrix();
		glTranslatef(0,1,3);
		glScalef(0.7,0.7,0.7);
		drawHead();
	glPopMatrix();
	
	// Draw the tail
	glPushMatrix();
	glColor3f(1,0.5,0.5);
		glTranslatef(0,0,-2.8);
		glRotatef(-90,0,1,0);
		glRotatef(-90,0,0,1);
		glScalef(0.5,0.5,0.5);
		drawT();
	glPopMatrix();
	
	// Put the wings in the right place on the pig's body
	glPushMatrix();
		glTranslatef(0,0,1);
		
		// Drawing the wing with 6 segments
		glPushMatrix();
		glColor3f(1,0.9,0);
			glRotatef(90,1,0,0);
			glScalef(1,1,-1);
			wing(5, wingAngle);
		glPopMatrix();
		
		// Drawing the wing with 6 segments
		glPushMatrix();
		glColor3f(1,0.9,0);
			glScalef(-1,1,-1);
			glRotatef(-90,1,0,0);
			wing(5, wingAngle);
		glPopMatrix();
	glPopMatrix();
	
	// Draw feet
	glColor3f(1,0.5,0.5);
	glPushMatrix();
		glTranslatef(1,-2.7,2);
		drawFoot();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(1,-2.7,-2);
		drawFoot();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-1,-2.7,2);
		drawFoot();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-1,-2.7,-2);
		drawFoot();
	glPopMatrix();
	
glPopMatrix();}
