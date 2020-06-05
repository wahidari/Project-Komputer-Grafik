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
//untuk print di console
using namespace std;

//cek penekanan v pertama
bool Vpertama= true;

///Ubah Layout///
bool change=false;

///Ubah 3D///
bool mode3d = false;

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

///Player///
void play(){

    //DEPAN
    glBegin(GL_POLYGON);
    glColor3f(0,0.5,0.5);
    glVertex3f(posX,posY,5);
    glVertex3f(posX+10,posY,5);
    glVertex3f(posX+10,posY+10,5);
    glVertex3f(posX,posY+10,5);
    glEnd();

    //BELAKANG
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex3f(posX+10,posY+10,-5);
    glVertex3f(posX+10,posY,-5);
    glVertex3f(posX,posY,-5);
    glVertex3f(posX,posY+10,-5);
    glEnd();

    //KANAN
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex3f(posX+10,posY+10,5);
    glVertex3f(posX+10,posY,5);
    glVertex3f(posX+10,posY,-5);
    glVertex3f(posX+10,posY+10,-5);
    glEnd();

    //KIRI
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex3f(posX,posY+10,-5);
    glVertex3f(posX,posY,-5);
    glVertex3f(posX,posY,5);
    glVertex3f(posX,posY+10,5);
    glEnd();

    //ATAS
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex3f(posX,posY+10,-5);
    glVertex3f(posX,posY+10,5);
    glVertex3f(posX+10,posY+10,5);
    glVertex3f(posX+10,posY+10,-5);
    glEnd();

    //BAWAH
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex3f(posX,posY,5);
    glVertex3f(posX,posY,-5);
    glVertex3f(posX+10,posY,-5);
    glVertex3f(posX+10,posY,5);
    glEnd();

}

///NIM///
void nim(){
    //DEPAN
    glBegin(GL_POLYGON);//1111111111
    glColor3f(1,0,0);
    glVertex3f(12,11,0.5);
    glVertex3f(13,11,0.5);
    glVertex3f(13,19,0.5);
    glVertex3f(12,19,0.5);
    glEnd();

    //BELAKANG
    glBegin(GL_POLYGON);//1111111111
    glColor3f(1,0,0);
    glVertex3f(13,19,-0.5);
    glVertex3f(13,11,-0.5);
    glVertex3f(12,11,-0.5);
    glVertex3f(12,19,-0.5);
    glEnd();

    //KANAN
    glBegin(GL_POLYGON);//1111111111
    glColor3f(0,0,0);
    glVertex3f(13,19,0.5);
    glVertex3f(13,11,0.5);
    glVertex3f(13,11,-0.5);
    glVertex3f(13,19,-0.5);
    glEnd();

    //KIRI
    glBegin(GL_POLYGON);//1111111111
    glColor3f(0,0,0);
    glVertex3f(12,19,-0.5);
    glVertex3f(12,11,-0.5);
    glVertex3f(12,11,0.5);
    glVertex3f(12,19,0.5);
    glEnd();

    //ATAS
    glBegin(GL_POLYGON);//1111111111
    glColor3f(0,0,0);
    glVertex3f(12,19,-0.5);
    glVertex3f(12,19,0.5);
    glVertex3f(13,19,0.5);
    glVertex3f(13,19,-0.5);
    glEnd();

    //BAWAH
    glBegin(GL_POLYGON);//1111111111
    glColor3f(0,0,0);
    glVertex3f(12,11,0.5);
    glVertex3f(12,11,-0.5);
    glVertex3f(13,11,-0.5);
    glVertex3f(13,11,0.5);
    glEnd();

    //=================================================================//
    //======================================================================//

    //DEPAN
    glBegin(GL_POLYGON);//2222222222 atas
    glColor3f(1,0,0);
    glVertex3f(14,18,0.5);
    glVertex3f(17,18,0.5);
    glVertex3f(17,19,0.5);
    glVertex3f(14,19,0.5);
    glEnd();

    //BELAKANG
    glBegin(GL_POLYGON);//2222222222 atas
    glColor3f(1,0,0);
    glVertex3f(17,19,-0.5);
    glVertex3f(17,18,-0.5);
    glVertex3f(14,18,-0.5);
    glVertex3f(14,19,-0.5);
    glEnd();

    //KANAN
    glBegin(GL_POLYGON);//2222222222 atas
    glColor3f(0,0,0);
    glVertex3f(17,19,0.5);
    glVertex3f(17,18,0.5);
    glVertex3f(17,18,-0.5);
    glVertex3f(17,19,-0.5);
    glEnd();

    //KIRI
    glBegin(GL_POLYGON);//2222222222 atas
    glColor3f(0,0,0);
    glVertex3f(14,19,-0.5);
    glVertex3f(14,18,-0.5);
    glVertex3f(14,18,0.5);
    glVertex3f(14,19,0.5);
    glEnd();

    //ATAS
    glBegin(GL_POLYGON);//2222222222 atas
    glColor3f(0,0,0);
    glVertex3f(14,19,-0.5);
    glVertex3f(14,19,0.5);
    glVertex3f(17,19,0.5);
    glVertex3f(17,19,-0.5);
    glEnd();

    //BAWAH
    glBegin(GL_POLYGON);//2222222222 atas
    glColor3f(0,0,0);
    glVertex3f(14,18,0.5);
    glVertex3f(14,18,-0.5);
    glVertex3f(17,18,-0.5);
    glVertex3f(17,18,0.5);
    glEnd();

    //=================================================================//
    //======================================================================//

    //DEPAN
    glBegin(GL_POLYGON);//2222222222 atas kanan
    glColor3f(1,0,0);
    glVertex3f(16,16,0.5);
    glVertex3f(17,16,0.5);
    glVertex3f(17,19,0.5);
    glVertex3f(16,19,0.5);
    glEnd();

    //BELAKANG
    glBegin(GL_POLYGON);//2222222222 atas kanan
    glColor3f(1,0,0);
    glVertex3f(17,19,-0.5);
    glVertex3f(17,16,-0.5);
    glVertex3f(16,16,-0.5);
    glVertex3f(16,19,-0.5);
    glEnd();

    //KANAN
    glBegin(GL_POLYGON);//2222222222 atas kanan
    glColor3f(0,0,0);
    glVertex3f(17,19,0.5);
    glVertex3f(17,16,0.5);
    glVertex3f(17,16,-0.5);
    glVertex3f(17,19,-0.5);
    glEnd();

    //KIRI
    glBegin(GL_POLYGON);//2222222222 atas kanan
    glColor3f(0,0,0);
    glVertex3f(16,19,-0.5);
    glVertex3f(16,16,-0.5);
    glVertex3f(16,16,0.5);
    glVertex3f(16,19,0.5);
    glEnd();

    //ATAS
    glBegin(GL_POLYGON);//2222222222 atas kanan
    glColor3f(0,0,0);
    glVertex3f(16,19,-0.5);
    glVertex3f(16,19,0.5);
    glVertex3f(17,19,0.5);
    glVertex3f(17,19,-0.5);
    glEnd();

    //BAWAH
    glBegin(GL_POLYGON);//2222222222 atas kanan
    glColor3f(0,0,0);
    glVertex3f(16,16,0.5);
    glVertex3f(16,16,-0.5);
    glVertex3f(17,16,-0.5);
    glVertex3f(17,16,0.5);
    glEnd();

    //=================================================================//
    //======================================================================//

    //DEPAN
    glBegin(GL_POLYGON);//222222222 tengah
    glColor3f(1,0,0);
    glVertex3f(14,15,0.5);
    glVertex3f(17,15,0.5);
    glVertex3f(17,16,0.5);
    glVertex3f(14,16,0.5);
    glEnd();
//
    //BELAKANG
    glBegin(GL_POLYGON);//222222222 tengah
    glColor3f(1,0,0);
    glVertex3f(17,16,-0.5);
    glVertex3f(17,15,-0.5);
    glVertex3f(14,15,-0.5);
    glVertex3f(14,16,-0.5);
    glEnd();

    //KANAN
    glBegin(GL_POLYGON);//222222222 tengah
    glColor3f(0,0,0);
    glVertex3f(17,16,0.5);
    glVertex3f(17,15,0.5);
    glVertex3f(17,15,-0.5);
    glVertex3f(17,16,-0.5);
    glEnd();

    //KIRI
    glBegin(GL_POLYGON);//222222222 tengah
    glColor3f(0,0,0);
    glVertex3f(14,16,-0.5);
    glVertex3f(14,15,-0.5);
    glVertex3f(14,15,0.5);
    glVertex3f(14,16,0.5);
    glEnd();

    //ATAS
    glBegin(GL_POLYGON);//222222222 tengah
    glColor3f(0,0,0);
    glVertex3f(14,16,-0.5);
    glVertex3f(14,16,0.5);
    glVertex3f(17,16,0.5);
    glVertex3f(17,16,-0.5);
    glEnd();

    //BAWAH
    glBegin(GL_POLYGON);//222222222 tengah
    glColor3f(0,0,0);
    glVertex3f(14,15,0.5);
    glVertex3f(14,15,-0.5);
    glVertex3f(17,15,-0.5);
    glVertex3f(17,15,0.5);
    glEnd();

    //=================================================================//
    //======================================================================//

    //DEPAN
    glBegin(GL_POLYGON);//22222222 bawah kiri
    glColor3f(1,0,0);
    glVertex3f(14,12,0.5);
    glVertex3f(15,12,0.5);
    glVertex3f(15,15,0.5);
    glVertex3f(14,15,0.5);
    glEnd();

    //BELAKANG
    glBegin(GL_POLYGON);//22222222 bawah kiri
    glColor3f(1,0,0);
    glVertex3f(15,15,-0.5);
    glVertex3f(15,12,-0.5);
    glVertex3f(14,12,-0.5);
    glVertex3f(14,15,-0.5);
    glEnd();

    //KANAN
    glBegin(GL_POLYGON);//22222222 bawah kiri
    glColor3f(0,0,0);
    glVertex3f(15,15,0.5);
    glVertex3f(15,12,0.5);
    glVertex3f(15,12,-0.5);
    glVertex3f(15,15,-0.5);
    glEnd();

    //KIRI
    glBegin(GL_POLYGON);//22222222 bawah kiri
    glColor3f(0,0,0);
    glVertex3f(14,15,-0.5);
    glVertex3f(14,12,-0.5);
    glVertex3f(14,12,0.5);
    glVertex3f(14,15,0.5);
    glEnd();

    //ATAS
    glBegin(GL_POLYGON);//22222222 bawah kiri
    glColor3f(0,0,0);
    glVertex3f(14,15,-0.5);
    glVertex3f(14,15,0.5);
    glVertex3f(15,15,0.5);
    glVertex3f(15,15,-0.5);
    glEnd();

    //BAWAH
    glBegin(GL_POLYGON);//22222222 bawah kiri
    glColor3f(0,0,0);
    glVertex3f(14,12,0.5);
    glVertex3f(14,12,-0.5);
    glVertex3f(15,12,-0.5);
    glVertex3f(15,12,0.5);
    glEnd();

    //=================================================================//
    //======================================================================//

    //DEPAN
    glBegin(GL_POLYGON);//22222222 bawah
    glColor3f(1,0,0);
    glVertex3f(14,11,0.5);
    glVertex3f(17,11,0.5);
    glVertex3f(17,12,0.5);
    glVertex3f(14,12,0.5);
    glEnd();

    //BELAKANG
    glBegin(GL_POLYGON);//22222222 bawah
    glColor3f(1,0,0);
    glVertex3f(17,12,-0.5);
    glVertex3f(17,11,-0.5);
    glVertex3f(14,11,-0.5);
    glVertex3f(14,12,-0.5);
    glEnd();

    //KANAN
    glBegin(GL_POLYGON);//22222222 bawah
    glColor3f(0,0,0);
    glVertex3f(17,12,0.5);
    glVertex3f(17,11,0.5);
    glVertex3f(17,11,-0.5);
    glVertex3f(17,12,-0.5);
    glEnd();

    //KIRI
    glBegin(GL_POLYGON);//22222222 bawah
    glColor3f(0,0,0);
    glVertex3f(14,12,-0.5);
    glVertex3f(14,11,-0.5);
    glVertex3f(14,11,0.5);
    glVertex3f(14,12,0.5);
    glEnd();

    //ATAS
    glBegin(GL_POLYGON);//22222222 bawah
    glColor3f(0,0,0);
    glVertex3f(14,12,-0.5);
    glVertex3f(14,12,0.5);
    glVertex3f(17,12,0.5);
    glVertex3f(17,12,-0.5);
    glEnd();

    //BAWAH
    glBegin(GL_POLYGON);//22222222 bawah
    glColor3f(0,0,0);
    glVertex3f(14,11,0.5);
    glVertex3f(14,11,-0.5);
    glVertex3f(17,11,-0.5);
    glVertex3f(17,11,0.5);
    glEnd();

    //=================================================================//
    //======================================================================//

    //DEPAN
    glBegin(GL_POLYGON);//11111111111111111
    glColor3f(1,0,0);
    glVertex3f(18,11,0.5);
    glVertex3f(19,11,0.5);
    glVertex3f(19,19,0.5);
    glVertex3f(18,19,0.5);
    glEnd();

    //BELAKANG
    glBegin(GL_POLYGON);//11111111111111111
    glColor3f(1,0,0);
    glVertex3f(19,19,-0.5);
    glVertex3f(19,11,-0.5);
    glVertex3f(18,11,-0.5);
    glVertex3f(18,19,-0.5);
    glEnd();

    //KANAN
    glBegin(GL_POLYGON);//11111111111111111
    glColor3f(0,0,0);
    glVertex3f(19,19,0.5);
    glVertex3f(19,11,0.5);
    glVertex3f(19,11,-0.5);
    glVertex3f(19,19,-0.5);
    glEnd();

    //KIRI
    glBegin(GL_POLYGON);//11111111111111111
    glColor3f(0,0,0);
    glVertex3f(18,19,-0.5);
    glVertex3f(18,11,-0.5);
    glVertex3f(18,11,0.5);
    glVertex3f(18,19,0.5);
    glEnd();

    //ATAS
    glBegin(GL_POLYGON);//11111111111111111
    glColor3f(0,0,0);
    glVertex3f(18,19,-0.5);
    glVertex3f(18,19,0.5);
    glVertex3f(19,19,0.5);
    glVertex3f(19,19,-0.5);
    glEnd();

    //BAWAH
    glBegin(GL_POLYGON);//11111111111111111
    glColor3f(0,0,0);
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
    glColor4f(0.0, 0.0, 1.0, 0.2);

    //DEPAN
    glBegin(GL_POLYGON);
    glVertex3f(0,0,-5.1);
    glVertex3f(130,0,-5.1);
    glVertex3f(130,130,-5.1);
    glVertex3f(0,130,-5.1);
    glEnd();

    //BELAKANG
    glBegin(GL_POLYGON);
    glVertex3f(130,130,-5.3);
    glVertex3f(130,0,-5.3);
    glVertex3f(0,0,-5.3);
    glVertex3f(0,130,-5.3);
    glEnd();

    //KANAN
    glBegin(GL_POLYGON);
    glVertex3f(130,130,-5.1);
    glVertex3f(130,0,-5.1);
    glVertex3f(130,0,-5.3);
    glVertex3f(130,130,-5.3);
    glEnd();

    //KIRI
    glBegin(GL_POLYGON);
    glVertex3f(0,130,-5.3);
    glVertex3f(0,0,-5.3);
    glVertex3f(0,0,-5.1);
    glVertex3f(0,130,-5.1);
    glEnd();

    //ATAS
    glBegin(GL_POLYGON);
    glVertex3f(0,130,-5.3);
    glVertex3f(0,130,-5.1);
    glVertex3f(130,130,-5.1);
    glVertex3f(130,130,-5.3);
    glEnd();

    //BAWAH
    glBegin(GL_POLYGON);
    glVertex3f(0,130,-5.1);
    glVertex3f(0,130,-5.3);
    glVertex3f(130,130,-5.3);
    glVertex3f(130,130,-5.1);
    glEnd();
}

