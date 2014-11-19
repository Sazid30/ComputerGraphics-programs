#include<iostream>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>
#include<unistd.h>
float nx[15],ny[15];
void myInit()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(20);
    glLineWidth(10);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-320.0,320.0,-240.0,240.0);
}
void myRotate(float a[],float b[])
{
    int i,j,k,h;
    for(h=0;h<4;h++)
    {
     float val = 45*3.142/180;
     float p[3][3]={cos(val),-sin(val),0,sin(val),cos(val),0,0,0,1};
     float q[3][1]={a[h],b[h],1};
     float c[3][1]={0,0,0};
     for(i=0;i<3;i++)
     {
         for(j=0;j<1;j++)
         {
             c[i][j]=0;
             for(k=0;k<3;k++)
             {
                 c[i][j]=c[i][j]+p[i][k]*q[k][j];
             }
         }
     }
     nx[h]=c[0][0];
     std::cout<<h<<"   "<<nx[h]<<"\n";
     ny[h]=c[1][0];
     std::cout<<h<<"   "<<nx[h]<<"\n";
    }
}
void afterrotate(int dummy)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.3f,0.6f,1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(-5,-320);
    glVertex2d(5,-320);
    glVertex2d(5,0);
    glVertex2d(-5,0);
    glEnd();
    glColor3f(1.0f,0.3f,0.6f);
    glBegin(GL_POINTS);
    glVertex2d(0,0);
    glEnd();
    glColor3f(0.3f,1.0f,0.6f);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(nx[0],ny[0]);
    glVertex2d(0,0);
    glVertex2d(nx[1],ny[1]);
    glVertex2d(0,0);
    glVertex2d(nx[2],ny[2]);
    glVertex2d(0,0);
    glVertex2d(ny[3],ny[3]);
    glEnd();
    glFlush();
    myRotate(nx,ny);
    glutTimerFunc(1000,afterrotate,1);
}
void myDisplay()
{
    nx[0]=-100;
    ny[0]=-100;
    nx[1]=-100;
    ny[1]=100;
    nx[2]=100;
    ny[2]=-100;
    nx[3]=100;
    ny[3]=100;
    afterrotate(1);
}

int main(int argc , char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutCreateWindow("sample");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 1;
}
