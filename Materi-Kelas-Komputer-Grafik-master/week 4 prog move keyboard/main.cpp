#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
//untuk menggunakan print di console
#include<iostream>
using namespace std;

//yg per lu di import untuk random
#include<iostream>
#include<stdlib.h>
#include<time.h>

//Variabel Global
bool warna=false;
int lala=0;
float posY=0.0;
float posX=0.0;

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(4);
	glBegin(GL_POLYGON);
	glVertex2f(-1.0+posX,-1.0+posY);
	glVertex2f(1.0+posX,-1.0+posY);
	glVertex2f(0.0+posX,1.0+posY);
	glEnd();

	glFlush();
}

void keyboard(unsigned char key, int x, int y){
    if(key=='c'){
        if(lala%2==0 && warna==false){
            glColor3f(1.0,0.0,0.0);
            lala+=1;
            warna=true;
        }
        else if(lala%2==1){
            glColor3f(0.0,0.0,1.0);
            lala+=1;
        }
        else{
            glColor3f(0.0,1.0,0.0);
            warna=false;
        }
        display();
        cout << "ganti warna" << endl;
    }
    if (key=='w'){
        posY+=0.2;
        glColor3f(1.0,0.0,0.0);
        cout << "keatas" << endl;
        display();
    }
    if(key=='s'){
        posY-=0.2;
        cout << "kebawah" << endl;
         glColor3f(0.0,1.0,0.0);
        display();
    }
    if(key=='a'){
        posX-=0.2;
        cout << "kekiri" << endl;
        glColor3f(0.0,0.0,1.0);
        display();
        int randAngka= rand()%10;
	cout << "angka hasil random: " << randAngka << endl;
    }
    if(key=='d'){
        posX+=0.2;
        cout << "kekanan" << endl;
         glColor3f(1.0,0.0,1.0);
        display();
    }
}


void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0,2.0,-2.0,2.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,1.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("Segitiga Titik");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	myinit();
	srand(time (NULL));
	glutMainLoop();

	return 0;
}
