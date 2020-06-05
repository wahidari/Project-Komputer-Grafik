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
float theta[3] = {0,0,0} ;

void gambarKotakNim(float x, float y) {
    ///========================belakang - kuning
    glBegin(GL_POLYGON);
    glVertex3f(x + 0.3, y - 0.3, -0.3);
    glVertex3f(x - 0.3, y - 0.3, -0.3);
    glVertex3f(x - 0.3, y + 0.3, -0.3);
    glVertex3f(x + 0.3, y + 0.3, -0.3);
    glEnd();

    ///========================bawah - abu abu
    glColor4ub(68, 90, 100, 255);
    glBegin(GL_POLYGON);
    glVertex3f(x - 0.3, y - 0.3, -0.3);
    glVertex3f(x + 0.3, y - 0.3, -0.3);
    glVertex3f(x + 0.3, y - 0.3, 0.3);
    glVertex3f(x - 0.3, y - 0.3, 0.3);
    glEnd();
    ///========================kanan - ungu
    glColor4ub(211, 0, 247, 255);
    glBegin(GL_POLYGON);
    glVertex3f(x + 0.3, y - 0.3, 0.3);
    glVertex3f(x + 0.3, y - 0.3, -0.3);
    glVertex3f(x + 0.3, y + 0.3, -0.3);
    glVertex3f(x + 0.3, y + 0.3, 0.3);
    glEnd();
    ///========================kiri - merah
    glColor4ub(234, 47, 16, 255);
    glBegin(GL_POLYGON);
    glVertex3f(x - 0.3, y - 0.3, -0.3);
    glVertex3f(x - 0.3, y - 0.3, 0.3);
    glVertex3f(x - 0.3, y + 0.3, 0.3);
    glVertex3f(x - 0.3, y + 0.3, -0.3);
    glEnd();
    ///========================depan - hijau
    glColor4ub(26, 162, 96, 255);
    glBegin(GL_POLYGON);
    glVertex3f(x - 0.3, y - 0.3, 0.3);
    glVertex3f(x + 0.3, y - 0.3, 0.3);
    glVertex3f(x + 0.3, y + 0.3, 0.3);
    glVertex3f(x - 0.3, y + 0.3, 0.3);
    glEnd();
    ///========================atas - biru
    glColor4ub(71, 136, 244, 255);
    glBegin(GL_POLYGON);
    glVertex3f(x - 0.3, y + 0.3, 0.3);
    glVertex3f(x + 0.3, y + 0.3, 0.3);
    glVertex3f(x + 0.3, y + 0.3, -0.3);
    glVertex3f(x - 0.3, y + 0.3, -0.3);
    glEnd();
}

void gambarNim() {
    int nim[5][11]={
    {0,1,0,0,1,1,1,0,0,1,0},
    {0,1,0,0,0,0,1,0,0,1,0},
    {0,1,0,0,1,1,1,0,0,1,0},
    {0,1,0,0,1,0,0,0,0,1,0},
    {0,1,0,0,1,1,1,0,0,1,0}};
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 11; x++) {
            if (nim[y][x] == 1) {
                gambarKotakNim(((x - 5)*0.55), ((-y + 2)*0.55));
            }
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotated(35, 1, 1, 1);
    GLfloat mat_specular[] = {0.7, 0.7, 0.7, 1.0};
    GLfloat mat_shininess[] = {10.0};
    GLfloat mat_diffuse[] = {0.7, 0.7, 0.7, 1.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glRotatef(theta[0], 1, 0, 0);
    glRotatef(theta[1], 0, 1, 0);
    glRotatef(theta[2], 0, 0, 1);

    gambarNim();
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-3.5, 3.5, -3.5 * (GLfloat) h / (GLfloat) w, 3.5 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-3.5 * (GLfloat) w / (GLfloat) h, 3.5 * (GLfloat) w / (GLfloat) h, -3.5, 3.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void myinit() {

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    GLfloat light_position_diff[] = {-1.0, 1.0, 1.0, 0.0};
    GLfloat diffuse_light[] = {0.0, 1.0, 1.0, 1.0};

    GLfloat light_position_spec[] = {1.0, 0.0, 1.0, 0.0};
    GLfloat specular_light[] = {0.0, 1.0, 1.0, 1.0};

    GLfloat light_position_spec2[] = {1.0, -1.0, 1.0, 0.0};
    GLfloat specular_light2[] = {1.0, 0.0, 1.0, 1.0};

    GLfloat ambient_light[] = {0.9, 0.9, 0.9, 1.0};

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
        theta[0] += 0.1 ;
    } else if (rot == 'y') {
        theta[1] += 0.1 ;
    } else if (rot == 'z') {
        theta[2] += 0.1 ;
    }
//theta += 0.03;
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
    display();
}

int main(int argc, char* argv[]) {
    cout<<"penambahan specular merah dengan tombol 4"<<endl;
    cout<<"atur rotasi dengan klik kanan ,  kiri ,tengah mouse"<<endl;

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
