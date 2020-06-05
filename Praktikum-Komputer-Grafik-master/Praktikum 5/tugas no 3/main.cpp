#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <stdlib.h>

using namespace std;

static GLfloat spin = 0.0;
string rot = "";
bool stop = true;
int n = 8;
void cell(){
    glRectf(-4.0, -4.0, -3.0, -3.0);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    if (rot == "a"){
        glRotatef(spin, 0.0, 0.0, 1.0);
    }
    else if (rot == "b"){
        glRotatef(spin, 0.0, 1.0, 0.0);
    }
    else if (rot == "c"){
        glRotatef(spin, 1.0, 0.0, 0.0);
    }

    glColor3f(0.0, 0.0, 1.0);
    cell();
    for(int kolom = 1; kolom < n; kolom++)
    {
        if (kolom%2 == 1)
        {
            glColor3f(1.0, 1.0, 0.0);
        }
        else
        {
            glColor3f(0.0, 0.0, 1.0);
        }
        glTranslatef(1.0, 0.0, 0.0);
        cell();
    }

    for(int baris = 1; baris < n; baris++)
    {
        glColor3f(0.0, 0.0, 1.0);
        glTranslatef(0.0, 1.0, 0.0);
        cell();
        if(baris%2 == 1)
        {
            for(int kolom = 1; kolom < n; kolom++)
            {
                if (kolom%2 == 1)
                {
                    glColor3f(1.0, 1.0, 0.0);
                }
                else
                {
                    glColor3f(0.0, .0, 1.0);
                }
                glTranslatef(-1.0, 0.0, 0.0);
                cell();
            }

        }
//
        if(baris%2 == 0)
        {
            for(int kolom = 1; kolom < n; kolom++)
            {
                if (kolom%2 == 1)
                {
                    glColor3f(1.0, 1.0, 0.0);
                }
                else
                {
                    glColor3f(0.0, 0.0, 1.0);
                }
                glTranslatef(1.0, 0.0, 0.0);
                cell();
            }
        }
    }
    glPopMatrix();
    glutSwapBuffers();
}

void spinDisplay(void)
{
    spin = spin + 0.05;
    if (spin > 360.0)
    spin = spin - 360.0;
    glutPostRedisplay();
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
    glOrtho(-7.0, 7.0, -7.0, 7.0, -7.0, 7.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void keyinput(unsigned char key, int x, int y){

    if(key == 'p' || key == 'P'){
        if(stop == true){
            glutIdleFunc(NULL);
            stop = false;
        }
        else {
            glutIdleFunc(spinDisplay);
            stop = true;
        }
    }
}

void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
                rot = "a";
                glutIdleFunc(spinDisplay);
            break;
        case GLUT_MIDDLE_BUTTON:
            if (state == GLUT_DOWN)
                rot = "b";
                glutIdleFunc(spinDisplay);
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
                rot = "c";
                glutIdleFunc(spinDisplay);
            break;
        default:
            break;
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
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyinput);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
 }
