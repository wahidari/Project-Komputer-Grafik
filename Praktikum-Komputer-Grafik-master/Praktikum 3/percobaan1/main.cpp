#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
void garis_tengah (){
glBegin(GL_LINES);
glVertex2d(-10,0);
glVertex2d(10,0);
glVertex2d(0,10);
glVertex2d(0,-10);
glEnd();
glPointSize(4);
glBegin(GL_POINTS);
for(int x =-5 ; x<=6 ; x++){
    glVertex2d(x,0);
    glVertex2d(0,x);
}
glEnd();
}
void titik(float x , float y){
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
}
void nomor1(){
    titik(2,3);
    glTranslated(3,-4,0);
    glColor3f(1,0,0);
    titik(2,3);
}
void nomor2(){
    titik(3,3);
    glRotated(90.0,0,0,1);
    glColor3f(1,0,0);
    titik(3,3);
}
void nomor3(){
    titik(3,2);
    glScaled(2.0,1.5,0.0);
    glColor3f(1,0,0);
    titik(3,2);
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(1);
    garis_tengah();
     //nomor1();
  // nomor2();
   nomor3();

	glFlush();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10.0,10.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0,1.0,1.0,1.0);
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
