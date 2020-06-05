#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

void display(void)
{
    /* bersihkan layar dari titik pixel yang masih ada */
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 0.0);

    /* gambar 5 titik di layar */

//    Pilihan glBegin()
   // glBegin(GL_LINE_STRIP);
//    glBegin(GL_LINE_LOOP);
//    glBegin(GL_LINES);
//    glBegin(GL_TRIANGLES);
//    glBegin(GL_TRIANGLE_FAN);
//    glBegin(GL_TRIANGLE_STRIP);
    //glBegin(GL_QUADS);
//    glBegin(GL_QUAD_STRIP);
    glBegin(GL_POLYGON);


    //glBegin(GL_POINTS);
    /*ganti script diatas dengan script yang di sediakan di pilihan glBegin() diatas
     untuk mencoba berbagai macam primitif drawing*/
    glVertex3f (0.0, 0.0, 0.0);
    glVertex3f (0.0, 0.8, 0.0);
    glVertex3f (0.8, 0.0, 0.0);
    glVertex3f (0.0, -0.8, 0.0);
    glVertex3f (-0.8, 0.0, 0.0);
    glEnd();

    glFlush ();
}

 void kunci(unsigned char key, int x, int y)
{
   switch (key)
   {
     /* aplikasi berhenti ketika tombol q ditekan */
     case 27 :
     case 'q':
      exit(0);
      break;
     }
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
glutInitWindowSize(400,400);
glutInitWindowPosition(100,100);
glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
glutCreateWindow("Primitif");
glutDisplayFunc(display);
glutKeyboardFunc(kunci);
glutMainLoop();
return 0;
}
