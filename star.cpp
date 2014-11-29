#include <iostream>
#include<GL/glut.h>
using namespace std;
float a[6][3]={{100,110,0},{200,110,0},{150,225,0},{120,130,-90},{220,130,-90},{170,255,-90}};	//1st triangle
float b[6][3]={{100,190,0},{200,190,0},{150,75,0},{120,210,-90},{220,210,-90},{170,95,-90}};	//2nd triangle
float ref1[4][4]={{1,0,0,0},{0,-1,0,0},{0,0,1,0},{0,0,0,1}};
float ref2[4][4]={{1,0,0,0},{0,1,0,0},{0,0,-1,0},{0,0,0,1}};
float ref3[4][4]={{-1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
float refa[6][3],refb[6][3],ref[4][4];
int i,j,k,ch;

void myInit()
{
	glClearColor(1.1,1.1,1.1,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	glOrtho(-300,300,-300,300,-300,300);
}

void drawStar(float a[6][3],float b[6][3])
{
	//DRAWING STAR AS TWO TRIANGLES
	
	//FIRST TRIANGLE
	glColor3f(0.33f,0.33f,0.33f);
	glBegin(GL_POLYGON);		//FRONT FACE
		glVertex3f(a[0][0],a[0][1],a[0][2]);
		glVertex3f(a[1][0],a[1][1],a[1][2]);
		glVertex3f(a[2][0],a[2][1],a[2][2]);
	glEnd();
	glBegin(GL_POLYGON);		//LEFT FACE
		glVertex3f(a[0][0],a[0][1],a[0][2]);
		glVertex3f(a[3][0],a[3][1],a[3][2]);
		glVertex3f(a[5][0],a[5][1],a[5][2]);
		glVertex3f(a[2][0],a[2][1],a[2][2]);
	glEnd();
	glBegin(GL_POLYGON);		//BACK FACE
		glVertex3f(a[3][0],a[3][1],a[3][2]);
		glVertex3f(a[5][0],a[5][1],a[5][2]);
		glVertex3f(a[4][0],a[4][1],a[4][2]);
	glEnd();
	glColor3f(0.66f,0.66f,0.66f);
	glBegin(GL_POLYGON);		//RIGHT FACE
		glVertex3f(a[1][0],a[1][1],a[1][2]);
		glVertex3f(a[4][0],a[4][1],a[4][2]);
		glVertex3f(a[5][0],a[5][1],a[5][2]);
		glVertex3f(a[2][0],a[2][1],a[2][2]);
	glEnd();
	glBegin(GL_POLYGON);		//BOTTOM FACE
		glVertex3f(a[1][0],a[1][1],a[1][2]);
		glVertex3f(a[4][0],a[4][1],a[4][2]);
		glVertex3f(a[3][0],a[3][1],a[3][2]);
		glVertex3f(a[0][0],a[0][1],a[0][2]);
	glEnd();
	
	//SECOND INVERTED TRIANGLE
	glColor3f(0.33f,0.33f,0.33f);
	glBegin(GL_POLYGON);		//FRONT FACE
		glVertex3f(b[0][0],b[0][1],b[0][2]);
		glVertex3f(b[1][0],b[1][1],b[1][2]);
		glVertex3f(b[2][0],b[2][1],b[2][2]);
	glEnd();
	glBegin(GL_POLYGON);		//LEFT FACE
		glVertex3f(b[0][0],b[0][1],b[0][2]);
		glVertex3f(b[3][0],b[3][1],b[3][2]);
		glVertex3f(b[5][0],b[5][1],b[5][2]);
		glVertex3f(b[2][0],b[2][1],b[2][2]);
	glEnd();
	glBegin(GL_POLYGON);		//BACK FACE
		glVertex3f(b[3][0],b[3][1],b[3][2]);
		glVertex3f(b[5][0],b[5][1],b[5][2]);
		glVertex3f(b[4][0],b[4][1],b[4][2]);
	glEnd();
	glColor3f(0.66f,0.66f,0.66f);
	glBegin(GL_POLYGON);		//RIGHT FACE
		glVertex3f(b[1][0],b[1][1],b[1][2]);
		glVertex3f(b[4][0],b[4][1],b[4][2]);
		glVertex3f(b[5][0],b[5][1],b[5][2]);
		glVertex3f(b[2][0],b[2][1],b[2][2]);
	glEnd();
	glColor3f(0.88f,0.88f,0.88f);
	glBegin(GL_POLYGON);		//BOTTOM FACE
		glVertex3f(b[1][0],b[1][1],b[1][2]);
		glVertex3f(b[4][0],b[4][1],b[4][2]);
		glVertex3f(b[3][0],b[3][1],b[3][2]);
		glVertex3f(b[0][0],b[0][1],b[0][2]);
	glEnd();

	glColor3f(0.0f,0.0f,0.0f);
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glBegin(GL_LINES);			//AXES
		glVertex3f(-300,0,0);
		glVertex3f(300,0,0);
		glVertex3f(0,-300,0);
		glVertex3f(0,300,0);
	glEnd();
	
	drawStar(a,b);		//DRAW ORIGINAL STAR
	
	if(ch==1)			//ASSIGNING REFLECTION MATRIX BASED ON CHOICE
	{
		for(i=0;i<4;i++)		
			for(j=0;j<4;j++)
				ref[i][j]=ref1[i][j];
	}
	else if(ch==2)
	{
		for(i=0;i<4;i++)		
			for(j=0;j<4;j++)
				ref[i][j]=ref2[i][j];
	}
	else if(ch==3)
    {
		for(i=0;i<4;i++)		
			for(j=0;j<4;j++)
				ref[i][j]=ref3[i][j];
	}
	
	for(k=0;k<6;k++)	//REFLECTING FIRST TRIANGLE
	{
		float p[4][1]={1,1,1,1};
		float p1[4][1]={0,0,0,1};
		for(i=0;i<3;i++)		//ASSIGNING POINT
			p[i][0]=a[k][i]; 
		for(i=0;i<4;i++)		//MULTIPLYING MATRICES REF N POINT
			for(j=0;j<4;j++)
				p1[i][0]+=ref[i][j]*p[j][0];
		for(i=0;i<3;i++)		//ASSIGNING RESULTANT POINT TO RESULTANT MATRIX
			refa[k][i]=p1[i][0]; 
	}
	
	for(k=0;k<6;k++)	//REFLECTING SECOND INVERTED TRIANGLE
	{
		float pt[4][1]={1,1,1,1};
		float pt1[4][1]={0,0,0,1};
		for(i=0;i<3;i++)		//ASSIGNING POINT
			pt[i][0]=b[k][i]; 
		for(i=0;i<4;i++)		//MULTIPLYING MATRICES REF N POINT
			for(j=0;j<4;j++)
				pt1[i][0]+=ref[i][j]*pt[j][0];
		for(i=0;i<3;i++)		//ASSIGNING RESULTANT POINT TO RESULTANT MATRIX
			refb[k][i]=pt1[i][0]; 
	}
	
	drawStar(refa,refb);	//DRAW REFLECTED STAR
	
	glFlush();
}

int main (int argc, char * argv[]) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(600,600);
	glutCreateWindow("3D STAR");
	cout<<"Do you want to reflect with repect to \n1.XZ \n2.XY \n3.YZ \n";
	cin>>ch;
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
    return 1;
}
