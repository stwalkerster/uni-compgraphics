#include <GL/glut.h>
#include "drawW.h"
#include "3DCurve.h"
#include "Cube.h"

void drawW()
{
	// draw left |
	glPushMatrix();
		//glTranslatef(
		//r
		glScalef(0.5,2,1);
		cube();
	glPopMatrix();

	// draw right |

	// draw left U

	// draw right U
}
