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

void display()
{
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glLoadIdentity();
    for(int a = -5.0; a < 5.0; a++ ){
        glColor3f(0,0,1);
        glBegin(GL_LINE_STRIP);
        glVertex3f(a,-5,0);
        glVertex3f(a,5,0);
        glEnd();
        glBegin(GL_LINE_STRIP);
        glVertex3f(-5,a,0);
        glVertex3f(5,a,0);
        glEnd();
        glBegin(GL_LINE_STRIP);
        glColor3f(1,0,0);
        glVertex3f(0,-5,0);
        glVertex3f(0,5,0);
        glEnd();
        glBegin(GL_LINE_STRIP);
        glVertex3f(-5,0,0);
        glVertex3f(5,0,0);
        glEnd();
    }
    glPopMatrix();

////    depan
//    glColor3f(0,0,1);
//    glBegin(GL_POLYGON);
//    glVertex3f(-1, -1, 1);
//    glVertex3f(1, -1, 1);
//    glVertex3f(1, 1, 1);
//    glVertex3f(-1, 1, 1);
//    glEnd();
//
//    //belakang
//    glColor3f(0,1,0);
//    glBegin(GL_POLYGON);
//    glVertex3f(1, -1, -1);
//    glVertex3f(-1, -1, -1);
//    glVertex3f(-1, 1, -1);
//    glVertex3f(1, 1, -1);
//    glEnd();
//
//    //kiri
//    glColor3f(1,0,0);
//    glBegin(GL_POLYGON);
//    glVertex3f(-1, -1, -1);
//    glVertex3f(-1, -1, 1);
//    glVertex3f(-1, 1, 1);
//    glVertex3f(-1, 1, -1);
//    glEnd();
//
//    //kanan
//    glColor3f(0,1,1);
//    glBegin(GL_POLYGON);
//    glVertex3f(1, -1, -1);
//    glVertex3f(1, 1, -1);
//    glVertex3f(1, 1, 1);
//    glVertex3f(1, -1, 1);
//    glEnd();
//
//    //bawah
//    glColor3f(0,0.5,0.5);
//    glBegin(GL_POLYGON);
//    glVertex3f(1, -1, 1);
//    glVertex3f(-1, -1, 1);
//    glVertex3f(-1, -1, -1);
//    glVertex3f(1, -1, -1);
//    glEnd();
//
//    //atas
//    glColor3f(1,1,0);
//    glBegin(GL_POLYGON);
//    glVertex3f(-1, 1, 1);
//    glVertex3f(1, 1, 1);
//    glVertex3f(1, 1, -1);
//    glVertex3f(-1, 1, -1);
//    glEnd();

glPushMatrix();
glTranslatef(-2,-2,1);
glScalef(1,4,1);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslatef(2,-2,1);
glScalef(1,4,1);
glutSolidCube(1);
glPopMatrix();

//glPushMatrix();
//glTranslatef(1.7,-2,-1);
//glScalef(1,3.5,1);
//glutSolidCube(1);
//glPopMatrix();

glPushMatrix();
glScalef(5,1,4);
glutSolidCube(1);
glPopMatrix();

	glFlush();
}

void keyboard(unsigned char key, int x, int y){

    if(key == 'w'|| key == 'W'){
        glRotatef(-3,1,0,0);
        display();
    } else if(key == 's'|| key == 'S'){
        glRotatef(3,1,0,0);
        display();
    } else if(key == 'a'|| key == 'A'){
        glRotatef(3,0,1,0);
        display();
    } else if(key == 'd'|| key == 'D'){
        glRotatef(-3,0,1,0);
        display();
    }

}

void init(void)
{
    glClearColor (0, 0, 0, 0);
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
