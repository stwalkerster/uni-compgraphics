// Author  : Simon Walker - Vasileios Spyridakis
// Date    : 22/11/2011
// Version : 3c975f816499732c2100c1ce0ce2842b9d617378
//
// Program behaviour:
// Mouse Button & Drag - Changes the View Point.
// Key "F3" - Toggle OSD
// Key "w"  - Wire Frame
// Key "f"  - Fill
// Key "a"  - Toggle animation
// Key "="  - Raise wings
// Key "-"  - Lower wings
// Key "R"  - Reset the View
// Key "m"  - Cycle models
// Key "p"  - Toggle prespective
// Key "l"  - Toggle lighting
// Key "x"  - Toggle x axis
// Key "y"  - Toggle y axis
// Key "z"  - Toggle z axis

#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "3DCurve.h"
#include "Cube.h"
#include "drawS.h"
#include "drawT.h"
#include "drawU.h"
#include "drawV.h"
#include "drawW.h"
#include "drawX.h"
#include "Ear.h"
#include "drawEyes.h"
#include "drawNose.h"
#include "drawOval.h"
#include "Ucube.h"
#include "wing.h"
#include "drawHead.h"
#include "test.h"
#include "drawFoot.h"
#include "drawBody.h"

#if defined WIN32
#include "stdafx.h"
#endif

#define NUMBER_OF_MODELS 19

//======================================================
// GLOBAL VARIABLES
//======================================================
static double theta_stop1 = 270;
float pitch = 0.0f;
float yaw = 0.0f;
float pitch0, yaw0;
bool MousePressed;
int mouseX0, mouseY0;
bool animation=false;
int current_model=19;
std::string current_model_string = "pig";
int x_y_display=0, y_z_display=0, x_z_display=0;
bool F3pressed=true;
bool rotateModel=true;
bool perspective=false;
int vpW=0, vpH=0;
bool lighting = false;
int wingAngle = 0;
int wingAngleIncrement = 1;
int wingAngleMax = 10;

//======================================================
// Prototypes
//======================================================

void help(void);

//======================================================
// DRAW AXES and GRIDS
//======================================================
void drawAxesAndGridLines(void)
{
	glDisable(GL_LIGHTING);

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
	if(lighting)
		glEnable(GL_LIGHTING);
}

void idleCallBack (){
	if(abs(wingAngle) < wingAngleMax) 
	{ // less
		wingAngle += wingAngleIncrement;
	}
	else
	{ // equal or above, 
		wingAngleIncrement *=-1;
		wingAngle += wingAngleIncrement;
	}
    glutPostRedisplay();
}

//======================================================
// VIEW CONTROL ROUTINES
//======================================================

void animateView(bool r){
	animation = r;
	if (r) glutIdleFunc(idleCallBack); else glutIdleFunc(NULL);
}

