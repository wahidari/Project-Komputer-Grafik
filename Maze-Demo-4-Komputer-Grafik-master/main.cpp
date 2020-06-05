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
#include<math.h>
#endif
///untuk print di console
using namespace std;

///kondisi awal lighting
bool diff = true, spec = true, amb = true;

//cek penekanan v pertama
bool Vpertama= true;

///Ubah Layout///
bool change=false;

///kondisi awal viewmode///
string viewmode = "2d";

///Posisi Player///
float posX=50;
float posY=120;

///Animasi Nim///
float RotNimX = 1;
float RotNimY = 0;
float RotNimZ = 0;
float RotNim[3]={0.0,0.0,0.0};
float SaveRotNim[3]={0.0,0.0,0.0};

///Cek Posisi Player///
int baris = 0;
int kolom = 5;

///kondisi awal nightmode///
bool night = false;

///opacity dinding///
float awall = 1.0;

///kondisi tabrakan///
float collision = false;

/// posisi awal kamera
float pos[3]={55,170,0};
///hadapnya,
GLdouble viewdir[] = {0,-1,0};
double alpha = 4.71;

///Cek Array Untuk Layout 1///
int layout1 [13] [13] = {
    {1,1,1,1,1,0,1,1,1,1,1,1,1},
    {1,0,0,0,1,0,0,0,1,0,0,0,1},
    {1,0,1,0,1,1,1,0,1,1,1,0,1},
    {1,0,1,0,0,0,1,0,1,0,0,0,1},
    {1,0,1,1,1,1,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,1,0,0,0,1,0,1},
    {1,0,1,1,1,0,1,1,1,1,1,0,1},
    {1,0,0,0,1,0,0,0,0,0,1,0,1},
    {1,1,1,0,1,1,1,0,1,0,1,0,1},
    {1,0,0,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,1,1,0,1,0,1,1,1,0,1},
    {1,0,0,0,0,0,1,0,0,0,0,0,1},
    {1,1,1,1,1,0,1,1,1,1,1,1,1}
};

///Cek Array Untuk Layout 2///
int layout2 [13] [13] = {
    {1,1,1,1,1,0,1,1,1,1,1,1,1},
    {1,0,0,0,1,0,0,0,1,0,0,0,1},
    {1,1,1,0,1,1,1,0,1,0,1,1,1},
    {1,0,0,0,1,0,1,0,1,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,1,1,0,1},
    {1,0,1,0,0,0,1,0,0,0,1,0,1},
    {1,0,1,1,1,1,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,1,0,1,0,1},
    {1,0,1,1,1,1,1,0,1,0,1,0,1},
    {1,0,1,0,0,0,1,0,1,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,1,1,0,1},
    {1,0,0,0,1,0,1,0,0,0,0,0,1},
    {1,1,1,1,1,0,1,1,1,1,1,1,1},
};

