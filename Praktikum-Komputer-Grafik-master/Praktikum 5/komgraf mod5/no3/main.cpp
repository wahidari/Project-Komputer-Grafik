#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<iostream>

static GLfloat spin = 0.0;
bool color=false;

void checkboard(){
   // glPushMatrix();
      glColor3f(0.0,0.0,0.5);

    for(int i=0; i<8;i++){

        for(int j=0; j<8;j++){
            if(color==true){
                glColor3f(0,0,1);
                color=false;
            }
            else{
                glColor3f(1,1,0);
                color=true;
            }

            glRecti(0,0, 5, 5);
            if(j!=7){

                    if(i%2==1){
                       glTranslated(-5,0,0);
                    }
                    else{
                         glTranslated(5,0,0);
                    }
            }
        }
        glTranslated(0,5,0);

   }

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //glBegin(GL_LINES);

    glPushMatrix();

    glRotatef(spin, 0.0, 0.0, 1.0);
    glTranslatef(-20,-20,0);
    checkboard();
    glPopMatrix();

    //glutSpecialFunc(SpecialInput);
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
    glOrtho(-40.0, 40.0, -40.0, 40.0, -40.0, 40.0);
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


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (400, 400);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
//    glutSpecialFunc(SpecialInput);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
 }
