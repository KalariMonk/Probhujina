#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<fstream>
#include<math.h>
#define GL_PI 3.14159

using namespace std;
GLfloat angle= 0.0,x1=0,z1=0;;
GLdouble viewer[3]={0.0,-5.0,5.0};

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 0.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 0.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 0.0f };
const GLfloat high_shininess[] = { 100.0f };

string line;
char str[80];
int len=0,flag=2,value,window;
int w,h;

void linear();
void helical();
void keyboard(unsigned char,int,int);

void menu(int num){
  if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
    if(value==1)
        flag=0;
    else
        flag=1;
  }
  glutPostRedisplay();
}

void CreateMenu()
{
    glutCreateMenu(menu);
    glutAddMenuEntry("Linear",1);
    glutAddMenuEntry("Helical",2);
    glutAddMenuEntry("Exit",0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void spin1(void) {
    angle+= 0.01;
    /*if(viewer[2]<20)
        viewer[2]+=0.01;*/
    glutPostRedisplay();
}


void spin2(void) {
    angle+= 0.01;

   if(viewer[2]<80)
    {     viewer[1]-=0.02;
        viewer[2]+=0.02;}
    glutPostRedisplay();
}


void drawStringl(void *font,char *str)
{
    char *ch;
    glPushMatrix();
    glRasterPos3f(3.0,3.0,-8.0);
    for(ch=str;*ch;ch++)
        glutBitmapCharacter(font,(int)*ch);

    glPopMatrix();
}


void drawStringh(void *font,char *str)
{
    char *ch;
    glPushMatrix();
    glColor3f(1.0,0.0,0.0);
    glScalef(2.0,2.0,2.0);
    glRasterPos3f(2.0,3.0,-8.0);
    for(ch=str;*ch;ch++)
        glutBitmapCharacter(font,*ch);

    glPopMatrix();
}

void Title()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glDisable(GL_LIGHTING);
    glLoadIdentity();
    glTranslatef(-5,1,0);
    glColor3f(0.0,1.0,1.0);
    drawStringl(GLUT_BITMAP_TIMES_ROMAN_24,"Pesit Bangalore South Campus");
    glTranslatef(-1.2,-0.5,0);
    drawStringl(GLUT_BITMAP_TIMES_ROMAN_24,"Department of Computer Science and Engineering");
    glTranslatef(1.3,-1.5,0);
    glColor3f(1.0,0.0,1.0);
    drawStringl(GLUT_BITMAP_TIMES_ROMAN_24,"A MINI PROJECT ON");
    glTranslatef(-1,-0.5,0);
    drawStringl(GLUT_BITMAP_TIMES_ROMAN_24,"PROBHUJINA:Protein Structure Simulation");
    glTranslatef(-2,-1.5,0);
    glColor3f(1.0,0.0,0.0);
    drawStringl(GLUT_BITMAP_TIMES_ROMAN_24,"By");
    glTranslatef(0,-0.5,0);
    glColor3f(0.0,1.0,0.0);
    drawStringl(GLUT_BITMAP_TIMES_ROMAN_24,"1.Prateek Gupta  1PE14CS101");
    glTranslatef(0,-0.5,0);
    glColor3f(0.0,1.0,0.0);
    drawStringl(GLUT_BITMAP_TIMES_ROMAN_24,"2.Rajat Praveen Sangwa  1PE14CS109");
    glTranslatef(8,1.1,0);
    glColor3f(1.0,0.0,0.0);
    drawStringl(GLUT_BITMAP_TIMES_ROMAN_24,"Project Guide");
    glTranslatef(0,-0.5,0);
    glColor3f(0.0,1.0,0.0);
    drawStringl(GLUT_BITMAP_TIMES_ROMAN_24,"Archana Mathur");
    glTranslatef(-2,-3.5,0);
    glColor3f(0.0,1.0,0.0);
    drawStringl(GLUT_BITMAP_TIMES_ROMAN_24,"Press Right Click to Switch between the Structures");
    glEnable(GL_LIGHTING);
    glFlush();
}

void display(void) {

    if(flag==2)
     Title();

    else if(flag==0)
        linear();
    else{
        helical();}
    glutSwapBuffers();
}
 void linear()
 {
    glClearColor(0.0,0.0,0.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt (10.0,0.0,20.0,0.0,-2.0,-2.0,0.0,1.0,0.0);
    glRotatef(angle, 0, 1, 0);

    len=strlen(line.c_str());

    const char *cstr=line.c_str();

    glTranslatef(0.0,7.0,0.0);
    for(int i=0,j=-4;i<len||str[i]!='\0';i++,j+=2,cstr++)
    {

      glPushMatrix();
      glScalef(0.5,0.5,0.5);

       if(*cstr=='A'||*cstr=='G'||*cstr=='M'||*cstr=='S'||*cstr=='Y'||str[i]=='A'||str[i]=='G'||str[i]=='M'||str[i]=='S'||str[i]=='Y')
       {
         glTranslatef(0.0,-j,0.0);
         glColor3f(1.0,1.0,1.0);
         glRasterPos3f(0.0,0.0,0.0);
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*cstr);
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
         glColor3f(1.0,0.0,0.0);
         glutSolidSphere(1,20,20);

       }
       else if(*cstr=='B'||*cstr=='H'||*cstr=='N'||*cstr=='T'||*cstr=='Z'||str[i]=='B'||str[i]=='H'||str[i]=='N'||str[i]=='T'||str[i]=='Z')
       {
         glTranslatef(0.0,-j,0.0);
         glColor3f(1.0,1.0,1.0);
         glRasterPos3f(0.0,0.0,0.0);
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*cstr);
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
         glColor3f(0.0,1.0,0.0);
         glutSolidSphere(1,20,20);

       }
       else if(*cstr=='C'||*cstr=='I'||*cstr=='O'||*cstr=='U'||str[i]=='C'||str[i]=='I'||str[i]=='O'||str[i]=='U')
       {
         glTranslatef(0.0,-j,0.0);
         glColor3f(1.0,1.0,1.0);
         glRasterPos3f(0.0,0.0,0.0);
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*cstr);
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
         glColor3f(0.0,0.0,1.0);
         glutSolidSphere(1,20,20);

       }
       else if(*cstr=='D'||*cstr=='J'||*cstr=='P'||*cstr=='V'||str[i]=='D'||str[i]=='J'||str[i]=='P'||str[i]=='V')
       {
         glTranslatef(0.0,-j,0.0);
         glColor3f(1.0,1.0,1.0);
         glRasterPos3f(0.0,0.0,0.0);
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*cstr);
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
         glColor3f(1.0,1.0,0.0);
         glutSolidSphere(1,20,20);

       }
       else if(*cstr=='E'||*cstr=='K'||*cstr=='Q'||*cstr=='W'||str[i]=='E'||str[i]=='K'||str[i]=='Q'||str[i]=='W')
       {
         glTranslatef(0.0,-j,0.0);
         glColor3f(1.0,1.0,1.0);
         glRasterPos3f(0.0,0.0,0.0);
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*cstr);
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
         glColor3f(0.0,1.0,1.0);
         glutSolidSphere(1,20,20);

       }
       else if(*cstr=='F'||*cstr=='L'||*cstr=='R'||*cstr=='X'||str[i]=='F'||str[i]=='L'||str[i]=='R'||str[i]=='X')
       {
         glTranslatef(0.0,-j,0.0);
         glColor3f(1.0,1.0,1.0);
         glRasterPos3f(0.0,0.0,0.0);
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*cstr);
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
         glColor3f(1.0,0.0,1.0);
         glutSolidSphere(1,20,20);

       }
       else
       {
         exit(0);
       }

      glPopMatrix();
    }
    glColor3f(1.0,1.0,1.0);
    glDisable(GL_LIGHTING);
    glLoadIdentity();
    drawStringl(GLUT_BITMAP_HELVETICA_18,"Linear Protein Structure");

    glEnable(GL_LIGHTING);
    glFlush();

 }

 void helical()
 {
    glClearColor(0.0,0.0,0.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glutIdleFunc(spin2);
    gluLookAt (viewer[0], viewer[1], viewer[2], 0.0, -2.0, -2.0, 0.0, 1.0, 0.0);
    //glRotatef(angle, 0, 1, 0);
    //gluLookAt(-40.0,30.0,-30.0,0.0,-2.0,-2.0,0.0,1.0,0.0);

    const char *cstr=line.c_str();
    for(int i=0,ngle=0,j=0;i<len||str[i]!='\0'/*ngle<=(360)*/; i++,j+=1.0,ngle+=10,cstr++)
    {
        x1 = 20*cos(ngle*GL_PI/180);
		z1 = -20*sin(ngle*GL_PI/180);

        if(*cstr=='A'||*cstr=='G'||*cstr=='M'||*cstr=='S'||*cstr=='Y'||str[i]=='A'||str[i]=='G'||str[i]=='M'||str[i]=='S'||str[i]=='Y')
        {
          glPushMatrix();
          glTranslatef(x1,-j,z1);
          glEnable(GL_BLEND);
          glBlendFunc(GL_ONE, GL_ZERO);
          glDisable(GL_LIGHTING);
          glColor3f(1.0,1.0,1.0);
          glRasterPos3f(0.0,0.0,0.0);
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*cstr);
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
          glEnable(GL_LIGHTING);
          glScalef(1,1,1);
          glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
          glColor4f(1.0,0.0,0.0,0.5);
          glutSolidSphere(2.0,20,20);
          glPopMatrix();
        }
        else if(*cstr=='B'||*cstr=='H'||*cstr=='N'||*cstr=='T'||*cstr=='Z'||str[i]=='B'||str[i]=='H'||str[i]=='N'||str[i]=='T'||str[i]=='Z')
        {
          glPushMatrix();
          glTranslatef(x1,-j,z1);
          glEnable(GL_BLEND);
          glBlendFunc(GL_ONE, GL_ZERO);
          glDisable(GL_LIGHTING);
          glColor3f(1.0,1.0,1.0);
          glRasterPos3f(0.0,0.0,0.0);
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*cstr);
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
          glEnable(GL_LIGHTING);
          glScalef(1,1,1);
          glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
          glColor4f(0.0,1.0,0.0,0.5);
          glutSolidSphere(2.0,20,20);
          glPopMatrix();
        }
        else if(*cstr=='C'||*cstr=='I'||*cstr=='O'||*cstr=='U'||str[i]=='C'||str[i]=='I'||str[i]=='O'||str[i]=='U')
        {
          glPushMatrix();
          glTranslatef(x1,-j,z1);
          glEnable(GL_BLEND);
          glBlendFunc(GL_ONE, GL_ZERO);
          glDisable(GL_LIGHTING);
          glColor3f(1.0,1.0,1.0);
          glRasterPos3f(0.0,0.0,0.0);
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*cstr);
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
          glEnable(GL_LIGHTING);
          glScalef(1,1,1);
          glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
          glColor4f(0.0,0.0,1.0,0.8);
          glutSolidSphere(2.0,20,20);
          glPopMatrix();
        }
        else if(*cstr=='D'||*cstr=='J'||*cstr=='P'||*cstr=='V'||str[i]=='D'||str[i]=='J'||str[i]=='P'||str[i]=='V')
        {
          glPushMatrix();
          glTranslatef(x1,-j,z1);
          glEnable(GL_BLEND);
          glBlendFunc(GL_ONE, GL_ZERO);
          glDisable(GL_LIGHTING);
          glColor3f(1.0,1.0,1.0);
          glRasterPos3f(0.0,0.0,0.0);
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*cstr);
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
          glEnable(GL_LIGHTING);
          glScalef(1,1,1);
          glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
          glColor4f(1.0,1.0,0.0,0.8);
          glutSolidSphere(2.0,20,20);
          glPopMatrix();
        }
        else if(*cstr=='E'||*cstr=='K'||*cstr=='Q'||*cstr=='W'||str[i]=='E'||str[i]=='K'||str[i]=='Q'||str[i]=='W')
        {
          glPushMatrix();
          glTranslatef(x1,-j,z1);
          glEnable(GL_BLEND);
          glBlendFunc(GL_ONE, GL_ZERO);
          glDisable(GL_LIGHTING);
          glColor3f(1.0,1.0,1.0);
          glRasterPos3f(0.0,0.0,0.0);
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*cstr);
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
          glEnable(GL_LIGHTING);
          glScalef(1,1,1);
          glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
          glColor4f(0.0,1.0,1.0,0.8);
          glutSolidSphere(2.0,20,20);
          glPopMatrix();
        }
        else if(*cstr=='F'||*cstr=='L'||*cstr=='R'||*cstr=='X'||str[i]=='F'||str[i]=='L'||str[i]=='R'||str[i]=='X')
        {
          glPushMatrix();
          glTranslatef(x1,-j,z1);
          glEnable(GL_BLEND);
          glBlendFunc(GL_ONE, GL_ZERO);
          glDisable(GL_LIGHTING);
          glColor3f(1.0,1.0,1.0);
          glRasterPos3f(0.0,0.0,0.0);
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*cstr);
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
          glEnable(GL_LIGHTING);
          glScalef(1,1,1);
          glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
          glColor4f(1.0,0.0,1.0,0.8);
          glutSolidSphere(2.0,20,20);

          glPopMatrix();
        }
        else
           exit(0);

    }
    glColor3f(1.0,1.0,1.0);
    glDisable(GL_LIGHTING);
    glLoadIdentity();
    drawStringh(GLUT_BITMAP_HELVETICA_18,"Alpha Helix Protein Structure");
    glEnable(GL_LIGHTING);
    glFlush();
 }


