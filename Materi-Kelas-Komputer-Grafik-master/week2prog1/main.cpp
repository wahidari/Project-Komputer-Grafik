#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(8);
	//glPointSize();
	//diletakkan sebelum glbegin

	//glBegin(GL_LINE_STRIP);
	//glBegin(GL_LINES);//
	//glBegin(GL_LINE_LOOP);
	//glBegin(GL_POINTS);
	//memulai untuk menggambar apapun
	glVertex2f(0.0,1.7);
	glVertex2f(-1.0,1.0);
	glVertex2f(0.0,1.0);
	glVertex2f(1.0,1.0);
	glVertex2f(-1.0,0.0);
	glVertex2f(1.0,0.0);
	glVertex2f(-1.0,-1.0);
	glVertex2f(0.0,-1.0);
	glVertex2f(1.0,-1.0);
	//titik sudut dengan posisi sesuai nilai titik cartesius
	//dimensi pengaruh pad jumlah argumen
	glEnd();
	//mengakhiri

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
