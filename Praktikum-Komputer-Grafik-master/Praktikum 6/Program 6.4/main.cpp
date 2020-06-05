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
boolean diff = true, spec = true, amb = true;
float theta = 0.0;

void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);

    GLfloat light_position_diff[] = { -1.0, 1.0, 1.0, 0.0 };
    GLfloat diffuse_light[] = { 0.0, 0.0, 1.0, 1.0 };
    GLfloat light_position_spec[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat specular_light[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat ambient_light[] = { 0.9, 0.9, 0.9, 1.0 };

    glLightfv(GL_LIGHT0, GL_POSITION, light_position_diff);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position_spec);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular_light);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient_light);

    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glShadeModel (GL_SMOOTH);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    GLfloat mat_specular[] = { 0.7, 0.7, 0.7, 1.0 };
    GLfloat mat_shininess[] = { 10.0 };
    GLfloat mat_diffuse[] = { 0.7, 0.7, 0.7, 1.0 };

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

    glRotatef(theta, 0,1,0);
    glTranslatef(1.0, 0.0, 0.0);
    glutSolidTeapot(0.5);
    glTranslatef(-2.0, 0.0, 0.0);

    GLfloat mat_specular_1[] = { 0.7, 0.1, 0.1, 1.0 };
    GLfloat mat_shininess_1[] = { 10.0 };
    GLfloat mat_diffuse_1[] = { 0.7, 0.1, 0.1, 1.0 };

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_1);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_1);
    glutSolidIcosahedron();

    glFlush ();
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho (-2.5, 2.5, -2.5*(GLfloat)h/(GLfloat)w, 2.5*(GLfloat)h/(GLfloat)w, - 10.0, 10.0);
    else
        glOrtho (-2.5*(GLfloat)w/(GLfloat)h, 2.5*(GLfloat)w/(GLfloat)h, -2.5, 2.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
 }

 void mykey(unsigned char key, int mouseX, int mouseY){
    if (key=='1'){
        if (amb == true){
            GLfloat ambient_light[] = { 0.3, 0.3, 0.3, 1.0 };
            glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient_light);
            amb = false;
        }
        else{
            GLfloat ambient_light[] = { 0.9, 0.9, 0.9, 1.0 };
            glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient_light);
            amb = true;
        }
    }
    if (key=='2'){
        if (diff == true){
            glDisable(GL_LIGHT0);
            diff = false;
        }
        else{
            glEnable(GL_LIGHT0);
            diff = true;
        }
    }
    if (key=='3'){
        if (spec == true){
            glDisable(GL_LIGHT1);
            spec = false;
        }
        else{
            glEnable(GL_LIGHT1);
            spec = true;
        }
    }
    display();
 }

 void myIdle(){
    theta +=0.1;
    display();
 }

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500, 500); glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(mykey);
    glutIdleFunc(myIdle);
    glutMainLoop();
    return 0;
}
