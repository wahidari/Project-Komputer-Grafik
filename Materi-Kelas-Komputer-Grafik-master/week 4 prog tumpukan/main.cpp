#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(4);

	glBegin(GL_POLYGON);
//
//	glColor3f(0.0,0.0,1.0);
	glVertex2f(-0.5,0.0);
	glVertex2f(1.0,0.0);
	glVertex2f(1.0,-1.0);
	glVertex2f(0.0,-1.3);
	glVertex2f(-0.5,-1.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0,0.0,0.0);
	glVertex2f(-0.6,-0.1);
	glVertex2f(0.9,-0.1);
	glVertex2f(0.9,-1.1);
	glVertex2f(-0.1,-1.4);
	glVertex2f(-0.6,-1.1);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.0,1.0,0.0);
	glVertex2f(-0.7,-0.2);
	glVertex2f(0.8,-0.2);
	glVertex2f(0.8,-1.2);
	glVertex2f(-0.2,-1.5);
	glVertex2f(-0.7,-1.2);
	glEnd();

	glFlush();
}
void input(unsigned char key, int x, int y){
    if(key=='c' || key=='C'){
        glColor3f(1.0,1.0,0.0);
        display();
    }
    if(key=='v'){
        glColor3f(0.0,1.0,0.0);
        display();
    }
    if(key=='b'){
        glColor3f(0.0,1.0,1.0);
        display();
    }
    if(key=='n'){
        glColor3f(1.2,1.9,0.0);
        display();
    }
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0,2.0,-2.0,2.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.0,0.0,1.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("Segitiga Titik");
	glutDisplayFunc(display);
	glutKeyboardFunc(input);
	myinit();
	glutMainLoop();

	return 0;
}

