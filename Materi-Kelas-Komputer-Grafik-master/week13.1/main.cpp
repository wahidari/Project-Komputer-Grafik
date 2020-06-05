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

    glClearColor (0.0, 0.0, 0.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    GLfloat light_position_diff[] = { -1.0, 1.0, 1.0, 0.0 };
    GLfloat diffuse_light[] = { 0.0, 0.0, 1.0, 1.0 };
    GLfloat light_position_spec[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat specular_light[] = { 0.0, 1.0, 0.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position_diff);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position_spec);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular_light);
    GLfloat mat_specular[] = { 0.7, 0.7, 0.7, 1.0 };
    GLfloat mat_shininess[] = { 10.0 };
    GLfloat mat_diffuse[] = { 0.7, 0.7, 0.7, 1.0 };
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glShadeModel (GL_SMOOTH);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
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
//         viewdir[0] = viewdir[0] * cos(0.02) + viewdir[2] * sin(0.03);
//         viewdir[2] = -viewdir[0] * sin(0.03) + viewdir[2] * cos(0.02);
//     }
//     else if (key == 'n') {
//         viewdir[0] = viewdir[0] * cos(-0.02) + viewdir[2] * sin(-0.03);
//         viewdir[2] = -viewdir[0] * sin(-0.03) + viewdir[2] * cos(-0.02);
//     }
    else if (key == 'v') {
        alpha -= 0.005;
        viewdir[0] = cos(alpha);
        viewdir[2] = sin(alpha);
    }
    else if (key == 'n') {
        alpha += 0.005;
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
