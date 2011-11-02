#include <GL/glut.h>
#include "Ucube.h"
#include "test.h"

void test()
{
	glPushMatrix();
		//glTranslatef();
		Ucube();
	glPopMatrix();	
}