///maze 1
void maze1(){
        //SHOW LAYOUT 1  //SHOW LAYOUT 1  //SHOW LAYOUT 1
        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON); //1111111111111111
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(10,120,5);
        glVertex3f(50,120,5);
        glVertex3f(50,130,5);
        glVertex3f(10,130,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON); //1111111111111111
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(50,130,-5);
        glVertex3f(50,120,-5);
        glVertex3f(10,120,-5);
        glVertex3f(10,130,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON); //1111111111111111
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(50,130,5);
        glVertex3f(50,120,5);
        glVertex3f(50,120,-5);
        glVertex3f(50,130,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON); //1111111111111111
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(10,130,-5);
        glVertex3f(10,120,-5);
        glVertex3f(10,120,5);
        glVertex3f(10,130,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON); //1111111111111111
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(10,130,-5);
        glVertex3f(10,130,5);
        glVertex3f(50,130,5);
        glVertex3f(50,130,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON); //1111111111111111
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(10,120,5);
        glVertex3f(10,120,-5);
        glVertex3f(50,120,-5);
        glVertex3f(50,120,5);
        glEnd();


        //=============================================================//
        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//2222222222222222
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(0,0,5);
        glVertex3f(10,0,5);
        glVertex3f(10,130,5);
        glVertex3f(0,130,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//2222222222222222
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(10,130,-5);
        glVertex3f(10,0,-5);
        glVertex3f(0,0,-5);
        glVertex3f(0,130,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//2222222222222222
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(10,130,5);
        glVertex3f(10,0,5);
        glVertex3f(10,0,-5);
        glVertex3f(10,130,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//2222222222222222
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(0,130,-5);
        glVertex3f(0,0,-5);
        glVertex3f(0,0,5);
        glVertex3f(0,130,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//2222222222222222
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(0,130,-5);
        glVertex3f(0,130,5);
        glVertex3f(10,130,5);
        glVertex3f(10,130,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//2222222222222222
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(0,0,5);
        glVertex3f(10,0,5);
        glVertex3f(10,0,-5);
        glVertex3f(0,0,-5);
        glEnd();

        //=============================================================//
        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//3333333333333333
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(10,0,5);
        glVertex3f(50,0,5);
        glVertex3f(50,10,5);
        glVertex3f(10,10,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//3333333333333333
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(50,10,-5);
        glVertex3f(50,0,-5);
        glVertex3f(10,0,-5);
        glVertex3f(10,10,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//3333333333333333
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(50,10,5);
        glVertex3f(50,0,5);
        glVertex3f(50,0,-5);
        glVertex3f(50,10,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//3333333333333333
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(10,10,-5);
        glVertex3f(10,0,-5);
        glVertex3f(10,0,5);
        glVertex3f(10,10,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//3333333333333333
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(10,10,-5);
        glVertex3f(10,10,5);
        glVertex3f(50,10,5);
        glVertex3f(50,10,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//3333333333333333
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(10,0,5);
        glVertex3f(10,0,-5);
        glVertex3f(50,0,-5);
        glVertex3f(50,0,5);
        glEnd();


//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//4444444444444444444
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(10,40,5);
        glVertex3f(30,40,5);
        glVertex3f(30,50,5);
        glVertex3f(10,50,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//4444444444444444444
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(30,50,-5);
        glVertex3f(30,40,-5);
        glVertex3f(10,40,-5);
        glVertex3f(10,50,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//4444444444444444444
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(30,50,5);
        glVertex3f(30,40,5);
        glVertex3f(30,40,-5);
        glVertex3f(30,50,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//4444444444444444444
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(10,50,-5);
        glVertex3f(10,40,-5);
        glVertex3f(10,40,5);
        glVertex3f(10,50,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//4444444444444444444
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(10,50,-5);
        glVertex3f(10,50,5);
        glVertex3f(30,50,5);
        glVertex3f(30,50,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//4444444444444444444
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(10,40,5);
        glVertex3f(10,40,-5);
        glVertex3f(30,40,-5);
        glVertex3f(30,40,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//5555555555555555555
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(40,100,5);
        glVertex3f(50,100,5);
        glVertex3f(50,120,5);
        glVertex3f(40,120,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//5555555555555555555
       glNormal3f(0.0,0.0,-1.0);
        glVertex3f(50,120,-5);
        glVertex3f(50,100,-5);
        glVertex3f(40,100,-5);
        glVertex3f(40,120,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//5555555555555555555
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(50,120,5);
        glVertex3f(50,100,5);
        glVertex3f(50,100,-5);
        glVertex3f(50,120,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//5555555555555555555
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(40,120,-5);
        glVertex3f(40,100,-5);
        glVertex3f(40,100,5);
        glVertex3f(40,120,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//5555555555555555555
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(40,120,-5);
        glVertex3f(40,120,5);
        glVertex3f(50,120,5);
        glVertex3f(50,120,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//5555555555555555555
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(40,100,5);
        glVertex3f(40,100,-5);
        glVertex3f(50,100,-5);
        glVertex3f(50,100,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//
//
        //DEPAN
        glBegin(GL_POLYGON);//66666666666666666
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(50,100,5);
        glVertex3f(70,100,5);
        glVertex3f(70,110,5);
        glVertex3f(50,110,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//66666666666666666
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(70,110,-5);
        glVertex3f(70,100,-5);
        glVertex3f(50,100,-5);
        glVertex3f(50,110,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//66666666666666666
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(70,110,5);
        glVertex3f(70,100,5);
        glVertex3f(70,100,-5);
        glVertex3f(70,110,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//66666666666666666
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(50,110,-5);
        glVertex3f(50,100,-5);
        glVertex3f(50,100,5);
        glVertex3f(50,110,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//66666666666666666
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(50,110,-5);
        glVertex3f(50,110,5);
        glVertex3f(70,110,5);
        glVertex3f(70,110,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//66666666666666666
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(50,100,5);
        glVertex3f(50,100,-5);
        glVertex3f(70,100,-5);
        glVertex3f(70,100,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//7777777777777777777777
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(60,60,5);
        glVertex3f(70,60,5);
        glVertex3f(70,100,5);
        glVertex3f(60,100,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//7777777777777777777777
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(70,100,-5);
        glVertex3f(70,60,-5);
        glVertex3f(60,60,-5);
        glVertex3f(60,100,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//7777777777777777777777
       glNormal3f(1.0,0.0,0.0);
        glVertex3f(70,100,5);
        glVertex3f(70,60,5);
        glVertex3f(70,60,-5);
        glVertex3f(70,100,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//7777777777777777777777
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(60,100,-5);
        glVertex3f(60,60,-5);
        glVertex3f(60,60,5);
        glVertex3f(60,100,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//7777777777777777777777
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(60,100,-5);
        glVertex3f(60,100,5);
        glVertex3f(70,100,5);
        glVertex3f(70,100,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//7777777777777777777777
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(60,60,5);
        glVertex3f(60,60,-5);
        glVertex3f(70,60,-5);
        glVertex3f(70,60,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//88888888888888888888888
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(20,80,5);
        glVertex3f(60,80,5);
        glVertex3f(60,90,5);
        glVertex3f(20,90,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//88888888888888888888888
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(60,90,-5);
        glVertex3f(60,80,-5);
        glVertex3f(20,80,-5);
        glVertex3f(20,90,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//88888888888888888888888
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(60,90,5);
        glVertex3f(60,80,5);
        glVertex3f(60,80,-5);
        glVertex3f(60,90,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//88888888888888888888888
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(20,90,-5);
        glVertex3f(20,80,-5);
        glVertex3f(20,80,5);
        glVertex3f(20,90,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//88888888888888888888888
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(20,90,-5);
        glVertex3f(20,90,5);
        glVertex3f(60,90,5);
        glVertex3f(60,90,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//88888888888888888888888
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(20,80,5);
        glVertex3f(20,80,-5);
        glVertex3f(60,80,-5);
        glVertex3f(60,80,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//999999999999999999999
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(20,90,5);
        glVertex3f(30,90,5);
        glVertex3f(30,110,5);
        glVertex3f(20,110,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//999999999999999999999
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(30,110,-5);
        glVertex3f(30,90,-5);
        glVertex3f(20,90,-5);
        glVertex3f(20,110,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//999999999999999999999
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(30,110,5);
        glVertex3f(30,90,5);
        glVertex3f(30,90,-5);
        glVertex3f(30,110,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//999999999999999999999
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(20,110,-5);
        glVertex3f(20,90,-5);
        glVertex3f(20,90,5);
        glVertex3f(20,110,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//999999999999999999999
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(20,110,-5);
        glVertex3f(20,110,5);
        glVertex3f(30,110,5);
        glVertex3f(30,110,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//999999999999999999999
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(20,90,5);
        glVertex3f(20,90,-5);
        glVertex3f(30,90,-5);
        glVertex3f(30,90,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//10 10 10 10 10
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(70,60,5);
        glVertex3f(100,60,5);
        glVertex3f(100,70,5);
        glVertex3f(70,70,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//10 10 10 10 10
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(100,70,-5);
        glVertex3f(100,60,-5);
        glVertex3f(70,60,-5);
        glVertex3f(70,70,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//10 10 10 10 10
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(100,70,5);
        glVertex3f(100,60,5);
        glVertex3f(100,60,-5);
        glVertex3f(100,70,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//10 10 10 10 10
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(70,70,-5);
        glVertex3f(70,60,-5);
        glVertex3f(70,60,5);
        glVertex3f(70,70,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//10 10 10 10 10
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(70,70,-5);
        glVertex3f(70,70,5);
        glVertex3f(100,70,5);
        glVertex3f(100,70,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//10 10 10 10 10
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(70,60,5);
        glVertex3f(70,60,-5);
        glVertex3f(100,60,-5);
        glVertex3f(100,60,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(100,20,5);
        glVertex3f(110,20,5);
        glVertex3f(110,90,5);
        glVertex3f(100,90,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(110,90,-5);
        glVertex3f(110,20,-5);
        glVertex3f(100,20,-5);
        glVertex3f(100,90,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(110,90,5);
        glVertex3f(110,20,5);
        glVertex3f(110,20,-5);
        glVertex3f(110,90,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(100,90,-5);
        glVertex3f(100,20,-5);
        glVertex3f(100,20,5);
        glVertex3f(100,90,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(100,90,-5);
        glVertex3f(100,90,5);
        glVertex3f(110,90,5);
        glVertex3f(110,90,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(100,20,5);
        glVertex3f(100,20,-5);
        glVertex3f(110,20,-5);
        glVertex3f(110,20,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(80,20,5);
        glVertex3f(100,20,5);
        glVertex3f(100,30,5);
        glVertex3f(80,30,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(100,30,-5);
        glVertex3f(100,20,-5);
        glVertex3f(80,20,-5);
        glVertex3f(80,30,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(100,30,5);
        glVertex3f(100,20,5);
        glVertex3f(100,20,-5);
        glVertex3f(100,30,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(80,30,-5);
        glVertex3f(80,20,-5);
        glVertex3f(80,20,5);
        glVertex3f(80,30,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(80,30,-5);
        glVertex3f(80,30,5);
        glVertex3f(100,30,5);
        glVertex3f(100,30,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(80,20,5);
        glVertex3f(80,20,-5);
        glVertex3f(100,20,-5);
        glVertex3f(100,20,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//13 13 13 13 13 13
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(80,30,5);
        glVertex3f(90,30,5);
        glVertex3f(90,50,5);
        glVertex3f(80,50,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//13 13 13 13 13 13
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(90,50,-5);
        glVertex3f(90,30,-5);
        glVertex3f(80,30,-5);
        glVertex3f(80,50,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//13 13 13 13 13 13
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(90,50,5);
        glVertex3f(90,30,5);
        glVertex3f(90,30,-5);
        glVertex3f(90,50,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//13 13 13 13 13 13
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(80,50,-5);
        glVertex3f(80,30,-5);
        glVertex3f(80,30,5);
        glVertex3f(80,50,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//13 13 13 13 13 13
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(80,50,-5);
        glVertex3f(80,50,5);
        glVertex3f(90,50,5);
        glVertex3f(90,50,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//13 13 13 13 13 13
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(80,30,5);
        glVertex3f(80,30,-5);
        glVertex3f(90,30,-5);
        glVertex3f(90,30,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);// 14 14 14 14 14 14 14
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(60,120,5);
        glVertex3f(130,120,5);
        glVertex3f(130,130,5);
        glVertex3f(60,130,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);// 14 14 14 14 14 14 14
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(130,130,-5);
        glVertex3f(130,120,-5);
        glVertex3f(60,120,-5);
        glVertex3f(60,130,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);// 14 14 14 14 14 14 14
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(130,130,5);
        glVertex3f(130,120,5);
        glVertex3f(130,120,-5);
        glVertex3f(130,130,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);// 14 14 14 14 14 14 14
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(60,130,-5);
        glVertex3f(60,120,-5);
        glVertex3f(60,120,5);
        glVertex3f(60,130,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);// 14 14 14 14 14 14 14
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(60,130,-5);
        glVertex3f(60,130,5);
        glVertex3f(130,130,5);
        glVertex3f(130,130,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);// 14 14 14 14 14 14 14
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(60,120,5);
        glVertex3f(60,120,-5);
        glVertex3f(130,120,-5);
        glVertex3f(130,120,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON); //15 15 15 15 15 15 15
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(80,80,5);
        glVertex3f(90,80,5);
        glVertex3f(90,120,5);
        glVertex3f(80,120,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON); //15 15 15 15 15 15 15
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(90,120,-5);
        glVertex3f(90,80,-5);
        glVertex3f(80,80,-5);
        glVertex3f(80,120,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON); //15 15 15 15 15 15 15
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(90,120,5);
        glVertex3f(90,80,5);
        glVertex3f(90,80,-5);
        glVertex3f(90,120,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON); //15 15 15 15 15 15 15
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(80,120,-5);
        glVertex3f(80,80,-5);
        glVertex3f(80,80,5);
        glVertex3f(80,120,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON); //15 15 15 15 15 15 15
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(80,120,-5);
        glVertex3f(80,120,5);
        glVertex3f(90,120,5);
        glVertex3f(90,120,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON); //15 15 15 15 15 15 15
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(80,80,5);
        glVertex3f(80,80,-5);
        glVertex3f(90,80,-5);
        glVertex3f(90,80,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(90,100,5);
        glVertex3f(110,100,5);
        glVertex3f(110,110,5);
        glVertex3f(90,110,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(110,110,-5);
        glVertex3f(110,100,-5);
        glVertex3f(90,100,-5);
        glVertex3f(90,110,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(110,110,5);
        glVertex3f(110,100,5);
        glVertex3f(110,100,-5);
        glVertex3f(110,110,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(90,110,-5);
        glVertex3f(90,100,-5);
        glVertex3f(90,100,5);
        glVertex3f(90,110,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(90,110,-5);
        glVertex3f(90,110,5);
        glVertex3f(110,110,5);
        glVertex3f(110,110,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(90,100,5);
        glVertex3f(90,100,-5);
        glVertex3f(110,100,-5);
        glVertex3f(110,100,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//
        //DEPAN
         glBegin(GL_POLYGON);//17 17 17 17 17 17 17
         glNormal3f(0.0,0.0,1.0);
        glVertex3f(120,0,5);
        glVertex3f(130,0,5);
        glVertex3f(130,120,5);
        glVertex3f(120,120,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(130,120,-5);
        glVertex3f(130,0,-5);
        glVertex3f(120,0,-5);
        glVertex3f(120,120,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(130,120,5);
        glVertex3f(130,0,5);
        glVertex3f(130,0,-5);
        glVertex3f(130,120,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(120,120,-5);
        glVertex3f(120,0,-5);
        glVertex3f(120,0,5);
        glVertex3f(120,120,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(120,120,-5);
        glVertex3f(120,120,5);
        glVertex3f(130,120,5);
        glVertex3f(130,120,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(120,0,5);
        glVertex3f(120,0,-5);
        glVertex3f(130,0,-5);
        glVertex3f(130,0,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//18 18 18 18 18 18
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(60,0,5);
        glVertex3f(120,0,5);
        glVertex3f(120,10,5);
        glVertex3f(60,10,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//18 18 18 18 18 18
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(120,10,-5);
        glVertex3f(120,0,-5);
        glVertex3f(60,0,-5);
        glVertex3f(60,10,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//18 18 18 18 18 18
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(120,10,5);
        glVertex3f(120,0,5);
        glVertex3f(120,0,-5);
        glVertex3f(120,10,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//18 18 18 18 18 18
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(60,10,-5);
        glVertex3f(60,0,-5);
        glVertex3f(60,0,5);
        glVertex3f(60,10,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//18 18 18 18 18 18
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(60,10,-5);
        glVertex3f(60,10,5);
        glVertex3f(120,10,5);
        glVertex3f(120,10,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//18 18 18 18 18 18
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(60,0,5);
        glVertex3f(60,0,-5);
        glVertex3f(120,0,-5);
        glVertex3f(120,0,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(60,10,5);
        glVertex3f(70,10,5);
        glVertex3f(70,40,5);
        glVertex3f(60,40,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(70,40,-5);
        glVertex3f(70,10,-5);
        glVertex3f(60,10,-5);
        glVertex3f(60,40,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(70,40,5);
        glVertex3f(70,10,5);
        glVertex3f(70,10,-5);
        glVertex3f(70,40,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(60,40,-5);
        glVertex3f(60,10,-5);
        glVertex3f(60,10,5);
        glVertex3f(60,40,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(60,40,-5);
        glVertex3f(60,40,5);
        glVertex3f(70,40,5);
        glVertex3f(70,40,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(60,10,5);
        glVertex3f(60,10,-5);
        glVertex3f(70,10,-5);
        glVertex3f(70,10,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(50,40,5);
        glVertex3f(70,40,5);
        glVertex3f(70,50,5);
        glVertex3f(50,50,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(70,50,-5);
        glVertex3f(70,40,-5);
        glVertex3f(50,40,-5);
        glVertex3f(50,50,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(70,50,5);
        glVertex3f(70,40,5);
        glVertex3f(70,40,-5);
        glVertex3f(70,50,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(50,50,-5);
        glVertex3f(50,40,-5);
        glVertex3f(50,40,5);
        glVertex3f(50,50,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(50,50,-5);
        glVertex3f(50,50,5);
        glVertex3f(70,50,5);
        glVertex3f(70,50,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(50,40,5);
        glVertex3f(50,40,-5);
        glVertex3f(70,40,-5);
        glVertex3f(70,40,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//21 21 21 21 21 21 21
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(40,20,5);
        glVertex3f(50,20,5);
        glVertex3f(50,70,5);
        glVertex3f(40,70,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//21 21 21 21 21 21 21
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(50,70,-5);
        glVertex3f(50,20,-5);
        glVertex3f(40,20,-5);
        glVertex3f(40,70,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//21 21 21 21 21 21 21
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(50,70,5);
        glVertex3f(50,20,5);
        glVertex3f(50,20,-5);
        glVertex3f(50,70,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//21 21 21 21 21 21 21
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(40,70,-5);
        glVertex3f(40,20,-5);
        glVertex3f(40,20,5);
        glVertex3f(40,70,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//21 21 21 21 21 21 21
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(40,70,-5);
        glVertex3f(40,70,5);
        glVertex3f(50,70,5);
        glVertex3f(50,70,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//21 21 21 21 21 21 21
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(40,20,-5);
        glVertex3f(40,20,5);
        glVertex3f(50,20,5);
        glVertex3f(50,20,-5);
        glEnd();


//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//22 22 22 22 22 22 22 22
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(20,60,5);
        glVertex3f(40,60,5);
        glVertex3f(40,70,5);
        glVertex3f(20,70,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//22 22 22 22 22 22 22 22
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(40,70,-5);
        glVertex3f(40,60,-5);
        glVertex3f(20,60,-5);
        glVertex3f(20,70,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//22 22 22 22 22 22 22 22
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(40,70,5);
        glVertex3f(40,60,5);
        glVertex3f(40,60,-5);
        glVertex3f(40,70,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//22 22 22 22 22 22 22 22
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(20,70,-5);
        glVertex3f(20,60,-5);
        glVertex3f(20,60,5);
        glVertex3f(20,70,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//22 22 22 22 22 22 22 22
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(20,70,-5);
        glVertex3f(20,70,5);
        glVertex3f(40,70,5);
        glVertex3f(40,70,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//22 22 22 22 22 22 22 22
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(20,60,5);
        glVertex3f(20,60,-5);
        glVertex3f(40,60,-5);
        glVertex3f(40,60,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//23 23 23 23 23 23 23
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(20,20,5);
        glVertex3f(40,20,5);
        glVertex3f(40,30,5);
        glVertex3f(20,30,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//23 23 23 23 23 23 23
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(40,30,-5);
        glVertex3f(40,20,-5);
        glVertex3f(20,20,-5);
        glVertex3f(20,30,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//23 23 23 23 23 23 23
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(40,30,5);
        glVertex3f(40,20,5);
        glVertex3f(40,20,-5);
        glVertex3f(40,30,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//23 23 23 23 23 23 23
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(20,30,-5);
        glVertex3f(20,20,-5);
        glVertex3f(20,20,5);
        glVertex3f(20,30,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//23 23 23 23 23 23 23
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(20,30,-5);
        glVertex3f(20,30,5);
        glVertex3f(40,30,5);
        glVertex3f(40,30,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//23 23 23 23 23 23 23
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(20,20,5);
        glVertex3f(20,20,-5);
        glVertex3f(40,20,-5);
        glVertex3f(40,20,5);
        glEnd();
}

///maze 2
void maze2(){
        //SHOW LAYOUT 2 //SHOW LAYOUT 2 //SHOW LAYOUT 2
        //=============================================================//
        //DEPAN
        glBegin(GL_POLYGON);//11111111111111111111
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(0,120,5);
        glVertex3f(50,120,5);
        glVertex3f(50,130,5);
        glVertex3f(0,130,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//11111111111111111111
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(50,130,-5);
        glVertex3f(50,120,-5);
        glVertex3f(0,120,-5);
        glVertex3f(0,130,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//11111111111111111111
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(50,130,5);
        glVertex3f(50,120,5);
        glVertex3f(50,120,-5);
        glVertex3f(50,130,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//11111111111111111111
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(0,130,-5);
        glVertex3f(0,120,-5);
        glVertex3f(0,120,5);
        glVertex3f(0,130,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//11111111111111111111
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(0,130,-5);
        glVertex3f(0,130,5);
        glVertex3f(50,130,5);
        glVertex3f(50,130,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//11111111111111111111
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(0,120,5);
        glVertex3f(0,120,-5);
        glVertex3f(50,120,-5);
        glVertex3f(50,120,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//2222222222222222222222
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(0,0,5);
        glVertex3f(10,0,5);
        glVertex3f(10,120,5);
        glVertex3f(0,120,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//2222222222222222222222
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(10,120,-5);
        glVertex3f(10,0,-5);
        glVertex3f(0,0,-5);
        glVertex3f(0,120,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//2222222222222222222222
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(10,120,5);
        glVertex3f(10,0,5);
        glVertex3f(10,0,-5);
        glVertex3f(10,120,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//2222222222222222222222
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(0,120,-5);
        glVertex3f(0,0,-5);
        glVertex3f(0,0,5);
        glVertex3f(0,120,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//2222222222222222222222
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(0,120,-5);
        glVertex3f(0,120,5);
        glVertex3f(10,120,5);
        glVertex3f(10,120,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//2222222222222222222222
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(0,0,5);
        glVertex3f(0,0,-5);
        glVertex3f(10,0,-5);
        glVertex3f(10,0,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//333333333333333333
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(10,0,5);
        glVertex3f(50,0,5);
        glVertex3f(50,10,5);
        glVertex3f(10,10,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//333333333333333333
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(50,10,-5);
        glVertex3f(50,0,-5);
        glVertex3f(10,0,-5);
        glVertex3f(10,10,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//333333333333333333
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(50,10,5);
        glVertex3f(50,0,5);
        glVertex3f(50,0,-5);
        glVertex3f(50,10,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//333333333333333333
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(10,10,-5);
        glVertex3f(10,0,-5);
        glVertex3f(10,0,5);
        glVertex3f(10,10,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//333333333333333333
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(10,10,-5);
        glVertex3f(10,10,5);
        glVertex3f(50,10,5);
        glVertex3f(50,10,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//333333333333333333
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(10,0,5);
        glVertex3f(10,0,-5);
        glVertex3f(50,0,-5);
        glVertex3f(50,0,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//444444444444444444444
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(40,10,5);
        glVertex3f(50,10,5);
        glVertex3f(50,30,5);
        glVertex3f(40,30,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//444444444444444444444
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(50,30,-5);
        glVertex3f(50,10,-5);
        glVertex3f(40,10,-5);
        glVertex3f(40,30,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//444444444444444444444
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(50,30,5);
        glVertex3f(50,10,5);
        glVertex3f(50,10,-5);
        glVertex3f(50,30,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//444444444444444444444
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(40,30,-5);
        glVertex3f(40,10,-5);
        glVertex3f(40,10,5);
        glVertex3f(40,30,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//444444444444444444444
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(40,30,-5);
        glVertex3f(40,30,5);
        glVertex3f(50,30,5);
        glVertex3f(50,30,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//444444444444444444444
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(40,10,5);
        glVertex3f(40,10,-5);
        glVertex3f(50,10,-5);
        glVertex3f(50,10,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//555555555555555555
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(10,100,5);
        glVertex3f(30,100,5);
        glVertex3f(30,110,5);
        glVertex3f(10,110,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//555555555555555555
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(30,110,-5);
        glVertex3f(30,100,-5);
        glVertex3f(10,100,-5);
        glVertex3f(10,110,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//555555555555555555
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(30,110,5);
        glVertex3f(30,100,5);
        glVertex3f(30,100,-5);
        glVertex3f(30,110,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//555555555555555555
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(10,110,-5);
        glVertex3f(10,100,-5);
        glVertex3f(10,100,5);
        glVertex3f(10,110,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//555555555555555555
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(10,110,-5);
        glVertex3f(10,110,5);
        glVertex3f(30,110,5);
        glVertex3f(30,110,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//555555555555555555
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(10,100,5);
        glVertex3f(10,100,-5);
        glVertex3f(30,100,-5);
        glVertex3f(30,100,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//666666666666666666666
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(40,80,5);
        glVertex3f(50,80,5);
        glVertex3f(50,120,5);
        glVertex3f(40,120,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//666666666666666666666
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(50,120,-5);
        glVertex3f(50,80,-5);
        glVertex3f(40,80,-5);
        glVertex3f(40,120,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//666666666666666666666
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(50,120,5);
        glVertex3f(50,80,5);
        glVertex3f(50,80,-5);
        glVertex3f(50,120,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//666666666666666666666
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(40,120,-5);
        glVertex3f(40,80,-5);
        glVertex3f(40,80,5);
        glVertex3f(40,120,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//666666666666666666666
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(40,120,-5);
        glVertex3f(40,120,5);
        glVertex3f(50,120,5);
        glVertex3f(50,120,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//666666666666666666666
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(40,80,5);
        glVertex3f(40,80,-5);
        glVertex3f(50,80,-5);
        glVertex3f(50,80,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//7777777777777777777
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(50,100,5);
        glVertex3f(60,100,5);
        glVertex3f(60,110,5);
        glVertex3f(50,110,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//7777777777777777777
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(60,110,-5);
        glVertex3f(60,100,-5);
        glVertex3f(50,100,-5);
        glVertex3f(50,110,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//7777777777777777777
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(60,110,5);
        glVertex3f(60,100,5);
        glVertex3f(60,100,-5);
        glVertex3f(60,110,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//7777777777777777777
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(50,110,-5);
        glVertex3f(50,100,-5);
        glVertex3f(50,100,5);
        glVertex3f(50,110,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//7777777777777777777
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(50,110,-5);
        glVertex3f(50,110,5);
        glVertex3f(60,110,5);
        glVertex3f(60,110,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//7777777777777777777
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(50,100,5);
        glVertex3f(50,100,-5);
        glVertex3f(60,100,-5);
        glVertex3f(60,100,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//888888888888888888888
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(60,70,5);
        glVertex3f(70,70,5);
        glVertex3f(70,110,5);
        glVertex3f(60,110,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//888888888888888888888
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(70,110,-5);
        glVertex3f(70,70,-5);
        glVertex3f(60,70,-5);
        glVertex3f(60,110,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//888888888888888888888
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(70,110,5);
        glVertex3f(70,70,5);
        glVertex3f(70,70,-5);
        glVertex3f(70,110,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//888888888888888888888
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(60,110,-5);
        glVertex3f(60,70,-5);
        glVertex3f(60,70,5);
        glVertex3f(60,110,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//888888888888888888888
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(60,110,-5);
        glVertex3f(60,110,5);
        glVertex3f(70,110,5);
        glVertex3f(70,110,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//888888888888888888888
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(60,70,5);
        glVertex3f(60,70,-5);
        glVertex3f(70,70,-5);
        glVertex3f(70,70,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//9999999999999999999999
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(30,60,5);
        glVertex3f(90,60,5);
        glVertex3f(90,70,5);
        glVertex3f(30,70,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//9999999999999999999999
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(90,70,-5);
        glVertex3f(90,60,-5);
        glVertex3f(30,60,-5);
        glVertex3f(30,70,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//9999999999999999999999
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(90,70,5);
        glVertex3f(90,60,5);
        glVertex3f(90,60,-5);
        glVertex3f(90,70,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//9999999999999999999999
       glNormal3f(-1.0,0.0,0.0);
        glVertex3f(30,70,-5);
        glVertex3f(30,60,-5);
        glVertex3f(30,60,5);
        glVertex3f(30,70,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//9999999999999999999999
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(30,70,-5);
        glVertex3f(30,70,5);
        glVertex3f(90,70,5);
        glVertex3f(90,70,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//9999999999999999999999
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(30,60,5);
        glVertex3f(30,60,-5);
        glVertex3f(90,60,-5);
        glVertex3f(90,60,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//10 10 10 10 10 10
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(20,60,5);
        glVertex3f(30,60,5);
        glVertex3f(30,90,5);
        glVertex3f(20,90,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//10 10 10 10 10 10
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(30,90,-5);
        glVertex3f(30,60,-5);
        glVertex3f(20,60,-5);
        glVertex3f(20,90,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//10 10 10 10 10 10
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(30,90,5);
        glVertex3f(30,60,5);
        glVertex3f(30,60,-5);
        glVertex3f(30,90,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//10 10 10 10 10 10
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(20,90,-5);
        glVertex3f(20,60,-5);
        glVertex3f(20,60,5);
        glVertex3f(20,90,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//10 10 10 10 10 10
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(20,90,-5);
        glVertex3f(20,90,5);
        glVertex3f(30,90,5);
        glVertex3f(30,90,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//10 10 10 10 10 10
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(20,60,5);
        glVertex3f(20,60,-5);
        glVertex3f(30,60,-5);
        glVertex3f(30,60,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(80,20,5);
        glVertex3f(90,20,5);
        glVertex3f(90,60,5);
        glVertex3f(80,60,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(90,60,-5);
        glVertex3f(90,20,-5);
        glVertex3f(80,20,-5);
        glVertex3f(80,60,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(90,60,5);
        glVertex3f(90,20,5);
        glVertex3f(90,20,-5);
        glVertex3f(90,60,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(80,60,-5);
        glVertex3f(80,20,-5);
        glVertex3f(80,20,5);
        glVertex3f(80,60,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(80,60,-5);
        glVertex3f(80,60,5);
        glVertex3f(90,60,5);
        glVertex3f(90,60,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(80,20,5);
        glVertex3f(80,20,-5);
        glVertex3f(90,20,-5);
        glVertex3f(90,20,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12 12
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(90,20,5);
        glVertex3f(110,20,5);
        glVertex3f(110,30,5);
        glVertex3f(90,30,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12 12
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(110,30,-5);
        glVertex3f(110,20,-5);
        glVertex3f(90,20,-5);
        glVertex3f(90,30,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12 12
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(110,30,5);
        glVertex3f(110,20,5);
        glVertex3f(110,20,-5);
        glVertex3f(110,30,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12 12
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(90,30,-5);
        glVertex3f(90,20,-5);
        glVertex3f(90,20,5);
        glVertex3f(90,30,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12 12
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(90,30,-5);
        glVertex3f(90,30,5);
        glVertex3f(110,30,5);
        glVertex3f(110,30,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12 12
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(90,20,5);
        glVertex3f(90,20,-5);
        glVertex3f(110,20,-5);
        glVertex3f(110,20,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//13 13 13 13 13 13 13
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(60,120,5);
        glVertex3f(130,120,5);
        glVertex3f(130,130,5);
        glVertex3f(60,130,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//13 13 13 13 13 13 13
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(130,130,-5);
        glVertex3f(130,120,-5);
        glVertex3f(60,120,-5);
        glVertex3f(60,130,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//13 13 13 13 13 13 13
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(130,130,5);
        glVertex3f(130,120,5);
        glVertex3f(130,120,-5);
        glVertex3f(130,130,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//13 13 13 13 13 13 13
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(60,130,-5);
        glVertex3f(60,120,-5);
        glVertex3f(60,120,5);
        glVertex3f(60,130,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//13 13 13 13 13 13 13
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(60,130,-5);
        glVertex3f(60,130,5);
        glVertex3f(130,130,5);
        glVertex3f(130,130,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//13 13 13 13 13 13 13
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(60,120,5);
        glVertex3f(60,120,-5);
        glVertex3f(130,120,-5);
        glVertex3f(130,120,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//14 14 14 14 14 14 14 14
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(80,80,5);
        glVertex3f(90,80,5);
        glVertex3f(90,120,5);
        glVertex3f(80,120,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//14 14 14 14 14 14 14 14
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(90,120,-5);
        glVertex3f(90,80,-5);
        glVertex3f(80,80,-5);
        glVertex3f(80,120,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//14 14 14 14 14 14 14 14
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(90,120,5);
        glVertex3f(90,80,5);
        glVertex3f(90,80,-5);
        glVertex3f(90,120,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//14 14 14 14 14 14 14 14
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(80,120,-5);
        glVertex3f(80,80,-5);
        glVertex3f(80,80,5);
        glVertex3f(80,120,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//14 14 14 14 14 14 14 14
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(80,120,-5);
        glVertex3f(80,120,5);
        glVertex3f(90,120,5);
        glVertex3f(90,120,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//14 14 14 14 14 14 14 14
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(80,80,5);
        glVertex3f(80,80,-5);
        glVertex3f(90,80,-5);
        glVertex3f(90,80,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//15 15 15 15 15 15 15
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(90,80,5);
        glVertex3f(110,80,5);
        glVertex3f(110,90,5);
        glVertex3f(90,90,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//15 15 15 15 15 15 15
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(110,90,-5);
        glVertex3f(110,80,-5);
        glVertex3f(90,80,-5);
        glVertex3f(90,90,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//15 15 15 15 15 15 15
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(110,90,5);
        glVertex3f(110,80,5);
        glVertex3f(110,80,-5);
        glVertex3f(110,90,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//15 15 15 15 15 15 15
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(90,90,-5);
        glVertex3f(90,80,-5);
        glVertex3f(90,80,5);
        glVertex3f(90,90,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//15 15 15 15 15 15 15
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(90,90,-5);
        glVertex3f(90,90,5);
        glVertex3f(110,90,5);
        glVertex3f(110,90,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//15 15 15 15 15 15 15
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(90,80,5);
        glVertex3f(90,80,-5);
        glVertex3f(110,80,-5);
        glVertex3f(110,80,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(100,40,5);
        glVertex3f(110,40,5);
        glVertex3f(110,80,5);
        glVertex3f(100,80,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(110,80,-5);
        glVertex3f(110,40,-5);
        glVertex3f(100,40,-5);
        glVertex3f(100,80,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(110,80,5);
        glVertex3f(110,40,5);
        glVertex3f(110,40,-5);
        glVertex3f(110,80,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(100,80,-5);
        glVertex3f(100,40,-5);
        glVertex3f(100,40,5);
        glVertex3f(100,80,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(100,80,-5);
        glVertex3f(100,80,5);
        glVertex3f(110,80,5);
        glVertex3f(110,80,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(100,40,5);
        glVertex3f(100,40,-5);
        glVertex3f(110,40,-5);
        glVertex3f(110,40,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(100,100,5);
        glVertex3f(120,100,5);
        glVertex3f(120,110,5);
        glVertex3f(100,110,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(120,110,-5);
        glVertex3f(120,100,-5);
        glVertex3f(100,100,-5);
        glVertex3f(100,110,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(120,110,5);
        glVertex3f(120,100,5);
        glVertex3f(120,100,-5);
        glVertex3f(120,110,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(100,110,-5);
        glVertex3f(100,100,-5);
        glVertex3f(100,100,5);
        glVertex3f(100,110,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(100,110,-5);
        glVertex3f(100,110,5);
        glVertex3f(120,110,5);
        glVertex3f(120,110,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(100,100,5);
        glVertex3f(100,100,-5);
        glVertex3f(120,100,-5);
        glVertex3f(120,100,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//18 18 18 18 18 18 18
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(120,0,5);
        glVertex3f(130,0,5);
        glVertex3f(130,120,5);
        glVertex3f(120,120,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//18 18 18 18 18 18 18
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(130,120,-5);
        glVertex3f(130,0,-5);
        glVertex3f(120,0,-5);
        glVertex3f(120,120,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//18 18 18 18 18 18 18
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(130,120,5);
        glVertex3f(130,0,5);
        glVertex3f(130,0,-5);
        glVertex3f(130,120,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//18 18 18 18 18 18 18
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(120,120,-5);
        glVertex3f(120,0,-5);
        glVertex3f(120,0,5);
        glVertex3f(120,120,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//18 18 18 18 18 18 18
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(120,120,-5);
        glVertex3f(120,120,5);
        glVertex3f(130,120,5);
        glVertex3f(130,120,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//18 18 18 18 18 18 18
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(120,0,5);
        glVertex3f(120,0,-5);
        glVertex3f(130,0,-5);
        glVertex3f(130,0,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(60,0,5);
        glVertex3f(120,0,5);
        glVertex3f(120,10,5);
        glVertex3f(60,10,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(120,10,-5);
        glVertex3f(120,0,-5);
        glVertex3f(60,0,-5);
        glVertex3f(60,10,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(120,10,5);
        glVertex3f(120,0,5);
        glVertex3f(120,0,-5);
        glVertex3f(120,10,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(60,10,-5);
        glVertex3f(60,0,-5);
        glVertex3f(60,0,5);
        glVertex3f(60,10,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(60,10,-5);
        glVertex3f(60,10,5);
        glVertex3f(120,10,5);
        glVertex3f(120,10,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(60,0,5);
        glVertex3f(60,0,-5);
        glVertex3f(120,0,-5);
        glVertex3f(120,0,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(60,10,5);
        glVertex3f(70,10,5);
        glVertex3f(70,50,5);
        glVertex3f(60,50,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(70,50,-5);
        glVertex3f(70,10,-5);
        glVertex3f(60,10,-5);
        glVertex3f(60,50,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(70,50,5);
        glVertex3f(70,10,5);
        glVertex3f(70,10,-5);
        glVertex3f(70,50,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(60,50,-5);
        glVertex3f(60,10,-5);
        glVertex3f(60,10,5);
        glVertex3f(60,50,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(60,50,-5);
        glVertex3f(60,50,5);
        glVertex3f(70,50,5);
        glVertex3f(70,50,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(60,10,5);
        glVertex3f(60,10,-5);
        glVertex3f(70,10,-5);
        glVertex3f(70,10,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//21 21 21 21 21 21
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(20,40,5);
        glVertex3f(60,40,5);
        glVertex3f(60,50,5);
        glVertex3f(20,50,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//21 21 21 21 21 21
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(60,50,-5);
        glVertex3f(60,40,-5);
        glVertex3f(20,40,-5);
        glVertex3f(20,50,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//21 21 21 21 21 21
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(60,50,5);
        glVertex3f(60,40,5);
        glVertex3f(60,40,-5);
        glVertex3f(60,50,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//21 21 21 21 21 21
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(20,50,-5);
        glVertex3f(20,40,-5);
        glVertex3f(20,40,5);
        glVertex3f(20,50,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//21 21 21 21 21 21
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(20,50,-5);
        glVertex3f(20,50,5);
        glVertex3f(60,50,5);
        glVertex3f(60,50,-5);
        glEnd();

        //BAWAH
         glBegin(GL_POLYGON);//21 21 21 21 21 21
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(20,40,5);
        glVertex3f(20,40,-5);
        glVertex3f(60,40,-5);
        glVertex3f(60,40,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//22 22 22 22 22 22
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(20,20,5);
        glVertex3f(30,20,5);
        glVertex3f(30,40,5);
        glVertex3f(20,40,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//22 22 22 22 22 22
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(30,40,-5);
        glVertex3f(30,20,-5);
        glVertex3f(20,20,-5);
        glVertex3f(20,40,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//22 22 22 22 22 22
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(30,40,5);
        glVertex3f(30,20,5);
        glVertex3f(30,20,-5);
        glVertex3f(30,40,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//22 22 22 22 22 22
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(20,40,-5);
        glVertex3f(20,20,-5);
        glVertex3f(20,20,5);
        glVertex3f(20,40,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//22 22 22 22 22 22
        glNormal3f(0.0,1.0,0.0);
        glVertex3f(20,40,-5);
        glVertex3f(20,40,5);
        glVertex3f(30,40,5);
        glVertex3f(30,40,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//22 22 22 22 22 22
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f(20,20,5);
        glVertex3f(20,20,-5);
        glVertex3f(30,20,-5);
        glVertex3f(30,20,5);
        glEnd();
}

///Player///
void play(){
    //DEPAN
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(posX,posY,3);
    glVertex3f(posX+10,posY,3);
    glVertex3f(posX+10,posY+10,3);
    glVertex3f(posX,posY+10,3);
    glEnd();

    //BELAKANG
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f(posX+10,posY+10,-3);
    glVertex3f(posX+10,posY,-3);
    glVertex3f(posX,posY,-3);
    glVertex3f(posX,posY+10,-3);
    glEnd();

    //KANAN
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(posX+10,posY+10,3);
    glVertex3f(posX+10,posY,3);
    glVertex3f(posX+10,posY,-3);
    glVertex3f(posX+10,posY+10,-3);
    glEnd();

    //KIRI
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f(posX,posY+10,-3);
    glVertex3f(posX,posY,-3);
    glVertex3f(posX,posY,3);
    glVertex3f(posX,posY+10,3);
    glEnd();

    //ATAS
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    glVertex3f(posX,posY+10,-3);
    glVertex3f(posX,posY+10,3);
    glVertex3f(posX+10,posY+10,3);
    glVertex3f(posX+10,posY+10,-3);
    glEnd();

    //BAWAH
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f(posX,posY,3);
    glVertex3f(posX,posY,-3);
    glVertex3f(posX+10,posY,-3);
    glVertex3f(posX+10,posY,3);
    glEnd();
}

///NIM///
void nim(){
    //DEPAN
    glBegin(GL_POLYGON);//1111111111
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(12,11,0.5);
    glVertex3f(13,11,0.5);
    glVertex3f(13,19,0.5);
    glVertex3f(12,19,0.5);
    glEnd();

    //BELAKANG
    glBegin(GL_POLYGON);//1111111111
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f(13,19,-0.5);
    glVertex3f(13,11,-0.5);
    glVertex3f(12,11,-0.5);
    glVertex3f(12,19,-0.5);
    glEnd();

    //KANAN
    glBegin(GL_POLYGON);//1111111111
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(13,19,0.5);
    glVertex3f(13,11,0.5);
    glVertex3f(13,11,-0.5);
    glVertex3f(13,19,-0.5);
    glEnd();

    //KIRI
    glBegin(GL_POLYGON);//1111111111
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f(12,19,-0.5);
    glVertex3f(12,11,-0.5);
    glVertex3f(12,11,0.5);
    glVertex3f(12,19,0.5);
    glEnd();

    //ATAS
    glBegin(GL_POLYGON);//1111111111
    glNormal3f(0.0,1.0,0.0);
    glVertex3f(12,19,-0.5);
    glVertex3f(12,19,0.5);
    glVertex3f(13,19,0.5);
    glVertex3f(13,19,-0.5);
    glEnd();

    //BAWAH
    glBegin(GL_POLYGON);//1111111111
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f(12,11,0.5);
    glVertex3f(12,11,-0.5);
    glVertex3f(13,11,-0.5);
    glVertex3f(13,11,0.5);
    glEnd();

    //=================================================================//
    //======================================================================//

    //DEPAN
    glBegin(GL_POLYGON);//2222222222 atas
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(14,18,0.5);
    glVertex3f(17,18,0.5);
    glVertex3f(17,19,0.5);
    glVertex3f(14,19,0.5);
    glEnd();

    //BELAKANG
    glBegin(GL_POLYGON);//2222222222 atas
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f(17,19,-0.5);
    glVertex3f(17,18,-0.5);
    glVertex3f(14,18,-0.5);
    glVertex3f(14,19,-0.5);
    glEnd();

    //KANAN
    glBegin(GL_POLYGON);//2222222222 atas
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(17,19,0.5);
    glVertex3f(17,18,0.5);
    glVertex3f(17,18,-0.5);
    glVertex3f(17,19,-0.5);
    glEnd();

    //KIRI
    glBegin(GL_POLYGON);//2222222222 atas
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f(14,19,-0.5);
    glVertex3f(14,18,-0.5);
    glVertex3f(14,18,0.5);
    glVertex3f(14,19,0.5);
    glEnd();

    //ATAS
    glBegin(GL_POLYGON);//2222222222 atas
    glNormal3f(0.0,1.0,0.0);
    glVertex3f(14,19,-0.5);
    glVertex3f(14,19,0.5);
    glVertex3f(17,19,0.5);
    glVertex3f(17,19,-0.5);
    glEnd();

    //BAWAH
    glBegin(GL_POLYGON);//2222222222 atas
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f(14,18,0.5);
    glVertex3f(14,18,-0.5);
    glVertex3f(17,18,-0.5);
    glVertex3f(17,18,0.5);
    glEnd();

    //=================================================================//
    //======================================================================//

    //DEPAN
    glBegin(GL_POLYGON);//2222222222 atas kanan
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(16,16,0.5);
    glVertex3f(17,16,0.5);
    glVertex3f(17,19,0.5);
    glVertex3f(16,19,0.5);
    glEnd();

    //BELAKANG
    glBegin(GL_POLYGON);//2222222222 atas kanan
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f(17,19,-0.5);
    glVertex3f(17,16,-0.5);
    glVertex3f(16,16,-0.5);
    glVertex3f(16,19,-0.5);
    glEnd();

    //KANAN
    glBegin(GL_POLYGON);//2222222222 atas kanan
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(17,19,0.5);
    glVertex3f(17,16,0.5);
    glVertex3f(17,16,-0.5);
    glVertex3f(17,19,-0.5);
    glEnd();

    //KIRI
    glBegin(GL_POLYGON);//2222222222 atas kanan
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f(16,19,-0.5);
    glVertex3f(16,16,-0.5);
    glVertex3f(16,16,0.5);
    glVertex3f(16,19,0.5);
    glEnd();

    //ATAS
    glBegin(GL_POLYGON);//2222222222 atas kanan
    glNormal3f(0.0,1.0,0.0);
    glVertex3f(16,19,-0.5);
    glVertex3f(16,19,0.5);
    glVertex3f(17,19,0.5);
    glVertex3f(17,19,-0.5);
    glEnd();

    //BAWAH
    glBegin(GL_POLYGON);//2222222222 atas kanan
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f(16,16,0.5);
    glVertex3f(16,16,-0.5);
    glVertex3f(17,16,-0.5);
    glVertex3f(17,16,0.5);
    glEnd();

    //=================================================================//
    //======================================================================//

    //DEPAN
    glBegin(GL_POLYGON);//222222222 tengah
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(14,15,0.5);
    glVertex3f(17,15,0.5);
    glVertex3f(17,16,0.5);
    glVertex3f(14,16,0.5);
    glEnd();
//
    //BELAKANG
    glBegin(GL_POLYGON);//222222222 tengah
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f(17,16,-0.5);
    glVertex3f(17,15,-0.5);
    glVertex3f(14,15,-0.5);
    glVertex3f(14,16,-0.5);
    glEnd();

    //KANAN
    glBegin(GL_POLYGON);//222222222 tengah
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(17,16,0.5);
    glVertex3f(17,15,0.5);
    glVertex3f(17,15,-0.5);
    glVertex3f(17,16,-0.5);
    glEnd();

    //KIRI
    glBegin(GL_POLYGON);//222222222 tengah
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f(14,16,-0.5);
    glVertex3f(14,15,-0.5);
    glVertex3f(14,15,0.5);
    glVertex3f(14,16,0.5);
    glEnd();

    //ATAS
    glBegin(GL_POLYGON);//222222222 tengah
    glNormal3f(0.0,1.0,0.0);
    glVertex3f(14,16,-0.5);
    glVertex3f(14,16,0.5);
    glVertex3f(17,16,0.5);
    glVertex3f(17,16,-0.5);
    glEnd();

    //BAWAH
    glBegin(GL_POLYGON);//222222222 tengah
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f(14,15,0.5);
    glVertex3f(14,15,-0.5);
    glVertex3f(17,15,-0.5);
    glVertex3f(17,15,0.5);
    glEnd();

    //=================================================================//
    //======================================================================//

    //DEPAN
    glBegin(GL_POLYGON);//22222222 bawah kiri
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(14,12,0.5);
    glVertex3f(15,12,0.5);
    glVertex3f(15,15,0.5);
    glVertex3f(14,15,0.5);
    glEnd();

    //BELAKANG
    glBegin(GL_POLYGON);//22222222 bawah kiri
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f(15,15,-0.5);
    glVertex3f(15,12,-0.5);
    glVertex3f(14,12,-0.5);
    glVertex3f(14,15,-0.5);
    glEnd();

    //KANAN
    glBegin(GL_POLYGON);//22222222 bawah kiri
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(15,15,0.5);
    glVertex3f(15,12,0.5);
    glVertex3f(15,12,-0.5);
    glVertex3f(15,15,-0.5);
    glEnd();

    //KIRI
    glBegin(GL_POLYGON);//22222222 bawah kiri
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f(14,15,-0.5);
    glVertex3f(14,12,-0.5);
    glVertex3f(14,12,0.5);
    glVertex3f(14,15,0.5);
    glEnd();

    //ATAS
    glBegin(GL_POLYGON);//22222222 bawah kiri
    glNormal3f(0.0,1.0,0.0);
    glVertex3f(14,15,-0.5);
    glVertex3f(14,15,0.5);
    glVertex3f(15,15,0.5);
    glVertex3f(15,15,-0.5);
    glEnd();

    //BAWAH
    glBegin(GL_POLYGON);//22222222 bawah kiri
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f(14,12,0.5);
    glVertex3f(14,12,-0.5);
    glVertex3f(15,12,-0.5);
    glVertex3f(15,12,0.5);
    glEnd();

    //=================================================================//
    //======================================================================//

    //DEPAN
    glBegin(GL_POLYGON);//22222222 bawah
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(14,11,0.5);
    glVertex3f(17,11,0.5);
    glVertex3f(17,12,0.5);
    glVertex3f(14,12,0.5);
    glEnd();

    //BELAKANG
    glBegin(GL_POLYGON);//22222222 bawah
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f(17,12,-0.5);
    glVertex3f(17,11,-0.5);
    glVertex3f(14,11,-0.5);
    glVertex3f(14,12,-0.5);
    glEnd();

    //KANAN
    glBegin(GL_POLYGON);//22222222 bawah
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(17,12,0.5);
    glVertex3f(17,11,0.5);
    glVertex3f(17,11,-0.5);
    glVertex3f(17,12,-0.5);
    glEnd();

    //KIRI
    glBegin(GL_POLYGON);//22222222 bawah
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f(14,12,-0.5);
    glVertex3f(14,11,-0.5);
    glVertex3f(14,11,0.5);
    glVertex3f(14,12,0.5);
    glEnd();

    //ATAS
    glBegin(GL_POLYGON);//22222222 bawah
    glNormal3f(0.0,1.0,0.0);
    glVertex3f(14,12,-0.5);
    glVertex3f(14,12,0.5);
    glVertex3f(17,12,0.5);
    glVertex3f(17,12,-0.5);
    glEnd();

    //BAWAH
    glBegin(GL_POLYGON);//22222222 bawah
   glNormal3f(0.0,-1.0,0.0);
    glVertex3f(14,11,0.5);
    glVertex3f(14,11,-0.5);
    glVertex3f(17,11,-0.5);
    glVertex3f(17,11,0.5);
    glEnd();

    //=================================================================//
    //======================================================================//

    //DEPAN
    glBegin(GL_POLYGON);//11111111111111111
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(18,11,0.5);
    glVertex3f(19,11,0.5);
    glVertex3f(19,19,0.5);
    glVertex3f(18,19,0.5);
    glEnd();

    //BELAKANG
    glBegin(GL_POLYGON);//11111111111111111
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f(19,19,-0.5);
    glVertex3f(19,11,-0.5);
    glVertex3f(18,11,-0.5);
    glVertex3f(18,19,-0.5);
    glEnd();

    //KANAN
    glBegin(GL_POLYGON);//11111111111111111
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(19,19,0.5);
    glVertex3f(19,11,0.5);
    glVertex3f(19,11,-0.5);
    glVertex3f(19,19,-0.5);
    glEnd();

    //KIRI
    glBegin(GL_POLYGON);//11111111111111111
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f(18,19,-0.5);
    glVertex3f(18,11,-0.5);
    glVertex3f(18,11,0.5);
    glVertex3f(18,19,0.5);
    glEnd();

    //ATAS
    glBegin(GL_POLYGON);//11111111111111111
   glNormal3f(0.0,1.0,0.0);
    glVertex3f(18,19,-0.5);
    glVertex3f(18,19,0.5);
    glVertex3f(19,19,0.5);
    glVertex3f(19,19,-0.5);
    glEnd();

    //BAWAH
    glBegin(GL_POLYGON);//11111111111111111
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f(18,11,0.5);
    glVertex3f(18,11,-0.5);
    glVertex3f(19,11,-0.5);
    glVertex3f(19,11,0.5);
    glEnd();

    //=================================================================//
    //======================================================================//
}

///Lantai///
void floor(){
    //DEPAN
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(0,0,-5.1);
    glVertex3f(130,0,-5.1);
    glVertex3f(130,130,-5.1);
    glVertex3f(0,130,-5.1);
    glEnd();

    //BELAKANG
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f(130,130,-5.3);
    glVertex3f(130,0,-5.3);
    glVertex3f(0,0,-5.3);
    glVertex3f(0,130,-5.3);
    glEnd();

    //KANAN
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(130,130,-5.1);
    glVertex3f(130,0,-5.1);
    glVertex3f(130,0,-5.3);
    glVertex3f(130,130,-5.3);
    glEnd();

    //KIRI
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f(0,130,-5.3);
    glVertex3f(0,0,-5.3);
    glVertex3f(0,0,-5.1);
    glVertex3f(0,130,-5.1);
    glEnd();

    //ATAS
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    glVertex3f(0,130,-5.3);
    glVertex3f(0,130,-5.1);
    glVertex3f(130,130,-5.1);
    glVertex3f(130,130,-5.3);
    glEnd();

    //BAWAH
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f(0,130,-5.1);
    glVertex3f(0,130,-5.3);
    glVertex3f(130,130,-5.3);
    glVertex3f(130,130,-5.1);
    glEnd();
}

///setup material///
void material(float r, float g, float b, float a){
    GLfloat mat_specular[] = {r, g, b, a};
    GLfloat mat_shininess[] = {10.0};
    GLfloat mat_diffuse[] = {r, g, b, a};
    GLfloat mat_ambient[] = {r, g, b, a};
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
}

///Setup Orthogonal | Prespectiv
void init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glShadeModel(GL_SMOOTH);
    ///transparant
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    ///3d
    glEnable(GL_DEPTH_TEST);
    if(viewmode=="camera"){ //prespectif
        gluPerspective(35,1,1, 150);
        gluLookAt(pos[0],pos[1],pos[2],  pos[0]+viewdir[0],pos[1]+viewdir[1],pos[2]+viewdir[2],   0,0,1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    } else { //orthogonal
        glOrtho(-50,180,-50,180,-150,150);
        glMatrixMode(GL_MODELVIEW);
    }
}

///Display Object///
void display(){
    //jika tdk ada display putih
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //jika tdk ada depth gambar awal rusak // tdk ada color gmbar rusak saat v

    material(0.0, 0.0, 1.0, awall);
    if(change == false){
        //SHOW LAYOUT 1  //SHOW LAYOUT 1  //SHOW LAYOUT 1
        maze1();
    }
    else{
        //SHOW LAYOUT 2 //SHOW LAYOUT 2 //SHOW LAYOUT 2
        maze2();
    }

    material(1.0, 0.0, 0.0, 1.0);
    play();

    material(0.0, 1.0, 0.0, 1.0);
    glPushMatrix(); //gunakan push dan pop agar objek lain tdk terpengaruh
    glTranslatef(15,15,0);//3 kembalikan ke posisi awal
    glRotatef(RotNim[0], 1, 0, 0);
    glRotatef(RotNim[1], 0, 1, 0);
    glRotatef(RotNim[2], 0, 0, 1); //2 rotasi objek
    glTranslatef(-15,-15,0); // 1 pindah objek ke kordinat
    nim(); //taruh paling bawah agar transformasi brjalan
    glPopMatrix();

    material(0.4, 0.4, 0.6, 0.5);
    floor(); //taruh terakhir agar semua objek terlihat
    //glFlush();
    glutSwapBuffers();
}

///ADD SPINDISPLAY TO ROTATE NIM///
void spinDisplay(void){
    if(RotNimX==1){
        RotNim[0]+=0.05;
    } else if (RotNimZ==1){
        RotNim[1]+=0.05;
    } else if (RotNimY==1){
        RotNim[2]+=0.05;
    }
    glutPostRedisplay(); //berfungsi untuk menandai bahwa tampilan perlu untuk digambar ulang.
}

///ADD MOUSE FUNC TO ROTATE NIM///
void mouse(int button, int state, int x, int y){
    switch (button){
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
                RotNimX = 1;
                RotNimY = 0;
                RotNimZ = 0;
            break;
        case GLUT_MIDDLE_BUTTON:
            if (state == GLUT_DOWN)
                RotNimX = 0;
                RotNimY = 1;
                RotNimZ = 0;
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
                RotNimX = 0;
                RotNimY = 0;
                RotNimZ = 1;
            break;
        default:
            break;
    }
 }

///Cek Collision Player & Nim///
void cekcollision(){
    if (collision == false && baris == 11 && kolom == 1){
        cout << "\ncollision\n";
        collision = true;
    }
}

void keyboard (unsigned char key, int x, int y){
    switch (key){
        case 'v':
        case 'V':
            if (viewmode == "2d"){
                if (Vpertama == true){
                    glRotatef(-20,1,0,0);
                    Vpertama = false;
                }
                cout << "\npindah SaveRotNim ke RotNim dan hapus SaveRotNim\n=====================================\n";
                glPopMatrix(); //tampilkan penyimpanan transformasi dibawah duplikat
                for (int i=0;i<3;i++){
                    RotNim[i]=SaveRotNim[i];
                    SaveRotNim[i]=0.0;
                    cout << "RotNim " <<i<<" = "<< RotNim[i]<<"\n";
                }
                glutIdleFunc(spinDisplay);//callback function //spinDisplay: bertugas menambah nilai rotasi // terjadi berulang dan terus-menerus.
                viewmode = "3d";
            } else if (viewmode == "3d" ){
                //duplikat dan simpan transformasi terakhir
                glPushMatrix();
                viewmode = "camera";
            } else if (viewmode == "camera"){
                cout << "\npindah RotNim ke SaveRotNim dan hapus RotNim\n=====================================\n";
                for (int i=0;i<3;i++){
                    SaveRotNim[i]=RotNim[i];
                    RotNim[i]=0.0;
                    cout << "SaveRotNim " <<i<<" = "<< SaveRotNim[i]<<"\n";
                }
                glutIdleFunc(NULL);
                viewmode = "2d";
            }
            break;
        case 'c':
        case 'C':
            if(change == false){
                cout << "\nLayout 2\n";
                change = true;
            }
            else{
                change = false;
                cout << "\nLayout 1\n";
            }
            posX = 50;
            posY = 120;
            baris = 0;
            kolom = 5;
            break;
        case 'w':
        case 'W':
            baris -= 1;
            if (baris >= 0){
                if (change == false){
                    if (layout1[baris][kolom] == 0){
                        posY += 10;
                    }
                    else{
                        baris += 1;
                    }
                }
                else if (change == true){
                    if (layout2[baris][kolom] == 0){
                        posY += 10;
                    }
                    else{
                        baris += 1;
                    }
                }
                cekcollision();
            }
            else{
                baris = 0;
            }
            cout << "\nbaris = " << baris;
            cout << "\nkolom = " << kolom << "\n";
            break;
        case 's':
        case 'S':
            baris += 1;
            if (baris <= 12){
                if (change == false){
                    if (layout1[baris][kolom] == 0){
                        posY -= 10;
                    }
                    else{
                        baris -= 1;
                    }
                }
                else if (change == true){
                    if (layout2[baris][kolom] == 0){
                        posY -= 10;
                    }
                    else{
                        baris -= 1;
                    }
                }
                cekcollision();
            }
            else{
                baris = 12;
            }
            cout << "\nbaris = " << baris;
            cout << "\nkolom = " << kolom << "\n";
            break;
        case 'a':
        case 'A':
            kolom -= 1;
            if (change == false){
                if (layout1[baris][kolom] == 0){
                    posX-=10;
                }
                else{
                    kolom += 1;
                }
            }
            else{
                if (layout2[baris][kolom] == 0){
                    posX-=10;
                }
                else{
                    kolom += 1;
                }
            }
            cekcollision();
            cout << "\nbaris = " << baris;
            cout << "\nkolom = " << kolom << "\n";
            break;
        case 'd':
        case 'D':
            kolom += 1;
            if (change == false){
                if (layout1[baris][kolom] == 0){
                    posX+=10;
                }
                else{
                    kolom -= 1;
                }
            }
            else{
                if (layout2[baris][kolom] == 0){
                    posX+=10;
                }
                else{
                    kolom -= 1;
                }
            }
            cekcollision();
            cout << "\nbaris = " << baris;
            cout << "\nkolom = " << kolom << "\n";
            break;
        default:
            break;
    }

    ///ADD ROTATE MODE 3D
    ///ADD ROTATE MODE 3D
    if (viewmode == "3d"){
        if (key == 'j' || key == 'J'){
            glTranslated(65,65,0);
            glRotated(-1,0,1,0);
            glTranslated(-65,-65,0);
        }
        else if (key == 'l' || key == 'L'){
            glTranslated(65,65,0);
            glRotated(1,0,1,0);
            glTranslated(-65,-65,0);
        }
        else if (key == 'i' || key == 'I'){
            glTranslated(65,65,0);
            glRotated(-1,1,0,0);
            glTranslated(-65,-65,0);
        }
        else if (key == 'k' || key == 'K'){
            glTranslated(65,65,0);
            glRotated(1,1,0,0);
            glTranslated(-65,-65,0);
        }
    }

    if (key=='1'){
        if (amb == true){
            GLfloat ambient_light[] = { 0.1, 0.1, 0.1, 1.0 };
            glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient_light);
            amb = false;
        }
        else{
            GLfloat ambient_light[] = { 0.5, 0.5, 0.7, 1.0 };
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
    if (key=='4'){
        if (night == false){
           glClearColor(0.5,0.5,1.0,1.0);
           night=true;
        }
        else{
            glClearColor(0.0,0.0,0.0,1.0);
            night=false;
        }

    }
    if (key=='5'){
        if (awall == 1.0){
           awall = 0.3;
        }
        else{
            awall = 1.0;
        }

    }
    init();
    display();
}

///Setup Light///
void light(){
    GLfloat light_position_diff[] = {  65.0, 65.0, 100.0, 1.0 };
    GLfloat light_position_spec[] = { 65.0, 65.0, 100.0, 1.0 };
    GLfloat diffuse_light[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat specular_light[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat ambient_light[] = { 0.5, 0.5, 0.7, 1.0 };

    glLightfv(GL_LIGHT0, GL_POSITION, light_position_diff);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position_spec);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular_light);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient_light);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
}

void arrowkey(int key, int x, int y){
    if (viewmode == "camera"){
        if (key == GLUT_KEY_UP) {
            pos[0] += 0.5 * viewdir[0];
            pos[1] += 0.5 * viewdir[1];
            pos[2] += 0.5 * viewdir[2];
        } else if (key == GLUT_KEY_DOWN) {
            pos[0] -= 0.5 * viewdir[0];
            pos[1] -= 0.5 * viewdir[1];
            pos[2] -= 0.5 * viewdir[2];
        } else if (key == GLUT_KEY_LEFT) {
            alpha += 0.1;
            viewdir[0] = cos(alpha);
            viewdir[1] = sin(alpha);
        } else if (key == GLUT_KEY_RIGHT) {
            alpha -= 0.1;
            viewdir[0] = cos(alpha);
            viewdir[1] = sin(alpha);
        }
        init();
        display();
    }
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(450, 100);
    glutCreateWindow("Maze 4");
    init();
    cout << "Layout 1\n";
    cout << "Posisi Awal Player";
    cout << "\nBaris = " << baris;
    cout << "\nKolom = " << kolom << "\n";
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(arrowkey);
    glutMouseFunc(mouse);
    light();
    glutMainLoop();
    return 0;
}
