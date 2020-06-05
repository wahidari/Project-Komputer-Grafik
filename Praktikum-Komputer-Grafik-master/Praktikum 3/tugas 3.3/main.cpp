/*
 TUGAS PRAKTIKUM KOMPUTER GRAFIK MODUL 3 NO 2 Buat snow flake (bunga salju) berikut menggunakan transformasi.
 */
#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>

void salju(){
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.0,0.0);
    glVertex2f(2.0,0.0);
    glVertex2f(3.0,1.5);
    glVertex2f(3.5,1.5);
    glVertex2f(2.5,0.0);

    glVertex2f(4.5,0.0);
    glVertex2f(5.4,1.0);
    glVertex2f(5.9,1.0);
    glVertex2f(5.0,0.0);

    glVertex2f(7.0,0.0);
    glVertex2f(7.6,0.7);
    glVertex2f(8.1,0.7);
    glVertex2f(7.5,0.0);

    glVertex2f(8.7,0.0);
    glVertex2f(9.5,-0.2);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    salju();
    glTranslatef(0,-0.4,0);
    glScalef(1,-1,1);
    salju();

    glTranslatef(0,0,0);
    glScalef(1,-1,1);
    glRotated(-60,0,0,1);
    salju();

    glTranslatef(0,-0.4,0);
    glScalef(1,-1,1);
    glRotated(0,0,0,1);
    salju();

    glTranslatef(0,0,0);
    glScalef(1,-1,1);
    glRotated(-60,0,0,1);
    salju();

    glTranslatef(0,-0.4,0);
    glScalef(1,-1,1);
    glRotated(0,0,0,1);
    salju();

    glTranslatef(0,0,0);
    glScalef(1,-1,1);
    glRotated(-60,0,0,1);
    salju();

    glTranslatef(0,-0.4,0);
    glScalef(1,-1,1);
    glRotated(0,0,0,1);
    salju();

    glTranslatef(0,0,0);
    glScalef(1,-1,1);
    glRotated(-60,0,0,1);
    salju();

    glTranslatef(0,-0.4,0);
    glScalef(1,-1,1);
    glRotated(0,0,0,1);
    salju();

    glTranslatef(0,0,0);
    glScalef(1,-1,1);
    glRotated(-60,0,0,1);
    salju();

    glTranslatef(0,-0.4,0);
    glScalef(1,-1,1);
    glRotated(0,0,0,1);
    salju();

    glFlush();
}

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10.0,10.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.0,0.0,0.0);

}



int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400,400);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("Garis Sejajar Sumbu X");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();

	return 0;
}