void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective (60, (GLfloat) w / (GLfloat) h, 1.0, 3200.0);
    glMatrixMode (GL_MODELVIEW);
}
void keyboard(unsigned char key, int x, int y) {
  if (key == 27) exit (0);

  if(key=='L' || key=='l')
     flag=0;
   if(key=='H' || key=='h')
     flag=1;
}
void mouse(int btn,int state,int x,int y)
{
      if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
         linear();
      if(btn==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN)
         helical();
}


int main(int argc, char **argv) {
    int choice;
    do
    {
        cout<<"Menu.\n";
        cout<<"1.Enter Sequence.\n";
        cout<<"2.Use default sequence.\n";
        cout<<"3.exit\n";
        cout<<"Press 'H' for helical and 'l' for linear structures once in the simulation.\n";
        cout<<"Enter your choice:\n";
        cin>>choice;
        if(choice==2)
        {
            ifstream myfile ("sequence.txt");
            if (myfile.is_open())
            {
                getline (myfile,line);
                cout<<line<<"\n";
            }
          //myfile.close();
            else cout << "Unable to open file";
        }
        else if(choice==1)
        {
            printf("\nEnter the Sequence:");
            scanf("%s",str);
        }
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
        glutInitWindowSize (900, 900);
        glutInitWindowPosition (100, 100);
        window=glutCreateWindow ("Protein Structure");
        CreateMenu();
        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutKeyboardFunc(keyboard);
        glutMouseFunc(mouse);
        glutIdleFunc(spin2);
        glutFullScreen();
        //printf("debug");
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHT0);
        glEnable(GL_NORMALIZE);
        glEnable(GL_COLOR_MATERIAL);
        glEnable(GL_LIGHTING);
        glEnable(GL_BLEND);
        glBlendFunc (GL_ONE, GL_ONE);
        glDepthMask(GL_FALSE);
        glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);

        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
        glDisable(GL_BLEND);
        glDepthMask(GL_TRUE);
        glutMainLoop();

    }while(choice!=3);

    return 0;
}
