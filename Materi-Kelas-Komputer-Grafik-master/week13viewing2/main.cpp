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

void init(void) {
    GLfloat light_position_diff[] = { -1.0, 1.0, 1.0, 0.0 };
    GLfloat diffuse_light[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position_diff);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glShadeModel (GL_FLAT);
    glEnable(GL_LIGHT0);
}
void material(float r, float g, float b, float a){
    GLfloat mat_shininess[] = {10.0};
    GLfloat mat_diffuse[] = {r, g, b, a};
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0,0,-10, 0,0,1, 0,1,0);
    material(1,0,0,1);
    glutSolidSphere(1,40,16);
    glTranslated(0,0,3);
    material(0,1,0,1);
    glutSolidTeapot(1);
    glTranslated(0,0,-6);
    material(0,0,1,1);
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
    glutMainLoop();
    return 0;
}
