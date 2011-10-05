#include <GL/glut.h>
#include "drawS.h"
#include "3DCurve.h"
#include "Cube.h"

void drawS()
{
	glTranslatef(0,1.3,0);
	glScalef(0.75,0.75,0.75);
	draw3Dcurve  (1.0,          //depth  
				  1.5,          //inner radius
				  2.0,          //outer radius
				  0.0,          //start angle //0.0
				  270,  		//stop angle
				  5.0);         //anular increments
				  
				  
				  
	glTranslatef(0,-3.5,0);
	glRotatef(180,0,0,1);
	draw3Dcurve  (1.0,          //depth  
				  1.5,          //inner radius
				  2.0,          //outer radius
				  0.0,          //start angle //0.0
				  270,  		//stop angle
				  5.0);
				  //glTranslatef(0,1.75,0);
				  //glRotatef(45,1,0,0);
				  //glScalef(0.65,0.65,0.65);
				  //cube();
}
