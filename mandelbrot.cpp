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
     gluOrtho2D(0.0,480.0,0.0,281.0);     
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_POINTS);
    
    float cx, cy, x, y, temp;
    float r,g,b;
    int i, j;
    int iterations;
    
    cy = -1.1;
    for(j=0; j<281; j++)
    {
       cx = -2.5;
       for(i=0; i<480; i++)
       {
           //Now we have cx and cy which will be the complex number c in z = z^2 + c
           //Initial value = 0 + 0i
           
           x = y = 0;
           iterations = 0;
           
           while( (x*x+y*y)<4 && iterations<1000 )
           {
                temp = x;
                x = x*x - y*y + cx;
                y = 2*temp*y + cy;        
                iterations++;   
           }
           
           if(iterations<1000)
           {
                b = (iterations%10) * 0.1;
                iterations /= 10;
                g = (iterations%10) * 0.1;
                iterations /= 10;
                r = (iterations%10) * 0.1;
                
                glColor3f(r,g,b);
                glVertex2d(i,j);         
           }
           else
           {
                glColor3f(0.0,0.0,0.0);
                glVertex2d(i,j);
           }
           
           cx += 0.0075;         
       }
       cy += 0.0075;
    }
    glEnd();
    
    
    glFlush();    
}

int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(480,281);
    glutCreateWindow("My Window");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;       
}
