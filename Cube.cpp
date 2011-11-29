////////////////////////////////////////////////////////////////
//
// Cube.cpp - code for Cube model
// 
// Author: Mike Chantler
//
// Edited by Vasileios Spyridakis & Simon Walker
//
////////////////////////////////////////////////////////////////

#include <GL/glut.h>
#include "Cube.h"

float vertices[][3] = 
{
		{-0.5,-0.5,-0.5},{0.5,-0.5,-0.5},
		{0.5,0.5,-0.5}, {-0.5,0.5,-0.5}, {-0.5,-0.5,0.5}, 
		{0.5,-0.5,0.5}, {0.5,0.5,0.5}, {-0.5,0.5,0.5}
};

// Edit: Removed colours.

void polygon(int a, int b, int c , int d)
{
	// draw a polygon using colour of first vertex

 	glBegin(GL_POLYGON);
		// Edit: Removed color.
		glVertex3fv(vertices[a]);
		glVertex3fv(vertices[b]);
		glVertex3fv(vertices[c]);
		glVertex3fv(vertices[d]);
	glEnd();
	
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINE_LOOP);
		// Edit: Removed color.
		glVertex3fv(vertices[a]);
		glVertex3fv(vertices[b]);
		glVertex3fv(vertices[c]);
		glVertex3fv(vertices[d]);
	glEnd();
	glDisable(GL_LINE_SMOOTH);
}

void cube(void) {
	//Draw unit cube centred on the origin
	polygon(0,3,2,1);
	polygon(2,3,7,6);
	polygon(4,7,3,0);
	polygon(1,2,6,5);
	polygon(7,4,5,6);
	polygon(5,4,0,1);
}
