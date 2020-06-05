#include <windows.h>
#include <iostream>
#include<stdlib.h>
#include<time.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
using namespace std;

int posx=5;
int posy=12;

bool change = false;
int randX = (rand()%6)*2;
int randY = (rand()%6)*2;
//Player Function
void player(){
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(posx,posy);
    glVertex2f(posx+1,posy);
    glVertex2f(posx+1,posy+1);
    glVertex2f(posx,posy+1);
    glEnd();
}
void nim(){
    glRectf(1.2+randX,1.1+randY,1.3+randX,1.9+randY);//1111111
    glRectf(1.4+randX,1.8+randY,1.7+randX,1.9+randY);//2222222
    glRectf(1.6+randX,1.6+randY,1.7+randX,1.9+randY);//2222222
    glRectf(1.4+randX,1.5+randY,1.7+randX,1.6+randY);//2222222
    glRectf(1.4+randX,1.2+randY,1.5+randX,1.5+randY);//2222222
    glRectf(1.4+randX,1.1+randY,1.7+randX,1.2+randY);//2222222
    glRectf(1.8+randX,1.1+randY,1.9+randX,1.9+randY);//1111111
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
    if(change==false){//SHOW LAYOUT 1
        glColor3f(0.0,0.0,1.0);//COLOR
        glRectf(0.0,12.0,5.0,13.0);//1
        glRectf(0.0,0.0,1.0,13.0);//2
        glRectf(0.0,0.0,5.0,1.0);//3
        glRectf(0.0,4.0,3.0,5.0);//4
        glRectf(4.0,10.0,5.0,13.0);//5
        glRectf(4.0,10.0,7.0,11.0);//6
        glRectf(6.0,6.0,7.0,11.0);//7
        glRectf(2.0,8.0,7.0,9.0);//8
        glRectf(2.0,8.0,3.0,11.0);//9
        glRectf(6.0,6.0,11.0,7.0);//10
        glRectf(10.0,2.0,11.0,9.0);//11
        glRectf(8.0,2.0,11.0,3.0);//12
        glRectf(8.0,2.0,9.0,5.0);//13
        glRectf(6.0,12.0,13.0,13.0);//14
        glRectf(8.0,8.0,9.0,13.0);//15
        glRectf(8.0,10.0,11.0,11.0);//16
        glRectf(12.0,0.0,13.0,13.0);//17
        glRectf(6.0,0.0,13.0,1.0);//18
        glRectf(6.0,0.0,7.0,5.0);//19
        glRectf(4.0,4.0,7.0,5.0);//20
        glRectf(4.0,2.0,5.0,7.0);//21
        glRectf(2.0,6.0,5.0,7.0);//22
        glRectf(2.0,2.0,5.0,3.0);//23
	}
	else{//SHOW LAYOUT 2
        glColor3f(0.0,0.0,1.0);//COLOR
        glRectf(0.0,12.0,5.0,13.0);//1
        glRectf(0.0,0.0,1.0,13.0);//2
        glRectf(0.0,0.0,5.0,1.0);//3
        glRectf(4.0,0.0,5.0,3.0);//4
        glRectf(0.0,10.0,3.0,11.0);//5
        glRectf(4.0,8.0,5.0,13.0);//6
        glRectf(4.0,10.0,7.0,11.0);//7
        glRectf(6.0,6.0,7.0,11.0);//8
        glRectf(2.0,6.0,9.0,7.0);//9
        glRectf(2.0,6.0,3.0,9.0);//10
        glRectf(8.0,2.0,9.0,7.0);//11
        glRectf(8.0,2.0,11.0,3.0);//12
        glRectf(6.0,12.0,13.0,13.0);//13
        glRectf(8.0,8.0,9.0,13.0);//14
        glRectf(8.0,8.0,11.0,9.0);//15
        glRectf(10.0,4.0,11.0,9.0);//16
        glRectf(10.0,10.0,13.0,11.0);//17
        glRectf(12.0,0.0,13.0,13.0);//18
        glRectf(6.0,0.0,13.0,1.0);//19
        glRectf(6.0,0.0,7.0,5.0);//20
        glRectf(2.0,4.0,7.0,5.0);//21
        glRectf(2.0,2.0,3.0,5.0);//22
	}
	player();
	nim();
	glFlush();
}

void input(unsigned char key,int x, int y){
    if(key == 'w'|| key == 'W'){
        posy+=1;
    }
    else if(key == 'a'|| key == 'A'){
        posx-=1;
    }
    else if(key == 's'|| key == 'S'){
        posy-=1;
    }
    else if(key == 'd'|| key == 'D'){
        posx+=1;
    }
    else if (key == 'c'){
        if(change == false){
            change = true;
        }
        else{
            change = false;
        }
        posx = 5;
        posy = 12;
        randX=(rand()%6)*2;
        randY=(rand()%6)*2;
        cout << "angka hasil random y: " << randY << endl;
        cout << "angka hasil random x: " << randX << endl;
    }
    display();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-0.1,13.1,-0.1,13.1);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,1.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow("Segitiga Titik");
	glutDisplayFunc(display);
	glutKeyboardFunc(input);
	myinit();
	glutMainLoop();
	return 0;
}
