
///TEKAN "s / S" ATAU "w / W" UNTUK MEROTASI OBJEK///

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <iostream>
#endif
using namespace std;

int rot = 0;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glRotated(rot,1,1,1);

    ///KOTAK 1----------------------------
    ///KOTAK 1 (DEPAN)
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0,  2.0,  0.5);
    glVertex3f(-2.0, -2.0,  0.5);
    glVertex3f(-1.0, -2.0,  0.5);
    glVertex3f(-1.0,  2.0,  0.5);
    glEnd();

    ///KOTAK 1 (BELAKANG)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0,  2.0,  -0.5);
    glVertex3f(-2.0, -2.0,  -0.5);
    glVertex3f(-1.0, -2.0,  -0.5);
    glVertex3f(-1.0,  2.0,  -0.5);
    glEnd();

    ///KOTAK 1 (KIRI)
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0,  2.0,  0.5);
    glVertex3f(-2.0, -2.0,  0.5);
    glVertex3f(-2.0, -2.0,  -0.5);
    glVertex3f(-2.0,  2.0,  -0.5);
    glEnd();

    ///KOTAK 1 (KANAN)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-1.0,  2.0,  0.5);
    glVertex3f(-1.0, -2.0,  0.5);
    glVertex3f(-1.0, -2.0,  -0.5);
    glVertex3f(-1.0,  2.0,  -0.5);
    glEnd();

    ///KOTAK 1 (ATAS)
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0,  2.0,  0.5);
    glVertex3f(-1.0, 2.0,  0.5);
    glVertex3f(-1.0, 2.0,  -0.5);
    glVertex3f(-2.0,  2.0,  -0.5);
    glEnd();

    ///KOTAK 1 (BAWAH)
    glColor3f(0.4, 0.2, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, -2.0,  0.5);
    glVertex3f(-1.0, -2.0,  0.5);
    glVertex3f(-1.0, -2.0,  -0.5);
    glVertex3f(-2.0, -2.0,  -0.5);
    glEnd();
    ///-------------------------------

    ///KOTAK 2------------------------
    ///KOTAK 2 (DEPAN)
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, 2.0,  0.5);
    glVertex3f(-2.0, 1.0,  0.5);
    glVertex3f(2.0, 1.0,  0.5);
    glVertex3f(2.0, 2.0,  0.5);
    glEnd();

    ///KOTAK 2 (BELAKANG)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, 2.0,  -0.5);
    glVertex3f(-2.0, 1.0,  -0.5);
    glVertex3f(2.0, 1.0,  -0.5);
    glVertex3f(2.0, 2.0,  -0.5);
    glEnd();

    ///KOTAK 2 (KIRI)
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, 2.0, 0.5);
    glVertex3f(-2.0, 1.0, 0.5);
    glVertex3f(-2.0, 1.0, -0.5);
    glVertex3f(-2.0, 2.0, -0.5);
    glEnd();

    ///KOTAK 2 (KANAN)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(2.0, 2.0, 0.5);
    glVertex3f(2.0, 1.0, 0.5);
    glVertex3f(2.0, 1.0, -0.5);
    glVertex3f(2.0, 2.0, -0.5);
    glEnd();

    ///KOTAK 2 (ATAS)
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, 2.0, 0.5);
    glVertex3f(2.0, 2.0, 0.5);
    glVertex3f(2.0, 2.0, -0.5);
    glVertex3f(-2.0, 2.0, -0.5);
    glEnd();

    ///KOTAK 2 (BAWAH)
    glColor3f(0.4, 0.2, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, 1.0, 0.5);
    glVertex3f(2.0, 1.0, 0.5);
    glVertex3f(2.0, 1.0, -0.5);
    glVertex3f(-2.0, 1.0, -0.5);
    glEnd();
    ///----------------------------

    ///KOTAK 3---------------------
    ///KOTAK 3 (DEPAN)
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(1.0, 2.0,  0.5);
    glVertex3f(1.0, -2.0,  0.5);
    glVertex3f(2.0, -2.0,  0.5);
    glVertex3f(2.0, 2.0,  0.5);
    glEnd();

    ///KOTAK 3 (BELAKANG)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(1.0, 2.0,  -0.5);
    glVertex3f(1.0, -2.0, -0.5);
    glVertex3f(2.0, -2.0, -0.5);
    glVertex3f(2.0, 2.0,  -0.5);
    glEnd();

    ///KOTAK 3 (KIRI)
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(1.0, 2.0,  0.5);
    glVertex3f(1.0, -2.0,  0.5);
    glVertex3f(1.0, -2.0,  -0.5);
    glVertex3f(1.0, 2.0,  -0.5);
    glEnd();

    ///KOTAK 3 (KANAN)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(2.0, 2.0,  0.5);
    glVertex3f(2.0, -2.0,  0.5);
    glVertex3f(2.0, -2.0,  -0.5);
    glVertex3f(2.0, 2.0,  -0.5);
    glEnd();

    ///KOTAK 3 (ATAS)
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(1.0, 2.0,  0.5);
    glVertex3f(2.0, 2.0,  0.5);
    glVertex3f(2.0, 2.0,  -0.5);
    glVertex3f(1.0, 2.0,  -0.5);
    glEnd();

    ///KOTAK 3 (BAWAH)
    glColor3f(0.4, 0.2, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(1.0, -2.0,  0.5);
    glVertex3f(2.0, -2.0,  0.5);
    glVertex3f(2.0, -2.0,  -0.5);
    glVertex3f(1.0, -2.0,  -0.5);
    glEnd();
    ///-----------------------------

    ///KOTAK 4----------------------
    ///KOTAK 4 (DEPAN)
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, -1.0,  0.5);
    glVertex3f(-2.0, -2.0,  0.5);
    glVertex3f(2.0, -2.0,  0.5);
    glVertex3f(2.0, -1.0,  0.5);
    glEnd();

    ///KOTAK 4 (BELAKANG)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, -1.0,  -0.5);
    glVertex3f(-2.0, -2.0,  -0.5);
    glVertex3f(2.0, -2.0,  -0.5);
    glVertex3f(2.0, -1.0,  -0.5);
    glEnd();

    ///KOTAK 4 (KIRI)
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, -1.0,  0.5);
    glVertex3f(-2.0, -2.0,  0.5);
    glVertex3f(-2.0, -2.0,  -0.5);
    glVertex3f(-2.0, -1.0,  -0.5);
    glEnd();

    ///KOTAK 4 (KANAN)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(2.0, -1.0,  0.5);
    glVertex3f(2.0, -2.0,  0.5);
    glVertex3f(2.0, -2.0,  -0.5);
    glVertex3f(2.0, -1.0,  -0.5);
    glEnd();

    ///KOTAK 4 (ATAS)
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, -1.0,  0.5);
    glVertex3f(2.0, -1.0,  0.5);
    glVertex3f(2.0, -1.0,  -0.5);
    glVertex3f(-2.0, -1.0,  -0.5);
    glEnd();

    ///KOTAK 4 (BAWAH)
    glColor3f(0.4, 0.2, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, -2.0,  0.5);
    glVertex3f(2.0, -2.0,  0.5);
    glVertex3f(2.0, -2.0,  -0.5);
    glVertex3f(-2.0, -2.0,  -0.5);
    glEnd();

    glFlush();

    cout << "rotate sebesar = " << rot << endl;
}

void keyboard (unsigned char key, int x, int y){
    if (key == 'w' || key == 'W'){
        rot += 1;
    }else if (key == 's' || key == 'S'){
        rot -= 1;
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
    glutCreateWindow("4 Balok");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
 }
