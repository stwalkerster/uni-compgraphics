// Example_8_1.cpp : Rotating Wire-Frame 3D Curve
//
// Author  : Mike Chantler
// Date    : 29/04/2008
// Version : 1.1 - Commenting changed to match other examples style
//
// Program behaviour:
// Mouse Button & Drag - Changes the View Point.
// Key "b" - Back Fill
// Key "f" - Front Fill
// Key "l" - Wire Frame/Line Fill
// Key "i" - Increment Sections of Curve
// Key "d" - Decrement Sections of Curve
// Key "r" - Automated Rotation
// Key "R" - Reset the View
//
// Callback commentary sent to normal command window.
//
// Last tested in Visual C++ 2010 Express

/*
 * draw is once solid then change draw mode and redraw it. remove color from 3dcurve to be able to draw it once in white then in black
 */

#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <iostream>
//#include "3DCurve.h"
//#include "Cube.h"
#include "drawS.h"
#include "drawV.h"
#include "drawX.h"
#include "drawT.h"
#include "drawW.h"
#include "drawU.h"

#if defined WIN32
#include "stdafx.h"
#endif

#define NUMBER_OF_MODELS 6
//======================================================
// GLOBAL VARIABLES
//======================================================
static double theta_stop1 = 270;
float pitch = 0.0f;
float yaw = 0.0f;
float pitch0, yaw0;
bool MousePressed;
int mouseX0, mouseY0;
bool rotating=false;
int current_model=1;
std::string current_model_string = "S";
int x_y_display=0, y_z_display=0, x_z_display=0;
bool F3pressed=true;

//======================================================
// DRAW AXES and GRIDS
//======================================================
void drawAxesAndGridLines(void)
{
	float offset;
	glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		glVertex3f(-20, 0, 0);
		glVertex3f(+20, 0, 0);
		glColor3f(0, 1, 0);
		glVertex3f( 0 ,-20, 0);
		glVertex3f(	0, +20, 0);
		glColor3f(0, 0, 1);
		glVertex3f( 0, 0,-20);
		glVertex3f(	0, 0, +20);

	glEnd();
	glLineStipple(1, 0xAAAA); //line style = fine dots
	glEnable(GL_LINE_STIPPLE);

	glBegin(GL_LINES);
		if (x_y_display) {glColor3f(1.0,0.0,0.0);
		for (offset=-10.0;offset<10.1;offset++){
			//draw lines in x-y plane
			glVertex3f(-10.0, offset, 0.0);					// Top Left
			glVertex3f(+10.0, offset, 0.0);					// Top Right
			glVertex3f( offset,-10, 0.0);					// Bottom Right
			glVertex3f(	offset,+10.0, 0.0);					// Bottom Left
		}}

		if (y_z_display) {glColor3f(0.7,0.0,0.7);
		for (offset=-10.0;offset<10.1;offset++){
			//draw lines in y-z plane
			glVertex3f( 0, offset, -10);
			glVertex3f(	0, offset, 10.0);
			glVertex3f( 0, -10, offset);
			glVertex3f(	0, 10, offset);
		}}

		if (x_z_display) {glColor3f(0.7,0.7,0.0);
		for (offset=-10.0;offset<10.1;offset++){
			//draw lines in x-z plane
			glVertex3f( offset, 0, -10);
			glVertex3f(	offset, 0, 10.0);
			glVertex3f( -10, 0, offset);
			glVertex3f(	10, 0, offset);
		}}

	glEnd();
	glDisable(GL_LINE_STIPPLE);

}

//======================================================
// VIEW CONTROL ROUTINES
//======================================================

void idleCallBack (){
	yaw=yaw+.25;
    glutPostRedisplay();
}

void rotateView(bool r){
	rotating = r;
	if (r) glutIdleFunc(idleCallBack); else glutIdleFunc(NULL);
}

void resetView(){
	rotateView(false); //Stop view rotation
	yaw=pitch=0;
}

void executeViewControl (float y, float p){
	glRotatef(y, 0.0f, 1.0f, 0.0f); //yaw about y-axis
    glRotatef(p, 1.0f, 0.0f, 0.0f); //pitch about x-axis 
}

void mouseClickCallBack(int button, int state, int x, int y) {
	//Called on button press or release
    switch (state)
    {
		case GLUT_DOWN:
			MousePressed = true;
			rotateView(false);
			pitch0 = pitch; yaw0 = yaw;
			mouseX0 = x; mouseY0 = y;
			break;
		default:
		case GLUT_UP:
			MousePressed = false;
			//rotateView(true);
			break;
    }
} 

void mouseMotionCallBack(int x, int y) 
{
	// Called when the Mouse is moved with left button down
    pitch = pitch0 + (y - mouseY0);
    yaw = yaw0 + (x - mouseX0);
	glutPostRedisplay();
} 

