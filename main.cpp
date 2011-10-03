#include <GL/glut.h>
#include <math.h>
 
#include "functions.h"

float xPos = 0.0;
float yPos = 50.0;
float road = 50.0;
double angle = 0.0;
int DELAY = 15;
int ms = 10;


void reshape(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	gluOrtho2D(0.0,(GLdouble)w, 0.0, (GLdouble)h);
}

void renderScene(void) {

	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0,0);
	glBegin(GL_POINTS);
		for(int i = 0;i < glutGet(GLUT_WINDOW_WIDTH);i++){
			glVertex2f(i,6* sin(i*0.2)+(road-20));
		}
	glEnd();

	glColor3f(0.5,1.0,0.0);
	glBegin(GL_QUADS);
		glVertex3f(xPos,yPos,0.0);
		glVertex3f(xPos,yPos+20,0.0);
		glVertex3f(xPos+97,yPos+20,0.0);
		glVertex3f(xPos+97,yPos,0.0);
	glEnd();

	glBegin(GL_QUADS);
		glVertex2f(xPos+57,yPos+20);
		glVertex2f(xPos+57,yPos+42);
		glVertex2f(xPos+67,yPos+42);
		glVertex2f(xPos+75,yPos+20);
	glEnd();

	glColor3f(0.0,0.5,0.3);
	int wheel1[] = {xPos+15,yPos-10,xPos+25,yPos,xPos+35,yPos-10,xPos+25,yPos-20}; 
	glBegin(GL_QUADS);
		for(int i = 0;i < 8;i+=2){
			glVertex2f(wheel1[i],wheel1[i+1]);
		}
	glEnd();

	int wheel2[] = {xPos+65,yPos-10,xPos+75,yPos,xPos+85,yPos-10,xPos+75,yPos-20};
	glBegin(GL_QUADS);
		for(int i = 0;i < 8;i+=2){
			glVertex2f(wheel2[i],wheel2[i+1]);
		}
	glEnd();

	int* circle = drawCircle(0.5,0.5);
	

	glBegin(GL_TRIANGLES);
		for(int i = 0;i < 6; i+= 2){
			glVertex2f(i,i+1);
		}
	glEnd();

	//glRotatef(angle*0.1,0,0,0.5);

	if(xPos < 32000)
		xPos = xPos+0.5;
		yPos += cos(angle);
		angle += 0.1;
	glutSwapBuffers();
}

void animate(int val){
	glutTimerFunc(DELAY,animate,0);
	glutTimerFunc(ms,animate,0);

	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0,0);
	glBegin(GL_POINTS);
		for(int i = 0;i < glutGet(GLUT_WINDOW_WIDTH);i++){
			glVertex2f(i,6* sin(i*0.2)+(road-20));
		}
	glEnd();

	glColor3f(0.5,1.0,0.0);
	glBegin(GL_QUADS);
		glVertex3f(xPos,yPos,0.0);
		glVertex3f(xPos,yPos+20,0.0);
		glVertex3f(xPos+97,yPos+20,0.0);
		glVertex3f(xPos+97,yPos,0.0);
	glEnd();

	glBegin(GL_QUADS);
		glVertex2f(xPos+57,yPos+20);
		glVertex2f(xPos+57,yPos+42);
		glVertex2f(xPos+67,yPos+42);
		glVertex2f(xPos+75,yPos+20);
	glEnd();

	glColor3f(0.0,0.5,0.3);
	int wheel1[] = {xPos+15,yPos-10,xPos+25,yPos,xPos+35,yPos-10,xPos+25,yPos-20}; 
	glBegin(GL_QUADS);
		for(int i = 0;i < 8;i+=2){
			glVertex2f(wheel1[i],wheel1[i+1]);
		}
	glEnd();

	int wheel2[] = {xPos+65,yPos-10,xPos+75,yPos,xPos+85,yPos-10,xPos+75,yPos-20};
	glBegin(GL_QUADS);
		for(int i = 0;i < 8;i+=2){
			glVertex2f(wheel2[i],wheel2[i+1]);
		}
	glEnd();

	int* circle = drawCircle(0.5,0.5);
	

	glBegin(GL_TRIANGLES);
		for(int i = 0;i < 6; i+= 2){
			glVertex2f(i,i+1);
		}
	glEnd();

	//glRotatef(angle*0.1,0,0,0.5);

	if(xPos < 32000)
		xPos = xPos+0.5;
		yPos += cos(angle);
		angle += 0.1;
	glutSwapBuffers();
}

void mouse(int a, int button, int x, int y){
	switch(button){
	case GLUT_LEFT_BUTTON:
		xPos = x;
		break;
	default:
		break;
	}
}

void main(int argc, char **argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(320,320);
	glutCreateWindow("Lighthouse3D- GLUT Tutorial");



	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(reshape);
	//glutIdleFunc(renderScene);
	//glutTimerFunc(DELAY,animate,0);
	glutTimerFunc(ms,animate,0);
	glutMouseFunc(mouse);

	// enter GLUT event processing cycle
	glutMainLoop();
}