#include<GL/GLUT.h>
#include<iostream>

using namespace std;

void myInit()
{
     glClearColor(1.0,1.0,1.0,0.0);
     glColor3f(0.0f,0.0f,0.0f);
     glPointSize(2);
     glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
     gluOrtho2D(0.0,640.0,0.0,440.0);     
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_POINTS);
    
    float cx=-0.012,cy=0.74, x, y, x0, y0, temp;
    float r,g,b;
    int i, j;
    int iterations;
    
    for(j=0; j<440; j++)
    {
       for(i=0; i<640; i++)
       {
           //cx and cy are considered random
           //Initial value = x + yi
           
           x = (i-320.0)/320.0;
           y = (j-220.0)/220.0;
           iterations = 0;
           
           while( (x*x+y*y)<4 && iterations<50 )
           {
                temp = x;
                x = x*x - y*y + cx;
                y = 2*temp*y + cy;        
                iterations++;   
           }
           
           if(iterations<50)
           {
                glColor3f(1.0,1.0,1.0);
                glVertex2d(i,j);         
           }
           else
           {
                glColor3f(0.0,0.0,0.0);
                glVertex2d(i,j);
           }
       }
    }
    glEnd();
    
    
    glFlush();    
}

int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,440);
    glutCreateWindow("My Window");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;       
}
