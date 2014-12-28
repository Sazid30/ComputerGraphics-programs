#include<GL/glut.h>
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cstdlib>

char word[20];
float xa,xb,ya,yb;

void myInit()

{

glClearColor(1.0,1.0,1.0,0.0);

glColor3f(0.0f,0.0f,0.0f);

glPointSize(1);

glMatrixMode(GL_PROJECTION);

glLoadIdentity();

gluOrtho2D(0.0,640.0,0.0,480.0);

}

void drawcoord(float xa,float ya,float xb,float yb)
{
glBegin(GL_POINTS);
float dx, dy, x, y, xEnd,yEnd,p;
float m;
std::cout<<xa<<" "<<ya<<" "<<xb<<" "<<yb<<"\n";
m=(yb-ya)/(xb-xa);

dx =abs(xa-xb);
dy =abs(ya-yb);

if(m<=1 && m>=0)
{
p= 2*dy - dx;
if (xa>xb)
{
x=xb;
y=yb;
xEnd=xa;
}
else
{
x=xa;
y=ya;
xEnd=xb;
}
glVertex2d(x,y);
while (x<xEnd)
{
x= x+1;
if (p<0)
{
p= p+(2 * dy);
}
else
{
y=y+1;
p=p+(2*(dy-dx));
}
glVertex2d(x,y);
}
}

else if(m>1)
{
p= 2*dx - dy;
if (ya>yb)
{
x=xb;
y=yb;
yEnd=ya;
}
else
{
x=xa;
y=ya;
yEnd=yb;
}
glVertex2d(x,y);
while (y<yEnd)
{
y= y+1;
if (p<0)
{
p= p+(2 * dx);
}
else
{
x=x+1;
p=p+(2*(dx-dy));
}
glVertex2d(x,y);
}
}
else if(m<0 && m>=-1)
{
 p= 2*dy - dx;
if (xa>xb)
{
x=xb;
y=yb;
xEnd=xa;
}
else
{
x=xa;
y=ya;
xEnd=xb;
}
glVertex2d(x,y);
while (x<xEnd)
{
x= x+1;
if (p<0)
{
p= p+(2 * dy);
}
else
{
y=y-1;
p=p+(2*(dy-dx));
}
glVertex2d(x,y);
}
}

else if(m<-1)
{
p= 2*dx - dy;
if (ya>yb)
{
x=xb;
y=yb;
yEnd=ya;
}
else
{
x=xa;
y=ya;
yEnd=yb;
}
glVertex2d(x,y);
while (y<yEnd)
{
y= y+1;
if (p<0)
{
p= p+(2 * dx);
}
else
{
x=x-1;
p=p+(2*(dx-dy));
}
glVertex2d(x,y);
}
}
glEnd();
glFlush();
}

