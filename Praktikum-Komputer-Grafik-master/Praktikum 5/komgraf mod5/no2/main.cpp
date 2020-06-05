#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<iostream>



static GLfloat spin = 0.0;
int cek=0;
bool gerak = false;

void spinDisplay(void)
{
    spin = spin + 0.5;
    if (spin > 360.0)
        spin = spin - 360.0;

    glutPostRedisplay();
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    if (cek == 1)
    {
        glRotatef(spin, 0.0, 0.0, 1.0);
    }
    else if (cek==2)
    {
        glRotatef(spin, 0.0, 1.0, 0.0);
    }
    else
    {
        glRotatef(spin, 1.0, 0.0, 0.0);
    }
    glColor3f(1.0, 1.0, 1.0);
    glRectf(-25.0, -25.0, 25.0, 25.0);

    if (gerak == true)
    {
        glutIdleFunc(spinDisplay);
    }
    else if (gerak == false)
    {
        glutIdleFunc(NULL);
    }
    glutSwapBuffers();

    glPopMatrix();

}


void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}

void reshape(int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
            cek=1;
        glutIdleFunc(spinDisplay);
        break;
    case GLUT_MIDDLE_BUTTON:
        if (state == GLUT_DOWN)
            cek=2;
        glutIdleFunc(spinDisplay);
        break;

    case GLUT_RIGHT_BUTTON:
        if(state==GLUT_DOWN)
            cek=3;
        glutIdleFunc(spinDisplay);
        break;
    default:
        break;
    }
}

void input(unsigned char key, int x, int y){
    if (key== 'p'|'P')
    {
        if (gerak == true)
        {
            gerak = false;
        }
        else if (gerak == false)
        {
            gerak = true;
            glutPostRedisplay();
        }
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (400, 400);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutKeyboardFunc(input);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
