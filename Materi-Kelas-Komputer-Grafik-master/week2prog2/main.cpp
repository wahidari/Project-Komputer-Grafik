#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(4);
//    glColor3f(1.0,0.0,0.0);
//	glBegin(GL_POLYGON);
//	glColor3f(1.0,0.0,0.0);
//	glVertex2f(-1.5,0.4);
//	glColor3f(0.0,1.0,0.0);
//    glVertex2f(-1.5,-0.4);
//    glColor3f(0.0,0.0,1.0);
//    glVertex2f(1.0,-0.4);
//	glVertex2f(1.0,0.4);
//	glVertex2f(-1.5,0.4);
//
//    glEnd();
     //glColor3f(0.3,0.5,0.1);
//    glBegin(GL_POLYGON);
//    glColor3f(1.0,0.0,0.0);
//	glVertex2f(1.0,-0.7);
//	glColor3f(0.0,0.0,1.0);
//	glVertex2f(1.7,0.0);
//	glColor3f(0.0,1.0,0.0);
//	glVertex2f(1.0,0.7);
//	glVertex2f(1.0,-0.7);


//    glVertex2f(-1.0,0.0);
//    glVertex2f(1.0,0.0);
//    glVertex2f(0.0,1.0);

	//glEnd();
	glRectf(-0.5,-0.5,0.5,0.5);

	glFlush();
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
	glutCreateWindow("Segitiga Titik");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();

	return 0;
}
