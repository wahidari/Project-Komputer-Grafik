#include <windows.h>
//untuk print di console
#include <iostream>
//untuk random angka
#include<stdlib.h>
#include<time.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
using namespace std;

bool change=false;

float posX=5.0;
float posY=12.0;

int randX,randY;

void play(){
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex2f(posX,posY);
    glVertex2f(posX+1.0,posY);
    glVertex2f(posX+1.0,posY+1.0);
    glVertex2f(posX,posY+1.0);
    glEnd();
}

void nim(){
    glBegin(GL_POLYGON);//1111111111
    glVertex2f(1.2+randX,1.1+randY);
    glVertex2f(1.3+randX,1.1+randY);
    glVertex2f(1.3+randX,1.9+randY);
    glVertex2f(1.2+randX,1.9+randY);
    glEnd();

    glBegin(GL_POLYGON);//2222222222 atas
    glVertex2f(1.4+randX,1.8+randY);
    glVertex2f(1.7+randX,1.8+randY);
    glVertex2f(1.7+randX,1.9+randY);
    glVertex2f(1.4+randX,1.9+randY);
    glEnd();

    glBegin(GL_POLYGON);//2222222222 atas kanan
    glVertex2f(1.6+randX,1.6+randY);
    glVertex2f(1.7+randX,1.6+randY);
    glVertex2f(1.7+randX,1.9+randY);
    glVertex2f(1.6+randX,1.9+randY);
    glEnd();

    glBegin(GL_POLYGON);//222222222 tengah
    glVertex2f(1.4+randX,1.5+randY);
    glVertex2f(1.7+randX,1.5+randY);
    glVertex2f(1.7+randX,1.6+randY);
    glVertex2f(1.4+randX,1.6+randY);
    glEnd();

    glBegin(GL_POLYGON);//22222222 bawah kiri
    glVertex2f(1.4+randX,1.2+randY);
    glVertex2f(1.5+randX,1.2+randY);
    glVertex2f(1.5+randX,1.5+randY);
    glVertex2f(1.4+randX,1.5+randY);
    glEnd();

    glBegin(GL_POLYGON);//22222222 bawah
    glVertex2f(1.4+randX,1.1+randY);
    glVertex2f(1.7+randX,1.1+randY);
    glVertex2f(1.7+randX,1.2+randY);
    glVertex2f(1.4+randX,1.2+randY);
    glEnd();

    glBegin(GL_POLYGON);//11111111111111111
    glVertex2f(1.8+randX,1.1+randY);
    glVertex2f(1.9+randX,1.1+randY);
    glVertex2f(1.9+randX,1.9+randY);
    glVertex2f(1.8+randX,1.9+randY);
    glEnd();

}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
    if(change==false){ //SHOW LAYOUT 1  //SHOW LAYOUT 1  //SHOW LAYOUT 1
        glBegin(GL_POLYGON); //1111111111111111
        glColor3f(0,0,1);
        glVertex2f(0.0,12.0);
        glVertex2f(5.0,12.0);
        glVertex2f(5.0,13.0);
        glVertex2f(0.0,13.0);
        glEnd();


        glBegin(GL_POLYGON);//2222222222222222
        glVertex2f(0.0,0.0);
        glVertex2f(1.0,0.0);
        glVertex2f(1.0,13.0);
        glVertex2f(0.0,13.0);
        glEnd();


        glBegin(GL_POLYGON);//3333333333333333
        glVertex2f(0.0,0.0);
        glVertex2f(5.0,0.0);
        glVertex2f(5.0,1.0);
        glVertex2f(0.0,1.0);
        glEnd();

        glBegin(GL_POLYGON);//4444444444444444444
        glVertex2f(0.0,4.0);
        glVertex2f(3.0,4.0);
        glVertex2f(3.0,5.0);
        glVertex2f(0.0,5.0);
        glEnd();


        glBegin(GL_POLYGON);//5555555555555555555
        glVertex2f(4.0,10.0);
        glVertex2f(5.0,10.0);
        glVertex2f(5.0,13.0);
        glVertex2f(4.0,13.0);
        glEnd();


        glBegin(GL_POLYGON);//66666666666666666
        glVertex2f(4.0,10.0);
        glVertex2f(7.0,10.0);
        glVertex2f(7.0,11.0);
        glVertex2f(4.0,11.0);
        glEnd();


        glBegin(GL_POLYGON);//7777777777777777777777
        glVertex2f(6.0,6.0);
        glVertex2f(7.0,6.0);
        glVertex2f(7.0,11.0);
        glVertex2f(6.0,11.0);
        glEnd();


        glBegin(GL_POLYGON);//88888888888888888888888
        glVertex2f(2.0,8.0);
        glVertex2f(7.0,8.0);
        glVertex2f(7.0,9.0);
        glVertex2f(2.0,9.0);
        glEnd();


        glBegin(GL_POLYGON);//999999999999999999999
        glVertex2f(2.0,8.0);
        glVertex2f(3.0,8.0);
        glVertex2f(3.0,11.0);
        glVertex2f(2.0,11.0);
        glEnd();


        glBegin(GL_POLYGON);//10 10 10 10 10
        glVertex2f(6.0,6.0);
        glVertex2f(11.0,6.0);
        glVertex2f(11.0,7.0);
        glVertex2f(6.0,7.0);
        glEnd();

        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glVertex2f(10.0,2.0);
        glVertex2f(11.0,2.0);
        glVertex2f(11.0,9.0);
        glVertex2f(10.0,9.0);
        glEnd();


        glBegin(GL_POLYGON);//12 12 12 12 12 12 12
        glVertex2f(8.0,2.0);
        glVertex2f(11.0,2.0);
        glVertex2f(11.0,3.0);
        glVertex2f(8.0,3.0);
        glEnd();


        glBegin(GL_POLYGON);//13 13 13 13 13 13
        glVertex2f(8.0,2.0);
        glVertex2f(9.0,2.0);
        glVertex2f(9.0,5.0);
        glVertex2f(8.0,5.0);
        glEnd();



        glBegin(GL_POLYGON);// 14 14 14 14 14 14 14
        glVertex2f(6.0,12.0);
        glVertex2f(13.0,12.0);
        glVertex2f(13.0,13.0);
        glVertex2f(6.0,13.0);
        glEnd();


         glBegin(GL_POLYGON); //15 15 15 15 15 15 15
        glVertex2f(8.0,8.0);
        glVertex2f(9.0,8.0);
        glVertex2f(9.0,13.0);
        glVertex2f(8.0,13.0);
        glEnd();


        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glVertex2f(8.0,10.0);
        glVertex2f(11.0,10.0);
        glVertex2f(11.0,11.0);
        glVertex2f(8.0,11.0);
        glEnd();


         glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glVertex2f(12.0,0.0);
        glVertex2f(13.0,0.0);
        glVertex2f(13.0,13.0);
        glVertex2f(12.0,13.0);
        glEnd();


        glBegin(GL_POLYGON);//18 18 18 18 18 18
        glVertex2f(6.0,0.0);
        glVertex2f(13.0,0.0);
        glVertex2f(13.0,1.0);
        glVertex2f(6.0,1.0);
        glEnd();


        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glVertex2f(6.0,0.0);
        glVertex2f(7.0,0.0);
        glVertex2f(7.0,5.0);
        glVertex2f(6.0,5.0);
        glEnd();


        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glVertex2f(4.0,4.0);
        glVertex2f(7.0,4.0);
        glVertex2f(7.0,5.0);
        glVertex2f(4.0,5.0);
        glEnd();


        glBegin(GL_POLYGON);//21 21 21 21 21 21 21
        glVertex2f(4.0,2.0);
        glVertex2f(5.0,2.0);
        glVertex2f(5.0,7.0);
        glVertex2f(4.0,7.0);
        glEnd();


        glBegin(GL_POLYGON);//22 22 22 22 22 22 22 22
        glVertex2f(2.0,6.0);
        glVertex2f(5.0,6.0);
        glVertex2f(5.0,7.0);
        glVertex2f(2.0,7.0);
        glEnd();


        glBegin(GL_POLYGON);//23 23 23 23 23 23 23
        glVertex2f(2.0,2.0);
        glVertex2f(5.0,2.0);
        glVertex2f(5.0,3.0);
        glVertex2f(2.0,3.0);
        glEnd();
    }
    else{//SHOW LAYOUT 2 //SHOW LAYOUT 2 //SHOW LAYOUT 2
        glBegin(GL_POLYGON);//11111111111111111111
        glColor3f(0,0,1);
        glVertex2f(0.0,12.0);
        glVertex2f(5.0,12.0);
        glVertex2f(5.0,13.0);
        glVertex2f(0.0,13.0);
        glEnd();


        glBegin(GL_POLYGON);//2222222222222222222222
        glVertex2f(0.0,0.0);
        glVertex2f(1.0,0.0);
        glVertex2f(1.0,13.0);
        glVertex2f(0.0,13.0);
        glEnd();


        glBegin(GL_POLYGON);//333333333333333333
        glVertex2f(0.0,0.0);
        glVertex2f(5.0,0.0);
        glVertex2f(5.0,1.0);
        glVertex2f(0.0,1.0);
        glEnd();


        glBegin(GL_POLYGON);//444444444444444444444
        glVertex2f(4.0,0.0);
        glVertex2f(5.0,0.0);
        glVertex2f(5.0,3.0);
        glVertex2f(4.0,3.0);
        glEnd();


        glBegin(GL_POLYGON);//555555555555555555
        glVertex2f(0.0,10.0);
        glVertex2f(3.0,10.0);
        glVertex2f(3.0,11.0);
        glVertex2f(0.0,11.0);
        glEnd();


        glBegin(GL_POLYGON);//666666666666666666666
        glVertex2f(4.0,8.0);
        glVertex2f(5.0,8.0);
        glVertex2f(5.0,13.0);
        glVertex2f(4.0,13.0);
        glEnd();


        glBegin(GL_POLYGON);//7777777777777777777
        glVertex2f(4.0,10.0);
        glVertex2f(7.0,10.0);
        glVertex2f(7.0,11.0);
        glVertex2f(4.0,11.0);
        glEnd();


        glBegin(GL_POLYGON);//888888888888888888888
        glVertex2f(6.0,6.0);
        glVertex2f(7.0,6.0);
        glVertex2f(7.0,11.0);
        glVertex2f(6.0,11.0);
        glEnd();


        glBegin(GL_POLYGON);//9999999999999999999999
        glVertex2f(2.0,6.0);
        glVertex2f(9.0,6.0);
        glVertex2f(9.0,7.0);
        glVertex2f(2.0,7.0);
        glEnd();


        glBegin(GL_POLYGON);//10 10 10 10 10 10
        glVertex2f(2.0,6.0);
        glVertex2f(3.0,6.0);
        glVertex2f(3.0,9.0);
        glVertex2f(2.0,9.0);
        glEnd();


        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glVertex2f(8.0,2.0);
        glVertex2f(9.0,2.0);
        glVertex2f(9.0,7.0);
        glVertex2f(8.0,7.0);
        glEnd();


        glBegin(GL_POLYGON);//12 12 12 12 12 12 12 12
        glVertex2f(8.0,2.0);
        glVertex2f(11.0,2.0);
        glVertex2f(11.0,3.0);
        glVertex2f(8.0,3.0);
        glEnd();


        glBegin(GL_POLYGON);//13 13 13 13 13 13 13
        glVertex2f(6.0,12.0);
        glVertex2f(13.0,12.0);
        glVertex2f(13.0,13.0);
        glVertex2f(6.0,13.0);
        glEnd();


        glBegin(GL_POLYGON);//14 14 14 14 14 14 14 14
        glVertex2f(8.0,8.0);
        glVertex2f(9.0,8.0);
        glVertex2f(9.0,13.0);
        glVertex2f(8.0,13.0);
        glEnd();


        glBegin(GL_POLYGON);//15 15 15 15 15 15 15
        glVertex2f(8.0,8.0);
        glVertex2f(11.0,8.0);
        glVertex2f(11.0,9.0);
        glVertex2f(8.0,9.0);
        glEnd();


        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glVertex2f(10.0,4.0);
        glVertex2f(11.0,4.0);
        glVertex2f(11.0,9.0);
        glVertex2f(10.0,9.0);
        glEnd();


        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glVertex2f(10.0,10.0);
        glVertex2f(13.0,10.0);
        glVertex2f(13.0,11.0);
        glVertex2f(10.0,11.0);
        glEnd();


        glBegin(GL_POLYGON);//18 18 18 18 18 18 18
        glVertex2f(12.0,0.0);
        glVertex2f(13.0,0.0);
        glVertex2f(13.0,13.0);
        glVertex2f(12.0,13.0);
        glEnd();


        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glVertex2f(6.0,0.0);
        glVertex2f(13.0,0.0);
        glVertex2f(13.0,1.0);
        glVertex2f(6.0,1.0);
        glEnd();


        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glVertex2f(6.0,0.0);
        glVertex2f(7.0,0.0);
        glVertex2f(7.0,5.0);
        glVertex2f(6.0,5.0);
        glEnd();


        glBegin(GL_POLYGON);//21 21 21 21 21 21
        glVertex2f(2.0,4.0);
        glVertex2f(7.0,4.0);
        glVertex2f(7.0,5.0);
        glVertex2f(2.0,5.0);
        glEnd();


        glBegin(GL_POLYGON);//22 22 22 22 22 22
        glVertex2f(2.0,2.0);
        glVertex2f(3.0,2.0);
        glVertex2f(3.0,5.0);
        glVertex2f(2.0,5.0);
        glEnd();
    }
    play();
    nim();
    glFlush();
}

void keyboard(unsigned char key, int x, int y){
    if(key == 'w'|| key == 'W'){
        posY+=0.1;
    }
    else if(key == 'a'|| key == 'A'){
        posX-=0.1;
    }
    else if(key == 's'|| key == 'S'){
        posY-=0.1;
    }
    else if(key == 'd'|| key == 'D'){
        posX+=0.1;
    }
    else if (key == 'c' || key == 'C'){
        if(change == false){
            change = true;
        }
        else{
            change = false;
        }
        posX = 5;
        posY = 12;
        randX=(rand()%6)*2;
        randY=(rand()%6)*2;
        cout << "angka hasil random x: " << randX << endl;
        cout << "angka hasil random y: " << randY << endl;
    }
    display();
}
void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,13.0,-0.0,13.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,1.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow("Maze 2D Polygon");
	srand (time(NULL));
	randX = (rand()%6)*2;
	randY = (rand()%6)*2;
	cout << "angka awal hasil random x: " << randX << endl;
	cout << "angka awal hasil random y: " << randY << endl;
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	myinit();
	glutMainLoop();
	return 0;
}
