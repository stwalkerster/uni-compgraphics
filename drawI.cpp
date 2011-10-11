#include <GL/glut.h>
#include "drawI.h"
#include "3DCurve.h"
#include "Cube.h"

void drawI()
{
	glPushMatrix();
		glScalef(0.5,2,0.5);#test comment
	cube();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,1.8,0);
		glScalef(0.15,0.15,0.15);
		draw3Dcurve  (1.0,          //depth  
					  1.5,          //inner radius
					  2.0,          //outer radius
					  0.0,          //start angle //0.0
					  360,  		//stop angle
					  5.0);         //anular increments
					  
					  glRotatef(90,0,1,0);
					  draw3Dcurve  (1.0,          //depth  
					  1.5,          //inner radius
					  2.0,          //outer radius
					  0.0,          //start angle //0.0
					  360,  		//stop angle
					  5.0);         //anular increments
					  
					  glRotatef(45,0,1,0);
					  draw3Dcurve  (1.0,          //depth  
					  1.5,          //inner radius
					  2.0,          //outer radius
					  0.0,          //start angle //0.0
					  360,  		//stop angle
					  5.0);         //anular increments
					  
					  glRotatef(90,0,1,0);
					  draw3Dcurve  (1.0,          //depth  
					  1.5,          //inner radius
					  2.0,          //outer radius
					  0.0,          //start angle //0.0
					  360,  		//stop angle
					  5.0);         //anular increments*/
					  
					  
	glPopMatrix();
				  		  
				  
	/*			  
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
				  //cube();*/
}
