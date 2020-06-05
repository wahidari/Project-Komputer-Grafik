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

static float rotAngle = 0.1;

void init(void)
{
    glClearColor(0.0,0.0, 0.2, 0.0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 1.0, 0.0);

    glPushMatrix();
    glRotatef(rotAngle, 0.0, 0.0, 0.1);
    //glRotatef(-rotAngle, 0.0, 0.0, 0.1);
    glBegin (GL_LINES);
    glVertex2f (-0.5, 0.5);
    glVertex2f (0.5, -0.5);
    glEnd ();
    glPopMatrix();

    glColor3f (0.0, 0.0, 1.0);
    glPushMatrix();
    glRotatef(rotAngle, 0.0, 0.0, 0.1);
    glBegin (GL_LINES);
    glVertex2f (0.5, 0.5);
    glVertex2f (-0.5, -0.5);
    glEnd ();
    glPopMatrix();

    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        gluOrtho2D (-1.0, 1.0, -1.0*(GLfloat)h/(GLfloat)w, 1.0*(GLfloat)h/(GLfloat)w);
    else
        gluOrtho2D (-1.0*(GLfloat)w/(GLfloat)h, 1.0*(GLfloat)w/(GLfloat)h, -1.0, 1.0); glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'r':
        case  'R':
            rotAngle -= 20.;
            //rotAngle -= 20.;
            if (rotAngle >= 360.) rotAngle = 0.;
            glutPostRedisplay();
            break;
        case 27:
            exit(0);
            break;
        default:
            break;
   }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (400, 400);
    glutCreateWindow (argv[0]);
    init();
    glutReshapeFunc (reshape);
    glutKeyboardFunc (keyboard);
    glutDisplayFunc (display);
    glutMainLoop();
    return 0;
}

