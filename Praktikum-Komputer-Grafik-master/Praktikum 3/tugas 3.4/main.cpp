/*
 TUGAS PRAKTIKUM KOMPUTER GRAFIK MODUL 3 NO 1 Buat checker board 8 x 8 kotak dengan menggunakan glTranslate.
 */
#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>

void bintang(){
    //luar
    glBegin(GL_LINE_STRIP);
    glVertex2f(-1.6,-0.1);
    glVertex2f(0.0,5.0);
    glVertex2f(1.1,1.55);
    glEnd();
    //dalam
    glBegin(GL_LINE_STRIP);
    glVertex2f(-1.1,-0.35);
    glVertex2f(0.0,3.2);
    glVertex2f(0.5,1.55);
    glEnd();

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    bintang();
    glRotated(-72,0,0,1);
    bintang();
    glRotated(-72,0,0,1);
    bintang();
    glRotated(-72,0,0,1);
    bintang();
    glRotated(-72,0,0,1);
    bintang();
    glFlush();
}

void myinit()
{
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
	glutInitWindowSize(400,400);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("Garis Sejajar Sumbu X");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();

	return 0;
}
