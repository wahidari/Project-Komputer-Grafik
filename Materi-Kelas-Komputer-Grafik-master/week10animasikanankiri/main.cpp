
#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>

float spin = 0.0;
float rotx = 1.0;
float roty = 0.0;
float rotz = 0.0;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(-4,0.0,0.0);
    glRotatef(spin, rotx, roty, rotz);
    glTranslatef(4,0.0,0.0);
    glColor3f(1.0, 0.0, 1.0);
    glRectf(-5.0, -1.0, -3.0, 1.0);
    glPopMatrix();

    glPushMatrix();
    glRotatef(spin, rotx, roty, rotz);
    glColor3f(1.0, 1.0, 1.0);
    glRectf(-1.0, -1.0, 1.0, 1.0);
    glPopMatrix();
    glutSwapBuffers();
}

void spinDisplay(void)
{
    spin += 0.05;
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
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouse(int button, int state, int x, int y){
    switch (button){
        case GLUT_LEFT_BUTTON:
//            if (state == GLUT_DOWN)
                glutIdleFunc(spinDisplay);
                rotx = 1.0;
                roty = 0.0;
                rotz = 0.0;
            break;
        case GLUT_MIDDLE_BUTTON:
//            if (state == GLUT_DOWN)
                glutIdleFunc(spinDisplay);
                rotx = 0.0;
                roty = 1.0;
                rotz = 0.0;
            break;
        case GLUT_RIGHT_BUTTON:
//            if (state == GLUT_DOWN)
                glutIdleFunc(spinDisplay);
                rotx = 0.0;
                roty = 0.0;
                rotz = 1.0;
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
    glutMouseFunc(mouse);
    glutIdleFunc(spinDisplay);
    glutMainLoop();
    return 0;
 }

