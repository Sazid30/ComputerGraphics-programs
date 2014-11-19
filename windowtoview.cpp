#include<iostream>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>
#include<unistd.h>
float x[5],y[5];
float nx[5],ny[5];
float xvmin,yvmin,xvmax,yvmax;
float xwmin,ywmin,xwmax,ywmax;
float sx,sy;
void myInit()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(2);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,640.0,0.0,640.0);
}
void mytransform()
{
    int i;
    sx=(xvmax-xvmin)/(xwmax-xwmin);
    sy=(yvmax-yvmin)/(ywmax-ywmin);
    for(i=0;i<5;i++)
    {
        if(x[i]>xwmax)
            x[i]=xwmax;
        else if(x[i]<xwmin)
            x[i]=xwmin;
        nx[i]=xvmin+(x[i]-xwmin)*sx;
        if(y[i]>ywmax)
            y[i]=ywmax;
        else if(y[i]<ywmin)
            y[i]=ywmin;
        ny[i]=yvmin+(y[i]-ywmin)*sy;
    }
    glBegin(GL_LINE_LOOP);
    glVertex2d(xvmin,yvmin);
    glVertex2d(xvmax,yvmin);
    glVertex2d(xvmax,yvmax);
    glVertex2d(xvmin,yvmax);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(nx[0],ny[0]);
    glVertex2d(nx[1],ny[1]);
    glVertex2d(nx[2],ny[2]);
    glVertex2d(nx[3],ny[3]);
    glVertex2d(nx[4],ny[4]);
    glEnd();
}
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex2d(x[0],y[0]);
    glVertex2d(x[1],y[1]);
    glVertex2d(x[2],y[2]);
    glVertex2d(x[3],y[3]);
    glVertex2d(x[4],y[4]);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2d(xwmin,ywmin);
    glVertex2d(xwmax,ywmin);
    glVertex2d(xwmax,ywmax);
    glVertex2d(xwmin,ywmax);
    glEnd();
    std::cout<<xvmin<<yvmin<<xvmax<<yvmax<<"\n";
    mytransform();
    glFlush();
}
int main(int argc , char* argv[])
{
    x[0]=150;
    y[0]=150;
    x[1]=300;
    y[1]=150;
    x[2]=300;
    y[2]=300;
    x[3]=225;
    y[3]=450;
    x[4]=150;
    y[4]=300;
    std::cout<<"Enter the viewport min and max values:";
    std::cin>>xvmin>>yvmin>>xvmax>>yvmax;
    std::cout<<"Enter the window min and max values:";
    std::cin>>xwmin>>ywmin>>xwmax>>ywmax;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutCreateWindow("sample");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 1;
}

