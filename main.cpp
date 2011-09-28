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
// MAIN PROGRAM 
//======================================================
int main(int argc, char **argv)
{
	// Create and Name window
	// Add Display & Mouse CallBacks
    	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Simon Walker's project!");
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
