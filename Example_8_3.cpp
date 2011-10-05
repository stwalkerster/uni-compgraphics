// Example_8_3.cpp : Mechanical Arm Example
//
// Author  : Mike Chantler
// Date    : 18/03/2007
// Version : 1.0
//
// This program shows how to use a hierarchical model to save a great deal of problems when
// attempting to rotate a model at different points (in this case, at each arm joint)
//
// Program behaviour:
// Key 'u/U' : Moves Finger 1 Up/Down
// Key 'i/I' : Moves Finger 2 Up
// Key 'o/O' : Moves Finger 3 Up
// Key 'f/F' : Toggle Floor On/Off
// Key 'm/M' : Cycles through different models
// Key 'r'   : Rotates arm at the base.
// Key 'R'   : Resets the view
// Key 'p/P' : Angles Palm Up/Down
// Key 'z/Z' : Zooms view Out/In
// Key 'x/y/X' : Toggles Grid for the X/Y/Z Axis
//
// Callback commentary sent to normal command window.
//
// Last tested in Visual C++ 2010 Express 

//#include "stdafx.h"
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#include "cube.h"

//Hand size parameters
#define LENGTH_FOREARM 3
#define WIDTH_FOREARM 1.5
#define LENGTH_PALM 2
#define LENGTH_FINGER 1.5
#define THICKNESS_FINGER 0.2

//Number of models & grids
#define NUMBER_OF_MODELS 5 


//======================================================
// GLOBAL VARIABLES 
//======================================================

//for model, floor and grid display
int current_model=1;
int dont_display_floor=1; 
int x_y_display=0, y_z_display=0, x_z_display=0;

//for view control
static float G_theta[3]; // View X,Y,Z
static float G_zoom=0.3;

bool MousePressed; // Used in Mouse Drag to change the Viewpoint
float pitch0, yaw0;
int mouseX0, mouseY0;

//for articulation of hand
static float G_hand_rot=0, G_palm_angle=10.0, G_f1_angle=0, G_f2_angle=0, G_f3_angle=0;

//======================================================
// PROTOTYPES 
//======================================================

void drawScene(float hand_rot, float palm_angle, float f1_angle, float f2_angle, float f3_angle);
void drawForearm();
void viewControl();
void drawFloor();
void drawForearmPalmFingers(float palm_angle, float f1_angle, float f2_angle, float f3_angle);
void drawPalmFingers(float f1_angle, float f2_angle, float f3_angle);
void drawFinger();
void drawFingerTip();
void action(unsigned char key);
void menuCallback (int id);

