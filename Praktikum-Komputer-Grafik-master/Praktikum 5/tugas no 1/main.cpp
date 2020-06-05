#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <stdlib.h>

void bintang(){
    glBegin(GL_POLYGON);
    glVertex2f(-1, 1);
    glVertex2f(1, 1);
    glVertex2f(0, 3);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glRectf(-1.0, 1.0, 1.0, -1.0);
    bintang();
    for(int i = 1; i<= 3; i++){
        glRotatef(90, 0, 0, 1);
        bintang();
    }
    glFlush();
}
static void key(unsigned char key, int x, int y)
{
    switch (key){
        case 27 :
        case 'q':
            exit(0);
            break;
    }
    glutPostRedisplay();
}
static void SpecialKeys(int key, int x, int y)
{
    switch (key){
		case GLUT_KEY_UP:
            glColor3f(0.5,0,0.5);
			break;
		case GLUT_KEY_DOWN:
            glColor3f(0.5,1,0);
			break;
	}
    glutPostRedisplay();
}

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5.0,5.0,-5.0,5.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0,0.0,1.0);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Animation");
    myinit();
    glutDisplayFunc(display);
    glutSpecialFunc(SpecialKeys);
    glutKeyboardFunc(key);
    glutMainLoop();

    return 0;
}
