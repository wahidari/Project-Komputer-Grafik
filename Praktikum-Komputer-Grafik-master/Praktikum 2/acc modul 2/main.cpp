#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>

void head(){
    float a=0.5, b=2.5,c=1.5,d=-6.0;
	float t= 0.0;
    glColor3f(0,0.5,0);
	glBegin(GL_POLYGON);
	for( t = -3.0; t<=3.0; t+=0.01){//atas
        glVertex3f (t*2.01,-0.2+t*t*-0.1+6.75, 0.0);
    }
	for( t = -3.0; t<=2.1; t+=0.01){//kanan
        /* x(t) = -1 + 2t; y(t) = 0 */
        glVertex3f (-0.1+t*t*-0.1+6.63, t*2.65, 0.0);
    }
	for( t = -3.0; t<=2.1; t+=0.01){//kiri
        /* x(t) = -1 + 2t; y(t) = 0 */
        glVertex3f (0.1+t*t*0.1-6.63, t*2.65, 0.0);
    }
	for( t=-5.5;t<=5.7;t+=0.01){//bawah
        glVertex2f(t,a*sin(b*t+c)-8.0);
	}
	glEnd();
}

void eye(){
    glColor3f(1,1,1);//mata kiri hitam
	glBegin(GL_POLYGON);
	for(float t=-5.5; t<=1.98; t+=0.01){
        glVertex2f(cos(t)*1.7-2.8,sin(t)*1.7+2.2);
	}
	glEnd();

    glColor3f(0,0,0);//mata kiri hitam
	glBegin(GL_POLYGON);
	for(float t=-5.0; t<=1.28; t+=0.01){
        glVertex2f(cos(t)-2.8,sin(t)+2.2);
	}
	glEnd();

    glColor3f(1,1,1);//mata kanan hitam
	glBegin(GL_POLYGON);
	for(float t=-5.5; t<=1.98; t+=0.01){
        glVertex2f(cos(t)*1.7+2.8,sin(t)*1.7+2.2);
	}
	glEnd();
	glColor3f(0,0,0);//mata kanan hitam
	glBegin(GL_POLYGON);
	for(float t=-5.0; t<=1.28; t+=0.01){
        glVertex2f(cos(t)+2.8,sin(t)+2.2);
	}
	glEnd();
}

void hidung(){
    glColor3f(1,1,0);//hidung kuning
	glBegin(GL_POLYGON);
	for(float t=-5.0; t<=1.28; t+=0.01){
        glVertex2f(cos(t)*0.9,sin(t)*1.5-0.7);
	}
	glEnd();
}

void mulut(){
    glColor3f(1,1,1);//mulut putih besar
	glBegin(GL_POLYGON);
	for(float t = -4.5; t<=4.5; t+=0.01){
        /* x(t) = -1 + 2t; y(t) = 0 */
        glVertex3f (t, -0.1+t*t*0.2-6.7, 0.0);
    }
	glEnd();

	glColor3f(1,0.2,0.5);//mulut pink
	glBegin(GL_POLYGON);
	for(float t = -3.5; t<=3.5; t+=0.01){
        /* x(t) = -1 + 2t; y(t) = 0 */
        glVertex3f (t*1.22, -0.9+t*t*0.3-5.95, 0.0);
    }
	glEnd();
	glColor3f(1,1,1);//mulut putih kecil
	glBegin(GL_POLYGON);
	for(float t = -3.5; t<=3.5; t+=0.01){
        /* x(t) = -1 + 2t; y(t) = 0 */
        glVertex3f (t*0.635, -0.55+t*t*0.08-6.295, 0.0);
    }
	glEnd();
}

void telinga(){
    glBegin(GL_POLYGON);//telinga kiri besar
    glColor3f(1,1,0);
    glVertex2f(-7.0,3.5);
    glVertex2f(-3.0,4.7);
    glVertex2f(-6.0,6.9);
    glEnd();

    glBegin(GL_POLYGON);//telinga kiri kecil
    glColor3f(0.63,0.082,0);
    glVertex2f(-6.4,3.6);
    glVertex2f(-3.7,4.5);
    glVertex2f(-5.6,5.8);
    glEnd();

    glBegin(GL_POLYGON);//telinga kanan besar
    glColor3f(1,1,0);
    glVertex2f(7.0,3.5);
    glVertex2f(3.0,4.7);
    glVertex2f(6.0,6.9);
    glEnd();

    glBegin(GL_POLYGON);//telinga kanan kecil
    glColor3f(0.63,0.082,0);
    glVertex2f(6.4,3.6);
    glVertex2f(3.7,4.5);
    glVertex2f(5.6,5.8);
    glEnd();

}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(4);
    head();
    eye();
    mulut();
    hidung();
    telinga();
	glFlush();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10.0,10.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.0,0.0,1.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("Garis Sejajar Sumbu X");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	return 0;
}
