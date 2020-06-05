#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);
    glLoadIdentity();
    glPointSize(6);

    //Point pertama
    glBegin(GL_POINTS);
    glVertex2f(15,15);
    glEnd();

  //  glPushMatrix();

//    glScalef(2,1,1);
//
//    //Point pertama yang di Scale
//    glBegin(GL_POINTS);
//    glVertex2f(15,15);
//    glEnd();

//    //Point kedua yang sudah di Scale
//    glColor3f(0.0,1.0,0.0);
//    glBegin(GL_POINTS);
//    glVertex2f(10,25);
//    glEnd();
//
//    glPopMatrix();
//
//    //Point kedua tanpa Scale
//    glBegin(GL_POINTS);
//    glVertex2f(10,25);
//    glEnd();
//
    glRotatef(-3, -5, 0, 1);

    //Point pertama dengan rotate
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    glVertex2f(15,15);
    glEnd();
//
//    glPushMatrix();
//
//    glTranslatef(5,0,0);
//
//    //Point pertama dengan rotate dulu dan setelah itu di translate
//    glBegin(GL_POINTS);
//    glVertex2f(15,15);
//    glEnd();
//
    glFlush();
}

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,50.0,0.0,50.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
}

int main(int argc, char* argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Transform");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();

	return 0;
}
