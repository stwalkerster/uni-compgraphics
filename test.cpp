#include <GL/glut.h>
#include "Ucube.h"
#include "test.h"

void test()
{
	for(int i = 0; i< 100; i++)
{

	glTranslatef(0,-0.01,0);
	glPushMatrix();
		glRotatef(90,1,0,0);
		Ucube();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,0.5,0);
		glRotatef(90,1,0,0);
		Ucube();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,1,0);
		glRotatef(90,1,0,0);
		Ucube();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,1.5,0);
		glRotatef(90,1,0,0);
		Ucube();
	glPopMatrix();	
	
	glPushMatrix();
		glTranslatef(0,2,0);
		glRotatef(90,1,0,0);
		Ucube();
	glPopMatrix();	
	
	glPushMatrix();
		glTranslatef(0,2.5,0);
		glRotatef(90,1,0,0);
		Ucube();
	glPopMatrix();
}
}
