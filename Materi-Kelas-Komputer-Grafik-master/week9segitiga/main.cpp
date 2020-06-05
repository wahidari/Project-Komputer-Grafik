/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
#include <stdlib.h>
//untuk print di console
#include <iostream>
#include<time.h>

using namespace std;
int rot = 0;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    for(int a = -5.0; a < 5.0; a++ ){
        glColor3f(0.0,0.0,1.0);
        glBegin(GL_LINE_STRIP);
        glVertex3f(a,-5,0);
        glVertex3f(a,5,0);
        glEnd();
        glBegin(GL_LINE_STRIP);
        glVertex3f(-5,a,0);
        glVertex3f(5,a,0);
        glEnd();
        glBegin(GL_LINE_STRIP);
        glColor3f(1.0,0.0,0.0);
        glVertex3f(0,-5,0);
        glVertex3f(0,5,0);
        glEnd();
        glBegin(GL_LINE_STRIP);
        glVertex3f(-5,0,0);
        glVertex3f(5,0,0);
        glEnd();
    }
    glRotatef(rot,1,1,1);
    //depan
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-1.0,-1.0,0.2);
    glVertex3f(1.0,-1.0,0.2);
    glVertex3f(0.0,1.0,0.2);
    glEnd();
    //belakang
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-1.0,-1.0,-0.2);
    glVertex3f(1.0,-1.0,-0.2);
    glVertex3f(0.0,1.0,-0.2);
    glEnd();
    //kiri
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-1.0,-1.0,-0.2);
    glVertex3f(-1.0,-1.0,0.2);
    glVertex3f(0.0,1.0,0.2);
    glVertex3f(0.0,1.0,-0.2);
    glEnd();

    //kanan
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(1.0,-1.0,0.2);
    glVertex3f(1.0,-1.0,-0.2);
    glVertex3f(0.0,1.0,-0.2);
    glVertex3f(0.0,1.0,0.2);
    glEnd();

    //bawah
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-1.0,-1.0,-0.2);
    glVertex3f(-1.0,-1.0,0.2);
    glVertex3f(1.0,-1.0,0.2);
    glVertex3f(1.0,-1.0,-0.2);
    glEnd();


	glFlush();
}
void keyboard(unsigned char key, int x, int y){
    if(key == 'w'|| key == 'W'){
        rot+=1;
    } else if(key == 's'|| key == 'S'){
        rot-=1;
    }
    display();
}

void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
    glMatrixMode(GL_MODELVIEW);
    glShadeModel (GL_FLAT);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Kubus");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
 }
