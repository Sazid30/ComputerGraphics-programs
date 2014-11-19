#include<iostream>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>
void myInit()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,640.0,0.0,480.0);
}
void plot(int a,int b,float cx,float cy)
{
    glVertex2d(cx+a,cy+b);
    glVertex2d(cx-a,cy+b);
    glVertex2d(cx+b,cy+a);
    glVertex2d(cx-b,cy+a);
}
void plot2(int a,int b,float cx,float cy)
{
    glVertex2d(cx+a,cy-b);
    glVertex2d(cx-a,cy-b);
    glVertex2d(cx+b,cy-a);
    glVertex2d(cx-b,cy-a);
}
void myCircle(float cx,float cy,float r,int ch)
{
float p,x,y;
p=1-r;
x=0,y=r;
if(ch==1)
plot(0,r,cx,cy);
else
plot2(0,r,cx,cy);
while(x<=y)
{
    x+=1;
    if(p<0)
    {
        p=p+(2*x)+1;
    }
    else
    {
        p=p+(2*x)-(2*y)+1;
        y-=1;
    }
    if(ch==1)
    plot(x,y,cx,cy);
    else
    plot2(x,y,cx,cy);
    std::cout<<"("<<x<<","<<y<<"),";
}
}
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    myCircle(300,300,100,1);
    myCircle(225,300,25,1);
    myCircle(275,300,25,1);
    myCircle(325,300,25,1);
    myCircle(375,300,25,1);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(300,300);
    glVertex2d(300,200);
    glEnd();
    glBegin(GL_POINTS);
    myCircle(275,200,25,2);
    glEnd();
    glFlush();
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
