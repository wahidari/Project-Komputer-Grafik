#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glRotated(35,1,0,0);
    glRotated(45,0,0,1);

    ///atas
    glPushMatrix();
    glTranslatef(0,2,0);
    glScaled(2.5,0.5,0.5);
    glutWireCube(2);
    glPopMatrix();

    ///bawah
    glPushMatrix();
    glTranslatef(0,-2,0);
    glScaled(2.5,0.5,0.5);
    glutWireCube(2);
    glPopMatrix();

    ///kanan
    glPushMatrix();
    glTranslatef(2,0,0);
    glScaled(0.5,2.5,0.5);
    glutWireCube(2);
    glPopMatrix();

    ///kiri
    glPushMatrix();
    glTranslatef(-2,0,0);
    glScaled(0.5,2.5,0.5);
    glutWireCube(2);
    glPopMatrix();


    glFlush();
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
    glutMainLoop();
    return 0;
 }
