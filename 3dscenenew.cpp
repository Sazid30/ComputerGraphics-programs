
#include<iostream>
#include<GL/glut.h>

using namespace std;

#define red {0xff, 0x00, 0xff}
#define white {0xff, 0xff, 0xff}

GLubyte texture[][3] = {
red,white,white,red};
void myinit()
{
double ht=1.0;
//properties of surface material
GLfloat ambience[]={1.0f,0.0f,0.0f,1.0f};
/*GLfloat diffuse[]={1.0f,1.0f,1.0f,1.0f};
GLfloat specular[]={1.0f,1.0f,1.0f,1.0f};
GLfloat shine[]={50.0f};*/

glMaterialfv(GL_FRONT,GL_AMBIENT,ambience);
/*glMaterialfv(GL_FRONT,GL_DIFFUSE,diffuse);
glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
glMaterialfv(GL_FRONT,GL_SHININESS,shine);*/

//light source
GLfloat lightposition[] = {2.0f,6.0f,3.0f,0.0f};
glLightfv(GL_LIGHT0,GL_POSITION,lightposition);

glClearColor(1.0f,1.0f,1.0f,0.0f);
glColor3f(0.0f,0.0f,0.0f);
/*
glEnable(GL_TEXTURE_2D);
p.readBMPFile("");
p.setTexture(2002);
*/

//camera
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
//glOrtho(-ht*64/48.0,ht*64/48.0,-ht,ht,0.1,100.0);
glOrtho(-640.0/480,640.0/480,-1,1,0.1,100.0);

glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt(2.3, 1.3, 2, 0, 0.25, 0, 0, 1.0, 0);
}

void reshape(int w, int h)
{
//glViewport(0, 0, w, h);
glEnable(GL_TEXTURE_2D);
glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
glTexImage2D(GL_TEXTURE_2D,
0,
// level 0
GL_RGB,
// use only R, G, and B components
2, 2,
// texture has 2x2 texels
0,
// no border
GL_RGB,
// texels are in RGB format
GL_UNSIGNED_BYTE,
// color components are unsigned bytes
texture);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}


void displaySolid()
{

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//axes

glBegin(GL_LINES);
glLineWidth(3);
glVertex3d(0,0,0);
glVertex3d(100,0,0);
glEnd();
//glFlush();

glBegin(GL_LINES);
glLineWidth(5);
glVertex3d(0,0,0);
glVertex3d(0,300,0);
glEnd();
//glFlush();

glBegin(GL_LINES);
glLineWidth(8);
glVertex3d(0,0,0);
glVertex3d(0,0,300);glEnd();
//glFlush();


//draw

glColor3f(1.0f,0.0f,0.0f);
glPushMatrix();
glRotatef(90,1.0,0.0,0.0);
glutSolidTorus(0.05,0.4,10,20);
glPopMatrix ();

glPushMatrix();
glTranslatef(0.6f,0.38f,0.5f);
//glRotatef(30,0.0f,1.0f,0.0f);
glScalef(2.5f,2.5f,2.5f);
glutSolidTeapot(0.1);


glPopMatrix();

glPushMatrix();

glTranslatef(0.9f,0.0f,0.0f);
glScalef(2.0f,2.0f,2.0f);
glutSolidSphere(0.1,150,150);
glPopMatrix();


glFlush();
}

int main(int argc, char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(640,480);
glutInitWindowPosition(100,100);
glutCreateWindow("3d scene");
glutDisplayFunc(displaySolid);
glutReshapeFunc(reshape);
myinit();

glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_DEPTH_TEST);
glEnable(GL_NORMALIZE);
//glClearColor(0.1f,0.1f,0.1f,0.0f);
//glViewport(0,0,640,480);
glutMainLoop();
return 0;

}
