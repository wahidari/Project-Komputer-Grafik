#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>

    float h =0.0;
    float v =0.0;
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_STRIP);
    for (float x=-3; x<=3; x+=0.01) {
        glVertex2f (x, 2*x+1);
    }
    glEnd();

    //Horizontal
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(-10.0,0.0);
    glVertex2f(10.0,0.0);
    glEnd();
        //Vertical
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(0.0,-10.0);
    glVertex2f(0.0,10.0);
    glEnd();


    for(h=-10.0 ;h<=10.0; h+=1.0){
        glBegin(GL_LINE_STRIP);
        glColor3f(0.0,0.0,1.0);
        glVertex2f(-10.0,h);
        glVertex2f(10.0,h);
        glEnd();
    }

    for(v=-10.0 ;v<=10.0; v+=1.0){
        glBegin(GL_LINE_STRIP);
        glColor3f(0.0,0.0,1.0);
        glVertex2f(v,-10.0);
        glVertex2f(v,10.0);
        glEnd();
    }

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
	glutCreateWindow("Segitiga Titik");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();

	return 0;
}
