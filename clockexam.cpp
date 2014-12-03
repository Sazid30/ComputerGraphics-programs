#include<GL/glut.h>
#include<iostream.h>
#include<math.h>

int xc = 0, yc = 0, R = 1 , curX,curY;
int pk;
int k=1;
int refX=300,refY=300;
int degree = 0,degree1 = 0, incre = 1;
double cosreg, sinreg;

float Input[3][1], Output[3][1];
float Input2[3][1], Output2[3][1];
//oat InputPoints[4][2] = {{50,50},{150,50},{150,150},{50,150}};
float Transform[3][3]= {{1,0,0},{0,1,0},{0,0,1}};

void myInit()
{
     glClearColor(1.0,1.0,1.0,0.0);
     glColor3f(0.0f,0.0f,0.0f);
     glPointSize(3);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(-640.0,640.0,-640.0,640.0);
}
double toRadian(int degree) {
	return ((degree * 3.14) / 180);
}
void matrixMultiply() {
     cosreg = cos(toRadian(degree));
	sinreg = sin(toRadian(degree));
	
	Transform[0][0] = cosreg;
	Transform[0][1] = -sinreg;
	Transform[1][0] = sinreg;
	Transform[1][1] = cosreg;
	Transform[0][2] = (1-cosreg)*refX + refY*sinreg;
	Transform[1][2] = (1-cosreg)*refY - refX*sinreg;
	int i, j, k;
	for(i=0; i<3; i++)	{
		for(j=0; j<1; j++) {
			Output[i][j] = 0;
			for(k=0; k<3; k++) {
				Output[i][j] += Transform[i][k] * Input[k][j];
			}
		}
	}
}
void matrixMultiply1() {
	 cosreg = cos(toRadian(degree1));
	sinreg = sin(toRadian(degree1));
	
	Transform[0][0] = cosreg;
	Transform[0][1] = -sinreg;
	Transform[1][0] = sinreg;
	Transform[1][1] = cosreg;
	Transform[0][2] = (1-cosreg)*refX + refY*sinreg;
	Transform[1][2] = (1-cosreg)*refY - refX*sinreg;
    
    int i, j, k;
	for(i=0; i<3; i++)	{
		for(j=0; j<1; j++) {
			Output2[i][j] = 0;
			for(k=0; k<3; k++) {
				Output2[i][j] += Transform[i][k] * Input2[k][j];
			}
		}
	}
}



/*id rotate(int x,int y)
{

	Transform[0][0] = cos(angle);
    Transform[0][1] = -sin(angle);
	Transform[0][2] = refX*(1 - cos(angle)) + refY*sin(angle);
	Transform[1][0] = sin(angle);
    Transform[1][1] = cos(angle);
	Transform[1][2] = refY*(1 - cos(angle)) - refX*sin(angle);

	
		Input[0][0] = x;
		Input[1][0] = y;
		Input[2][0] = 1;
		
		multiplyMatrices(Transform,Input,3,3,3,1);
		glVertex2d(Output[0][0],Output[1][0]);
	

}*/




void myDisplay()
{
     k++;
     glClear(GL_COLOR_BUFFER_BIT);
     glBegin(GL_POINTS);
     glColor3f(1,0,0);
     xc=300;
     yc=300;
     R=100;
     curX=0;
     curY=R;
      pk=1-R;
      //drawing circle
     while(curX<curY)
     {
      
      
      if(pk>=0)
      {
             curY--;
      }
      curX++;
      if(pk>=0)
      {
              pk=pk+2*curX-2*curY+1;
      }
      else
      {   
         pk=pk+2*curX+1;
      }
      
      //cout << endl << pk << " " << curX << " " << curY;
      
         glVertex2d(curX + xc, curY + yc);
         glVertex2d(xc - curX , yc + curY);
         glVertex2d(xc + curX , yc - curY);
         glVertex2d(xc - curX , yc - curY);
         glVertex2d(xc + curY , yc + curX);
         glVertex2d(xc - curY , yc + curX);
         glVertex2d(xc + curY , yc - curX);
         glVertex2d(xc - curY , yc - curX);
      }
      glEnd();
      
      
      
      
     
      //drawing the hands of clock
      glBegin(GL_LINES);
      glColor3f(0.8,0.7,0.8);
     // glVertex2d(xc,yc);
      //glVertex2d(xc,yc+R);
      
      glVertex2d(xc,yc);
      glVertex2d((xc+curY-20), (yc+curX-20));
      glEnd();
      
      
 //glClear(GL_COLOR_BUFFER_BIT);
 glBegin(GL_POINTS);
     glColor3f(1,0,0);
     xc=300;
     yc=300;
     R=100;
     curX=0;
     curY=R;
      pk=1-R;
      //drawing circle
     while(curX<curY)
     {
      
      
      if(pk>=0)
      {
             curY--;
      }
      curX++;
      if(pk>=0)
      {
              pk=pk+2*curX-2*curY+1;
      }
      else
      {   
         pk=pk+2*curX+1;
      }
      
      //cout << endl << pk << " " << curX << " " << curY;
      
         glVertex2d(curX + xc, curY + yc);
         glVertex2d(xc - curX , yc + curY);
         glVertex2d(xc + curX , yc - curY);
         glVertex2d(xc - curX , yc - curY);
         glVertex2d(xc + curY , yc + curX);
         glVertex2d(xc - curY , yc + curX);
         glVertex2d(xc + curY , yc - curX);
         glVertex2d(xc - curY , yc - curX);
      }
      glEnd();
      
       glBegin(GL_LINES);
      glColor3f(0.8,0.7,0.8);
      //glVertex2d(xc,yc);
      //glVertex2d(xc,yc+R);
      
      glVertex2d(xc,yc);
      glVertex2d((xc+curY-20), (yc+curX-20));
      glEnd();
 
 
 
      glBegin(GL_LINES);
		glVertex2d(xc,yc);
		Input[0][0] = xc;
		Input[1][0] = yc+R;
		Input[2][0] = 1;
		matrixMultiply();
		cout<<"k:"<<k<<endl;
		//cout<<Input[0][0]<<" "<<Input[1][0]<<" "<<Output[0][0]<<" "<<Output[1][0]<<" "<<degree<<endl;
		glVertex2d(Output[0][0],Output[1][0]);
	glEnd();
      if(k>10)
      {
              cout<<"go in buddy\n";
          glBegin(GL_LINES);
		glVertex2d(xc,yc);
		Input2[0][0] = xc;
		Input2[1][0] = yc+R;
		Input2[2][0] = 1;
		matrixMultiply1();
		cout<<Input2[0][0]<<" "<<Input2[1][0]<<" "<<Output2[0][0]<<" "<<Output2[1][0]<<" "<<degree<<endl;
		
		glVertex2d(Output2[0][0],Output2[1][0]);
		
	glEnd(); 
    k=0;   degree1-=1;
      }
              
      
      
      
      
      
            
      degree -= incre;
      
      glFlush();
}
void myTimer1(int time)
{
     glutPostRedisplay();
     glutTimerFunc(1000,myTimer1,0);
}
void myTimer(int time) {
	glutPostRedisplay();
	glutTimerFunc(1000,myTimer1,0);
	glutTimerFunc(100,myTimer,0);
}




int main(int argc,char* argv[])
{
    //getInput();
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutCreateWindow("Points");
    glutDisplayFunc(myDisplay);
    myInit();
    glutTimerFunc(0,myTimer,0);
    glutTimerFunc(0,myTimer1,0);
    glutMainLoop();
    return 1;
}