void display(){
    //jika tdk ada display putih
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //jika tdk ada depth gambar awal rusak // tdk ada color gmbar rusak saat v

    if(change == false){ //SHOW LAYOUT 1  //SHOW LAYOUT 1  //SHOW LAYOUT 1
        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON); //1111111111111111
        glColor3f(0,0,1);
        glVertex3f(0,120,5);
        glVertex3f(50,120,5);
        glVertex3f(50,130,5);
        glVertex3f(0,130,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON); //1111111111111111
        glColor3f(0,0.5,0.5);
        glVertex3f(50,130,-5);
        glVertex3f(50,120,-5);
        glVertex3f(0,120,-5);
        glVertex3f(0,130,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON); //1111111111111111
        glColor3f(0,1,1);
        glVertex3f(50,130,5);
        glVertex3f(50,120,5);
        glVertex3f(50,120,-5);
        glVertex3f(50,130,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON); //1111111111111111
        glColor3f(1,0,0);
        glVertex3f(0,130,-5);
        glVertex3f(0,120,-5);
        glVertex3f(0,120,5);
        glVertex3f(0,130,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON); //1111111111111111
        glColor3f(0,1,0);
        glVertex3f(0,130,-5);
        glVertex3f(0,130,5);
        glVertex3f(50,130,5);
        glVertex3f(50,130,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON); //1111111111111111
        glColor3f(1,1,0);
        glVertex3f(0,120,5);
        glVertex3f(0,120,-5);
        glVertex3f(50,120,-5);
        glVertex3f(50,120,5);
        glEnd();


        //=============================================================//
        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//2222222222222222
        glColor3f(0,0,1);
        glVertex3f(0,0,5);
        glVertex3f(10,0,5);
        glVertex3f(10,130,5);
        glVertex3f(0,130,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//2222222222222222
        glColor3f(0,0.5,0.5);
        glVertex3f(10,130,-5);
        glVertex3f(10,0,-5);
        glVertex3f(0,0,-5);
        glVertex3f(0,130,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//2222222222222222
        glColor3f(0,1,1);
        glVertex3f(10,130,5);
        glVertex3f(10,0,5);
        glVertex3f(10,0,-5);
        glVertex3f(10,130,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//2222222222222222
        glColor3f(1,0,0);
        glVertex3f(0,130,-5);
        glVertex3f(0,0,-5);
        glVertex3f(0,0,5);
        glVertex3f(0,130,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//2222222222222222
        glColor3f(0,1,0);
        glVertex3f(0,130,-5);
        glVertex3f(0,130,5);
        glVertex3f(10,130,5);
        glVertex3f(10,130,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//2222222222222222
        glColor3f(1,1,0);
        glVertex3f(0,0,5);
        glVertex3f(10,0,5);
        glVertex3f(10,0,-5);
        glVertex3f(0,0,-5);
        glEnd();

        //=============================================================//
        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//3333333333333333
        glColor3f(0,0,1);
        glVertex3f(0,0,5);
        glVertex3f(50,0,5);
        glVertex3f(50,10,5);
        glVertex3f(0,10,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//3333333333333333
        glColor3f(0,0.5,0.5);
        glVertex3f(50,10,-5);
        glVertex3f(50,0,-5);
        glVertex3f(0,0,-5);
        glVertex3f(0,10,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//3333333333333333
        glColor3f(0,1,1);
        glVertex3f(50,10,5);
        glVertex3f(50,0,5);
        glVertex3f(50,0,-5);
        glVertex3f(50,10,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//3333333333333333
        glColor3f(1,0,0);
        glVertex3f(0,10,-5);
        glVertex3f(0,0,-5);
        glVertex3f(0,0,5);
        glVertex3f(0,10,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//3333333333333333
        glColor3f(0,1,0);
        glVertex3f(0,10,-5);
        glVertex3f(0,10,5);
        glVertex3f(50,10,5);
        glVertex3f(50,10,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//3333333333333333
        glColor3f(1,1,0);
        glVertex3f(0,0,5);
        glVertex3f(0,0,-5);
        glVertex3f(50,0,-5);
        glVertex3f(50,0,5);
        glEnd();


//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//4444444444444444444
        glColor3f(0,0,1);
        glVertex3f(0,40,5);
        glVertex3f(30,40,5);
        glVertex3f(30,50,5);
        glVertex3f(0,50,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//4444444444444444444
        glColor3f(0,0.5,0.5);
        glVertex3f(30,50,-5);
        glVertex3f(30,40,-5);
        glVertex3f(0,40,-5);
        glVertex3f(0,50,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//4444444444444444444
        glColor3f(0,1,1);
        glVertex3f(30,50,5);
        glVertex3f(30,40,5);
        glVertex3f(30,40,-5);
        glVertex3f(30,50,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//4444444444444444444
        glColor3f(1,0,0);
        glVertex3f(0,50,-5);
        glVertex3f(0,40,-5);
        glVertex3f(0,40,5);
        glVertex3f(0,50,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//4444444444444444444
        glColor3f(0,1,0);
        glVertex3f(0,50,-5);
        glVertex3f(0,50,5);
        glVertex3f(30,50,5);
        glVertex3f(30,50,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//4444444444444444444
        glColor3f(1,1,0);
        glVertex3f(0,40,5);
        glVertex3f(0,40,-5);
        glVertex3f(30,40,-5);
        glVertex3f(30,40,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//5555555555555555555
        glColor3f(0,0,1);
        glVertex3f(40,100,5);
        glVertex3f(50,100,5);
        glVertex3f(50,130,5);
        glVertex3f(40,130,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//5555555555555555555
       glColor3f(0,0.5,0.5);
        glVertex3f(50,130,-5);
        glVertex3f(50,100,-5);
        glVertex3f(40,100,-5);
        glVertex3f(40,130,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//5555555555555555555
        glColor3f(0,1,1);
        glVertex3f(50,130,5);
        glVertex3f(50,100,5);
        glVertex3f(50,100,-5);
        glVertex3f(50,130,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//5555555555555555555
        glColor3f(1,0,0);
        glVertex3f(40,130,-5);
        glVertex3f(40,100,-5);
        glVertex3f(40,100,5);
        glVertex3f(40,130,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//5555555555555555555
        glColor3f(0,1,0);
        glVertex3f(40,130,-5);
        glVertex3f(40,130,5);
        glVertex3f(50,130,5);
        glVertex3f(50,130,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//5555555555555555555
        glColor3f(1,1,0);
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
        glColor3f(0,0,1);
        glVertex3f(40,100,5);
        glVertex3f(70,100,5);
        glVertex3f(70,110,5);
        glVertex3f(40,110,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//66666666666666666
        glColor3f(0,0.5,0.5);
        glVertex3f(70,110,-5);
        glVertex3f(70,100,-5);
        glVertex3f(40,100,-5);
        glVertex3f(40,110,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//66666666666666666
        glColor3f(0,1,1);
        glVertex3f(70,110,5);
        glVertex3f(70,100,5);
        glVertex3f(70,100,-5);
        glVertex3f(70,110,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//66666666666666666
        glColor3f(1,0,0);
        glVertex3f(40,110,-5);
        glVertex3f(40,100,-5);
        glVertex3f(40,100,5);
        glVertex3f(40,110,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//66666666666666666
        glColor3f(0,1,0);
        glVertex3f(40,110,-5);
        glVertex3f(40,110,5);
        glVertex3f(70,110,5);
        glVertex3f(70,110,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//66666666666666666
        glColor3f(1,1,0);
        glVertex3f(40,100,5);
        glVertex3f(40,100,-5);
        glVertex3f(70,100,-5);
        glVertex3f(70,100,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//7777777777777777777777
        glColor3f(0,0,1);
        glVertex3f(60,60,5);
        glVertex3f(70,60,5);
        glVertex3f(70,110,5);
        glVertex3f(60,110,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//7777777777777777777777
        glColor3f(0,0.5,0.5);
        glVertex3f(70,110,-5);
        glVertex3f(70,60,-5);
        glVertex3f(60,60,-5);
        glVertex3f(60,110,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//7777777777777777777777
       glColor3f(0,1,1);
        glVertex3f(70,110,5);
        glVertex3f(70,60,5);
        glVertex3f(70,60,-5);
        glVertex3f(70,110,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//7777777777777777777777
        glColor3f(1,0,0);
        glVertex3f(60,110,-5);
        glVertex3f(60,60,-5);
        glVertex3f(60,60,5);
        glVertex3f(60,110,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//7777777777777777777777
        glColor3f(0,1,0);
        glVertex3f(60,110,-5);
        glVertex3f(60,110,5);
        glVertex3f(70,110,5);
        glVertex3f(70,110,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//7777777777777777777777
        glColor3f(1,1,0);
        glVertex3f(60,60,5);
        glVertex3f(60,60,-5);
        glVertex3f(70,60,-5);
        glVertex3f(70,60,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//88888888888888888888888
        glColor3f(0,0,1);
        glVertex3f(20,80,5);
        glVertex3f(70,80,5);
        glVertex3f(70,90,5);
        glVertex3f(20,90,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//88888888888888888888888
        glColor3f(0,0.5,0.5);
        glVertex3f(70,90,-5);
        glVertex3f(70,80,-5);
        glVertex3f(20,80,-5);
        glVertex3f(20,90,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//88888888888888888888888
        glColor3f(0,1,1);
        glVertex3f(70,90,5);
        glVertex3f(70,80,5);
        glVertex3f(70,80,-5);
        glVertex3f(70,90,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//88888888888888888888888
        glColor3f(1,0,0);
        glVertex3f(20,90,-5);
        glVertex3f(20,80,-5);
        glVertex3f(20,80,5);
        glVertex3f(20,90,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//88888888888888888888888
        glColor3f(0,1,0);
        glVertex3f(20,90,-5);
        glVertex3f(20,90,5);
        glVertex3f(70,90,5);
        glVertex3f(70,90,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//88888888888888888888888
        glColor3f(1,1,0);
        glVertex3f(20,80,5);
        glVertex3f(20,80,-5);
        glVertex3f(70,80,-5);
        glVertex3f(70,80,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//999999999999999999999
        glColor3f(0,0,1);
        glVertex3f(20,80,5);
        glVertex3f(30,80,5);
        glVertex3f(30,110,5);
        glVertex3f(20,110,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//999999999999999999999
        glColor3f(0,0.5,0.5);
        glVertex3f(30,110,-5);
        glVertex3f(30,80,-5);
        glVertex3f(20,80,-5);
        glVertex3f(20,110,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//999999999999999999999
        glColor3f(0,1,1);
        glVertex3f(30,110,5);
        glVertex3f(30,80,5);
        glVertex3f(30,80,-5);
        glVertex3f(30,110,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//999999999999999999999
        glColor3f(1,0,0);
        glVertex3f(20,110,-5);
        glVertex3f(20,80,-5);
        glVertex3f(20,80,5);
        glVertex3f(20,110,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//999999999999999999999
        glColor3f(0,1,0);
        glVertex3f(20,110,-5);
        glVertex3f(20,110,5);
        glVertex3f(30,110,5);
        glVertex3f(30,110,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//999999999999999999999
        glColor3f(1,1,0);
        glVertex3f(20,80,5);
        glVertex3f(20,80,-5);
        glVertex3f(30,80,-5);
        glVertex3f(30,80,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//10 10 10 10 10
        glColor3f(0,0,1);
        glVertex3f(60,60,5);
        glVertex3f(110,60,5);
        glVertex3f(110,70,5);
        glVertex3f(60,70,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//10 10 10 10 10
        glColor3f(0,0.5,0.5);
        glVertex3f(110,70,-5);
        glVertex3f(110,60,-5);
        glVertex3f(60,60,-5);
        glVertex3f(60,70,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//10 10 10 10 10
        glColor3f(0,1,1);
        glVertex3f(110,70,5);
        glVertex3f(110,60,5);
        glVertex3f(110,60,-5);
        glVertex3f(110,70,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//10 10 10 10 10
        glColor3f(1,0,0);
        glVertex3f(60,70,-5);
        glVertex3f(60,60,-5);
        glVertex3f(60,60,5);
        glVertex3f(60,70,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//10 10 10 10 10
        glColor3f(0,1,0);
        glVertex3f(60,70,-5);
        glVertex3f(60,70,5);
        glVertex3f(110,70,5);
        glVertex3f(110,70,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//10 10 10 10 10
        glColor3f(1,1,0);
        glVertex3f(60,60,5);
        glVertex3f(60,60,-5);
        glVertex3f(110,60,-5);
        glVertex3f(110,60,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glColor3f(0,0,1);
        glVertex3f(100,20,5);
        glVertex3f(110,20,5);
        glVertex3f(110,90,5);
        glVertex3f(100,90,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glColor3f(0,0.5,0.5);
        glVertex3f(110,90,-5);
        glVertex3f(110,20,-5);
        glVertex3f(100,20,-5);
        glVertex3f(100,90,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glColor3f(0,1,1);
        glVertex3f(110,90,5);
        glVertex3f(110,20,5);
        glVertex3f(110,20,-5);
        glVertex3f(110,90,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glColor3f(1,0,0);
        glVertex3f(100,90,-5);
        glVertex3f(100,20,-5);
        glVertex3f(100,20,5);
        glVertex3f(100,90,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glColor3f(0,1,0);
        glVertex3f(100,90,-5);
        glVertex3f(100,90,5);
        glVertex3f(110,90,5);
        glVertex3f(110,90,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glColor3f(1,1,0);
        glVertex3f(100,20,5);
        glVertex3f(100,20,-5);
        glVertex3f(110,20,-5);
        glVertex3f(110,20,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12
        glColor3f(0,0,1);
        glVertex3f(80,20,5);
        glVertex3f(110,20,5);
        glVertex3f(110,30,5);
        glVertex3f(80,30,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12
        glColor3f(0,0.5,0.5);
        glVertex3f(110,30,-5);
        glVertex3f(110,20,-5);
        glVertex3f(80,20,-5);
        glVertex3f(80,30,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12
        glColor3f(0,1,1);
        glVertex3f(110,30,5);
        glVertex3f(110,20,5);
        glVertex3f(110,20,-5);
        glVertex3f(110,30,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12
        glColor3f(1,0,0);
        glVertex3f(80,30,-5);
        glVertex3f(80,20,-5);
        glVertex3f(80,20,5);
        glVertex3f(80,30,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12
        glColor3f(0,1,0);
        glVertex3f(80,30,-5);
        glVertex3f(80,30,5);
        glVertex3f(110,30,5);
        glVertex3f(110,30,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12
        glColor3f(1,1,0);
        glVertex3f(80,20,5);
        glVertex3f(80,20,-5);
        glVertex3f(110,20,-5);
        glVertex3f(110,20,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//13 13 13 13 13 13
        glColor3f(0,0,1);
        glVertex3f(80,20,5);
        glVertex3f(90,20,5);
        glVertex3f(90,50,5);
        glVertex3f(80,50,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//13 13 13 13 13 13
        glColor3f(0,0.5,0.5);
        glVertex3f(90,50,-5);
        glVertex3f(90,20,-5);
        glVertex3f(80,20,-5);
        glVertex3f(80,50,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//13 13 13 13 13 13
        glColor3f(0,1,1);
        glVertex3f(90,50,5);
        glVertex3f(90,20,5);
        glVertex3f(90,20,-5);
        glVertex3f(90,50,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//13 13 13 13 13 13
        glColor3f(1,0,0);
        glVertex3f(80,50,-5);
        glVertex3f(80,20,-5);
        glVertex3f(80,20,5);
        glVertex3f(80,50,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//13 13 13 13 13 13
        glColor3f(0,1,0);
        glVertex3f(80,50,-5);
        glVertex3f(80,50,5);
        glVertex3f(90,50,5);
        glVertex3f(90,50,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//13 13 13 13 13 13
        glColor3f(1,1,0);
        glVertex3f(80,20,5);
        glVertex3f(80,20,-5);
        glVertex3f(90,20,-5);
        glVertex3f(90,20,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);// 14 14 14 14 14 14 14
        glColor3f(0,0,1);
        glVertex3f(60,120,5);
        glVertex3f(130,120,5);
        glVertex3f(130,130,5);
        glVertex3f(60,130,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);// 14 14 14 14 14 14 14
        glColor3f(0,0.5,0.5);
        glVertex3f(130,130,-5);
        glVertex3f(130,120,-5);
        glVertex3f(60,120,-5);
        glVertex3f(60,130,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);// 14 14 14 14 14 14 14
        glColor3f(0,1,1);
        glVertex3f(130,130,5);
        glVertex3f(130,120,5);
        glVertex3f(130,120,-5);
        glVertex3f(130,130,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);// 14 14 14 14 14 14 14
        glColor3f(1,0,0);
        glVertex3f(60,130,-5);
        glVertex3f(60,120,-5);
        glVertex3f(60,120,5);
        glVertex3f(60,130,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);// 14 14 14 14 14 14 14
        glColor3f(0,1,0);
        glVertex3f(60,130,-5);
        glVertex3f(60,130,5);
        glVertex3f(130,130,5);
        glVertex3f(130,130,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);// 14 14 14 14 14 14 14
        glColor3f(1,1,0);
        glVertex3f(60,120,5);
        glVertex3f(60,120,-5);
        glVertex3f(130,120,-5);
        glVertex3f(130,120,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON); //15 15 15 15 15 15 15
        glColor3f(0,0,1);
        glVertex3f(80,80,5);
        glVertex3f(90,80,5);
        glVertex3f(90,130,5);
        glVertex3f(80,130,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON); //15 15 15 15 15 15 15
        glColor3f(0,0.5,0.5);
        glVertex3f(90,130,-5);
        glVertex3f(90,80,-5);
        glVertex3f(80,80,-5);
        glVertex3f(80,130,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON); //15 15 15 15 15 15 15
        glColor3f(0,1,1);
        glVertex3f(90,130,5);
        glVertex3f(90,80,5);
        glVertex3f(90,80,-5);
        glVertex3f(90,130,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON); //15 15 15 15 15 15 15
        glColor3f(1,0,0);
        glVertex3f(80,130,-5);
        glVertex3f(80,80,-5);
        glVertex3f(80,80,5);
        glVertex3f(80,130,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON); //15 15 15 15 15 15 15
        glColor3f(0,1,0);
        glVertex3f(80,130,-5);
        glVertex3f(80,130,5);
        glVertex3f(90,130,5);
        glVertex3f(90,130,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON); //15 15 15 15 15 15 15
        glColor3f(1,1,0);
        glVertex3f(80,80,5);
        glVertex3f(80,80,-5);
        glVertex3f(90,80,-5);
        glVertex3f(90,80,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glColor3f(0,0,1);
        glVertex3f(80,100,5);
        glVertex3f(110,100,5);
        glVertex3f(110,110,5);
        glVertex3f(80,110,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glColor3f(0,0.5,0.5);
        glVertex3f(110,110,-5);
        glVertex3f(110,100,-5);
        glVertex3f(80,100,-5);
        glVertex3f(80,110,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glColor3f(0,1,1);
        glVertex3f(110,110,5);
        glVertex3f(110,100,5);
        glVertex3f(110,100,-5);
        glVertex3f(110,110,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glColor3f(1,0,0);
        glVertex3f(80,110,-5);
        glVertex3f(80,100,-5);
        glVertex3f(80,100,5);
        glVertex3f(80,110,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glColor3f(0,1,0);
        glVertex3f(80,110,-5);
        glVertex3f(80,110,5);
        glVertex3f(110,110,5);
        glVertex3f(110,110,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glColor3f(1,1,0);
        glVertex3f(80,100,5);
        glVertex3f(80,100,-5);
        glVertex3f(110,100,-5);
        glVertex3f(110,100,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//
        //DEPAN
         glBegin(GL_POLYGON);//17 17 17 17 17 17 17
         glColor3f(0,0,1);
        glVertex3f(120,0,5);
        glVertex3f(130,0,5);
        glVertex3f(130,130,5);
        glVertex3f(120,130,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glColor3f(0,0.5,0.5);
        glVertex3f(130,130,-5);
        glVertex3f(130,0,-5);
        glVertex3f(120,0,-5);
        glVertex3f(120,130,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glColor3f(0,1,1);
        glVertex3f(130,130,5);
        glVertex3f(130,0,5);
        glVertex3f(130,0,-5);
        glVertex3f(130,130,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glColor3f(1,0,0);
        glVertex3f(120,130,-5);
        glVertex3f(120,0,-5);
        glVertex3f(120,0,5);
        glVertex3f(120,130,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glColor3f(0,1,0);
        glVertex3f(120,130,-5);
        glVertex3f(120,130,5);
        glVertex3f(130,130,5);
        glVertex3f(130,130,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glColor3f(1,1,0);
        glVertex3f(120,0,5);
        glVertex3f(120,0,-5);
        glVertex3f(130,0,-5);
        glVertex3f(130,0,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//18 18 18 18 18 18
        glColor3f(0,0,1);
        glVertex3f(60,0,5);
        glVertex3f(130,0,5);
        glVertex3f(130,10,5);
        glVertex3f(60,10,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//18 18 18 18 18 18
        glColor3f(0,0.5,0.5);
        glVertex3f(130,10,-5);
        glVertex3f(130,0,-5);
        glVertex3f(60,0,-5);
        glVertex3f(60,10,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//18 18 18 18 18 18
        glColor3f(0,1,1);
        glVertex3f(130,10,5);
        glVertex3f(130,0,5);
        glVertex3f(130,0,-5);
        glVertex3f(130,10,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//18 18 18 18 18 18
        glColor3f(1,0,0);
        glVertex3f(60,10,-5);
        glVertex3f(60,0,-5);
        glVertex3f(60,0,5);
        glVertex3f(60,10,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//18 18 18 18 18 18
        glColor3f(0,1,0);
        glVertex3f(60,10,-5);
        glVertex3f(60,10,5);
        glVertex3f(130,10,5);
        glVertex3f(130,10,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//18 18 18 18 18 18
        glColor3f(1,1,0);
        glVertex3f(60,0,5);
        glVertex3f(60,0,-5);
        glVertex3f(130,0,-5);
        glVertex3f(130,0,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glColor3f(0,0,1);
        glVertex3f(60,0,5);
        glVertex3f(70,0,5);
        glVertex3f(70,50,5);
        glVertex3f(60,50,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glColor3f(0,0.5,0.5);
        glVertex3f(70,50,-5);
        glVertex3f(70,0,-5);
        glVertex3f(60,0,-5);
        glVertex3f(60,50,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glColor3f(0,1,1);
        glVertex3f(70,50,5);
        glVertex3f(70,0,5);
        glVertex3f(70,0,-5);
        glVertex3f(70,50,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glColor3f(1,0,0);
        glVertex3f(60,50,-5);
        glVertex3f(60,0,-5);
        glVertex3f(60,0,5);
        glVertex3f(60,50,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glColor3f(0,1,0);
        glVertex3f(60,50,-5);
        glVertex3f(60,50,5);
        glVertex3f(70,50,5);
        glVertex3f(70,50,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glColor3f(1,1,0);
        glVertex3f(60,0,5);
        glVertex3f(60,0,-5);
        glVertex3f(70,0,-5);
        glVertex3f(70,0,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glColor3f(0,0,1);
        glVertex3f(40,40,5);
        glVertex3f(70,40,5);
        glVertex3f(70,50,5);
        glVertex3f(40,50,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glColor3f(0,0.5,0.5);
        glVertex3f(70,50,-5);
        glVertex3f(70,40,-5);
        glVertex3f(40,40,-5);
        glVertex3f(40,50,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glColor3f(0,1,1);
        glVertex3f(70,50,5);
        glVertex3f(70,40,5);
        glVertex3f(70,40,-5);
        glVertex3f(70,50,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glColor3f(1,0,0);
        glVertex3f(40,50,-5);
        glVertex3f(40,40,-5);
        glVertex3f(40,40,5);
        glVertex3f(40,50,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glColor3f(0,1,0);
        glVertex3f(40,50,-5);
        glVertex3f(40,50,5);
        glVertex3f(70,50,5);
        glVertex3f(70,50,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glColor3f(1,1,0);
        glVertex3f(40,40,5);
        glVertex3f(40,40,-5);
        glVertex3f(70,40,-5);
        glVertex3f(70,40,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//21 21 21 21 21 21 21
        glColor3f(0,0,1);
        glVertex3f(40,20,5);
        glVertex3f(50,20,5);
        glVertex3f(50,70,5);
        glVertex3f(40,70,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//21 21 21 21 21 21 21
        glColor3f(0,0.5,0.5);
        glVertex3f(50,70,-5);
        glVertex3f(50,20,-5);
        glVertex3f(40,20,-5);
        glVertex3f(40,70,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//21 21 21 21 21 21 21
        glColor3f(0,1,1);
        glVertex3f(50,70,5);
        glVertex3f(50,20,5);
        glVertex3f(50,20,-5);
        glVertex3f(50,70,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//21 21 21 21 21 21 21
        glColor3f(1,0,0);
        glVertex3f(40,70,-5);
        glVertex3f(40,20,-5);
        glVertex3f(40,20,5);
        glVertex3f(40,70,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//21 21 21 21 21 21 21
        glColor3f(0,1,0);
        glVertex3f(40,70,-5);
        glVertex3f(40,70,5);
        glVertex3f(50,70,5);
        glVertex3f(50,70,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//21 21 21 21 21 21 21
        glColor3f(1,1,0);
        glVertex3f(40,20,-5);
        glVertex3f(40,20,5);
        glVertex3f(50,20,5);
        glVertex3f(50,20,-5);
        glEnd();


//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//22 22 22 22 22 22 22 22
        glColor3f(0,0,1);
        glVertex3f(20,60,5);
        glVertex3f(50,60,5);
        glVertex3f(50,70,5);
        glVertex3f(20,70,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//22 22 22 22 22 22 22 22
        glColor3f(0,0.5,0.5);
        glVertex3f(50,70,-5);
        glVertex3f(50,60,-5);
        glVertex3f(20,60,-5);
        glVertex3f(20,70,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//22 22 22 22 22 22 22 22
        glColor3f(0,1,1);
        glVertex3f(50,70,5);
        glVertex3f(50,60,5);
        glVertex3f(50,60,-5);
        glVertex3f(50,70,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//22 22 22 22 22 22 22 22
        glColor3f(1,0,0);
        glVertex3f(20,70,-5);
        glVertex3f(20,60,-5);
        glVertex3f(20,60,5);
        glVertex3f(20,70,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//22 22 22 22 22 22 22 22
        glColor3f(0,1,0);
        glVertex3f(20,70,-5);
        glVertex3f(20,70,5);
        glVertex3f(50,70,5);
        glVertex3f(50,70,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//22 22 22 22 22 22 22 22
        glColor3f(1,1,0);
        glVertex3f(20,60,5);
        glVertex3f(20,60,-5);
        glVertex3f(50,60,-5);
        glVertex3f(50,60,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//23 23 23 23 23 23 23
        glColor3f(0,0,1);
        glVertex3f(20,20,5);
        glVertex3f(50,20,5);
        glVertex3f(50,30,5);
        glVertex3f(20,30,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//23 23 23 23 23 23 23
        glColor3f(0,0.5,0.5);
        glVertex3f(50,30,-5);
        glVertex3f(50,20,-5);
        glVertex3f(20,20,-5);
        glVertex3f(20,30,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//23 23 23 23 23 23 23
        glColor3f(0,1,1);
        glVertex3f(50,30,5);
        glVertex3f(50,20,5);
        glVertex3f(50,20,-5);
        glVertex3f(50,30,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//23 23 23 23 23 23 23
        glColor3f(1,0,0);
        glVertex3f(20,30,-5);
        glVertex3f(20,20,-5);
        glVertex3f(20,20,5);
        glVertex3f(20,30,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//23 23 23 23 23 23 23
        glColor3f(0,1,0);
        glVertex3f(20,30,-5);
        glVertex3f(20,30,5);
        glVertex3f(50,30,5);
        glVertex3f(50,30,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//23 23 23 23 23 23 23
        glColor3f(1,1,0);
        glVertex3f(20,20,5);
        glVertex3f(20,20,-5);
        glVertex3f(50,20,-5);
        glVertex3f(50,20,5);
        glEnd();


    }
    else{//SHOW LAYOUT 2 //SHOW LAYOUT 2 //SHOW LAYOUT 2
        //=============================================================//
        //DEPAN
        glBegin(GL_POLYGON);//11111111111111111111
        glColor3f(0,0,1);
        glVertex3f(0,120,5);
        glVertex3f(50,120,5);
        glVertex3f(50,130,5);
        glVertex3f(0,130,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//11111111111111111111
        glColor3f(0,0.5,0.5);
        glVertex3f(50,130,-5);
        glVertex3f(50,120,-5);
        glVertex3f(0,120,-5);
        glVertex3f(0,130,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//11111111111111111111
        glColor3f(0,1,1);
        glVertex3f(50,130,5);
        glVertex3f(50,120,5);
        glVertex3f(50,120,-5);
        glVertex3f(50,130,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//11111111111111111111
        glColor3f(1,0,0);
        glVertex3f(0,130,-5);
        glVertex3f(0,120,-5);
        glVertex3f(0,120,5);
        glVertex3f(0,130,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//11111111111111111111
        glColor3f(0,1,0);
        glVertex3f(0,130,-5);
        glVertex3f(0,130,5);
        glVertex3f(50,130,5);
        glVertex3f(50,130,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//11111111111111111111
        glColor3f(1,1,0);
        glVertex3f(0,120,5);
        glVertex3f(0,120,-5);
        glVertex3f(50,120,-5);
        glVertex3f(50,120,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//2222222222222222222222
        glColor3f(0,0,1);
        glVertex3f(0,0,5);
        glVertex3f(10,0,5);
        glVertex3f(10,130,5);
        glVertex3f(0,130,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//2222222222222222222222
        glColor3f(0,0.5,0.5);
        glVertex3f(10,130,-5);
        glVertex3f(10,0,-5);
        glVertex3f(0,0,-5);
        glVertex3f(0,130,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//2222222222222222222222
        glColor3f(0,1,1);
        glVertex3f(10,130,5);
        glVertex3f(10,0,5);
        glVertex3f(10,0,-5);
        glVertex3f(10,130,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//2222222222222222222222
        glColor3f(1,0,0);
        glVertex3f(0,130,-5);
        glVertex3f(0,0,-5);
        glVertex3f(0,0,5);
        glVertex3f(0,130,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//2222222222222222222222
        glColor3f(0,1,0);
        glVertex3f(0,130,-5);
        glVertex3f(0,130,5);
        glVertex3f(10,130,5);
        glVertex3f(10,130,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//2222222222222222222222
        glColor3f(1,1,0);
        glVertex3f(0,0,5);
        glVertex3f(0,0,-5);
        glVertex3f(10,0,-5);
        glVertex3f(10,0,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//333333333333333333
        glColor3f(0,0,1);
        glVertex3f(0,0,5);
        glVertex3f(50,0,5);
        glVertex3f(50,10,5);
        glVertex3f(0,10,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//333333333333333333
        glColor3f(0,0.5,0.5);
        glVertex3f(50,10,-5);
        glVertex3f(50,0,-5);
        glVertex3f(0,0,-5);
        glVertex3f(0,10,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//333333333333333333
        glColor3f(0,1,1);
        glVertex3f(50,10,5);
        glVertex3f(50,0,5);
        glVertex3f(50,0,-5);
        glVertex3f(50,10,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//333333333333333333
        glColor3f(1,0,0);
        glVertex3f(0,10,-5);
        glVertex3f(0,0,-5);
        glVertex3f(0,0,5);
        glVertex3f(0,10,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//333333333333333333
        glColor3f(0,1,0);
        glVertex3f(00,10,-5);
        glVertex3f(00,10,5);
        glVertex3f(50,10,5);
        glVertex3f(50,10,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//333333333333333333
        glColor3f(1,1,0);
        glVertex3f(00,0,5);
        glVertex3f(00,0,-5);
        glVertex3f(50,0,-5);
        glVertex3f(50,0,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//444444444444444444444
        glColor3f(0,0,1);
        glVertex3f(40,0,5);
        glVertex3f(50,0,5);
        glVertex3f(50,30,5);
        glVertex3f(40,30,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//444444444444444444444
        glColor3f(0,0.5,0.5);
        glVertex3f(50,30,-5);
        glVertex3f(50,0,-5);
        glVertex3f(40,0,-5);
        glVertex3f(40,30,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//444444444444444444444
        glColor3f(0,1,1);
        glVertex3f(50,30,5);
        glVertex3f(50,0,5);
        glVertex3f(50,0,-5);
        glVertex3f(50,30,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//444444444444444444444
        glColor3f(1,0,0);
        glVertex3f(40,30,-5);
        glVertex3f(40,0,-5);
        glVertex3f(40,0,5);
        glVertex3f(40,30,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//444444444444444444444
        glColor3f(0,1,0);
        glVertex3f(40,30,-5);
        glVertex3f(40,30,5);
        glVertex3f(50,30,5);
        glVertex3f(50,30,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//444444444444444444444
        glColor3f(1,1,0);
        glVertex3f(40,0,5);
        glVertex3f(40,0,-5);
        glVertex3f(50,0,-5);
        glVertex3f(50,0,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//555555555555555555
        glColor3f(0,0,1);
        glVertex3f(0,100,5);
        glVertex3f(30,100,5);
        glVertex3f(30,110,5);
        glVertex3f(0,110,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//555555555555555555
        glColor3f(0,0.5,0.5);
        glVertex3f(30,110,-5);
        glVertex3f(30,100,-5);
        glVertex3f(0,100,-5);
        glVertex3f(0,110,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//555555555555555555
        glColor3f(0,1,1);
        glVertex3f(30,110,5);
        glVertex3f(30,100,5);
        glVertex3f(30,100,-5);
        glVertex3f(30,110,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//555555555555555555
        glColor3f(1,0,0);
        glVertex3f(0,110,-5);
        glVertex3f(0,100,-5);
        glVertex3f(0,100,5);
        glVertex3f(0,110,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//555555555555555555
        glColor3f(0,1,0);
        glVertex3f(0,110,-5);
        glVertex3f(0,110,5);
        glVertex3f(30,110,5);
        glVertex3f(30,110,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//555555555555555555
        glColor3f(1,1,0);
        glVertex3f(0,100,5);
        glVertex3f(0,100,-5);
        glVertex3f(30,100,-5);
        glVertex3f(30,100,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//666666666666666666666
        glColor3f(0,0,1);
        glVertex3f(40,80,5);
        glVertex3f(50,80,5);
        glVertex3f(50,130,5);
        glVertex3f(40,130,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//666666666666666666666
        glColor3f(0,0.5,0.5);
        glVertex3f(50,130,-5);
        glVertex3f(50,80,-5);
        glVertex3f(40,80,-5);
        glVertex3f(40,130,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//666666666666666666666
        glColor3f(0,1,1);
        glVertex3f(50,130,5);
        glVertex3f(50,80,5);
        glVertex3f(50,80,-5);
        glVertex3f(50,130,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//666666666666666666666
        glColor3f(1,0,0);
        glVertex3f(40,130,-5);
        glVertex3f(40,80,-5);
        glVertex3f(40,80,5);
        glVertex3f(40,130,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//666666666666666666666
        glColor3f(0,1,0);
        glVertex3f(40,130,-5);
        glVertex3f(40,130,5);
        glVertex3f(50,130,5);
        glVertex3f(50,130,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//666666666666666666666
        glColor3f(1,1,0);
        glVertex3f(40,80,5);
        glVertex3f(40,80,-5);
        glVertex3f(50,80,-5);
        glVertex3f(50,80,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//7777777777777777777
        glColor3f(0,0,1);
        glVertex3f(40,100,5);
        glVertex3f(70,100,5);
        glVertex3f(70,110,5);
        glVertex3f(40,110,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//7777777777777777777
        glColor3f(0,0.5,0.5);
        glVertex3f(70,110,-5);
        glVertex3f(70,100,-5);
        glVertex3f(40,100,-5);
        glVertex3f(40,110,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//7777777777777777777
        glColor3f(0,1,1);
        glVertex3f(70,110,5);
        glVertex3f(70,100,5);
        glVertex3f(70,100,-5);
        glVertex3f(70,110,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//7777777777777777777
        glColor3f(1,0,0);
        glVertex3f(40,110,-5);
        glVertex3f(40,100,-5);
        glVertex3f(40,100,5);
        glVertex3f(40,110,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//7777777777777777777
        glColor3f(0,1,0);
        glVertex3f(40,110,-5);
        glVertex3f(40,110,5);
        glVertex3f(70,110,5);
        glVertex3f(70,110,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//7777777777777777777
        glColor3f(1,1,0);
        glVertex3f(40,100,5);
        glVertex3f(40,100,-5);
        glVertex3f(70,100,-5);
        glVertex3f(70,100,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//888888888888888888888
        glColor3f(0,0,1);
        glVertex3f(60,60,5);
        glVertex3f(70,60,5);
        glVertex3f(70,110,5);
        glVertex3f(60,110,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//888888888888888888888
        glColor3f(0,0.5,0.5);
        glVertex3f(70,110,-5);
        glVertex3f(70,60,-5);
        glVertex3f(60,60,-5);
        glVertex3f(60,110,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//888888888888888888888
        glColor3f(0,1,1);
        glVertex3f(70,110,5);
        glVertex3f(70,60,5);
        glVertex3f(70,60,-5);
        glVertex3f(70,110,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//888888888888888888888
        glColor3f(1,0,0);
        glVertex3f(60,110,-5);
        glVertex3f(60,60,-5);
        glVertex3f(60,60,5);
        glVertex3f(60,110,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//888888888888888888888
        glColor3f(0,1,0);
        glVertex3f(60,110,-5);
        glVertex3f(60,110,5);
        glVertex3f(70,110,5);
        glVertex3f(70,110,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//888888888888888888888
        glColor3f(1,1,0);
        glVertex3f(60,60,5);
        glVertex3f(60,60,-5);
        glVertex3f(70,60,-5);
        glVertex3f(70,60,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//9999999999999999999999
        glColor3f(0,0,1);
        glVertex3f(20,60,5);
        glVertex3f(90,60,5);
        glVertex3f(90,70,5);
        glVertex3f(20,70,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//9999999999999999999999
        glColor3f(0,0.5,0.5);
        glVertex3f(90,70,-5);
        glVertex3f(90,60,-5);
        glVertex3f(20,60,-5);
        glVertex3f(20,70,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//9999999999999999999999
        glColor3f(0,1,1);
        glVertex3f(90,70,5);
        glVertex3f(90,60,5);
        glVertex3f(90,60,-5);
        glVertex3f(90,70,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//9999999999999999999999
       glColor3f(1,0,0);
        glVertex3f(20,70,-5);
        glVertex3f(20,60,-5);
        glVertex3f(20,60,5);
        glVertex3f(20,70,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//9999999999999999999999
        glColor3f(0,1,0);
        glVertex3f(20,70,-5);
        glVertex3f(20,70,5);
        glVertex3f(90,70,5);
        glVertex3f(90,70,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//9999999999999999999999
        glColor3f(1,1,0);
        glVertex3f(20,60,5);
        glVertex3f(20,60,-5);
        glVertex3f(90,60,-5);
        glVertex3f(90,60,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//10 10 10 10 10 10
        glColor3f(0,0,1);
        glVertex3f(20,60,5);
        glVertex3f(30,60,5);
        glVertex3f(30,90,5);
        glVertex3f(20,90,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//10 10 10 10 10 10
        glColor3f(0,0.5,0.5);
        glVertex3f(30,90,-5);
        glVertex3f(30,60,-5);
        glVertex3f(20,60,-5);
        glVertex3f(20,90,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//10 10 10 10 10 10
        glColor3f(0,1,1);
        glVertex3f(30,90,5);
        glVertex3f(30,60,5);
        glVertex3f(30,60,-5);
        glVertex3f(30,90,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//10 10 10 10 10 10
        glColor3f(1,0,0);
        glVertex3f(20,90,-5);
        glVertex3f(20,60,-5);
        glVertex3f(20,60,5);
        glVertex3f(20,90,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//10 10 10 10 10 10
        glColor3f(0,1,0);
        glVertex3f(20,90,-5);
        glVertex3f(20,90,5);
        glVertex3f(30,90,5);
        glVertex3f(30,90,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//10 10 10 10 10 10
        glColor3f(1,1,0);
        glVertex3f(20,60,5);
        glVertex3f(20,60,-5);
        glVertex3f(30,60,-5);
        glVertex3f(30,60,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glColor3f(0,0,1);
        glVertex3f(80,20,5);
        glVertex3f(90,20,5);
        glVertex3f(90,70,5);
        glVertex3f(80,70,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glColor3f(0,0.5,0.5);
        glVertex3f(90,70,-5);
        glVertex3f(90,20,-5);
        glVertex3f(80,20,-5);
        glVertex3f(80,70,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glColor3f(0,1,1);
        glVertex3f(90,70,5);
        glVertex3f(90,20,5);
        glVertex3f(90,20,-5);
        glVertex3f(90,70,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glColor3f(1,0,0);
        glVertex3f(80,70,-5);
        glVertex3f(80,20,-5);
        glVertex3f(80,20,5);
        glVertex3f(80,70,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glColor3f(0,1,0);
        glVertex3f(80,70,-5);
        glVertex3f(80,70,5);
        glVertex3f(90,70,5);
        glVertex3f(90,70,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//11 11 11 11 11 11 11
        glColor3f(1,1,0);
        glVertex3f(80,20,5);
        glVertex3f(80,20,-5);
        glVertex3f(90,20,-5);
        glVertex3f(90,20,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12 12
        glColor3f(0,0,1);
        glVertex3f(80,20,5);
        glVertex3f(110,20,5);
        glVertex3f(110,30,5);
        glVertex3f(80,30,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12 12
        glColor3f(0,0.5,0.5);
        glVertex3f(110,30,-5);
        glVertex3f(110,20,-5);
        glVertex3f(80,20,-5);
        glVertex3f(80,30,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12 12
        glColor3f(0,1,1);
        glVertex3f(110,30,5);
        glVertex3f(110,20,5);
        glVertex3f(110,20,-5);
        glVertex3f(110,30,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12 12
        glColor3f(1,0,0);
        glVertex3f(80,30,-5);
        glVertex3f(80,20,-5);
        glVertex3f(80,20,5);
        glVertex3f(80,30,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12 12
        glColor3f(0,1,0);
        glVertex3f(80,30,-5);
        glVertex3f(80,30,5);
        glVertex3f(110,30,5);
        glVertex3f(110,30,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//12 12 12 12 12 12 12 12
        glColor3f(1,1,0);
        glVertex3f(80,20,5);
        glVertex3f(80,20,-5);
        glVertex3f(110,20,-5);
        glVertex3f(110,20,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//13 13 13 13 13 13 13
        glColor3f(0,0,1);
        glVertex3f(60,120,5);
        glVertex3f(130,120,5);
        glVertex3f(130,130,5);
        glVertex3f(60,130,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//13 13 13 13 13 13 13
        glColor3f(0,0.5,0.5);
        glVertex3f(130,130,-5);
        glVertex3f(130,120,-5);
        glVertex3f(60,120,-5);
        glVertex3f(60,130,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//13 13 13 13 13 13 13
        glColor3f(0,1,1);
        glVertex3f(130,130,5);
        glVertex3f(130,120,5);
        glVertex3f(130,120,-5);
        glVertex3f(130,130,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//13 13 13 13 13 13 13
        glColor3f(1,0,0);
        glVertex3f(60,130,-5);
        glVertex3f(60,120,-5);
        glVertex3f(60,120,5);
        glVertex3f(60,130,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//13 13 13 13 13 13 13
        glColor3f(0,1,0);
        glVertex3f(60,130,-5);
        glVertex3f(60,130,5);
        glVertex3f(130,130,5);
        glVertex3f(130,130,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//13 13 13 13 13 13 13
        glColor3f(1,1,0);
        glVertex3f(60,120,5);
        glVertex3f(60,120,-5);
        glVertex3f(130,120,-5);
        glVertex3f(130,120,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//14 14 14 14 14 14 14 14
        glColor3f(0,0,1);
        glVertex3f(80,80,5);
        glVertex3f(90,80,5);
        glVertex3f(90,130,5);
        glVertex3f(80,130,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//14 14 14 14 14 14 14 14
        glColor3f(0,0.5,0.5);
        glVertex3f(90,130,-5);
        glVertex3f(90,80,-5);
        glVertex3f(80,80,-5);
        glVertex3f(80,130,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//14 14 14 14 14 14 14 14
        glColor3f(0,1,1);
        glVertex3f(90,130,5);
        glVertex3f(90,80,5);
        glVertex3f(90,80,-5);
        glVertex3f(90,130,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//14 14 14 14 14 14 14 14
        glColor3f(1,0,0);
        glVertex3f(80,130,-5);
        glVertex3f(80,80,-5);
        glVertex3f(80,80,5);
        glVertex3f(80,130,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//14 14 14 14 14 14 14 14
        glColor3f(0,1,0);
        glVertex3f(80,130,-5);
        glVertex3f(80,130,5);
        glVertex3f(90,130,5);
        glVertex3f(90,130,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//14 14 14 14 14 14 14 14
        glColor3f(1,1,0);
        glVertex3f(80,80,5);
        glVertex3f(80,80,-5);
        glVertex3f(90,80,-5);
        glVertex3f(90,80,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//15 15 15 15 15 15 15
        glColor3f(0,0,1);
        glVertex3f(80,80,5);
        glVertex3f(110,80,5);
        glVertex3f(110,90,5);
        glVertex3f(80,90,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//15 15 15 15 15 15 15
        glColor3f(0,0.5,0.5);
        glVertex3f(110,90,-5);
        glVertex3f(110,80,-5);
        glVertex3f(80,80,-5);
        glVertex3f(80,90,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//15 15 15 15 15 15 15
        glColor3f(0,1,1);
        glVertex3f(110,90,5);
        glVertex3f(110,80,5);
        glVertex3f(110,80,-5);
        glVertex3f(110,90,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//15 15 15 15 15 15 15
        glColor3f(1,0,0);
        glVertex3f(80,90,-5);
        glVertex3f(80,80,-5);
        glVertex3f(80,80,5);
        glVertex3f(80,90,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//15 15 15 15 15 15 15
        glColor3f(0,1,0);
        glVertex3f(80,90,-5);
        glVertex3f(80,90,5);
        glVertex3f(110,90,5);
        glVertex3f(110,90,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//15 15 15 15 15 15 15
        glColor3f(1,1,0);
        glVertex3f(80,80,5);
        glVertex3f(80,80,-5);
        glVertex3f(110,80,-5);
        glVertex3f(110,80,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glColor3f(0,0,1);
        glVertex3f(100,40,5);
        glVertex3f(110,40,5);
        glVertex3f(110,90,5);
        glVertex3f(100,90,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glColor3f(0,0.5,0.5);
        glVertex3f(110,90,-5);
        glVertex3f(110,40,-5);
        glVertex3f(100,40,-5);
        glVertex3f(100,90,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glColor3f(0,1,1);
        glVertex3f(110,90,5);
        glVertex3f(110,40,5);
        glVertex3f(110,40,-5);
        glVertex3f(110,90,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glColor3f(1,0,0);
        glVertex3f(100,90,-5);
        glVertex3f(100,40,-5);
        glVertex3f(100,40,5);
        glVertex3f(100,90,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glColor3f(0,1,0);
        glVertex3f(100,90,-5);
        glVertex3f(100,90,5);
        glVertex3f(110,90,5);
        glVertex3f(110,90,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//16 16 16 16 16 16 16
        glColor3f(1,1,0);
        glVertex3f(100,40,5);
        glVertex3f(100,40,-5);
        glVertex3f(110,40,-5);
        glVertex3f(110,40,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glColor3f(0,0,1);
        glVertex3f(100,100,5);
        glVertex3f(130,100,5);
        glVertex3f(130,110,5);
        glVertex3f(100,110,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glColor3f(0,0.5,0.5);
        glVertex3f(130,110,-5);
        glVertex3f(130,100,-5);
        glVertex3f(100,100,-5);
        glVertex3f(100,110,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glColor3f(0,1,1);
        glVertex3f(130,110,5);
        glVertex3f(130,100,5);
        glVertex3f(130,100,-5);
        glVertex3f(130,110,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glColor3f(1,0,0);
        glVertex3f(100,110,-5);
        glVertex3f(100,100,-5);
        glVertex3f(100,100,5);
        glVertex3f(100,110,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glColor3f(0,1,0);
        glVertex3f(100,110,-5);
        glVertex3f(100,110,5);
        glVertex3f(130,110,5);
        glVertex3f(130,110,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//17 17 17 17 17 17 17
        glColor3f(1,1,0);
        glVertex3f(100,100,5);
        glVertex3f(100,100,-5);
        glVertex3f(130,100,-5);
        glVertex3f(130,100,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//18 18 18 18 18 18 18
        glColor3f(0,0,1);
        glVertex3f(120,0,5);
        glVertex3f(130,0,5);
        glVertex3f(130,130,5);
        glVertex3f(120,130,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//18 18 18 18 18 18 18
        glColor3f(0,0.5,0.5);
        glVertex3f(130,130,-5);
        glVertex3f(130,0,-5);
        glVertex3f(120,0,-5);
        glVertex3f(120,130,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//18 18 18 18 18 18 18
        glColor3f(0,1,1);
        glVertex3f(130,130,5);
        glVertex3f(130,0,5);
        glVertex3f(130,0,-5);
        glVertex3f(130,130,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//18 18 18 18 18 18 18
        glColor3f(1,0,0);
        glVertex3f(120,130,-5);
        glVertex3f(120,0,-5);
        glVertex3f(120,0,5);
        glVertex3f(120,130,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//18 18 18 18 18 18 18
        glColor3f(0,1,0);
        glVertex3f(120,130,-5);
        glVertex3f(120,130,5);
        glVertex3f(130,130,5);
        glVertex3f(130,130,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//18 18 18 18 18 18 18
        glColor3f(1,1,0);
        glVertex3f(120,0,5);
        glVertex3f(120,0,-5);
        glVertex3f(130,0,-5);
        glVertex3f(130,0,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glColor3f(0,0,1);
        glVertex3f(60,0,5);
        glVertex3f(130,0,5);
        glVertex3f(130,10,5);
        glVertex3f(60,10,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glColor3f(0,0.5,0.5);
        glVertex3f(130,10,-5);
        glVertex3f(130,0,-5);
        glVertex3f(60,0,-5);
        glVertex3f(60,10,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glColor3f(0,1,1);
        glVertex3f(130,10,5);
        glVertex3f(130,0,5);
        glVertex3f(130,0,-5);
        glVertex3f(130,10,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glColor3f(1,0,0);
        glVertex3f(60,10,-5);
        glVertex3f(60,0,-5);
        glVertex3f(60,0,5);
        glVertex3f(60,10,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glColor3f(0,1,0);
        glVertex3f(60,10,-5);
        glVertex3f(60,10,5);
        glVertex3f(130,10,5);
        glVertex3f(130,10,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//19 19 19 19 19 19 19
        glColor3f(1,1,0);
        glVertex3f(60,0,5);
        glVertex3f(60,0,-5);
        glVertex3f(130,0,-5);
        glVertex3f(130,0,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glColor3f(0,0,1);
        glVertex3f(60,0,5);
        glVertex3f(70,0,5);
        glVertex3f(70,50,5);
        glVertex3f(60,50,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glColor3f(0,0.5,0.5);
        glVertex3f(70,50,-5);
        glVertex3f(70,0,-5);
        glVertex3f(60,0,-5);
        glVertex3f(60,50,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glColor3f(0,1,1);
        glVertex3f(70,50,5);
        glVertex3f(70,0,5);
        glVertex3f(70,0,-5);
        glVertex3f(70,50,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glColor3f(1,0,0);
        glVertex3f(60,50,-5);
        glVertex3f(60,0,-5);
        glVertex3f(60,0,5);
        glVertex3f(60,50,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glColor3f(0,1,0);
        glVertex3f(60,50,-5);
        glVertex3f(60,50,5);
        glVertex3f(70,50,5);
        glVertex3f(70,50,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//20 20 20 20 20 20 20
        glColor3f(1,1,0);
        glVertex3f(60,0,5);
        glVertex3f(60,0,-5);
        glVertex3f(70,0,-5);
        glVertex3f(70,0,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//21 21 21 21 21 21
        glColor3f(0,0,1);
        glVertex3f(20,40,5);
        glVertex3f(70,40,5);
        glVertex3f(70,50,5);
        glVertex3f(20,50,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//21 21 21 21 21 21
        glColor3f(0,0.5,0.5);
        glVertex3f(70,50,-5);
        glVertex3f(70,40,-5);
        glVertex3f(20,40,-5);
        glVertex3f(20,50,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//21 21 21 21 21 21
        glColor3f(0,1,1);
        glVertex3f(70,50,5);
        glVertex3f(70,40,5);
        glVertex3f(70,40,-5);
        glVertex3f(70,50,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//21 21 21 21 21 21
        glColor3f(1,0,0);
        glVertex3f(20,50,-5);
        glVertex3f(20,40,-5);
        glVertex3f(20,40,5);
        glVertex3f(20,50,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//21 21 21 21 21 21
        glColor3f(0,1,0);
        glVertex3f(20,50,-5);
        glVertex3f(20,50,5);
        glVertex3f(70,50,5);
        glVertex3f(70,50,-5);
        glEnd();

        //BAWAH
         glBegin(GL_POLYGON);//21 21 21 21 21 21
        glColor3f(1,1,0);
        glVertex3f(20,40,5);
        glVertex3f(20,40,-5);
        glVertex3f(70,40,-5);
        glVertex3f(70,40,5);
        glEnd();

//        //=============================================================//
//        //=============================================================//

        //DEPAN
        glBegin(GL_POLYGON);//22 22 22 22 22 22
        glColor3f(0,0,1);
        glVertex3f(20,20,5);
        glVertex3f(30,20,5);
        glVertex3f(30,50,5);
        glVertex3f(20,50,5);
        glEnd();

        //BELAKANG
        glBegin(GL_POLYGON);//22 22 22 22 22 22
        glColor3f(0,0.5,0.5);
        glVertex3f(30,50,-5);
        glVertex3f(30,20,-5);
        glVertex3f(20,20,-5);
        glVertex3f(20,50,-5);
        glEnd();

        //KANAN
        glBegin(GL_POLYGON);//22 22 22 22 22 22
        glColor3f(0,1,1);
        glVertex3f(30,50,5);
        glVertex3f(30,20,5);
        glVertex3f(30,20,-5);
        glVertex3f(30,50,-5);
        glEnd();

        //KIRI
        glBegin(GL_POLYGON);//22 22 22 22 22 22
        glColor3f(1,0,0);
        glVertex3f(20,50,-5);
        glVertex3f(20,20,-5);
        glVertex3f(20,20,5);
        glVertex3f(20,50,5);
        glEnd();

        //ATAS
        glBegin(GL_POLYGON);//22 22 22 22 22 22
        glColor3f(0,1,0);
        glVertex3f(20,50,-5);
        glVertex3f(20,50,5);
        glVertex3f(30,50,5);
        glVertex3f(30,50,-5);
        glEnd();

        //BAWAH
        glBegin(GL_POLYGON);//22 22 22 22 22 22
        glColor3f(1,1,0);
        glVertex3f(20,20,5);
        glVertex3f(20,20,-5);
        glVertex3f(30,20,-5);
        glVertex3f(30,20,5);
        glEnd();


    }

    play();

    glPushMatrix(); //gunakan push dan pop agar objek lain tdk terpengaruh
    glTranslatef(15,15,0);//3 kembalikan ke posisi awal
    glRotatef(RotNim[0], 1, 0, 0);
    glRotatef(RotNim[1], 0, 1, 0);
    glRotatef(RotNim[2], 0, 0, 1); //2 rotasi objek
    glTranslatef(-15,-15,0); // 1 pindah objek ke kordinat
    nim(); //taruh paling bawah agar transformasi brjalan
    glPopMatrix();

    floor(); //taruh terakhir agar semua objek terlihat
    glFlush();
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
//    cout << "RotNimX = " << RotNim[0]<<"\n";
//    cout << "RotNimY = " << RotNim[1]<<"\n";
//    cout << "RotNimZ = " << RotNim[2]<<"\n";
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

void keyboard (unsigned char key, int x, int y){
    switch (key){
        case 'v':
        case 'V':
            if (mode3d == false){
                if (Vpertama == true){
                    glRotatef(-25,1,0,0);
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
                mode3d = true;
            } else if (mode3d == true){
                cout << "\npindah RotNim ke SaveRotNim dan hapus RotNim\n=====================================\n";
                for (int i=0;i<3;i++){
                    SaveRotNim[i]=RotNim[i];
                    RotNim[i]=0.0;
                    cout << "SaveRotNim " <<i<<" = "<< SaveRotNim[i]<<"\n";
                }
                glPushMatrix(); //duplikat dan simpan transformasi terakhir
                glLoadIdentity(); //menetralkan efek transformasi pada duplikat
                glutIdleFunc(NULL);
                mode3d = false;
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
            cout << "\nbaris = " << baris;
            cout << "\nkolom = " << kolom << "\n";
            break;
        default:
            break;
    }

    ///ADD ROTATE MODE 3D
    ///ADD ROTATE MODE 3D
    if (mode3d == true){
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

    display();

}

void init(void){
    glMatrixMode(GL_PROJECTION); //jika tdk ada objek hilang saat v 2x
    ///yang diperlukan untuk 3D
    glOrtho(-50, 180, -50, 180, -150, 150); // jika range z kurang, objek terpotong saat di rotasi x dan y
    glMatrixMode(GL_MODELVIEW); //jika tdk ada objek hilang saat v 2x
    glShadeModel (GL_FLAT); //diperlukan pada beberapa kasus
    glEnable(GL_DEPTH_TEST); //jika tidak ada layout rusak saat ditekan tombol v
    ///============================
    ///Transparent Floor
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    ///=========================///

    glClearColor(1,1,1,1);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(450, 100);
    glutCreateWindow("Maze 3D v10 Fix Rotasi Nim");
    init();
    cout << "Layout 1\n";
    cout << "Posisi Awal Player";
    cout << "\nBaris = " << baris;
    cout << "\nKolom = " << kolom << "\n";
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
