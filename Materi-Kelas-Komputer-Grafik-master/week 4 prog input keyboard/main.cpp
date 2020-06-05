#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

bool a=false;

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(4);

	glBegin(GL_POLYGON);
	glVertex2f(-1.0,-1.0);
	glVertex2f(1.0,-1.0);
	glVertex2f(0.0,1.0);
	glEnd();

	glFlush();
}
void input(unsigned char key, int x, int y){
    if(key=='c' || key=='C'){
        if(a==true){
            glColor3f(1.0,0.0,0.0);
            a==true;
        }
        else{
            glColor3f(0.0,0.0,1.0);
            a==false;
        }
        display();
    }
}
void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0,2.0,-2.0,2.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,1.0,0.0);
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