void reshapeCallBack(int w, int h) 
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	if (w == 0 || h == 0) return;
    if (w <= h) glOrtho(-3.0, 3.0, -3.0 * (GLfloat) h / (GLfloat) w, 3.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else        glOrtho(-3.0 * (GLfloat) w / (GLfloat) h, 3.0 * (GLfloat) w / (GLfloat) h, -3.0, 3.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

//======================================================
// KEYBOARD CALLBACK ROUTINE 
//======================================================
void keyboardCallBack(unsigned char key, int x, int y) {
	printf("Keyboard call back: key=%c, x=%d, y=%d\n", key, x, y);
	switch(key)
	{
	case 'b': case 'B':
		glPolygonMode(GL_BACK,GL_FILL);
	break;
	case 'f': case 'F':
		glPolygonMode(GL_FRONT,GL_FILL);
	break;
	case 'l': case 'L':
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	break;
	case 'i': case 'I':
		theta_stop1+=10;
	break;
	case 'd': case 'D':
		theta_stop1-=10;
	break;
	case 'r': 
		rotating= !rotating;
		rotateView(rotating);
	break;
	case 'R':
        resetView();
	break;
	//Model selection
	case 'm': case 'M':
		current_model++;
		if (current_model > NUMBER_OF_MODELS) current_model = 1;
		if (current_model == 1)
		{
			current_model_string="S";
		}
		else if (current_model == 2)
		{
			current_model_string="V";
		}
		else if (current_model == 3)
		{
			current_model_string="X";
		}
		else if (current_model == 4)
		{
			current_model_string="t";
		}
		else if (current_model == 5)
		{
			current_model_string="W";
		}
		else if (current_model == 6)
		{
			current_model_string="U";
		}
	break;
	case 'x': x_y_display++; if(x_y_display>1) x_y_display=0; break;
	case 'y': y_z_display++; if(y_z_display>1) y_z_display=0; break;
	case 'z': x_z_display++; if(x_z_display>1) x_z_display=0; break;
	default:
		printf("Press b - back fill; f - front fill; l - line; i - increment; or d - decrement; r - rotate; R - reset view\n");
	}

	glutPostRedisplay();
}
void minecraftStyle(int key, int x, int y)
{
	if (key == GLUT_KEY_F3)
	{
		F3pressed = !F3pressed;
		std::cout << "Current model : current_model_string=" << current_model_string << "\n";
	}
	glutPostRedisplay();

}

//======================================================
// DISPLAY CALL BACK ROUTINE 
//======================================================
void displayCallBack()	
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	if (F3pressed)
	{

		glColor3f(1,1,1);
		glRasterPos3f (-3.4, 2.85, 0);

		std::string displayString = "Current model : current_model_string=" + current_model_string;

		for(int i = 0; i < displayString.size() ; i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, displayString[i]);
		}
	}

	executeViewControl (yaw, pitch);
	drawAxesAndGridLines();

	switch(current_model)
	{
		case 1:
			drawS();
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
			drawS();
		glPolygonMode(GL_FRONT,GL_FILL);

		break;
		case 2:
			drawV();
		break;
		case 3:
			drawX();
		break;
		case 4:
			drawT();
		break;
		case 5:
			drawW();
		break;
		case 6:
			drawU();
		break;

		default:
			printf("Unknown model\n");
	}

	//Draw curve using code in 3DCurve.cpp
	/*glTranslatef(0,1.3,0);
	glScalef(0.75,0.75,0.75);
	draw3Dcurve  (1.0,          //depth
				  1.5,          //inner radius
				  2.0,          //outer radius
				  0.0,          //start angle //0.0
				  theta_stop1,  //stop angle
				  5.0);         //anular increments
glTranslatef(0,-3.5,0);
glRotatef(180,0,0,0);
	draw3Dcurve  (1.0,          //depth
				  1.5,          //inner radius
				  2.0,          //outer radius
				  0.0,          //start angle //0.0
				  theta_stop1,  //stop angle
				  5.0);*/

	glutSwapBuffers();
}

//======================================================
// MAIN PROGRAM
//======================================================
int main(int argc, char** argv)
{
   // Allow cmd line arguments to be passed to the glut
	glutInit(&argc, argv);

	// Create and name window
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Need both double buffering and z buffer
    glutInitWindowSize(600, 600);
    glutCreateWindow("Initials");

	// Add Display & Mouse CallBacks
	glutReshapeFunc(reshapeCallBack);
	glutDisplayFunc(displayCallBack);
	glutIdleFunc(NULL); // Starts the Idle Function as having no routine attached to it. This is modified in rotateView()
	glutMouseFunc(mouseClickCallBack);
    glutMotionFunc(mouseMotionCallBack);
	glutKeyboardFunc(keyboardCallBack);
	glutSpecialFunc(minecraftStyle);

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */

	// Print Application Usage
	printf("Program Controls:\n");
	printf("Left Mouse Button & Drag - Changes the View.\n");
	printf("Key \"b\" - Back Fill.\n");
	printf("Key \"f\" - Front Fill.\n");
	printf("Key \"l\" - Wire Frame/Line Fill.\n");
	printf("Key \"i\" - Increment Sections of Curve.\n");
	printf("Key \"d\" - Decrement Sections of Curve.\n");
	printf("Key \"r\" - Automated Rotation.\n");
	printf("Key \"R\" - Reset the View.\n");

	glutMainLoop();

	return 0;
}

