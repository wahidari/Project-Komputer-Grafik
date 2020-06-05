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
void a(){
    glColor3f(1.0,1.0,0.0);
	glRecti(0,0, 1, 1);
	glTranslated(1.0, 1.0, 0);
	glRecti(0,0, 1, 1);
	glTranslated(1.0, 1.0, 0);
	glRecti(0,0, 1, 1);
	glTranslated(1.0, 1.0, 0);
	glRecti(0,0, 1, 1);
	glTranslated(1.0, 1.0, 0);
	glRecti(0,0, 1, 1);
	glTranslated(1.0, 1.0, 0);
	glRecti(0,0, 1, 1);
	glTranslated(1.0, 1.0, 0);
	glRecti(0,0, 1, 1);
	glTranslated(1.0, 1.0, 0);
	glRecti(0,0, 1, 1);
	glEnd();
}

void b(){
    glColor3f(0.0,0.0,1.0);
	glRecti(1,0, 2, 1);
	glTranslated(-1.0, -1.0, 0);
	glRecti(1,0, 2, 1);
	glTranslated(-1.0, -1.0, 0);
	glRecti(1,0, 2, 1);
	glTranslated(-1.0, -1.0, 0);
	glRecti(1,0, 2, 1);
	glTranslated(-1.0, -1.0, 0);
	glRecti(1,0, 2, 1);
	glTranslated(-1.0, -1.0, 0);
	glRecti(1,0, 2, 1);
	glTranslated(-1.0, -1.0, 0);
	glRecti(1,0, 2, 1);
	glTranslated(-1.0, -1.0, 0);
	glRecti(1,0, 2, 1);
}
void c(){
    glColor3f(0.0,0.0,1.0);
	glRecti(3,0, 4, 1);
	glTranslated(1.0, 1.0, 0);
	glRecti(3,0, 4, 1);
	glTranslated(1.0, 1.0, 0);
	glRecti(3,0, 4, 1);
	glTranslated(1.0, 1.0, 0);
	glRecti(3,0, 4, 1);
	glTranslated(1.0, 1.0, 0);
	glRecti(3,0, 4, 1);
}
void d(){
    glColor3f(0.0,0.0,1.0);
	glRecti(5,0, 6, 1);
	glTranslated(-1.0, -1.0, 0);
	glRecti(5,0, 6, 1);
	glTranslated(-1.0, -1.0, 0);
	glRecti(5,0, 6, 1);
	glTranslated(-1.0, -1.0, 0);
	glRecti(5,0, 6, 1);
	glTranslated(-1.0, -1.0, 0);
	glRecti(5,0, 6, 1);
}
void e(){
    glColor3f(0.0,0.0,1.0);
	glRecti(7,0, 8, 1);
	glTranslated(1.0, 1.0, 0);
	glRecti(7,0, 8, 1);
}
void f(){
    glColor3f(0.0,0.0,1.0);
    glTranslated(-1.0, -1.0, 0);
	glRecti(0,1, 1, 2);
	glTranslated(1.0, 1.0, 0);
	glRecti(0,1, 1, 2);
	glTranslated(1.0, 1.0, 0);
	glRecti(0,1, 1, 2);
	glTranslated(1.0, 1.0, 0);
	glRecti(0,1, 1, 2);
	glTranslated(1.0, 1.0, 0);
	glRecti(0,1, 1, 2);
	glTranslated(1.0, 1.0, 0);
	glRecti(0,1, 1, 2);
	glTranslated(1.0, 1.0, 0);
	glRecti(0,1, 1, 2);
}

void g(){
    glColor3f(0.0,0.0,1.0);
    glTranslated(-2.0, -2.0, 0);
	glRecti(0,3, 1, 4);
	glTranslated(-1.0, -1.0, 0);
	glRecti(0,3, 1, 4);
	glTranslated(-1.0, -1.0, 0);
	glRecti(0,3, 1, 4);
	glTranslated(-1.0, -1.0, 0);
	glRecti(0,3, 1, 4);
	glTranslated(-1.0, -1.0, 0);
	glRecti(0,3, 1, 4);
}
void h(){
    glColor3f(0.0,0.0,1.0);
	glRecti(0,5, 1, 6);
	glTranslated(1.0, 1.0, 0);
	glRecti(0,5, 1, 6);
	glTranslated(1.0, 1.0, 0);
	glRecti(0,5, 1, 6);
	glTranslated(-2.0, -2.0, 0);
	glRecti(0,7, 1, 8);
}
void i(){
    glColor3f(1.0,1.0,0.0);
	glRecti(2,0, 3, 1);
	glTranslated(1.0, 1.0, 0);
	glRecti(2,0, 3, 1);
	glTranslated(1.0, 1.0, 0);
	glRecti(2,0, 3, 1);
	glTranslated(1.0, 1.0, 0);
	glRecti(2,0, 3, 1);
	glTranslated(1.0, 1.0, 0);
	glRecti(2,0, 3, 1);
	glTranslated(1.0, 1.0, 0);
	glRecti(2,0, 3, 1);
}
void j(){
    glColor3f(1.0,1.0,0.0);
    glTranslated(-2.0, -2.0, 0);
	glRecti(4,0, 5, 1);
	glTranslated(-1.0, -1.0, 0);
	glRecti(4,0, 5, 1);
	glTranslated(-1.0, -1.0, 0);
	glRecti(4,0, 5, 1);
	glTranslated(-1.0, -1.0, 0);
	glRecti(4,0, 5, 1);
	glTranslated(0.0, 0.0, 0);
	glRecti(6,0, 7, 1);
	glTranslated(1.0, 1.0, 0);
	glRecti(6,0, 7, 1);
}
void k(){
    glColor3f(1.0,1.0,0.0);
    glTranslated(-1.0, -1.0, 0);
	glRecti(0,2, 1, 3);
    glTranslated(1.0, 1.0, 0);
	glRecti(0,2, 1, 3);
	glTranslated(1.0, 1.0, 0);
	glRecti(0,2, 1, 3);
	glTranslated(1.0, 1.0, 0);
	glRecti(0,2, 1, 3);
	glTranslated(1.0, 1.0, 0);
	glRecti(0,2, 1, 3);
	glTranslated(1.0, 1.0, 0);
	glRecti(0,2, 1, 3);
	glTranslated(-2.0, -2.0, 0);
	glRecti(0,4, 1, 5);
	glTranslated(-1.0, -1.0, 0);
	glRecti(0,4, 1, 5);
	glTranslated(-1.0, -1.0, 0);
	glRecti(0,4, 1, 5);
	glTranslated(-1.0, -1.0, 0);
	glRecti(0,4, 1, 5);
	glTranslated(0.0, 0.0, 0);
	glRecti(0,6, 1, 7);
	glTranslated(1.0, 1.0, 0);
	glRecti(0,6, 1, 7);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	a();
	b();
	c();
	d();
	e();
	f();
	g();
	h();
	i();
	j();
	k();

	glFlush();
}

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,8.0,0.0,8.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0,1.0,1.0,1.0);
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