void resetView(){
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
			
			pitch0 = pitch; yaw0 = yaw;
			mouseX0 = x; mouseY0 = y;
			break;
		default:
		case GLUT_UP:
			MousePressed = false;
			//animateView(true);
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
	vpW=w;
	vpH=h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	if (w == 0 || h == 0) return;
    if(!perspective)
	{
		if (w <= h)
			glOrtho(-3.0, 3.0, -3.0 * (GLfloat) h / (GLfloat) w, 3.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
	    else
			glOrtho(-3.0 * (GLfloat) w / (GLfloat) h, 3.0 * (GLfloat) w / (GLfloat) h, -3.0, 3.0, -10.0, 10.0);
	}
	else
	{
		gluPerspective(60,w/h, 1, 10.0);
		gluLookAt(0,0,5, //eye
			0,0,0, // center
			0,1,0); // up
	}
	
    glMatrixMode(GL_MODELVIEW);
}

//======================================================
// KEYBOARD CALLBACK ROUTINE 
//======================================================
void keyboardCallBack(unsigned char key, int x, int y) {
	printf("Keyboard call back: key=%c, x=%d, y=%d\n", key, x, y);
	switch(key)
	{
	case 'f': case 'F':
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		break;
	case 'w': case 'W':
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		break;
	case 'l':
		lighting = !lighting;
		break;
	case 'a': 
		animation= !animation;
		animateView(animation);
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
			current_model_string="Cube";
		}
		else if (current_model == 2)
		{
			current_model_string="Curve";
		}
		else if (current_model == 3)
		{
			current_model_string="Letter S";
		}
		else if (current_model == 4)
		{
			current_model_string="Letter t";
		}
		else if (current_model == 5)
		{
			current_model_string="Letter u";
		}
		else if (current_model == 6)
		{
			current_model_string="Letter V";
		}
		else if (current_model == 7)
		{
			current_model_string="Letter w";
		}
		else if (current_model == 8)
		{
			current_model_string="Letter x";
		}
		else if (current_model == 9)
		{
			current_model_string="Ear";
		}
		else if (current_model == 10)
		{
			current_model_string="Eyes";
		}
		else if (current_model == 11)
		{
			current_model_string="Nose";
		}
		else if (current_model == 12)
		{
			current_model_string="Oval";
		}
		else if (current_model == 13)
		{
			current_model_string="Ucube slice";
		}
		else if (current_model == 14)
		{
			current_model_string="Wing segment";
		}
		else if (current_model == 15)
		{
			current_model_string="Head";
		}
		else if (current_model == 16)
		{
			current_model_string="Ucube";
		}
		else if (current_model == 17)
		{
			current_model_string="Wing";
		}
		else if (current_model == 18)
		{
			current_model_string="Foot";
		}
		else if (current_model == 19)
		{
			current_model_string="Pig";
		}
		break;
	case 't':
		current_model=0;
		current_model_string="Teapot";
		break;
	case 'p':
		perspective=!perspective;
		reshapeCallBack(vpW, vpH);
		break;
	case 'x': x_y_display++; if(x_y_display>1) x_y_display=0; break;
	case 'y': y_z_display++; if(y_z_display>1) y_z_display=0; break;
	case 'z': x_z_display++; if(x_z_display>1) x_z_display=0; break;
	case '=': if(wingAngle < wingAngleMax) wingAngle+=1;break;
	case '-': if((-wingAngle) < wingAngleMax) wingAngle-=1;break;
	default:
		help();
	}

	glutPostRedisplay();
}
void minecraftStyle(int key, int x, int y)
{
	if (key == GLUT_KEY_F3)
	{
		F3pressed = !F3pressed;
		std::cout << "Current model : " << current_model_string << "\n";
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

		glDisable(GL_LIGHTING);
		glColor3f(1,1,1);
		glRasterPos3f (-3.4, 2.85, 0);

		std::string displayString = "Current model : " + current_model_string;

		for(unsigned int i = 0; i < displayString.size() ; i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, displayString[i]);
		}
		glEnable(GL_LIGHTING);
	}

	GLfloat light0_position[] = {-2,2,2,1};
	GLfloat light0_diffuse[] = {0.7,0.7,0.7,1};
	GLfloat light0_specular[] = {0.9,0.9,0.9,1};
	GLfloat lightscene_ambience[] = {0.4,0.4,0.4,1};
	GLfloat material_specular[] = {1,1,1,1};

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lightscene_ambience);

	glLightfv(GL_LIGHT0,GL_POSITION, light0_position);
	glLightfv(GL_LIGHT0,GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0,GL_SPECULAR, light0_specular);
	glEnable(GL_LIGHT0);

	glMaterialfv(GL_FRONT,GL_SPECULAR,material_specular);
	glMaterialf(GL_FRONT,GL_SHININESS,25); 

	/*if(lighting)
	{
		glDisable(GL_LIGHTING);
		glColor3f(1,1,1);
		glBegin(GL_LINES);
		glVertex3f(0,0,0);
		glVertex3f(light0_position[0],light0_position[1],light0_position[2]);
		glEnd();
		glEnable(GL_LIGHTING);
	}*/
	
	executeViewControl (yaw, pitch);
	drawAxesAndGridLines();

	glColor3f(1,1,1);

	switch(current_model)
	{
		case 1:
			cube();
			break;
		case 2:
			draw3Dcurve  (1.0,          //depth  
					  1.5,          //inner radius
					  2.0,          //outer radius
					  0.0,          //start angle //0.0
					  270,  		//stop angle
					  5.0);         //anular increments
			break;
		case 3:
			drawS();
			break;
		case 4:
			drawT();
			break;
		case 5:
			drawU();
			break;
		case 6:
			drawV();
			break;
		case 7:
			drawW();
			break;
		case 8:
			drawX();
			break;
		case 9:
			drawEar();
			break;
		case 10:
			drawEyes();
			break;
		case 11:
			drawNose();
			break;
		case 12:
			drawOval();
			break;
		case 13:
			Ucube();
			break;
		case 14:
			wingseg();
			break;
		case 15:
			drawHead();
			break;
		case 16:
			test();
			break;
		case 17:
			glScalef(0.2,0.2,0.2);
			wing(5, wingAngle);
			break;
		case 18:
			drawFoot();
			break;
		case 19:
			drawBody();
			break;
		case 0:
			glColor3f(1,1,1);
			glutSolidTeapot(1);
			break;
		default:
			printf("Unknown model\n");
	}

	glLoadIdentity();
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
	glutIdleFunc(NULL); // Starts the Idle Function as having no routine attached to it. This is modified in animateView()
	glutMouseFunc(mouseClickCallBack);
    glutMotionFunc(mouseMotionCallBack);
	glutKeyboardFunc(keyboardCallBack);
	glutSpecialFunc(minecraftStyle);

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
	glEnable( GL_COLOR_MATERIAL );

	glEnable( GL_NORMALIZE);

	help();

	glutMainLoop();

	return 0;
}

void help()
{
	// Print Application Usage
	printf("Program Controls:\n");
	printf("Left Mouse Button & Drag - Changes the View.\n");
	printf("Key \"F3\" - Toggle OSD.\n");
	printf("Key \"w\"  - Wire Frame.\n");
	printf("Key \"f\"  - Fill.\n");
	printf("Key \"a\"  - Automated Rotation.\n");
	printf("Key \"=\"  - Raise wings\n");
	printf("Key \"-\"  - Lower wings\n");
	printf("Key \"R\"  - Reset the View.\n");
	printf("Key \"m\"  - Cycle models.\n");
	printf("Key \"p\"  - Toggle perspective.\n");
	printf("Key \"l\"  - Toggle lighting.\n");
	printf("Key \"x\"  - Toggle x axis\n");
	printf("Key \"y\"  - Toggle y axis\n");
	printf("Key \"z\"  - Toggle z axis\n");
	
}
