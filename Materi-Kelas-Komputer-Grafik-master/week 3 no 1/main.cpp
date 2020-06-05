#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
//	glLineWidth(8);
//	//glPointSize();
//	//diletakkan sebelum glbegin
//
//	//glBegin(GL_LINE_STRIP);
//	//glBegin(GL_LINES);//
//	//glBegin(GL_LINE_LOOP);
//	glBegin(GL_POINTS);




//glBegin(GL_LINE_LOOP);
//glVertex2f(-1.8,-1.8);
//glVertex2f(0.0,-1.8);
//glVertex2f(0.0,0.0);
//glVertex2f(-0.9,1.0);
//glVertex2f(-1.8,0.0);
//glEnd();
//glBegin(GL_POLYGON);
//glEnd();
//glRectf(-1.5,-1.8,-1.2,-1.0);
//glEnd();
//glBegin(GL_POLYGON);
//glEnd();
//glRectf(-0.8,-1.0,-0.5,-0.7);
//glEnd();





//	//memulai untuk menggambar apapun
//	glVertex2f(0.0,1.7);
//	glVertex2f(-1.0,1.0);
//	glVertex2f(0.0,1.0);
//	glVertex2f(1.0,1.0);
//	glVertex2f(-1.0,0.0);
//	glVertex2f(1.0,0.0);
//	glVertex2f(-1.0,-1.0);
//	glVertex2f(0.0,-1.0);
//	glVertex2f(1.0,-1.0);
//	//titik sudut dengan posisi sesuai nilai titik cartesius
//	//dimensi pengaruh pad jumlah argumen
//	glEnd();
	//mengakhiri



//	glBegin(GL_POLYGON);
//    glColor3f (1.0, 0.0, 0.0);
//    glVertex3f (-1.5, -0.4, 0.0);
//    glColor3f (0.0, 0.0, 1.0);
//    glVertex3f (1.5, -0.4, 0.0);
//    glColor3f (0.0, 1.0, 0.0);
//    glVertex3f (1.5, 0.4, 0.0);
//    glColor3f (1.0, 0.0, 1.0);
//    glVertex3f (-1.5, 0.4, 0.0);
//    glEnd();
//    glBegin(GL_POLYGON);
//    glColor3f (1.0, 0.0, 1.0);
//    glVertex3f (-0.2, 0.6, 0.0);
//    glColor3f (0.0, 1.0, 0.0);
//    glVertex3f (0.2, 0.6, 0.0);
//    glColor3f (1.0, 0.5, 0.0);
//    glVertex3f (0.2, 1.0, 0.0);
//    glColor3f (1.0, 0.0, 0.0);
//    glVertex3f (-0.2, 1.0, 0.0);
//    glEnd();
//    glBegin(GL_POLYGON);
//    glColor3f (1.0, 0.6, 1.0);
//    glVertex3f (-0.2, -0.6, 0.0);
//    glColor3f (1.0, 0.0, 0.0);
//    glVertex3f (0.2, -0.6, 0.0);
//    glColor3f (1.0, 0.5, 0.0);
//    glVertex3f (0.2, -1.0, 0.0);
//    glColor3f (0.0, 1.0, 0.0);
//    glVertex3f (-0.2, -1.0, 0.0);
//    glEnd();




//BALOk balok
    glBegin(GL_POLYGON);//MERAH
    glEnd();
    glColor3f(1.0,0.0,0.0);
    glRectf(-1.5,-1.5,0.0,0.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(-1.5,-1.5);
    glVertex2f(0.0,-1.5);
    glVertex2f(0.0,0.0);
    glVertex2f(-1.5,0.0);
    glEnd();

    glBegin(GL_POLYGON);//HIJAU
    glColor3f(0.0,1.0,0.0);
    glVertex2f(-1.5,0.0);
    glVertex2f(0.0,0.0);
    glVertex2f(0.4,0.4);
    glVertex2f(-1.0,0.4);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(-1.5,0.0);
    glVertex2f(0.0,0.0);
    glVertex2f(0.4,0.4);
    glVertex2f(-1.0,0.4);
    glEnd();

    glBegin(GL_POLYGON);//KUNING
    glColor3f(1.0,1.0,0.0);
    glVertex2f(0.0,-1.5);
    glVertex2f(0.4,-1.0);
    glVertex2f(0.4,0.4);
    glVertex2f(0.0,0.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(0.0,-1.5);
    glVertex2f(0.4,-1.0);
    glVertex2f(0.4,0.4);
    glVertex2f(0.0,0.0);
    glEnd();


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
	glutInitWindowPosition(400,150);
	glutCreateWindow("Segitiga Titik");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();

	return 0;
}
