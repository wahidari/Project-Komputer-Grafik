/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(4);

	glBegin(GL_LINES);
	glVertex2f(-10.0,0.0);
	glVertex2f(10.0,0.0);
	glVertex2f(0.0,10.0);
	glVertex2f(0.0,-10.0);
	glEnd();

    glColor3f(1,0,0);
	glBegin(GL_LINE_STRIP);
    for(float t = -1.0; t<=1.0; t+=0.01){
            for(float s=1.0;s>=-1.0; s-=0.01){
        /* x(t) = -1 + 2t; y(t) = 0 */
        glVertex3f (t, s, 0.0);
        }
    }
	glEnd();


	glFlush();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10.0,10.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.0,0.0,1.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("Garis Sejajar Sumbu X");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();

	return 0;
}
