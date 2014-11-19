#include<iostream>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>
#include<unistd.h>
float nx[15],ny[15];
void translate(float a[],float b[])
{
    int i,j,k,h;
    for(h=0;h<=13;h++)
    {
    float p[3][3] = {1,0,5,0,1,0,0,0,1};
    float q[3][1] = {a[h],b[h],1};
    float c[3][1] = {0,0,0};
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
    ny[h]=c[1][0];
    }
}
void myInit()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(2);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,640.0,0.0,480.0);
}
void plot(int a,int b,float cx,float cy)
{
    glVertex2d(cx+a,cy-b);
    glVertex2d(cx-a,cy-b);
    glVertex2d(cx+b,cy-a);
    glVertex2d(cx-b,cy-a);
}
void myCircle(float cx,float cy,float r)
{
float p,x,y;
p=1-r;
x=0,y=r;
plot(0,r,cx,cy);
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
    plot(x,y,cx,cy);
    std::cout<<"("<<x<<","<<y<<"),";
}
}
void aftertranslate(int dummy)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    glVertex2d(nx[0],ny[0]);
    glVertex2d(nx[1],ny[1]);
    glVertex2d(nx[2],ny[2]);
    glVertex2d(nx[3],ny[3]);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2d(nx[4],ny[4]);
    glVertex2d(nx[5],ny[5]);
    glVertex2d(nx[6],ny[6]);
    glVertex2d(nx[7],ny[7]);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(nx[8],ny[8]);
    glVertex2d(nx[9],ny[9]);
    glVertex2d(nx[10],ny[10]);
    glVertex2d(nx[11],ny[11]);
    glEnd();
    glBegin(GL_POINTS);
    myCircle(nx[12],ny[12],25);
    myCircle(nx[13],ny[13],25);
    glEnd();
    glFlush();
    translate(nx,ny);
    glutTimerFunc(1000,aftertranslate,1);
}
void myDisplay()
{
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    nx[0]=100;
    ny[0]=200;
    nx[1]=100;
    ny[1]=250;
    nx[2]=300;
    ny[2]=250;
    nx[3]=300;
    ny[3]=200;
    nx[4]=50;
    ny[4]=200;
    nx[5]=350;
    ny[5]=200;
    nx[6]=350;
    ny[6]=150;
    nx[7]=50;
    ny[7]=150;
    nx[8]=100;
    ny[8]=250;
    nx[9]=75;
    ny[9]=200;
    nx[10]=300;
    ny[10]=250;
    nx[11]=325;
    ny[11]=200;
    nx[12]=125;
    ny[12]=150;
    nx[13]=275;
    ny[13]=150;
    glEnd();
    glFlush();
    aftertranslate(1);
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
