#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>

//bidang x dn z
bool diff = true, spec = true;
float pos[3];
double alpha = 3.1415; // posisi awal kamera dan hadapnya,
GLdouble viewdir[] = {-1,0,0};

void init(void)
{
    pos[0] = 10;
    pos[1] = 0;
    pos[2] = 0;
    GLfloat light_position_diff[] = { -1.0, 1.0, 1.0, 0.0 };
    GLfloat diffuse_light[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position_diff);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glShadeModel (GL_FLAT);
    glEnable(GL_LIGHT0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
   // gluLookAt(10,0,0, 0,0,0, 0,1,1);
    gluLookAt(pos[0],pos[1],pos[2],  pos[0]+viewdir[0],pos[1]+viewdir[1],pos[2]+viewdir[2],   0,1,0);
    glutSolidSphere(1,40,16);
    glTranslated(0,0,3);
    glutSolidTeapot(1);
    glTranslated(0,0,-6);
    glutSolidTorus(0.3,0.7,12,12);
    glFlush();
}

void reshape (int w, int h)
{
    glViewport(0,0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65, (GLfloat) w/(GLfloat) h, 0.1, 20);
    //glOrtho(-5, 5, -5, 5, -5, 5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mykey(unsigned char key, int mouseX, int mouseY)
{
    if (key == 'g') {
        pos[0] += 0.2 * viewdir[0];
        pos[1] += 0.2 * viewdir[1];
        pos[2] += 0.2 * viewdir[2];
    }
    else if (key == 'b') {
        pos[0] -= 0.2 * viewdir[0];
        pos[1] -= 0.2 * viewdir[1];
        pos[2] -= 0.2 * viewdir[2];
    }
//     else if (key == 'v') {
//         viewdir[0] = viewdir[0] * cos(0.02) + viewdir[2] * sin(0.02);
//         viewdir[2] = -viewdir[0] * sin(0.02) + viewdir[2] * cos(0.02);
//     }
//     else if (key == 'n') {
//         viewdir[0] = viewdir[0] * cos(-0.02) + viewdir[2] * sin(-0.02);
//         viewdir[2] = -viewdir[0] * sin(-0.02) + viewdir[2] * cos(-0.02);
//     }
    else if (key == 'v') {
        alpha -= 0.05;
        viewdir[0] = cos(alpha);
        viewdir[2] = sin(alpha);
    }
    else if (key == 'n') {
        alpha += 0.05;
        viewdir[0] = cos(alpha);
        viewdir[2] = sin(alpha);
    }

    display();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(mykey);
    glutMainLoop();
    return 0;
}
