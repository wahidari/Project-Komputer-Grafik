#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<iostream>

static GLfloat spin = 0.0;
bool gerak=false;

void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        glColor3f(0,0,1);
        break;
    case GLUT_KEY_DOWN:
        glColor3f(1,0,1);
        break;
    }

glutPostRedisplay();
}

void star(){
    ///atas
    glBegin(GL_POLYGON);
    glVertex2f(0.0,8.0);
    glVertex2f(-4.0,2.0);
    glVertex2f(4.0,2.0);
    glEnd();
    glRotatef(90,0,0,1);

    ///kana
    glBegin(GL_POLYGON);
    glVertex2f(0.0,8.0);
    glVertex2f(-4.0,2.0);
    glVertex2f(4.0,2.0);
    glEnd();

    ///bawah
    glRotatef(90,0,0,1);
     glBegin(GL_POLYGON);
    glVertex2f(0.0,8.0);
    glVertex2f(-4.0,2.0);
    glVertex2f(4.0,2.0);
    glEnd();

    ///kiri
     glRotatef(90,0,0,1);
     glBegin(GL_POLYGON);
    glVertex2f(0.0,8.0);
    glVertex2f(-4.0,2.0);
    glVertex2f(4.0,2.0);
    glEnd();

    ///kotak
    glBegin(GL_POLYGON);
    glVertex2f(-4.0,2.0);
    glVertex2f(-4.0,-2.0);
    glVertex2f(4.0,-2.0);
    glVertex2f(4.0,2.0);
    glEnd();


}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);


    glPushMatrix();
    star();
    glPopMatrix();

    glutSwapBuffers();
}

void spinDisplay(void)
{
    spin = spin + 0.01;
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
    glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
                glutIdleFunc(spinDisplay);
            break;
        case GLUT_MIDDLE_BUTTON:
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
                glutIdleFunc(NULL);
            break;
        default:
            break;
    }
 }

 void keybord(){
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


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (400, 400);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutSpecialFunc(SpecialInput);
    glutKeyboardFunc;
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
 }
