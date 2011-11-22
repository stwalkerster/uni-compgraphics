#include "drawX.h"
#include <GL/glut.h>
#include "test.h"

void drawFoot()
{
	glScalef(0.3,0.3,0.3);
	glPushMatrix();
		glTranslatef(0,-0.1,-1.25);
		glRotatef(90,0,0,1);
		glScalef(0.99,0.99,0.99);
		glTranslatef(0,0,0.005);
		glColor3f(0,0,0);
		for(int j = 0;j<3;j++)
		{
			glTranslatef(0.35,0,0);
			glPushMatrix();
				drawX();
				for(int i = 0; i<5;i++)
				{
					glTranslatef(0,0,0.5);
					drawX();
				}
			glPopMatrix();
		}
	glPopMatrix();
	
	glColor3f(1,.5,.5);
	
	glPushMatrix();
		glScalef(1,3,1);
		glTranslatef(0,1.5,0);
		glRotatef(90,0,1,0);
		test();
	glPopMatrix();
	
}