//======================================================
// DRAW AXES and GRIDS
//======================================================
void drawAxesAndGridLines(void)
{
	float offset; int gd;
	glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		glVertex3f(-20, 0, 0);					
		glVertex3f(+20, 0, 0);					
		glVertex3f( 0 ,-20, 0);				    	
		glVertex3f(	0, +20, 0);
		glVertex3f( 0, 0,-20);				    	
		glVertex3f(	0, 0, +20);

	glEnd();
	
	glLineStipple(1, 0xAAAA); //line style = fine dots
	glEnable(GL_LINE_STIPPLE);

	glBegin(GL_LINES);
		
		if (x_y_display) {glColor3f(0.0,0.7,0.7);
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
// DRAW_FLOOR
//======================================================
void drawFloor()
{
	if (dont_display_floor) return; 
	//Just draw a square for the floor
	glPushMatrix(); 
		glTranslatef(0, -0.05, 0); //draw slightly below y=0 so we can see grid
		glBegin(GL_POLYGON);
			glColor3f(.75,.75,.75);
			glVertex3f(-10,0,10);
			glVertex3f(-10,0,-10);
			glVertex3f(10,0,-10);
			glVertex3f(10,0,10);
		glEnd();
	glPopMatrix();
}

//======================================================
// DRAW_SCENE 
//======================================================
void drawScene(float hand_rot, float palm_angle, float f1_angle, float f2_angle, float f3_angle)
{
	drawAxesAndGridLines();
	drawFloor();
	
	// Rotate and Draw hand
	glPushMatrix();	

	//glTranslate //No translation
	glRotatef(hand_rot, 0.0, 1.0, 0.0); //Rotate complete model about y-axis
	//glScale //No scaling

	switch(current_model)
	{
		case 1: 
			drawForearmPalmFingers(palm_angle, f1_angle, f2_angle, f3_angle);
			printf("Model = forearm_palm_fingers\n");
		break;
		case 2: 
			cube(); printf("Model = cube\n");
		break;
		case 3: 
			drawFinger(); printf("Model = finger\n");
		break;
		case 4: 
			drawPalmFingers(f1_angle, f2_angle, f3_angle);
			printf("Model =  palm_fingers\n");
		break;
		case 5: 
			drawForearm(); printf("Model = forearm\n");
		break;

		default:
			printf("Unknown model\n");
	}

	glPopMatrix();
}


//======================================================
// DRAW_FOREARM_PALM_FINGERS
//======================================================
void drawForearmPalmFingers(float palm_angle, float f1_angle, float f2_angle, float f3_angle)
{
	drawForearm();

	// Position/draw palm & fingers
	glPushMatrix();
		glTranslatef(LENGTH_FOREARM/2.0, 0.5, 0.0);      // draw at end of forearm 
		glRotatef(palm_angle, 0.0, 0.0, 1.0); //rotate palm
		//glScale                             //no scaling
		drawPalmFingers(f1_angle, f2_angle, f3_angle);
	glPopMatrix();
}

//======================================================
// DRAW_FOREARM
//======================================================
void drawForearm()
{
	glPushMatrix();
		glTranslatef(0,0.25,0.0); // move base up so that bottom face is at origin		
		//No glRotate 
		glScalef(LENGTH_FOREARM, 0.5, WIDTH_FOREARM);
		cube();
	glPopMatrix();
}


//======================================================
// DRAW_PALM_FINGERS
//======================================================
void drawPalmFingers(float f1_angle, float f2_angle, float f3_angle)
{
	glPushMatrix();
		//draw palm
		glPushMatrix();
			glTranslatef(LENGTH_PALM/2.0, -0.25, 0.0);
			//No glRotate
			glScalef(LENGTH_PALM, 0.5, 1.0); 
			cube();
		glPopMatrix();
		
		//draw first finger
		glPushMatrix();
			glTranslatef(LENGTH_PALM, 0, 0.5); // move to end of palm
			glRotatef(f1_angle, 0.0, 0.0, 1.0);
			drawFinger();
		glPopMatrix();

		//draw second finger
		glPushMatrix();
			glTranslatef(LENGTH_PALM, 0, 0); // move to end of palm
			glRotatef(f2_angle, 0.0, 0.0, 1.0);
			drawFinger();
		glPopMatrix();

		//draw third finger
		glPushMatrix();
			glTranslatef(LENGTH_PALM, 0, -0.5); // move to end of palm
			glRotatef(f3_angle, 0.0, 0.0, 1.0);
			drawFinger();
		glPopMatrix();

	glPopMatrix();
}

//======================================================
// DRAW_FINGER
//======================================================
void drawFinger()
{
	glPushMatrix();
		glTranslatef(LENGTH_FINGER/2.0, -1*THICKNESS_FINGER/2.0, 0);
		glScalef(LENGTH_FINGER, THICKNESS_FINGER, THICKNESS_FINGER);
		cube();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(LENGTH_FINGER, 0, 0);
		glRotatef(-20, 0.0, 0.0, 1.0);
		drawFingerTip();
	glPopMatrix();
}


//======================================================
// DRAW_FINGER_TIP
//======================================================
void drawFingerTip()
{
		glTranslatef(LENGTH_FINGER/2, -1*THICKNESS_FINGER/2.0, 0);
		glScalef(LENGTH_FINGER, THICKNESS_FINGER, THICKNESS_FINGER);
		cube();
}

//======================================================
// LOAD MENU ROUTINE 
//======================================================
void loadMenu()
{
	// This is the menu shown when you right click on the program display.
	glutCreateMenu(menuCallback);
	glutAddMenuEntry("Complete model[m]", 1);
	glutAddMenuEntry("Cube model[m]", 2);
	glutAddMenuEntry("Finger model[m]", 3);
	glutAddMenuEntry("Palm_finger model[m]", 4);
	glutAddMenuEntry("Palm model[m]", 5);
	glutAddMenuEntry("Floor(f)", 'f');
	glutAddMenuEntry("Reset view(R)", 'R');
	glutAddMenuEntry("Zoom out(z)", 'z');
	glutAddMenuEntry("Zoom in(Z)", 'Z');
	glutAddMenuEntry("Toggle x-y grid", 'x');
	glutAddMenuEntry("Toggle y-z grid", 'y');
	glutAddMenuEntry("Toggle x-z grid", 'X');

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

//======================================================
// MENU CALLBACK ROUTINE 
//======================================================
void menuCallback (int id) {
  switch (id) {
  case 1: case 2: case 3: case 4: case 5: 
	  current_model=id;  
	  glutPostRedisplay();
  break;
  default: action (id);
  }
}


//======================================================
// KEYBOARD CALLBACK ROUTINES 
//======================================================
void keyboardCallBack(unsigned char key, int x, int y)
{
	printf("Keyboard call back: key=%c, x=%d, y=%d\n", key, x, y);
	action (key);
}

void action(unsigned char key)
{
	switch(key)
	{
	//JOINT 1
	case 'u': G_f1_angle+=10; break;
	case 'U': G_f1_angle-=10; break;

	//JOINT 2
	case 'i': G_f2_angle+=10; break;
	case 'I': G_f2_angle-=10; break;

	//JOINT 3
	case 'o': G_f3_angle+=10; break;
	case 'O': G_f3_angle-=10; break;

	//Floor selection
	case 'f': case 'F':
		dont_display_floor++;
		if (dont_display_floor > 1) dont_display_floor = 0;
	break;

	//Model selection
	case 'm': case 'M':
		current_model++;
		if (current_model > NUMBER_OF_MODELS) current_model = 1;
	break;

	//Palm angle
	case 'p': G_palm_angle+=10; break;
	case 'P': G_palm_angle-=10; break;

	//Base rotation
	case 'r': G_hand_rot+=10; break;

	//Reset view angles
	case 'R': G_hand_rot=G_theta[0]=G_theta[1]=G_theta[2]=0; break; 

	//ZOOM
	case 'z': G_zoom/=1.5; break;
	case 'Z': G_zoom*=1.5; 	break;

	//GRIDS
	case 'x': x_y_display++; if(x_y_display>1) x_y_display=0; break;
	case 'y': y_z_display++; if(y_z_display>1) y_z_display=0; break;
	case 'X': x_z_display++; if(x_z_display>1) x_z_display=0; break;

	default: printf("Unknown input");
	}
	glutPostRedisplay();

}


//======================================================
// MOUSE CALLBACK ROUTINES
//======================================================

void mouseMotionCallBack(int x, int y) 
{
	// Called when the Mouse is moved with left button down
	G_theta[0] = pitch0 + (y - mouseY0);
    G_theta[1] = yaw0 + (x - mouseX0);
	glutPostRedisplay();
} 

void mouseClickCallBack(int button, int state, int x, int y) 
{
	// Called on button press or release
    switch (state)
    {
		case GLUT_DOWN:
			MousePressed = true;
			pitch0 = G_theta[0]; 
			yaw0 = G_theta[1];
			mouseX0 = x; mouseY0 = y;
			break;
		default:
		case GLUT_UP:
			MousePressed = false;
			break;
    }
} 


//======================================================
// DISPLAY RESHAPE CALLBACK ROUTINE 
//======================================================
void reshapeCallBack(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		if (w <= h)
			glOrtho(-2.0, 2.0, -2.0 * (float) h / (float) w,
				2.0 * (float) h / (float) w, -10.0, 10.0);
		else
			glOrtho(-2.0 * (float) w / (float) h,
				2.0 * (float) w / (float) h, -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}


//======================================================
// DISPLAY CALLBACK ROUTINE 
//======================================================
void displayCallBack(void)
{
	// display callback,
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	viewControl();
	drawScene(G_hand_rot, G_palm_angle, G_f1_angle, G_f2_angle, G_f3_angle);

	glFlush();
	glutSwapBuffers();
}

//======================================================
// VIEW CONTROL ROUTINE 
//======================================================
void viewControl()
{
	// Reset matrix
	glLoadIdentity();

	//Rotate everything 
	glRotatef(G_theta[0], 1.0, 0.0, 0.0);
	glRotatef(G_theta[1], 0.0, 1.0, 0.0);
	glRotatef(G_theta[2], 0.0, 0.0, 1.0);

	//zoom (NB glOrtho projection)
	glScalef(G_zoom,G_zoom,G_zoom);
}

//======================================================
// MAIN PROGRAM 
//======================================================
int main(int argc, char **argv)
{
	// Create and Name window
	// Add Display & Mouse CallBacks
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Example 8.3 - Mechanical Hand Demo");
	glutReshapeFunc(reshapeCallBack);
	glutDisplayFunc(displayCallBack);
	glutIdleFunc(NULL);
	glutMouseFunc(mouseClickCallBack);
    glutMotionFunc(mouseMotionCallBack);
	glutKeyboardFunc(keyboardCallBack);

	loadMenu();

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	//glEnableClientState(GL_COLOR_ARRAY); 
	//glEnableClientState(GL_VERTEX_ARRAY);
	//glVertexPointer(3, GL_FLOAT, 0, vertices);
    //glColorPointer(3,GL_FLOAT, 0, colors); 
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */

	// Print Application Usage
	printf("Program Controls:\n");
	printf("Left Mouse Button & Drag - Changes the View.\n");
	printf("Key 'u/U' : Moves Finger 1 Up/Down.\n");
	printf("Key 'i/I' : Moves Finger 2 Up.\n");
	printf("Key 'o/O' : Moves Finger 3 Up.\n");
	printf("Key 'f/F' : Toggle Floor On/Off.\n");
	printf("Key 'm/M' : Cycles through different models.\n");
	printf("Key 'r'   : Rotates arm at the base.\n");
	printf("Key 'R'   : Resets the view.\n");
	printf("Key 'p/P' : Angles Palm Up/Down.\n");
	printf("Key 'z/Z' : Zooms view Out/In.\n");
	printf("Key 'x/y/X' : Toggles Grid for the X/Y/Z Axis.\n");
	glutMainLoop();
	return 0;
}
