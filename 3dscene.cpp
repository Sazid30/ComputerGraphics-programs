#include<GL/glut.h>
#include<iostream>
using namespace std;

#define purple {0xff, 0x00, 0x70}
#define white {0xff, 0xff, 0xff}

GLubyte texture[][3] = {
    purple, white,
    white, purple,
};

static GLuint texName;

void tableLeg(double thick,double len)
{
	glPushMatrix();
	glTranslated(0,len/2,0);
	glScaled(thick,len,thick);
	glutSolidCube(1.0);
	glPopMatrix();
}

void table(double topwid,double topthick,double legthick,double leglen)
{
	glPushMatrix();
	glTranslated(0,leglen,0);
	glScaled(topwid,topthick,topwid);
	glutSolidCube(1.0);
	glPopMatrix();
	double dist=0.95*topwid/2.0-legthick/2.0;
	glPushMatrix();
	glTranslated(dist,0,dist);
	tableLeg(legthick,leglen);
	glTranslated(0,0,-2*dist);
	tableLeg(legthick,leglen);
	glTranslated(-2*dist,0,2*dist);
	tableLeg(legthick,leglen);
	glTranslated(0,0,-2*dist);
	tableLeg(legthick,leglen);
	glPopMatrix();
}

void display_solid(void)
{
	GLfloat mat_ambient[] = {0.4, 0.1745, 0.4};
	GLfloat mat_diffuse[]={0.6f,0.6f,0.6f};
	GLfloat mat_specular[]={1.0f,1.0f,1.0f};
	GLfloat mat_shininess[]={30.0f};

	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

	GLfloat lightIntensity[] = {0.7f, 0.7f, 0.7f, 1.0f};
	GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-640.0/480,640.0/480,-1,1,0.1,100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(2.3,1.3,2,0,0.25,0,0,1,0);
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texName);
	glTranslated(0.6,0.38,0.5);
	glRotated(30,0,1,0);
	glutSolidTeapot(0.08);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.25,0.42,0.35);
	glutSolidSphere(0.1,15,15);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.4,0,0.4);
	table(0.6,0.02,0.02,0.3);
	glPopMatrix();

	glFlush();
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(640,480);
    glutCreateWindow("3d Scene");
    glutDisplayFunc(display_solid);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_TEXTURE_2D);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D,
               0,                    // level 0
               3,                    // use only R, G, and B components
               2, 2,                 // texture has 2x2 texels
               0,                    // no border
               GL_RGB,               // texels are in RGB format
               GL_UNSIGNED_BYTE,     // color components are unsigned bytes
               texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glutMainLoop();
    return 0;
}
    
