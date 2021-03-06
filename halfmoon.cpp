#include<iostream>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>
void myInit()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(2);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,640.0,0.0,480.0);
}
void plot(float x,float y,int cx,int cy)
{
    //glVertex2d(cx+x,cy+y);
    //glVertex2d(cx-x,cy+y);
    glVertex2d(cx+x,cy-y);
    glVertex2d(cx-x,cy-y);
}
void myEllipse(float cx,float cy,float rx,float ry)
{
float p,x,y,p2;
p=(ry*ry)-(rx*rx*ry)+(rx*rx/4);
x=0,y=ry;
plot(0,ry,cx,cy);
while(2*x*ry*ry<=2*y*rx*rx)
{
    if(p<0)
    {
        x+=1;
        p=p+(2*x*ry*ry)+(ry*ry);
    }
    else
    {
        x+=1;
        p=p+(2*x*ry*ry)+(ry*ry)-(2*y*rx*rx);
        y-=1;
    }
    plot(x,y,cx,cy);
    std::cout<<"("<<x<<","<<y<<"),";
}
p2=rx*rx*(y-1)*(y-1)+ry*ry*(x+0.5)*(x+0.5)-rx*rx*ry*ry;
while(y>0)
{
     if(p2<=0)
    {
        x+=1;
        p2=p2+(2*x*ry*ry)+(rx*rx)-(2*y*rx*rx);
        y-=1;
    }
    else
    {
        y-=1;
        p2=p2-(2*y*rx*rx)+(rx*rx);
    }
    plot(x,y,cx,cy);
    std::cout<<"("<<x<<","<<y<<"),";
}
}
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    myEllipse(250,250,150,100);
    myEllipse(250,250,150,150);
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
