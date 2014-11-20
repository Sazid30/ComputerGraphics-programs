 #include<GL/glut.h>



void myInit()

{

glClearColor(1.0,1.0,1.0,0.0);

glColor3f(0.0f,0.0f,0.0f);

glPointSize(10);

glMatrixMode(GL_PROJECTION);

glLoadIdentity();

gluOrtho2D(0.0,640.0,0.0,480.0);

}



void myDisplay()

{

glClear(GL_COLOR_BUFFER_BIT);

glBegin(GL_QUADS);

int size = 60;

for(int i=0;i<8;i++){

for(int j=(i%2)?1:0;j<8;j++){

glVertex2d(size * i,size * j);

glVertex2d(size * i, size * (j+1));

glVertex2d(size * (i+1),size * (j+1));

glVertex2d(size * (i+1),size * j);

j++;

}

}

glEnd();

glFlush();

}


int main(int argc,char* argv[])

{

glutInit(&argc,argv);

glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

glutInitWindowSize(640,480);

glutCreateWindow("Checkerboard");

glutDisplayFunc(myDisplay);

myInit();

glutMainLoop();

return 1;

}