void myDisplay()
{
glClear(GL_COLOR_BUFFER_BIT);
int i=0;
int a=120,b=60;
float x=50,y=50;
while(word[i]!='\0')
{
    switch(word[i])
    {
        case 'a':drawcoord(x,y,x+(b/2),y+a);
        drawcoord(x+(b/2),y+a,x+b,y);
        drawcoord(x,y+(a/2),x+b,y+(a/2));
        break;
        case 'b':drawcoord(x,y,x,y+a);
        drawcoord(x,y+a,x+b,y+(3*a/4));
        drawcoord(x+b,y+(3*a/4),x,y+(a/2));
        drawcoord(x,y+(a/2),x+b,y+(a/4));
        drawcoord(x+b,y+(a/4),x,y);
        break;
        case 'c':drawcoord(x+b,y+(3*a/4),x+b/2,y+a);
        drawcoord(x+b/2,y+a,x,y+(a/2));
        drawcoord(x,y+(a/2),x+b/2,y);
        drawcoord(x+b/2,y,x+b,y+(a/4));
        break;
        case 'd':drawcoord(x,y,x,y+a);
        drawcoord(x,y+a,x+b,y+(a/2));
        drawcoord(x+b,y+(a/2),x,y);
        break;
        case 'e':drawcoord(x,y,x,y+a);
        drawcoord(x,y+a,x+b,y+a);
        drawcoord(x,y+(a/2),x+b,y+a/2);
        drawcoord(x,y,x+b,y);
        break;
        case 'f':drawcoord(x,y,x,y+a);
        drawcoord(x,y+a,x+b,y+a);
        drawcoord(x,y+(a/2),x+b,y+a/2);
        break;
        case 'g':drawcoord(x,y,x,y+a);
        drawcoord(x,y+a,x+b,y+a);
        drawcoord(x,y,x+b,y);
        drawcoord(x+b/2,y+(a/2),x+b,y+a/2);
        drawcoord(x+b,y,x+b,y+a/2);
        break;
        case 'h':drawcoord(x,y,x,y+a);
        drawcoord(x,y+(a/2),x+b,y+a/2);
        drawcoord(x+b,y+a,x+b,y);
        break;
        case 'i':drawcoord(x,y+a,x+b,y+a);
        drawcoord(x,y,x+b,y);
        drawcoord(x+b/2,y+a,x+b/2,y);
        break;
        case 'j':drawcoord(x,y+a,x+b,y+a);
        drawcoord(x,y,x+b/2,y);
        drawcoord(x+b/2,y+a,x+b/2,y);
        break;
        case 'k':drawcoord(x,y,x,y+a);
        drawcoord(x,y+a/2,x+b,y+a);
        drawcoord(x,y+a/2,x+b,y);
        break;
        case 'l':drawcoord(x,y,x,y+a);
        drawcoord(x,y,x+b,y);
        break;
        case 'm':drawcoord(x,y,x,y+a);
        drawcoord(x+b/2,y+a/2,x,y+a);
        drawcoord(x+b,y+a,x+b,y);
        drawcoord(x+b,y+a,x+b/2,y+a/2);
        break;
        case 'n':drawcoord(x,y,x,y+a);
        drawcoord(x+b,y+a,x+b,y);
        drawcoord(x+b,y,x,y+a);
        break;
        case 'o':drawcoord(x,y,x,y+a);
        drawcoord(x,y+a,x+b,y+a);
        drawcoord(x,y,x+b,y);
        drawcoord(x+b,y,x+b,y+a);
        break;
        case 'p':drawcoord(x,y,x,y+a);
        drawcoord(x,y+a,x+b,y+a);
        drawcoord(x,y+(a/2),x+b,y+a/2);
        drawcoord(x+b,y+a,x+b,y+a/2);
        break;
        case 'q':drawcoord(x,y+(a/2),x+(b/2),y);
        drawcoord(x+(b/2),y,x+b,y+(a/2));
        drawcoord(x,y+(a/2),x+(b/2),y+a);
        drawcoord(x+(b/2),y+a,x+b,y+(a/2));
        drawcoord(x+(b/2),y+(a/2),x+b,y);
        break;
        case 'r':drawcoord(x,y,x,y+a);
        drawcoord(x,y+a,x+b,y+(3*a/4));
        drawcoord(x+b,y+(3*a/4),x,y+a/2);
        drawcoord(x,y+a/2,x+b,y);
        break;
        case 's':drawcoord(x+b,y+a,x,y+a);
        drawcoord(x,y+a/2,x,y+a);
        drawcoord(x,y+a/2,x+b,y+a/2);
        drawcoord(x+b,y+(a/2),x+b,y);
        drawcoord(x+b,y,x,y);
        break;
        case 't':drawcoord(x,y+a,x+b,y+a);
        drawcoord(x+b/2,y+a,x+b/2,y);
        break;
        case 'u':drawcoord(x,y,x,y+a);
        drawcoord(x,y,x+b,y);
        drawcoord(x+b,y,x+b,y+a);
        break;
        case 'v':drawcoord(x+b/2,y,x,y+a);
        drawcoord(x+b,y+a,x+b/2,y);
        break;
        case 'w':drawcoord(x+b/4,y,x,y+a);
        drawcoord(x+b/4,y,x+b/2,y+a/2);
        drawcoord(x+(3*b/4),y,x+b/2,y+a/2);
        drawcoord(x+(3*b/4),y,x+b,y+a);
        break;
        case 'x':drawcoord(x,y,x+b,y+a);
        drawcoord(x,y+a,x+b,y);
        break;
        case 'y':drawcoord(x+b/2,y+a/2,x+b,y+a);
        drawcoord(x,y+a,x+b/2,y+a/2);
        drawcoord(x+b/2,y,x+b/2,y+a/2);
        case 'z':drawcoord(x,y+a,x+b,y+a);
        drawcoord(x,y,x+b,y);
        drawcoord(x,y,x+b,y+a);
        break;

    }
    x+=70;
    i++;
}

}


int main(int argc,char* argv[])

{

std::cout<<"Enter a string : ";

std::cin>>word;

std::cout<<word;

glutInit(&argc,argv);

glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

glutInitWindowSize(640,480);

glutCreateWindow("Letters");

glutDisplayFunc(myDisplay);

myInit();

glutMainLoop();

return 1;

}
