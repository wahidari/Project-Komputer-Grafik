#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotated(-35,1,1,1);

    glPushMatrix();
    glTranslated(-1,1,0);
    glColor3f(1.0,1.0,1.0);
    glutWireCube(2);
    glColor3f(0.0,1.0,0.0);
    glutWireTetrahedron();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1,-1,0);
    glColor3f(1.0,1.0,1.0);
    glutWireCube(2);
    glScaled(0.5,0.5,0.5);
    glColor3f(0.0,1.0,1.0);
    glutWireTeapot(1.1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1,-1,0);
    glColor3f(1.0,1.0,1.0);
    glutWireCube(2);
    glColor3f(1.0,1.0,0.0);
    glutWireSphere(0.7,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1,1,0);
    glColor3f(1.0,1.0,1.0);
    glutWireCube(2);
    glColor3f(0.0,0.0,1.0);
    glTranslated(0,-0.5,0);
    glRotated(-90,1,0,0);
    glutWireCone(0.7,1.2,50,2);
    glPopMatrix();

    glFlush();
}

void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4.0, 4.0, -4.0, 5.0, -5.0, 5.0);
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
    glutCreateWindow("4 Objek dalam 4 Kubus");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
 }
