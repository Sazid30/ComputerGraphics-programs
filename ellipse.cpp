#include<GL/glut.h>
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cstdlib>

float rx,ry,cx,cy;

void myInit()

{

glClearColor(1.0,1.0,1.0,0.0);

glColor3f(0.0f,0.0f,0.0f);

glPointSize(1);

glMatrixMode(GL_PROJECTION);

glLoadIdentity();

gluOrtho2D(0.0,640.0,0.0,480.0);

}

void plot(float x,float y)
{
glBegin(GL_POINTS);
glVertex2d(cx+x,cy+y);
glVertex2d(cx-x,cy+y);
glVertex2d(cx+x,cy-y);
glVertex2d(cx-x,cy-y);
glEnd();
glFlush();
}

void myDisplay()
{

glClear(GL_COLOR_BUFFER_BIT);

glBegin(GL_POINTS);
float x,y,p1,p2;
x=0;
y=ry;
plot(x,y);
p1=(ry*ry)-(rx*rx*ry)+(rx*rx/4);

while((2*x*ry*ry)<=(2*y*rx*rx))
{
    if(p1<0)
    {
    x=x+1;
    p1=p1+(2*ry*ry*x)+(ry*ry);
    plot(x,y);
    std::cout<<"("<<x+cx<<","<<y+cy<<")\n";
    }
    else
    {
    x=x+1;
    y=y-1;
    p1=p1+(2*ry*ry*x)+(ry*ry)-(2*rx*rx*y);
    plot(x,y);
    std::cout<<"("<<x+cx<<","<<y+cy<<")\n";
    }
}
p2=(ry*ry)*(x+0.5)*(x+0.5)-(rx*rx*ry*ry)+(rx*rx)*(y-1)*(y-1);
while(y>0)
{
     if(p2<=0)
    {
    x=x+1;
    y=y-1;
    p2=p2-(2*rx*rx*y)+(rx*rx)+(2*ry*ry*x);
    plot(x,y);
    std::cout<<"("<<x+cx<<","<<y+cy<<")\n";
    }
    else
    {
    y=y-1;
    p2=p2-(2*rx*rx*y)+(rx*rx);
    plot(x,y);
    std::cout<<"("<<x+cx<<","<<y+cy<<")\n";
    }
}
glEnd();

glFlush();

}


int main(int argc,char* argv[])

{
std::cout<<"\nEnter the rx length and ry length of the ellipse\n";
std::cin>>rx>>ry;
std::cout<<"\nEnter the centre of the ellipse\n";
std::cin>>cx>>cy;

glutInit(&argc,argv);

glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

glutInitWindowSize(640,480);

glutCreateWindow("Ellipse");

glutDisplayFunc(myDisplay);

myInit();

glutMainLoop();

return 1;

}
