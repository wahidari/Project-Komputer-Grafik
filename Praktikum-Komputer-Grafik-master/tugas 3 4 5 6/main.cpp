#include <windows.h>
#include <math.h>
#include <time.h>
#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

boolean diff = true, spec = true,  spec2 = true , amb = true;
char rot = 'z';
float theta[3] = {0,0,0} , ukuran = 2 , speed = 1;

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

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   // glLoadIdentity();
    GLfloat mat_specular[] = {0.5, 0.5, 0.5, 1.0};
    GLfloat mat_shininess[] = {10.0};
    GLfloat mat_diffuse[] = {0.7, 0.7, 0.7, 1.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

    glPushMatrix(); //gunakan push dan pop agar objek lain tdk terpengaruh
    glTranslatef(15,15,0);//3 kembalikan ke posisi awal
    glRotatef(theta[0], 1, 0, 0);
    glRotatef(theta[1], 0, 1, 0);
    glRotatef(theta[2], 0, 0, 1);
    glScalef(ukuran,ukuran,ukuran);
    glTranslatef(-15,-15,0); // 1 pindah objek ke kordinat
    nim(); //taruh paling bawah agar transformasi brjalan
    glPopMatrix();

    glPushMatrix(); //gunakan push dan pop agar objek lain tdk terpengaruh
    glTranslatef(30,30,0);
    glRotatef(theta[0], 1, 0, 0);
    glRotatef(theta[1], 0, 1, 0);
    glRotatef(theta[2], 0, 0, 1);
    glScalef(0.5,0.5,0.5);
    glTranslatef(-15,-15,0);
    nim();
    glColor3f(0,0.5,0.5);
    glPopMatrix();

    glPushMatrix(); //gunakan push dan pop agar objek lain tdk terpengaruh
    glColor3f(1,0,0);
    glTranslatef(0,0,0);
    glRotatef(theta[0], 1, 0, 0);
    glRotatef(theta[1], 0, 1, 0);
    glRotatef(theta[2], 0, 0, 1);
    glScalef(0.5,0.5,0.5);
    glTranslatef(-15,-15,0);
    nim();
    glPopMatrix();

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 40, -10, 40, -100, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void myinit() {

    glClearColor(0.3, 0.3, 0.3, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    GLfloat light_position_diff[] = {-1.0, 1.0, 1.0, 0.0};
    GLfloat diffuse_light[] = {0.0, 1.0, 1.0, 1.0};

    GLfloat light_position_spec[] = {1.0, 0.0, 1.0, 0.0};
    GLfloat specular_light[] = {0.0, 1.0, 1.0, 1.0};

    GLfloat light_position_spec2[] = {1.0, -1.0, 1.0, 0.0};
    GLfloat specular_light2[] = {1.0, 1.0, 0.0, 1.0};

    GLfloat ambient_light[] = {0.5, 0.5, 0.5, 1.0};

    glLightfv(GL_LIGHT0, GL_POSITION, light_position_diff);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position_spec);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular_light);

    glLightfv(GL_LIGHT2, GL_POSITION, light_position_spec2);
    glLightfv(GL_LIGHT2, GL_SPECULAR, specular_light2);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_light);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
}

void myIdle() {
    if (rot == 'x') {
        theta[0] += 0.01 * speed;
    } else if (rot == 'y') {
        theta[1] += 0.01 * speed;
    } else if (rot == 'z') {
        theta[2] += 0.01 * speed;
    }
    display();
}

void mouse(int button, int state, int x, int y) {
    switch (button) {
        case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
            rot = 'x';

        break;
        case GLUT_MIDDLE_BUTTON:
        if (state == GLUT_DOWN)
            rot = 'y';
        break;
        case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
            rot = 'z';
        break;
        default:
        break;
    }
}

void mykey(unsigned char key, int mouseX, int mouseY) {
    if (key == '1') {
        if (amb == true) {
            GLfloat ambient_light[] = {0.3, 0.3, 0.3, 1.0};
            glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_light);
            amb = false;
        } else {
            GLfloat ambient_light[] = {0.9, 0.9, 0.9, 1.0};
            glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_light);
            amb = true;
        }
    }
    if (key == '2') {
        if (diff == true) {
            glDisable(GL_LIGHT0);
            diff = false;
        } else {
            glEnable(GL_LIGHT0);
            diff = true;
        }
    }
    if (key == '3') {
        if (spec == true) {
            glDisable(GL_LIGHT1);
            spec = false;
        } else {
            glEnable(GL_LIGHT1);
            spec = true;
        }
    }
    if (key == '4') {
        if (spec2 == true) {
            glDisable(GL_LIGHT2);
            spec2 = false;
        } else {
            glEnable(GL_LIGHT2);
            spec2 = true;
        }
    }
    //0.75
    if (key == 'u') {
        ukuran = ukuran*0.75;
    }
    //1.5
    if (key == 'U') {
        ukuran = ukuran*1.5;
    }
    //lambat 0.5
    if (key == 'v') {
        speed = speed*0.5;
    }
    //cepat 2x
    if (key == 'V') {
        speed = speed*2;
    }
    display();
}

int main(int argc, char* argv[]) {
    cout<<"penambahan specular merah dengan tombol 4"<<endl;
    cout<<"atur rotasi dengan klik kanan ,  kiri ,tengah mouse"<<endl;
    cout<<"ubah kecepatan 'v' || 'V'  ,  ubah ukuran 'u' || 'U'"<<endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Kotak");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(myIdle);
    glutKeyboardFunc(mykey);
    glutMouseFunc(mouse);
    myinit();
    glutMainLoop();
    return 0;
}
