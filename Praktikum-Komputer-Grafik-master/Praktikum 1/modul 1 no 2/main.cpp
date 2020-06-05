#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display(){
	glClear (GL_COLOR_BUFFER_BIT);
   /* Nomor 2*/
	 glBegin(GL_POLYGON);
	 glColor3f (1.0, 0.0, 0.0);
	 glVertex3f (-1.0, -1.0, 0.0);
	 glVertex3f (1.0, -1.0, 0.0);
	 glColor3f (1.0, 0.5, 0.0);
	 glVertex3f (1.0, -0.75, 0.0);
	 glVertex3f (-1.0, -0.75, 0.0);
	 glEnd();

	 glBegin(GL_POLYGON);
	 glColor3f (1.0, 0.5, 0.0);
	 glVertex3f (-1.0, -0.75, 0.0);
	 glVertex3f (1.0, -0.75, 0.0);
	 glColor3f (1.0, 1.0, 0.0);
	 glVertex3f (1.0, -0.5, 0.0);
	 glVertex3f (-1.0, -0.5, 0.0);
	 glEnd();

	 glBegin(GL_POLYGON);
	 glColor3f (1.0, 1.0, 0.0);
	 glVertex3f (-1.0, -0.5, 0.0);
	 glVertex3f (1.0, -0.5, 0.0);
	 glColor3f (0.0, 1.0, 0.0);
	 glVertex3f (1.0, -0.25, 0.0);
	 glVertex3f (-1.0, -0.25, 0.0);
	 glEnd();

	 glBegin(GL_POLYGON);
	 glColor3f (0.0, 1.0, 0.0);
	 glVertex3f (-1.0, -0.25, 0.0);
	 glVertex3f (1.0, -0.25, 0.0);
	 glColor3f (0.0, 0.0, 1.0);
	 glVertex3f (1.0, 0.25, 0.0);
	 glVertex3f (-1.0, 0.25, 0.0);
	 glEnd();

	 glBegin(GL_POLYGON);
	 glColor3f (0.0, 0.0, 1.0);
	 glVertex3f (-1.0, 0.25, 1.0);
	 glVertex3f (1.0, 0.25, 0.0);
	 glColor3f (1.0, 0.0, 0.5);
	 glVertex3f (1.0, 0.5, 0.0);
	 glVertex3f (-1.0, 0.5, 0.0);
	 glEnd();

	 glBegin(GL_POLYGON);
	 glColor3f (1.0, 0.0, 0.5);
     glVertex3f (-1.0, 0.5, 0.0);
     glVertex3f (1.0, 0.5, 0.0);
     glColor3f (1.0, 0.0, 1.0);
     glVertex3f (1.0, 0.75, 0.0);
     glVertex3f (-1.0, 0.75, 0.0);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f (1.0, 0.0, 1.0);
     glVertex3f (-1.0, 0.75, 0.0);
     glVertex3f (1.0, 0.75, 0.0);
     glVertex3f (1.0, 1.0, 0.0);
     glVertex3f (-1.0, 1.0, 0.0);
     glEnd();

     glFlush ();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0,2.0,-2.0,2.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,1.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("horisontal 7 warna 7 rectangle GL_POLYGON");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();

	return 0;
}
