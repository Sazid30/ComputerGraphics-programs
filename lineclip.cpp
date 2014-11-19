#include<iostream>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>
#include<unistd.h>
float x[5],y[5];
float x1,yl,x2,y2;
int flag=0;
float xmin,ymin,xmax,ymax;
int t1=0,t2=0,l1=0,l2=0,r1=0,r2=0,b1=0,b2=0;
void myInit()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(2);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,640.0,0.0,640.0);
}
void setcode(float x1,float y1,float x2,float y2)
{
    std::cout<<x1<<y1<<x2<<y2;
    if(x1>xmax)
        r1=1;
    if(x2>xmax)
        r2=1;
    if(x1<xmin)
        l1=1;
    if(x2<xmin)
        l2=1;
    if(y1>ymax)
        t1=1;
    if(y2>ymax)
        t2=1;
    if(y1<ymin)
        b1=1;
    if(y2<ymin)
        b2=1;
if(t1|t2==0 && r1|r2==0 && b1|b2==0 && l1|l2==0)
{
    std::cout<<"trivial accept";
    flag=1;
}
else if(t1&t2==1 || r1&r2==1 || b1&b2==1 || l1&l2==1)
{
    std::cout<<"trivial reject";
    flag=2;
}
}
void cliptotal(int dummy)
{
    float y1=yl;
    float m;
    m=(y2-y1)/(x2-x1);
    if(y1>ymax)
    {
        x1=x1+(ymax-y1)/m;
        y1=ymax;
    }
    else if(y2>ymax)
    {
        x2=x2+(ymax-y2)/m;
        y2=ymax;
    }
    if(y1<ymin)
    {
        x1=x1+(ymin-y1)/m;
        y1=ymin;
    }
    else if(y2<ymin)
    {
        x2=x2+(ymin-y2)/m;
        y2=ymin;
    }
    if(x1>xmax)
    {
        y1=y1+(xmax-x1)*m;
        x1=xmax;
    }
    else if(x2>xmax)
    {
        y2=y2+(xmax-x2)*m;
        x2=xmax;
    }
    if(x1<xmin)
    {
        y1=y1+(xmin-x1)*m;
        x1=xmin;
    }
    else if(x2<xmin)
    {
        y2=y2+(xmin-x2)*m;
        x2=xmin;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glVertex2d(x1,y1);
    glVertex2d(x2,y2);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2d(xmin,ymin);
    glVertex2d(xmax,ymin);
    glVertex2d(xmax,ymax);
    glVertex2d(xmin,ymax);
    glEnd();
    glFlush();
}
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glVertex2d(x[0],y[0]);
    glVertex2d(x[1],y[1]);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2d(xmin,ymin);
    glVertex2d(xmax,ymin);
    glVertex2d(xmax,ymax);
    glVertex2d(xmin,ymax);
    glEnd();
    x1=x[0];
    yl=y[0];
    x2=x[1];
    y2=y[1];
    setcode(x[0],y[0],x[1],y[1]);
    if(flag==0)
    {
    glutTimerFunc(1000,cliptotal,1);
    }
    glFlush();
}
int main(int argc , char* argv[])
{
    x[0]=50;
    y[0]=50;
    x[1]=400;
    y[1]=150;
    std::cout<<"Enter the min and max values:";
    std::cin>>xmin>>ymin>>xmax>>ymax;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutCreateWindow("sample");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 1;
}

