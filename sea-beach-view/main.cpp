///glColor3ub(31,31,31) road pitch color
///glColor4f(1.0f, 1.0f, 0.0f, 0.0f) road side-line yellowish

///glColor3ub(18, 48, 4) green terrain+grass etc
///glColor3ub(238, 214, 180) sand color

#include<iostream>>
#include<cstdio>
#include <windows.h>
#include<bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <windows.h>
#include <mmsystem.h>
using namespace std;


GLfloat position = 0.0f ,position1 = 0.0f,sk1,sk2,sk3,sk4;
GLfloat position2 = 0.0f,position_sea=-0.3f;
GLfloat position3 = 0.0f;
GLfloat speed = 0.02f;
//int hello=0;

///time change variable for transition scenes
GLfloat timeChange=0.0f;

///sea variable

GLfloat s = 0.0f;
GLfloat m=0.0f;
GLfloat h=0.0f;

//GLfloat position = 0.0f,cloud1,cloud2,cloud3;
GLfloat cloud1,cloud2,cloud3;
//GLfloat speed = 0.1f;
GLfloat parameter=6;
#define PI acos(-1)

void soundPlayer(){

    ///change directory name
	PlaySound(TEXT("H:\\Computer Graphics\\seaBeach\\1.wav"),NULL,SND_ASYNC|SND_FILENAME);


	//system("PAUSE");
}

void update(int value) {

    if(position > 1.0)
        position = -1.2f;

    position += speed;


   if(position3 < -1.0)
        position3 = 1.2f;

    position3 -= speed;

    if(position1 < -1.0)
    position1 = 1.0f;

    position1 -= 0.05;

    if(position_sea < -0.4)
    position_sea = -0.3f;

    position_sea -= 0.01;


	glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}


void init() {
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed += 0.1f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}

	glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

        case 27 :
        case 'q':
            exit(0);
            break;

        case 'p':
            speed = 0.0f;
            break;
        case 'c':
            speed= 0.01f;
            break;
        case 'b':
            timeChange=0;
            break;

        case 'm':
            timeChange=40;
            break;
        case 's':
            timeChange=90;
            break;
        case 'r':
            timeChange=140;
            break;
       /* case 'a':
            speed = 0.1f;
            break;
        case 'w':

            if(position2 > 1.0)
                position2 = -1.2f;
           // position = 0.0f;
            position2 += 0.1f;
            break;
        case 's':

            if(position2 < -1.0)
                position2 = 1.2f;
           // position = 0.0f;
            position2 -= 0.1f;
            break;
*/

        glutPostRedisplay();


	}
}

void rain()
{
    glColor3ub(255, 255, 255);
    glBegin(GL_LINES);
    glVertex2d(0.0,1.7);
    glVertex2d(0.0,1.6);

    glVertex2d(0.0,1.5);
    glVertex2d(0.0,1.4);

    glVertex2d(0.0,1.3);
    glVertex2d(0.0,1.2);

    glVertex2d(0.0,1.1);
    glVertex2d(0.0,1.0);

    glVertex2d(0.0,0.9);
    glVertex2d(0.0,0.8);

    glVertex2d(0.0,0.7);
    glVertex2d(0.0,0.6);

    glVertex2d(0.0,0.5);
    glVertex2d(0.0,0.4);
    glVertex2d(0.0,0.3);
    glVertex2d(0.0,0.2);

    glVertex2d(0.0,0.1);
    glVertex2d(0.0,0.0);

    glVertex2d(0.0,-0.1);
    glVertex2d(0.0,-0.2);

    glVertex2d(0.0,-0.3);
    glVertex2d(0.0,-0.4);

    glVertex2d(0.0,-0.6);
    glVertex2d(0.0,-0.7);

    glVertex2d(0.0,-0.8);
    glVertex2d(0.0,-0.9);


    glVertex2d(0.0,-1.0);
    glVertex2d(0.0,-1.1);

    glVertex2d(0.0,-1.2);
    glVertex2d(0.0,-1.3);

    glVertex2d(0.0,-1.4);
    glVertex2d(0.0,-1.5);

    glVertex2d(0.0,-1.2);
    glVertex2d(0.0,-1.3);
    glEnd();

}

///utility
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 200; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}
void drawFilledHalfCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 200; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI/2;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}
void drawFilledCircleRoad(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 200; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI/4;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x - (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_LINE_LOOP);
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
}

///clouds
void sky1(int k)
{
    //glScalef(0.5,0.5,0);
    sk1+=0.006;
    sk2+=0.002;
    sk3+=0.004;
    sk4+=0.0008;
    if(sk1>1.5)
    {
        sk1=-1.5;
    }
    if(sk2>1.5)
    {
        sk2=-1.5;
    }
    if(sk3>1.5)
    {
        sk3=-1.5;
    }
     if(sk4>1.5)
    {
        sk4=-1.5;
    }
    if(k==1)
    {
        glTranslatef(sk1,0,0);

    int i;

    GLfloat x=.5f;
    GLfloat y=.7f;
    GLfloat radius =.06f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat a=.55f;
    GLfloat b=.84f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(a, b); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a + (radius * cos(i *  twicePi / triangleAmount)),
            b + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat c=.45f;
    GLfloat d=.78f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(c, d); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            c + (radius * cos(i *  twicePi / triangleAmount)),
            d + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat e=.56f;
    GLfloat f=.75f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius * cos(i *  twicePi / triangleAmount)),
            f+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat g=.65f;
    GLfloat h=.8f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g + (radius * cos(i *  twicePi / triangleAmount)),
            h+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


}
if(k==2)
{
    glTranslatef(sk2,0,0);

    int i;

    GLfloat x=.5f;
    GLfloat y=.7f;
    GLfloat radius =.06f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(160, 160, 160);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat a=.55f;
    GLfloat b=.8f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(160, 160, 160);
    glVertex2f(a, b); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a + (radius * cos(i *  twicePi / triangleAmount)),
            b + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat c=.45f;
    GLfloat d=.78f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(160, 160, 160);
    glVertex2f(c, d); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            c + (radius * cos(i *  twicePi / triangleAmount)),
            d + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat e=.56f;
    GLfloat f=.75f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(160, 160, 160);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius * cos(i *  twicePi / triangleAmount)),
            f+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat g=.65f;
    GLfloat h=.8f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(160, 160, 160);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g + (radius * cos(i *  twicePi / triangleAmount)),
            h+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

}
if(k==3)
{
    glTranslatef(sk3,0,0);

    int i;

    GLfloat x=.5f;
    GLfloat y=.7f;
    GLfloat radius =.06f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat a=.55f;
    GLfloat b=.8f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);
    glVertex2f(a, b); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a + (radius * cos(i *  twicePi / triangleAmount)),
            b + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat c=.45f;
    GLfloat d=.78f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);
    glVertex2f(c, d); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            c + (radius * cos(i *  twicePi / triangleAmount)),
            d + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat e=.56f;
    GLfloat f=.75f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius * cos(i *  twicePi / triangleAmount)),
            f+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat g=.65f;
    GLfloat h=.8f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g + (radius * cos(i *  twicePi / triangleAmount)),
            h+ (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();
}
///Air-Balloon
if(k==4)
{
    glTranslatef(sk4,0,0);
    glColor3ub(255, 255, 0);
    drawFilledHalfCircle(0,0,0.1);

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(-.1,0);
    glVertex2f(-.05,-.18);
    glVertex2f(.05,-.18);
    glVertex2f(.1,0);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0,-.18);
    glVertex2f(0,-.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);

    glVertex2f(-.0225,-.2);
    glVertex2f(-.0225,-.24);
    glVertex2f(.0225,-.24);
    glVertex2f(.0225,-.2);
    glEnd();


}
}

///marine_drive start
void hill(){


    glBegin(GL_TRIANGLES);
    glColor3ub(33, 89, 42);

    glVertex2d(-0.2,0);
    glVertex2d(0.2,0);
    glVertex2d(0,0.4);
    glEnd();

}
void draw_background()
{
    glBegin(GL_QUADS);
    glColor3ub(133, 193, 233);
    glVertex2d(-1,0.2);
    glVertex2d(1,0.2);
    glVertex2d(1,1);
    glVertex2d(-1,1);
    glEnd();
//hill start

     glLoadIdentity();
     glScalef(1.8,1.8,0);
     glTranslatef(-0.1,0.0,0);
     hill();

    glLoadIdentity();
     glScalef(1.3,1.3,0);
     glTranslatef(-0.75,0.0,0);
     hill();

    glLoadIdentity();
     glScalef(1.3,1.3,0);
     glTranslatef(-0.5,0.0,0);
     hill();

      glLoadIdentity();
     glScalef(1.3,1.3,0);
     glTranslatef(-0.35,0.0,0);
     hill();

     glLoadIdentity();
     glScalef(1.8,1.8,0);
     glTranslatef(0.1,0.0,0);
     hill();

    glLoadIdentity();
     glScalef(1.8,1.8,0);
     glTranslatef(0.5,0.0,0);
     hill();

  //hill done



//  //sun start
// glLoadIdentity();
//     //glScalef(1.8,1.8,0);
//     //glTranslatef(0.5,0.0,0);
//     glColor3ub(252, 212, 64);
//
//  drawFilledCircle(.65,.75,0.08);
//  //glTranslatef(0.5,0.0,0);
//  //glColor3f(1.0, 0.0, 0.0);
// // glutSolidSphere(0.3, 50, 50);
//
//
//  //sun done



    glLoadIdentity();
    glScalef(0.6,0.8,0);
    glTranslatef(0.2,0.1,0);

//    sky1(1);
//    glLoadIdentity();
//    glScalef(0.6,0.8,0);
//    glTranslatef(-0.2,0.3,0);
//    sky1(2);
//    glLoadIdentity();
//    glScalef(0.6,0.8,0);
//    glTranslatef(-0.5,0.1,0);
//    sky1(3);
//    glLoadIdentity();
//    glScalef(0.6,0.8,0);
//    glTranslatef(-0.9,-0.1,0);
//    sky1(1);
//    glLoadIdentity();
//    glScalef(0.6,0.8,0);
//    glTranslatef(-1.2,-0.1,0);
//    sky1(2);

     glLoadIdentity();
     glScalef(1.5,1.5,0);
     glTranslatef(0.3,0.0,0);
     hill();

     glLoadIdentity();
     glScalef(1.3,1.3,0);
     glTranslatef(0.45,0.0,0);
     hill();

     glLoadIdentity();
     glScalef(1.8,1.8,0);
     glTranslatef(-0.4,0.0,0);
     hill();

    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(64, 164, 223);
    glVertex2d(-1,-1);
    glVertex2d(1,-1);
    glVertex2d(1,0.2);
    glVertex2d(-1,0.2);
    glEnd();

}
void rail(){

    //glTranslatef(0.235,0.0,0); //5 rail
    glBegin(GL_LINES);
    glColor3ub(212,212,212);
    glVertex2f(-0.82f, -0.54f);
    glVertex2f(-0.82f, -0.6f);
    glEnd();
    glBegin(GL_LINES);

    glVertex2f(-0.79f, -0.54f);
    glVertex2f(-0.79f, -0.6f);
    glEnd();
    glBegin(GL_LINES);

    glVertex2f(-0.76f, -0.54f);
    glVertex2f(-0.76f, -0.6f);
    glEnd();
    glBegin(GL_LINES);

    glVertex2f(-0.73f, -0.54f);
    glVertex2f(-0.73f, -0.6f);
    glEnd();
    glBegin(GL_LINES);

    glVertex2f(-0.7f, -0.54f);
    glVertex2f(-0.7f, -0.6f);
    glEnd();
    glBegin(GL_LINES);

    glVertex2f(-0.67f, -0.54f);
    glVertex2f(-0.67f, -0.6f);
    glEnd();
    glBegin(GL_LINES);

    glVertex2f(-0.64f, -0.54f);
    glVertex2f(-0.64f, -0.6f);
    glEnd();


}

void rail_total(){


    glLineWidth(0.002);
    glBegin(GL_LINES);

      glColor3ub(128,128,128);
      glVertex2f(-1.0f, -0.57f);
      glVertex2f( 1.0f, -0.57f);

   glEnd();
       glBegin(GL_LINES);
      glVertex2f(-1.0f, -0.54f);
      glVertex2f( 1.0f, -0.54f);
    glEnd();

//1st rail
    rail();
    glTranslatef(0.245,0.0,0); //2nd rail
     rail();
    glTranslatef(0.245,0.0,0); //3rd rail
    rail();
    glTranslatef(0.235,0.0,0); //4th rail
    rail();
    glTranslatef(0.245,0.0,0); //5 rail
    rail();
    glTranslatef(0.245,0.0,0); //6 rail
    rail();
     glTranslatef(0.245,0.0,0); //7 rail
    rail();

}
void road(){

    //road
      glBegin(GL_QUADS);
      glColor3ub(31,31,31);
      glVertex2f(-1.0f, -0.3f);
      glVertex2f( 1.0f, -0.3f);
      glVertex2f( 1.0f, -0.6f);
      glVertex2f( -1.0f, -0.6f);
   glEnd();


 //side line up
    glBegin(GL_QUADS);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f(-1.0f, -0.3f);
      glVertex2f( 1.0f, -0.3f);
      glVertex2f( 1.0f, -0.29f);
      glVertex2f( -1.0f, -0.29f);
   glEnd();

//side line down
    glBegin(GL_QUADS);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f(-1.0f, -0.6f);
      glVertex2f( 1.0f, -0.6f);
      glVertex2f( 1.0f, -0.61f);
      glVertex2f( -1.0f, -0.61f);
   glEnd();

//mid-line

      glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-1.0f, -0.45f);
      glVertex2f( 1.0f, -0.45f);
      glVertex2f( 1.0f, -0.455f);
      glVertex2f( -1.0f, -0.455f);
   glEnd();


   //road-side-up
//green
     glBegin(GL_QUADS);
      glColor3ub(33, 89, 42);
      glVertex2f(-1.0f, -0.25f);
      glVertex2f( 1.0f, -0.25f);
      glVertex2f( 1.0f, -0.29f);
      glVertex2f( -1.0f, -0.29f);
   glEnd();
//beach
     glBegin(GL_QUADS);
      glColor3ub(238, 214, 175);
      glVertex2f(-1.0f, -0.18f);
      glVertex2f( 1.0f, -0.18f);
      glVertex2f( 1.0f, -0.25f);
      glVertex2f( -1.0f, -0.25f);
   glEnd();

//road-side-down
//green
     glBegin(GL_QUADS);
      glColor3ub(33, 89, 42);
      glVertex2f(-1.0f, -0.8f);
      glVertex2f( 1.0f, -0.8f);
      glVertex2f( 1.0f, -0.61f);
      glVertex2f( -1.0f, -0.61f);
   glEnd();




//railing lower side
rail_total();
//railing upper side
glLoadIdentity();
glScalef(1.2,1.2,0);
glTranslatef(0.0,0.468,0);
rail_total();






}
void car()
{



    glScalef(0.2,0.2,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.75, 0.71);
//car-body

    glVertex2f(-0.8,0.0);
    glVertex2f(-0.8,0.3);
    glVertex2f(-0.5,0.3);
    glVertex2f(-0.35,0.6);
    glVertex2f(0.35,0.6);
    glVertex2f(0.5,0.3);
    glVertex2f(0.8,0.3);
    glVertex2f(0.8,0.0);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.54, 0.61, 0.55);

    glVertex2f(-0.54,0.31);
    glVertex2f(-0.34,0.58);
    glVertex2f(0.34,0.58);
    glVertex2f(0.475,0.31);



    glEnd();
    glLineWidth(7.5);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0,0.58);
    glVertex2f(0,0.31);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(0.62,0.0);
    glVertex2f(0.57,0.1);
    glVertex2f(0.37,0.1);
    glVertex2f(0.32,0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(-0.62,0.0);
    glVertex2f(-0.57,0.1);
    glVertex2f(-0.37,0.1);
    glVertex2f(-0.32,0.0);
    glEnd();


     float x1=-0.47,x2=0.47,y1=-0.033,y2=-0.033,radius=0.13;;
	int i;
	int triangleAmount = 360; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f *3.14159;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.75, 0.71);
		glVertex2f(x2, y2); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x2 + (radius * cos(i *  twicePi / triangleAmount)),
			    y2 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.75, 0.71);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x1 + (radius * cos(i *  twicePi / triangleAmount)),
			    y1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


}
void marine_drive(){
    glPushMatrix();
    draw_background();
    glPopMatrix();

    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0.0,.2,0);
    glScalef(1.2,1.2,0);
    road();
    glPopMatrix();
/*ground
    glBegin(GL_QUADS);
      glColor3f(0.0, 0.39, 0.0);
      glVertex2f(-1.0f, -0.1f);
      glVertex2f( 1.0f, -0.1f);
      glVertex2f( 1.0f, -1.0f);
      glVertex2f( -1.0f, -1.0f);
   glEnd();
  */
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0.0,-.25,0);
    glTranslatef(position,position2, 0.0f);
    car();
    glPopMatrix();
}

///marine_drive_done


///marine_drive_extra_start scene 03
void  marine_drive_extra()
{

//soundPlayer();
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);






    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(64, 164, 223);
    glVertex2d(-1,-1);
    glVertex2d(1,-1);
    glVertex2d(1,1);
    glVertex2d(-1,1);
    glEnd();






    glLoadIdentity();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(133, 193, 233);
    glVertex3d(-1,0.2,1);
    glVertex3d(1,0.2,1.9);
    glVertex3d(1,1,0.8);
    glVertex3d(-1,1,0.5);
    glEnd();



    glScalef(0.6,0.8,0);
    glTranslatef(0.2,0.1,0);
    sky1(1);
    glLoadIdentity();
    glScalef(0.6,0.8,0);
    glTranslatef(-0.2,0.3,0);
    sky1(2);
    glLoadIdentity();
    glScalef(0.6,0.8,0);
    glTranslatef(-0.5,0.1,0);
    sky1(3);



    glPopMatrix();


    glLoadIdentity();
    glPushMatrix();
    glColor3ub(238, 214, 180);
    drawFilledCircleRoad(1,-1,1.4);
    glPopMatrix();


    glLoadIdentity();
    glPushMatrix();
    glColor3ub(18, 48, 4);
    drawFilledCircleRoad(1,-1,1.289);
    glPopMatrix();



    glLoadIdentity();

    glPushMatrix();
    glColor3ub(31,31,31);
    drawFilledCircleRoad(1,-1,1.2);
    glPopMatrix();

    glLoadIdentity();

    glPushMatrix();
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glLineWidth(20);
    drawHollowCircle(.999,-.999,1.2);
    glPopMatrix();

    glLoadIdentity();

    glPushMatrix();
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glLineWidth(20);
    drawHollowCircle(.999,-.999,.8);
    glPopMatrix();

     glLoadIdentity();
    glPushMatrix();
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    glLineWidth(20);
    drawHollowCircle(.999,-.999,1);
    glPopMatrix();

    glLoadIdentity();
    glPushMatrix();
    glColor3ub(18, 48, 4);
    drawFilledCircleRoad(1,-1,.8);
    glPopMatrix();

  /*  glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(31, 31, 40);
    glVertex2d(-1,-1);
    glVertex2d(1,-1);
    glVertex2d(1,1);
    glVertex2d(-1,1);
    glEnd();*/


    //draw_background();
//glutSolidTorus(0.01,0.03,100,100);

    glPushMatrix();
        glTranslated(2.4,1.2,-6);
        glRotated(60,1,0,0);
        glRotated(100,0,0,1);

    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();        //Air-Balloon
    glScalef(1.5,2,0);
    glTranslatef(-0.5,0.1,0);
    sky1(4);

    glLoadIdentity();        //Air-Balloon
    glScalef(1.5,2,0);
    glTranslatef(-0.1,0.13,0);
    sky1(4);

    glLoadIdentity();        //Air-Balloon
    glScalef(1.5,2,0);
    glTranslatef(-0.9,0.16,0);
    sky1(4);
    glPopMatrix();


}

///marine_drive_extra_done


///sea_start
void draw_rode()
{
    glBegin(GL_LINES);
    glColor3ub(255,0,0);
    glVertex2d(1,0.6);
    glVertex2d(-1,0.6);
    glVertex2d(1,-0.6);
    glVertex2d(-1,-0.6);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 149, 149);
    glVertex2d(1,0.5);
    glVertex2d(-1,0.5);
    glVertex2d(-1,-0.5);
    glVertex2d(1,-0.5);
    glEnd();

    ///middle line
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2d(1,0);
    glVertex2d(-1,0);

    glEnd();


}

void sea_beach_chair()
{

    //glColor3ub(84,182,211);
    glColor3ub(102, 68, 28);
    glBegin(GL_QUADS);
    glVertex2f(-0.76f, -0.41f);
    glVertex2f(-0.67f, -0.41f);
    glVertex2f(-0.67f, -0.39f);
    glVertex2f(-0.76f, -0.39f);
    glEnd();

    //glColor3ub(84,182,211);
    glBegin(GL_QUADS);
    glVertex2f(-0.74f, -0.39f);
    glVertex2f(-0.725f, -0.39f);
    glVertex2f(-0.745f, -0.35f);
    glVertex2f(-0.76f, -0.35f);
    glEnd();

    glLineWidth(3);
    //glColor3ub(58,156,185);
    glBegin(GL_LINES);
    glVertex2f(-.75f,-.41f);
    glVertex2f(-.75f,-0.44f);
    glEnd();

    //glColor3ub(58,156,185);
    glBegin(GL_LINES);
    glVertex2f(-.69f,-.41f);
    glVertex2f(-.69f,-0.44f);
    glEnd();

    //glColor3ub(58,156,185);
    glBegin(GL_LINES);
    glVertex2f(-.74f,-.41f);
    glVertex2f(-.74f,-0.43f);
    glEnd();

    //glColor3ub(58,156,185);
    glBegin(GL_LINES);
    glVertex2f(-.70f,-.41f);
    glVertex2f(-.70f,-0.43f);
    glEnd();

//    glColor3ub(132,132,132);
//    glBegin(GL_QUADS);
//    glVertex2f(-0.76f, -0.45f);
//    glVertex2f(-0.73f, -0.45f);
//    glVertex2f(-0.73f, -0.37f);
//    glVertex2f(-0.76f, -0.37f);
//    glEnd();
//
//    glColor3ub(49,49,49);
//    glBegin(GL_QUADS);
//    glVertex2f(-0.76f, -0.37f);
//    glVertex2f(-0.73f, -0.37f);
//    glVertex2f(-0.72f, -0.31f);
//    glVertex2f(-0.77f, -0.31f);
//    glEnd();
//
//    glLineWidth(2);
//    glColor3ub(245,245,245);
//    glBegin(GL_LINES);
//    glVertex2f(-.765f,-.35f);
//    glVertex2f(-.725f,-0.35f);
//    glEnd();
//
//    glColor3ub(245,245,245);
//    glBegin(GL_LINES);
//    glVertex2f(-.77f,-.33f);
//    glVertex2f(-.72f,-0.33f);
//    glEnd();


}
///end sea beach chair


void draw_background_sea()
{


    //sky
    glBegin(GL_QUADS);
    glColor3ub(133, 193, 233);
    glVertex2d(-1,0.0);
    glVertex2d(1,0.0);
    glVertex2d(1,1);
    glVertex2d(-1,1);
    glEnd();
    glLoadIdentity();


    //sun
     glLoadIdentity();
     //glScalef(1.8,1.8,0);
     //glTranslatef(0.5,0.0,0);
     glColor3ub(252, 212, 64);

     drawFilledCircle(.65,.75,0.08);
    //sun done

    //clouds
    glTranslatef(0.2,-0.1,0);
    sky1(1);
    glLoadIdentity();
    glTranslatef(-0.2,-0.3,0);
    sky1(2);
    glLoadIdentity();
    glTranslatef(-0.5,0.1,0);
    sky1(3);
    glLoadIdentity();
    glTranslatef(-0.9,-0.1,0);
    sky1(1);
    glLoadIdentity();
    glTranslatef(-1.4,-0.3,0);
    sky1(2);
    glLoadIdentity();

    //sea
    glBegin(GL_QUADS);
    //glColor3ub(64, 164, 223);
    glColor3ub(50, 76, 193);
    glVertex2d(-1,-1);
    glVertex2d(1,-1);
    glVertex2d(1,0.3);
    glVertex2d(-1,0.3);
    glEnd();



//    //wave
//    glBegin(GL_LINES)
//    glEnd();


}

void steam(float value) {
        GLfloat x=.35f;
        GLfloat y=value+0.1;
        GLfloat radius =.02f;
        int triangleAmount = 20;
        GLfloat twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(26, 26, 26);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
        glEnd();

        x=.3f;
        y=value+0.15;
        radius =.02f;
        triangleAmount = 20;
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(26, 26, 26);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
        glEnd();

        x=.25f;
        y=value+0.2;
        radius =.02f;
        triangleAmount = 20;
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(26, 26, 26);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
        glEnd();


}
void draw_boat()
{
    glBegin(GL_POLYGON);
    glVertex2d(0,0);
    glVertex2d(0.1,-0.1);
    glVertex2d(0.5,-0.1);
    glVertex2d(0.6,0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2d(0.1,0);
    glVertex2d(0.3,0);
    glVertex2d(0.25,0.08);
    glVertex2d(0.15,0.08);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2d(0.4,0.04);
    glVertex2d(0.4,0);
    glVertex2d(0.38,0);
    glVertex2d(0.38,0.08);
    glEnd();

    steam(0.0);

    glBegin(GL_QUADS);
    glColor3ub(225, 225, 225);
    glVertex2d(0.24,0.07);
    glVertex2d(0.19,0.07);
    glVertex2d(0.19,0.0);
    glVertex2d(0.29,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(225, 225, 225);
    glVertex2d(0.18,0.07);
    glVertex2d(0.16,0.07);
    glVertex2d(0.11,0.0);
    glVertex2d(0.18,0.0);
    glEnd();

}
void sea_sand()
{
    glBegin(GL_QUADS);
    glColor3ub(214, 151, 14);
    glVertex2d( 1.0,-0.3);
    glVertex2d(-1.0,-0.3);
    glVertex2d(-1.0,-1.0);
    glVertex2d( 1.0,-1.0);
    glEnd();
}
void sea() {
    //Sleep(1000);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();


    glPushMatrix();
    draw_background_sea();
    glPopMatrix();

     glLoadIdentity();
    glPushMatrix();
    glColor3ub(102, 102, 0);
    glRotatef(1,1,0,0);
    glScalef(0.2,0.5,1);
    glTranslatef(position,0.5f, 0.0f);
    draw_boat();
    glPopMatrix();

     glLoadIdentity();
    glPushMatrix();
    glColor3ub(64, 78, 52);
    glRotatef(180,0.1,1,0);
    glScalef(0.2,0.5,1);
    glTranslatef(position,0.3f, 0.0f);
    draw_boat();
    glPopMatrix();

    //sand
     glLoadIdentity();
     glPushMatrix();
     glTranslatef(0.0f,position_sea, 0.0f);
     sea_sand();
     glPopMatrix();

    //umbrella
    glPushMatrix();
    glLoadIdentity();
    glColor3ub(238,39,64);
    drawFilledHalfCircle(-0.6,-0.6,.085);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(-0.6,-0.6);
    glVertex2f(-0.6,-0.85);
    glEnd();
    glPopMatrix();
    //chair
    glPushMatrix();
    glTranslatef(0.21f,-0.39f, 0.0f);
    //glScalef(10,10,10);
    sea_beach_chair();
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glColor3ub(238,39,64);
    drawFilledHalfCircle(0.0,-0.6,.085);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(0.0,-0.6);
    glVertex2f(0.0,-0.85);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.81f,-0.39f, 0.0f);
    //glScalef(10,10,10);
    sea_beach_chair();
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glColor3ub(238,39,64);
    drawFilledHalfCircle(0.6,-0.6,.085);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(0.6,-0.6);
    glVertex2f(0.6,-0.85);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.41f,-0.39f, 0.0f);
    //glScalef(10,10,10);
    sea_beach_chair();
    glPopMatrix();


    //glFlush();
}
///sea_done




void sea_beach()
{
//beach
    glBegin(GL_QUADS);
    glColor3ub(238, 214, 175);
    glVertex2d(-1,-1);
    glVertex2d(1,-1);
    glVertex2d(1,.45);
    glVertex2d(-1,.45);
    glEnd();
//sea
    glBegin(GL_QUADS);
    glColor3ub(133, 193, 233);
    glVertex2d(-1,-1);
    glVertex2d(1,-1);
    glVertex2d(1,-.65);
    glVertex2d(-1,-.65);
    glEnd();

    //things
    glTranslatef(.2,-.9,0);
    glColor3ub(255,0,0);
    glutSolidTorus(0.01,0.04,100,100);

    glLoadIdentity();
    glTranslatef(.2,-.9,0);
    glColor3ub(255,0,0);
    glutSolidTorus(0.01,0.04,100,100);

    glLoadIdentity();
   // sea_beach_chair();




}

///sea_beach_done



///start clouds
void clouds()
{
    int i;

    GLfloat x=.5f;
    GLfloat y=.8f;
    GLfloat radius =.06f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat a=.55f;
    GLfloat b=.84f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(a, b); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a + (radius * cos(i *  twicePi / triangleAmount)),
            b + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat c=.45f;
    GLfloat d=.84f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(c, d); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            c + (radius * cos(i *  twicePi / triangleAmount)),
            d + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


    x=.0f;
    y=.8f;
    radius =.06f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(246, 246, 246);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    x=.08f;
    y=.8f;
    radius =.06f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(246, 246, 246);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    x=.05f;
    y=.87f;
    radius =.06f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(246, 246, 246);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glPopMatrix();
}
/// end clouds


///start sea beach umbrella
void sea_beach_umbrella()
{
    glColor3ub(238,39,64);
    drawFilledHalfCircle(-.8,-.3,.075);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(-.8f,-.45f);
    glVertex2f(-.8f,-0.3f);
    glEnd();
}
///end sea beach umbrella


///start sea beach chair


///start background houses
void bg_house()
{
   //blue sky
    glBegin(GL_QUADS);
    glColor3ub(133, 193, 233);
    glVertex2f(-1.0f,0.7f);
    glVertex2f(1.0f,0.7f);
    glVertex2f(1.0f,1.0f);
    glVertex2f(-1.0f,1.0f);
    glEnd();
   //end blue sky

    //start clouds
    clouds();
    //end clouds
    glPushMatrix();

    //background hotels

    //////////////////////////start left side///////////////////////

    //bg house 1
   glBegin(GL_QUADS);
      glColor3ub(98,55,62);
      glVertex2f(-0.9f, 0.7f);
      glVertex2f(-0.75f, 0.7f);
      glVertex2f(-0.75f, 1.0f);
      glVertex2f(-0.9f, 1.0f);
      glEnd();

      //background hotel window (1)
   //glTranslatef(0.0f,-0.9f,0.0f);
   glBegin(GL_QUADS);
      glColor3ub(172,194,181);
      glVertex2f(-0.85f,0.72f);
      glVertex2f(-0.79f, 0.72f);
      glVertex2f(-0.79f, 0.82f);
      glVertex2f(-0.85f, 0.82f);
      glEnd();

      glLineWidth(5);
      glBegin(GL_LINES);
    //background hotel window lines (1)
      glColor3ub(247, 223, 177);
      //horiontal
      glVertex2f(-0.85f,0.72f);
      glVertex2f(-0.79f, 0.72f);

      glVertex2f(-0.79f, 0.82f);
      glVertex2f(-0.85f, 0.82f);

      //vertical
      glVertex2f(-0.847f,0.72f);
      glVertex2f(-0.847f, 0.82f);

      glVertex2f(-0.793f, 0.72f);
      glVertex2f(-0.793f, 0.82f);

      glEnd();
      glLoadIdentity();

      //background hotel window (2)
   glTranslatef(0.0f,0.148f,0.0f);
   glBegin(GL_QUADS);
      glColor3ub(172,194,181);
      glVertex2f(-0.85f,0.72f);
      glVertex2f(-0.79f, 0.72f);
      glVertex2f(-0.79f, 0.82f);
      glVertex2f(-0.85f, 0.82f);
      glEnd();

      glLineWidth(5);
      glBegin(GL_LINES);
    //background hotel window lines (2)
      glColor3ub(247, 223, 177);
      //horiontal
      glVertex2f(-0.85f,0.72f);
      glVertex2f(-0.79f, 0.72f);

      glVertex2f(-0.79f, 0.82f);
      glVertex2f(-0.85f, 0.82f);

      //vertical
      glVertex2f(-0.847f,0.72f);
      glVertex2f(-0.847f, 0.82f);

      glVertex2f(-0.793f, 0.72f);
      glVertex2f(-0.793f, 0.82f);

      glEnd();
      glLoadIdentity();

    //adjacent house of bg house 1
    glTranslatef(0.06f,0.0f,0.0f);
    glScalef(0.9,0.9,0.0);
   glBegin(GL_QUADS);
      glColor3ub(98,55,62);
      glVertex2f(-0.9f, 0.7f);
      glVertex2f(-0.75f, 0.7f);
      glVertex2f(-0.75f, 1.0f);
      glVertex2f(-0.9f, 1.0f);
      glEnd();
      glLoadIdentity();

      //background hotel window of adjacent house of bg house 1 (3)
   glTranslatef(0.14f,0.03f,0.0f);
   glBegin(GL_QUADS);
      glColor3ub(172,194,181);
      glVertex2f(-0.85f,0.72f);
      glVertex2f(-0.79f, 0.72f);
      glVertex2f(-0.79f, 0.82f);
      glVertex2f(-0.85f, 0.82f);
      glEnd();

      glLineWidth(5);
      glBegin(GL_LINES);
    //background hotel window lines (2)
      glColor3ub(247, 223, 177);
      //horiontal
      glVertex2f(-0.85f,0.72f);
      glVertex2f(-0.79f, 0.72f);

      glVertex2f(-0.79f, 0.82f);
      glVertex2f(-0.85f, 0.82f);

      //vertical
      glVertex2f(-0.847f,0.72f);
      glVertex2f(-0.847f, 0.82f);

      glVertex2f(-0.793f, 0.72f);
      glVertex2f(-0.793f, 0.82f);

      glEnd();
      glLoadIdentity();

      //green tree
   glBegin(GL_QUADS);
      glColor3ub(162,119,85);
      glVertex2f(-0.5f,0.7f);
      glVertex2f(-0.53f, 0.7f);
      glVertex2f(-0.53f, 0.8f);
      glVertex2f(-0.5f, 0.8f);
      glEnd();

   glBegin(GL_TRIANGLES);
      glColor3ub(91,142,86);
      glVertex2f(-0.57f,0.8f);
      glVertex2f(-0.46f, 0.8f);
      glVertex2f(-0.515f, 0.9f);
      glEnd();


   glBegin(GL_TRIANGLES);
      glColor3ub(91,142,86);
      glVertex2f(-0.57f,0.87f);
      glVertex2f(-0.46f, 0.87f);
      glVertex2f(-0.515f, 0.97f);
      glEnd();

    //end green tree

    //bg house 1
    glTranslatef(0.5f,0.0f,0.0f);
   glBegin(GL_QUADS);
      glColor3ub(98,55,62);
      glVertex2f(-0.9f, 0.7f);
      glVertex2f(-0.75f, 0.7f);
      glVertex2f(-0.75f, 1.0f);
      glVertex2f(-0.9f, 1.0f);
      glEnd();

      //background hotel window (1)
   //glTranslatef(0.0f,-0.9f,0.0f);
   glBegin(GL_QUADS);
      glColor3ub(172,194,181);
      glVertex2f(-0.85f,0.72f);
      glVertex2f(-0.79f, 0.72f);
      glVertex2f(-0.79f, 0.82f);
      glVertex2f(-0.85f, 0.82f);
      glEnd();

      glLineWidth(5);
      glBegin(GL_LINES);
    //background hotel window lines (1)
      glColor3ub(247, 223, 177);
      //horiontal
      glVertex2f(-0.85f,0.72f);
      glVertex2f(-0.79f, 0.72f);

      glVertex2f(-0.79f, 0.82f);
      glVertex2f(-0.85f, 0.82f);

      //vertical
      glVertex2f(-0.847f,0.72f);
      glVertex2f(-0.847f, 0.82f);

      glVertex2f(-0.793f, 0.72f);
      glVertex2f(-0.793f, 0.82f);

      glEnd();
      glLoadIdentity();

      //background hotel window (2)
   glTranslatef(0.5f,0.148f,0.0f);
   glBegin(GL_QUADS);
      glColor3ub(172,194,181);
      glVertex2f(-0.85f,0.72f);
      glVertex2f(-0.79f, 0.72f);
      glVertex2f(-0.79f, 0.82f);
      glVertex2f(-0.85f, 0.82f);
      glEnd();

      glLineWidth(5);
      glBegin(GL_LINES);
    //background hotel window lines (2)
      glColor3ub(247, 223, 177);
      //horiontal
      glVertex2f(-0.85f,0.72f);
      glVertex2f(-0.79f, 0.72f);

      glVertex2f(-0.79f, 0.82f);
      glVertex2f(-0.85f, 0.82f);

      //vertical
      glVertex2f(-0.847f,0.72f);
      glVertex2f(-0.847f, 0.82f);

      glVertex2f(-0.793f, 0.72f);
      glVertex2f(-0.793f, 0.82f);

      glEnd();
      glLoadIdentity();

      //green tree
      glTranslatef(0.44f,-0.1f,0.0f);
      glScalef(1.1,1.1,0.0);
   glBegin(GL_QUADS);
      glColor3ub(162,119,85);
      glVertex2f(-0.5f,0.7f);
      glVertex2f(-0.53f, 0.7f);
      glVertex2f(-0.53f, 0.8f);
      glVertex2f(-0.5f, 0.8f);
      glEnd();

    //glTranslatef(0.4f,0.0f,0.0f);
   glBegin(GL_TRIANGLES);
      glColor3ub(91,142,86);
      glVertex2f(-0.57f,0.8f);
      glVertex2f(-0.46f, 0.8f);
      glVertex2f(-0.515f, 0.9f);
      glEnd();

   glBegin(GL_TRIANGLES);
      glColor3ub(91,142,86);
      glVertex2f(-0.57f,0.87f);
      glVertex2f(-0.46f, 0.87f);
      glVertex2f(-0.515f, 0.97f);
      glEnd();
      glLoadIdentity();
      //end green tree

      //////////////////////////end left side///////////////////////

    //////////////////////////start right side///////////////////////

    //bg house 1
   glBegin(GL_QUADS);
      glColor3ub(98,55,62);
      glVertex2f(0.9f, 0.7f);
      glVertex2f(0.75f, 0.7f);
      glVertex2f(0.75f, 1.0f);
      glVertex2f(0.9f, 1.0f);
      glEnd();

      //background hotel window (1)
   //glTranslatef(0.0f,-0.9f,0.0f);
   glBegin(GL_QUADS);
      glColor3ub(172,194,181);
      glVertex2f(0.85f,0.72f);
      glVertex2f(0.79f, 0.72f);
      glVertex2f(0.79f, 0.82f);
      glVertex2f(0.85f, 0.82f);
      glEnd();

      glLineWidth(5);
      glBegin(GL_LINES);
    //background hotel window lines (1)
      glColor3ub(247, 223, 177);
      //horiontal
      glVertex2f(0.85f,0.72f);
      glVertex2f(0.79f, 0.72f);

      glVertex2f(0.79f, 0.82f);
      glVertex2f(0.85f, 0.82f);

      //vertical
      glVertex2f(0.847f,0.72f);
      glVertex2f(0.847f, 0.82f);

      glVertex2f(0.793f, 0.72f);
      glVertex2f(0.793f, 0.82f);

      glEnd();
      glLoadIdentity();

      //background hotel window (2)
   glTranslatef(0.0f,0.148f,0.0f);
   glBegin(GL_QUADS);
      glColor3ub(172,194,181);
      glVertex2f(0.85f,0.72f);
      glVertex2f(0.79f, 0.72f);
      glVertex2f(0.79f, 0.82f);
      glVertex2f(0.85f, 0.82f);
      glEnd();

      glLineWidth(5);
      glBegin(GL_LINES);
    //background hotel window lines (2)
      glColor3ub(247, 223, 177);
      //horiontal
      glVertex2f(0.85f,0.72f);
      glVertex2f(0.79f, 0.72f);

      glVertex2f(0.79f, 0.82f);
      glVertex2f(0.85f, 0.82f);

      //vertical
      glVertex2f(0.847f,0.72f);
      glVertex2f(0.847f, 0.82f);

      glVertex2f(0.793f, 0.72f);
      glVertex2f(0.793f, 0.82f);

      glEnd();
      glLoadIdentity();

    //adjacent house of bg house 1
    glTranslatef(-0.06f,0.0f,0.0f);
    glScalef(0.9,0.9,0.0);
   glBegin(GL_QUADS);
      glColor3ub(98,55,62);
      glVertex2f(0.9f, 0.7f);
      glVertex2f(0.75f, 0.7f);
      glVertex2f(0.75f, 1.0f);
      glVertex2f(0.9f, 1.0f);
      glEnd();
      glLoadIdentity();

      //background hotel window of adjacent house of bg house 1 (3)
   glTranslatef(-0.14f,0.03f,0.0f);
   glBegin(GL_QUADS);
      glColor3ub(172,194,181);
      glVertex2f(0.85f,0.72f);
      glVertex2f(0.79f, 0.72f);
      glVertex2f(0.79f, 0.82f);
      glVertex2f(0.85f, 0.82f);
      glEnd();

      glLineWidth(5);
      glBegin(GL_LINES);
    //background hotel window lines (2)
      glColor3ub(247, 223, 177);
      //horiontal
      glVertex2f(0.85f,0.72f);
      glVertex2f(0.79f, 0.72f);

      glVertex2f(0.79f, 0.82f);
      glVertex2f(0.85f, 0.82f);

      //vertical
      glVertex2f(0.847f,0.72f);
      glVertex2f(0.847f, 0.82f);

      glVertex2f(0.793f, 0.72f);
      glVertex2f(0.793f, 0.82f);

      glEnd();
      glLoadIdentity();

      //green tree
   glBegin(GL_QUADS);
      glColor3ub(162,119,85);
      glVertex2f(0.5f,0.7f);
      glVertex2f(0.53f, 0.7f);
      glVertex2f(0.53f, 0.8f);
      glVertex2f(0.5f, 0.8f);
      glEnd();

   glBegin(GL_TRIANGLES);
      glColor3ub(91,142,86);
      glVertex2f(0.57f,0.8f);
      glVertex2f(0.46f, 0.8f);
      glVertex2f(0.515f, 0.9f);
      glEnd();


   glBegin(GL_TRIANGLES);
      glColor3ub(91,142,86);
      glVertex2f(0.57f,0.87f);
      glVertex2f(0.46f, 0.87f);
      glVertex2f(0.515f, 0.97f);
      glEnd();

    //end green tree

    //bg house 1
    glTranslatef(-0.5f,0.0f,0.0f);
   glBegin(GL_QUADS);
      glColor3ub(98,55,62);
      glVertex2f(0.9f, 0.7f);
      glVertex2f(0.75f, 0.7f);
      glVertex2f(0.75f, 1.0f);
      glVertex2f(0.9f, 1.0f);
      glEnd();

      //background hotel window (1)
   //glTranslatef(0.0f,-0.9f,0.0f);
   glBegin(GL_QUADS);
      glColor3ub(172,194,181);
      glVertex2f(0.85f,0.72f);
      glVertex2f(0.79f, 0.72f);
      glVertex2f(0.79f, 0.82f);
      glVertex2f(0.85f, 0.82f);
      glEnd();

      glLineWidth(5);
      glBegin(GL_LINES);
    //background hotel window lines (1)
      glColor3ub(247, 223, 177);
      //horiontal
      glVertex2f(0.85f,0.72f);
      glVertex2f(0.79f, 0.72f);

      glVertex2f(0.79f, 0.82f);
      glVertex2f(0.85f, 0.82f);

      //vertical
      glVertex2f(0.847f,0.72f);
      glVertex2f(0.847f, 0.82f);

      glVertex2f(0.793f, 0.72f);
      glVertex2f(0.793f, 0.82f);

      glEnd();
      glLoadIdentity();

      //background hotel window (2)
   glTranslatef(-0.5f,0.148f,0.0f);
   glBegin(GL_QUADS);
      glColor3ub(172,194,181);
      glVertex2f(0.85f,0.72f);
      glVertex2f(0.79f, 0.72f);
      glVertex2f(0.79f, 0.82f);
      glVertex2f(0.85f, 0.82f);
      glEnd();

      glLineWidth(5);
      glBegin(GL_LINES);
    //background hotel window lines (2)
      glColor3ub(247, 223, 177);
      //horiontal
      glVertex2f(0.85f,0.72f);
      glVertex2f(0.79f, 0.72f);

      glVertex2f(0.79f, 0.82f);
      glVertex2f(0.85f, 0.82f);

      //vertical
      glVertex2f(0.847f,0.72f);
      glVertex2f(0.847f, 0.82f);

      glVertex2f(0.793f, 0.72f);
      glVertex2f(0.793f, 0.82f);

      glEnd();
      glLoadIdentity();

      //green tree
      glTranslatef(-0.44f,-0.1f,0.0f);
      glScalef(1.1,1.1,0.0);
   glBegin(GL_QUADS);
      glColor3ub(162,119,85);
      glVertex2f(0.5f,0.7f);
      glVertex2f(0.53f, 0.7f);
      glVertex2f(0.53f, 0.8f);
      glVertex2f(0.5f, 0.8f);
      glEnd();

    //glTranslatef(0.4f,0.0f,0.0f);
   glBegin(GL_TRIANGLES);
      glColor3ub(91,142,86);
      glVertex2f(0.57f,0.8f);
      glVertex2f(0.46f, 0.8f);
      glVertex2f(0.515f, 0.9f);
      glEnd();

   glBegin(GL_TRIANGLES);
      glColor3ub(91,142,86);
      glVertex2f(0.57f,0.87f);
      glVertex2f(0.46f, 0.87f);
      glVertex2f(0.515f, 0.97f);
      glEnd();
      glLoadIdentity();
      //end green tree

      //////////////////////////end right side///////////////////////

    //end background hotels
}
///end background houses


///resort start
void resort()
{

   glClear(GL_COLOR_BUFFER_BIT);
   glLineWidth(8);
   glLoadIdentity();

   //soundPlayer();

    bg_house();

   //green space
   glBegin(GL_QUADS);
      glColor3ub(82, 190, 128);
      glVertex2f(1.0f, 0.48f);
      glVertex2f(1.0f, 0.7f);
      glVertex2f(-1.0f, 0.7f);
      glVertex2f(-1.0f, 0.48f);
      glEnd();
      //sand area
      glBegin(GL_QUADS);
      glColor3ub(255,225,161);
      glVertex2f(1.0f, -0.5f);
      glVertex2f(1.0f, -0.2f);
      glVertex2f(-1.0f, -0.2f);
      glVertex2f(-1.0f, -0.5f);
      glEnd();

      //sea area
      glBegin(GL_QUADS);
      glColor3ub(64,164,223);
      glVertex2f(1.0f, -1.0f);
      glVertex2f(1.0f, -0.5f);
      glVertex2f(-1.0f, -0.5f);
      glVertex2f(-1.0f, -1.0f);
      glEnd();

  //glScalef(0.0f,2.5f,0.0f);
    //right side ,4
    glBegin(GL_QUADS);
      glColor3ub(210, 150, 63);
      glVertex2f(0.55f, -0.2f);
      glVertex2f(0.42f, -0.2f);
      glVertex2f(0.42f, 0.48f);
      glVertex2f(0.55f, 0.48f);
      glEnd();
    glBegin(GL_QUADS);
      //glColor3ub(250, 215, 160);
      glColor3ub(210, 150, 63);
      glVertex2f(-0.55f, -0.2f);
      glVertex2f(-0.42f, -0.2f);
      glVertex2f(-0.42f, 0.48f);
      glVertex2f(-0.55f, 0.48f);
      glEnd();

//piller left
      glBegin(GL_QUADS);
      glColor3ub(255, 255, 204);
      glVertex2f(-0.5175f, -0.2f);
      glVertex2f(-0.4525f, -0.2f);
      glVertex2f(-0.4525f, 0.48f);
      glVertex2f(-0.5175f, 0.48f);
      glEnd();
//piller left
      glBegin(GL_QUADS);
      glColor3ub(255, 255, 204);
      glVertex2f(0.5175f, -0.2f);
      glVertex2f(0.4525f, -0.2f);
      glVertex2f(0.4525f, 0.48f);
      glVertex2f(0.5175f, 0.48f);
      glEnd();



       //RIGHT SIDE BACKGROUND
    glBegin(GL_QUADS);
      glColor3ub(238, 232, 170);
      glVertex2f(0.55f, -0.2f);
      glVertex2f(1.0f, -0.2f);
      glVertex2f(1.0f, 0.48f);
      glVertex2f(0.55f, 0.48f);
      glEnd();
       //LEFT SIDE BACKGROUND
    glBegin(GL_QUADS);
      glColor3ub(238, 232, 170);
      glVertex2f(-0.55f, -0.2f);
      glVertex2f(-1.0f, -0.2f);
      glVertex2f(-1.0f, 0.48f);
      glVertex2f(-0.55f, 0.48f);
      glEnd();


//////////////////window RIGHT,LEFT(1) outer border
       glBegin(GL_QUADS);
      glColor3ub(237, 151, 12);
      glVertex2f(0.730f,0.288f);
      glVertex2f(0.730f, 0.462f);
      glVertex2f(0.601f, 0.462f);
      glVertex2f(0.601f, 0.288f);
      glEnd();
      glBegin(GL_LINES);
////window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(0.724f,0.295f);
      glVertex2f(0.724f, 0.455f);
      glVertex2f(0.6062f, 0.455f);
      glVertex2f(0.6062f, 0.295f);
      glEnd();
      glBegin(GL_LINES);
//DOORS RIGHT,LEFT(1) lines
      glColor3ub(237, 151, 12);
      //horiontal
      glVertex2f(0.6062f,0.375f);
      glVertex2f(0.724f, 0.375f);
      //vertical
      glVertex2f(0.6656f,0.295f);
      glVertex2f(0.6656f, 0.455f);

      glEnd();


//DOORS RIGHT,right(1)
      ////translate
      glTranslatef(0.226f,0.0f,0.0f);
      glBegin(GL_QUADS);
      glColor3ub(237, 151, 12);
      glVertex2f(0.730f,0.288f);
      glVertex2f(0.730f, 0.462f);
      glVertex2f(0.601f, 0.462f);
      glVertex2f(0.601f, 0.288f);
      glEnd();
      glBegin(GL_LINES);
//window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(0.724f,0.295f);
      glVertex2f(0.724f, 0.455f);
      glVertex2f(0.6062f, 0.455f);
      glVertex2f(0.6062f, 0.295f);
      glEnd();
      glBegin(GL_LINES);
//DOORS RIGHT,LEFT(1) lines
      glColor3ub(237, 151, 12);
      //horiontal
      glVertex2f(0.6062f,0.375f);
      glVertex2f(0.724f, 0.375f);
      //vertical
      glVertex2f(0.6656f,0.295f);
      glVertex2f(0.6656f, 0.455f);

      glEnd();
      glLoadIdentity();

      //////////////////DOORS left,right(1)
      ////translate
      glTranslatef(-0.226f,0.0f,0.0f);
      glBegin(GL_QUADS);
      glColor3ub(237, 151, 12);
      glVertex2f(-0.730f,0.288f);
      glVertex2f(-0.730f, 0.462f);
      glVertex2f(-0.601f, 0.462f);
      glVertex2f(-0.601f, 0.288f);
      glEnd();
      glBegin(GL_LINES);
//window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(-0.724f,0.295f);
      glVertex2f(-0.724f, 0.455f);
      glVertex2f(-0.6062f, 0.455f);
      glVertex2f(-0.6062f, 0.295f);
      glEnd();
      glBegin(GL_LINES);
//window RIGHT,LEFT(1) lines
      glColor3ub(237, 151, 12);
      //horiontal
      glVertex2f(-0.6062f,0.375f);
      glVertex2f(-0.724f, 0.375f);
      //vertical
      glVertex2f(-0.6656f,0.295f);
      glVertex2f(-0.6656f, 0.455f);

      glEnd();
      glLoadIdentity();

//.////window right, left 2

      ////translate
      glTranslatef(0.0f,-0.225f,0.0f);
      glBegin(GL_QUADS);
      glColor3ub(237, 151, 12);
      glVertex2f(0.730f,0.288f);
      glVertex2f(0.730f, 0.462f);
      glVertex2f(0.601f, 0.462f);
      glVertex2f(0.601f, 0.288f);
      glEnd();
      glBegin(GL_LINES);
//window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(0.724f,0.295f);
      glVertex2f(0.724f, 0.455f);
      glVertex2f(0.6062f, 0.455f);
      glVertex2f(0.6062f, 0.295f);
      glEnd();
      glBegin(GL_LINES);
//DOORS RIGHT,LEFT(1) lines
      glColor3ub(237, 151, 12);
      //horiontal
      glVertex2f(0.6062f,0.375f);
      glVertex2f(0.724f, 0.375f);
      //vertical
      glVertex2f(0.6656f,0.295f);
      glVertex2f(0.6656f, 0.455f);

      glEnd();
      glLoadIdentity();


      //.////window right,right 2

      ////translate
      glTranslatef(0.0f,-0.225f,0.0f);
      glBegin(GL_QUADS);
      glColor3ub(237, 151, 12);
      glVertex2f(-0.730f,0.288f);
      glVertex2f(-0.730f, 0.462f);
      glVertex2f(-0.601f, 0.462f);
      glVertex2f(-0.601f, 0.288f);
      glEnd();
      glBegin(GL_LINES);
//window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(-0.724f,0.295f);
      glVertex2f(-0.724f, 0.455f);
      glVertex2f(-0.6062f, 0.455f);
      glVertex2f(-0.6062f, 0.295f);
      glEnd();
      glBegin(GL_LINES);
//DOORS RIGHT,LEFT(1) lines
      glColor3ub(237, 151, 12);
      //horiontal
      glVertex2f(-0.6062f,0.375f);
      glVertex2f(-0.724f, 0.375f);
      //vertical
      glVertex2f(-0.6656f,0.295f);
      glVertex2f(-0.6656f, 0.455f);
      glEnd();
      glLoadIdentity();

      //.////window right,right 2

      ////translate
      glTranslatef(0.225f,-0.225f,0.0f);
      glBegin(GL_QUADS);
      glColor3ub(237, 151, 12);
      glVertex2f(0.730f,0.288f);
      glVertex2f(0.730f, 0.462f);
      glVertex2f(0.601f, 0.462f);
      glVertex2f(0.601f, 0.288f);
      glEnd();
      glBegin(GL_LINES);
//window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(0.724f,0.295f);
      glVertex2f(0.724f, 0.455f);
      glVertex2f(0.6062f, 0.455f);
      glVertex2f(0.6062f, 0.295f);
      glEnd();
      glBegin(GL_LINES);
//DOORS RIGHT,LEFT(1) lines
      glColor3ub(237, 151, 12);
      //horiontal
      glVertex2f(0.6062f,0.375f);
      glVertex2f(0.724f, 0.375f);
      //vertical
      glVertex2f(0.6656f,0.295f);
      glVertex2f(0.6656f, 0.455f);

      glEnd();
      glLoadIdentity();
      //.////window right,left 2

      ////translate
      glTranslatef(-0.225f,-0.225f,0.0f);
      glBegin(GL_QUADS);
      glColor3ub(237, 151, 12);
      glVertex2f(-0.730f,0.288f);
      glVertex2f(-0.730f, 0.462f);
      glVertex2f(-0.601f, 0.462f);
      glVertex2f(-0.601f, 0.288f);
      glEnd();
      glBegin(GL_LINES);
//window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(-0.724f,0.295f);
      glVertex2f(-0.724f, 0.455f);
      glVertex2f(-0.6062f, 0.455f);
      glVertex2f(-0.6062f, 0.295f);
      glEnd();
      glBegin(GL_LINES);
//DOORS RIGHT,LEFT(1) lines
      glColor3ub(237, 151, 12);
      //horiontal
      glVertex2f(-0.6062f,0.375f);
      glVertex2f(-0.724f, 0.375f);
      //vertical
      glVertex2f(-0.6656f,0.295f);
      glVertex2f(-0.6656f, 0.455f);

      glEnd();
      glLoadIdentity();
      //.////window left,right 3

      ////translate
      glTranslatef(0.0f,-0.45f,0.0f);
      glBegin(GL_QUADS);
      glColor3ub(237, 151, 12);
      glVertex2f(-0.730f,0.288f);
      glVertex2f(-0.730f, 0.462f);
      glVertex2f(-0.601f, 0.462f);
      glVertex2f(-0.601f, 0.288f);
      glEnd();
      glBegin(GL_LINES);
//window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(-0.724f,0.295f);
      glVertex2f(-0.724f, 0.455f);
      glVertex2f(-0.6062f, 0.455f);
      glVertex2f(-0.6062f, 0.295f);
      glEnd();
      glBegin(GL_LINES);
//DOORS RIGHT,LEFT(1) lines
      glColor3ub(237, 151, 12);
      //horiontal
      glVertex2f(-0.6062f,0.375f);
      glVertex2f(-0.724f, 0.375f);
      //vertical
      glVertex2f(-0.6656f,0.295f);
      glVertex2f(-0.6656f, 0.455f);

      glEnd();
      glLoadIdentity();
      ////window 3 right,left
      ////translate
      glTranslatef(0.225f,-0.445f,0.0f);
      glBegin(GL_QUADS);
      glColor3ub(237, 151, 12);
      glVertex2f(0.730f,0.288f);
      glVertex2f(0.730f, 0.462f);
      glVertex2f(0.601f, 0.462f);
      glVertex2f(0.601f, 0.288f);
      glEnd();
      glBegin(GL_LINES);
//window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(0.724f,0.295f);
      glVertex2f(0.724f, 0.455f);
      glVertex2f(0.6062f, 0.455f);
      glVertex2f(0.6062f, 0.295f);
      glEnd();
      glBegin(GL_LINES);
//DOORS RIGHT,LEFT(1) lines
      glColor3ub(237, 151, 12);
      //horiontal
      glVertex2f(0.6062f,0.375f);
      glVertex2f(0.724f, 0.375f);
      //vertical
      glVertex2f(0.6656f,0.295f);
      glVertex2f(0.6656f, 0.455f);

      glEnd();
      glLoadIdentity();
      ////window 3 right,left
      ////translate
      glTranslatef(0.0f,-0.445f,0.0f);
      glBegin(GL_QUADS);
      glColor3ub(237, 151, 12);
      glVertex2f(0.730f,0.288f);
      glVertex2f(0.730f, 0.462f);
      glVertex2f(0.601f, 0.462f);
      glVertex2f(0.601f, 0.288f);
      glEnd();
      glBegin(GL_LINES);
//window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(0.724f,0.295f);
      glVertex2f(0.724f, 0.455f);
      glVertex2f(0.6062f, 0.455f);
      glVertex2f(0.6062f, 0.295f);
      glEnd();
      glBegin(GL_LINES);
//DOORS RIGHT,LEFT(1) lines
      glColor3ub(237, 151, 12);
      //horiontal
      glVertex2f(0.6062f,0.375f);
      glVertex2f(0.724f, 0.375f);
      //vertical
      glVertex2f(0.6656f,0.295f);
      glVertex2f(0.6656f, 0.455f);

      glEnd();
      glLoadIdentity();
      //window 3 left ,left
      ////translate
      glTranslatef(-0.225f,-0.445f,0.0f);
      glBegin(GL_QUADS);
      glColor3ub(237, 151, 12);
      glVertex2f(-0.730f,0.288f);
      glVertex2f(-0.730f, 0.462f);
      glVertex2f(-0.601f, 0.462f);
      glVertex2f(-0.601f, 0.288f);
      glEnd();
      glBegin(GL_LINES);
//window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(-0.724f,0.295f);
      glVertex2f(-0.724f, 0.455f);
      glVertex2f(-0.6062f, 0.455f);
      glVertex2f(-0.6062f, 0.295f);
      glEnd();
      glBegin(GL_LINES);
//DOORS RIGHT,LEFT(1) lines
      glColor3ub(237, 151, 12);
      //horiontal
      glVertex2f(-0.6062f,0.375f);
      glVertex2f(-0.724f, 0.375f);
      //vertical
      glVertex2f(-0.6656f,0.295f);
      glVertex2f(-0.6656f, 0.455f);

      glEnd();
      glLoadIdentity();


      //MIRROR LEFT SIDE
      //window RIGHT,LEFT(1) outer border
       glBegin(GL_QUADS);
      glColor3ub(237, 151, 12);
      glVertex2f(-0.730f,0.288f);
      glVertex2f(-0.730f, 0.462f);
      glVertex2f(-0.601f, 0.462f);
      glVertex2f(-0.601f, 0.288f);
      glEnd();
      glBegin(GL_LINES);
//window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(-0.724f,0.295f);
      glVertex2f(-0.724f, 0.455f);
      glVertex2f(-0.6062f, 0.455f);
      glVertex2f(-0.6062f, 0.295f);
      glEnd();
      glBegin(GL_LINES);
//windows RIGHT,LEFT(1) lines
      glColor3ub(237, 151, 12);
      //horiontal
      glVertex2f(-0.6062f,0.375f);
      glVertex2f(-0.724f, 0.375f);
      //vertical
      glVertex2f(-0.6656f,0.295f);
      glVertex2f(-0.6656f, 0.455f);
      glEnd();
      glLoadIdentity();


//window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(-0.724f,0.295f);
      glVertex2f(-0.724f, 0.455f);
      glVertex2f(-0.6062f, 0.455f);
      glVertex2f(-0.6062f, 0.295f);
      glEnd();
      //DOORS RIGHT,LEFT(1) lines
      glBegin(GL_LINES);
      glColor3ub(237, 151, 12);
      //horiontal
      glVertex2f(-0.6062f,0.375f);
      glVertex2f(-0.724f, 0.375f);
      //vertical
      glVertex2f(-0.6656f,0.295f);
      glVertex2f(-0.6656f, 0.455f);

      glEnd();
      glLoadIdentity();



    glBegin(GL_LINES);

       //right side
      //lines
      glColor3ub(238, 196, 113);
      glVertex2f(0.41f, 0.48f);
      glVertex2f(1.0f, 0.48f);

      glVertex2f(-0.41f, 0.48f);
      glVertex2f(-1.0f, 0.48f);

//vertical RIGHT
      glVertex2f(0.55f, 0.5f);
      glVertex2f(0.55f, -0.2f);

      glVertex2f(0.99f,0.48f);
      glVertex2f(0.99f,-0.2);


//LEFT
      glVertex2f(-0.55f, 0.5f);
      glVertex2f(-0.55f, -0.2f);
//HORIZONTAL RIGHT
      glVertex2f(0.775f, 0.48f);
      glVertex2f(0.775f, -0.2f);
//LEFT
      glVertex2f(-0.775f, 0.48f);
      glVertex2f(-0.775f, -0.2f);

      glVertex2f(-0.99f,0.48f);
      glVertex2f(-0.99f,-0.2);
      glEnd();

//1 roof
    glBegin(GL_QUADS);
      glColor3ub(249, 231, 159);
      glVertex2f(0.62f, 0.45f);
      glVertex2f(0.5f, 0.45f);
      glVertex2f(0.0f, 0.75f);
      glVertex2f(0.0f, 0.8f);
      glEnd();

    glBegin(GL_QUADS);
      glColor3ub(249, 231, 159);
      glVertex2f(-0.62f, 0.45f);
      glVertex2f(-0.5f, 0.45f);
      glVertex2f(-0.0f, 0.75f);
      glVertex2f(-0.0f, 0.8f);
      glEnd();
//2,roof

    glBegin(GL_QUADS);
      //glColor3ub(235, 152, 78);
      glColor3ub(229, 152, 102);
      glVertex2f(0.7f, 0.44f);
      glVertex2f(0.62f, 0.44f);
      glVertex2f(0.0f, 0.8f);
      glVertex2f(0.0f, 0.85f);
      glEnd();

    glBegin(GL_QUADS);
      glColor3ub(229, 152, 102);
      glVertex2f(-0.7f, 0.44f);
      glVertex2f(-0.62f, 0.44f);
      glVertex2f(0.0f, 0.8f);
      glVertex2f(0.0f, 0.85f);
      glEnd();

      //3 roof

    glBegin(GL_TRIANGLES);
      glColor3ub(238, 196, 113);
      //glColor3ub(251, 189, 66);
      glVertex2f(0.42f, 0.5f);
      glVertex2f(0.0f, 0.75f);
      glVertex2f(-0.42f, 0.5f);
      glEnd();
//mid background color
    glBegin(GL_QUADS);
      glColor3ub(238, 232, 170);
      glVertex2f(0.42f, -0.2f);
      glVertex2f(-0.42f, -0.2f);
      glVertex2f(-0.42f, 0.5f);
      glVertex2f(0.42f, 0.5f);
      glEnd();
//MIDDLE WINDOW
        //DOORS middle,RIGHT(4)
      ////translate
      glTranslatef(-0.390f,0.009f,0.0f);
      glBegin(GL_QUADS);
      glColor3ub(237, 151, 12);
      glVertex2f(0.730f,0.288f);
      glVertex2f(0.730f, 0.462f);
      glVertex2f(0.601f, 0.462f);
      glVertex2f(0.601f, 0.288f);
      glEnd();
      glBegin(GL_LINES);
//window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(0.724f,0.295f);
      glVertex2f(0.724f, 0.455f);
      glVertex2f(0.6062f, 0.455f);
      glVertex2f(0.6062f, 0.295f);
      glEnd();
      glBegin(GL_LINES);
//DOORS RIGHT,LEFT(1) lines
      glColor3ub(237, 151, 12);
      //horiontal
      glVertex2f(0.6062f,0.375f);
      glVertex2f(0.724f, 0.375f);
      //vertical
      glVertex2f(0.6656f,0.295f);
      glVertex2f(0.6656f, 0.455f);

      glEnd();
      glLoadIdentity();
        //DOORS middle,MIDDLE(4)
      ////translate
      glTranslatef(-0.665f,0.009f,0.0f);
      glBegin(GL_QUADS);
      glColor3ub(237, 151, 12);
      glVertex2f(0.730f,0.288f);
      glVertex2f(0.730f, 0.462f);
      glVertex2f(0.601f, 0.462f);
      glVertex2f(0.601f, 0.288f);
      glEnd();
      glBegin(GL_LINES);
//window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(0.724f,0.295f);
      glVertex2f(0.724f, 0.455f);
      glVertex2f(0.6062f, 0.455f);
      glVertex2f(0.6062f, 0.295f);
      glEnd();
      glBegin(GL_LINES);
//DOORS RIGHT,LEFT(1) lines
      glColor3ub(237, 151, 12);
      //horiontal
      glVertex2f(0.6062f,0.375f);
      glVertex2f(0.724f, 0.375f);
      //vertical
      glVertex2f(0.6656f,0.295f);
      glVertex2f(0.6656f, 0.455f);

      glEnd();
      glLoadIdentity();
      //DOORS middle,LEFT(4)
      ////translate
      glTranslatef(-0.935f,0.009f,0.0f);
      glBegin(GL_QUADS);
      glColor3ub(237, 151, 12);
      glVertex2f(0.730f,0.288f);
      glVertex2f(0.730f, 0.462f);
      glVertex2f(0.601f, 0.462f);
      glVertex2f(0.601f, 0.288f);
      glEnd();
      glBegin(GL_LINES);
//window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(0.724f,0.295f);
      glVertex2f(0.724f, 0.455f);
      glVertex2f(0.6062f, 0.455f);
      glVertex2f(0.6062f, 0.295f);
      glEnd();
      glBegin(GL_LINES);
//DOORS RIGHT,LEFT(1) lines
      glColor3ub(237, 151, 12);
      //horiontal
      glVertex2f(0.6062f,0.375f);
      glVertex2f(0.724f, 0.375f);
      //vertical
      glVertex2f(0.6656f,0.295f);
      glVertex2f(0.6656f, 0.455f);

      glEnd();
      glLoadIdentity();
      //DOORS middle,LEFT(5)
      ////translate
      glTranslatef(-0.935f,-0.225f,0.0f);
      glBegin(GL_QUADS);
      glColor3ub(237, 151, 12);
      glVertex2f(0.730f,0.288f);
      glVertex2f(0.730f, 0.462f);
      glVertex2f(0.601f, 0.462f);
      glVertex2f(0.601f, 0.288f);
      glEnd();
      glBegin(GL_LINES);
//window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(0.724f,0.295f);
      glVertex2f(0.724f, 0.455f);
      glVertex2f(0.6062f, 0.455f);
      glVertex2f(0.6062f, 0.295f);
      glEnd();
      glBegin(GL_LINES);
//DOORS RIGHT,LEFT(1) lines
      glColor3ub(237, 151, 12);
      //horiontal
      glVertex2f(0.6062f,0.375f);
      glVertex2f(0.724f, 0.375f);
      //vertical
      glVertex2f(0.6656f,0.295f);
      glVertex2f(0.6656f, 0.455f);

      glEnd();
      glLoadIdentity();
       //DOORS middle,MIDDLE(5)
      ////translate
      glTranslatef(-0.665f,-0.225f,0.0f);
      glBegin(GL_QUADS);
      glColor3ub(237, 151, 12);
      glVertex2f(0.730f,0.288f);
      glVertex2f(0.730f, 0.462f);
      glVertex2f(0.601f, 0.462f);
      glVertex2f(0.601f, 0.288f);
      glEnd();
      glBegin(GL_LINES);
//window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(0.724f,0.295f);
      glVertex2f(0.724f, 0.455f);
      glVertex2f(0.6062f, 0.455f);
      glVertex2f(0.6062f, 0.295f);
      glEnd();
      glBegin(GL_LINES);
//DOORS RIGHT,LEFT(1) lines
      glColor3ub(237, 151, 12);
      //horiontal
      glVertex2f(0.6062f,0.375f);
      glVertex2f(0.724f, 0.375f);
      //vertical
      glVertex2f(0.6656f,0.295f);
      glVertex2f(0.6656f, 0.455f);

      glEnd();
      glLoadIdentity();
        //DOORS middle,RIGHT(5)
      ////translate
      glTranslatef(-0.390f,-0.225f,0.0f);
      glBegin(GL_QUADS);
      glColor3ub(237, 151, 12);
      glVertex2f(0.730f,0.288f);
      glVertex2f(0.730f, 0.462f);
      glVertex2f(0.601f, 0.462f);
      glVertex2f(0.601f, 0.288f);
      glEnd();
      glBegin(GL_LINES);
//window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(0.724f,0.295f);
      glVertex2f(0.724f, 0.455f);
      glVertex2f(0.6062f, 0.455f);
      glVertex2f(0.6062f, 0.295f);
      glEnd();
      glBegin(GL_LINES);
//DOORS RIGHT,LEFT(1) lines
      glColor3ub(237, 151, 12);
      //horiontal
      glVertex2f(0.6062f,0.375f);
      glVertex2f(0.724f, 0.375f);
      //vertical
      glVertex2f(0.6656f,0.295f);
      glVertex2f(0.6656f, 0.455f);

      glEnd();
      glLoadIdentity();
//WINDOW MIDDLE ENDS.....................
//DOORS MIDDLE
  glBegin(GL_QUADS);
      glColor3ub(237, 151, 12);
      glVertex2f(0.110f,-0.199f);
      glVertex2f(0.110f, 0.020f);
      glVertex2f(-0.110f, 0.020f);
      glVertex2f(-0.110f,-0.199f);
      glEnd();
      glBegin(GL_LINES);
//window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(0.100f,-0.18f);
      glVertex2f(0.100f, 0.010f);
      glVertex2f(-0.100f, 0.010f);
      glVertex2f(-0.100f,-0.18f);
      glEnd();
      glBegin(GL_LINES);
//DOORS RIGHT,LEFT(1) lines
      glColor3ub(237, 151, 12);
      glVertex2f(0.0f,0.020f);
      glVertex2f(0.0f,- 0.199f);

      glEnd();
      //DOORS MIDDLE,LEFt
      glTranslatef(-0.270f,0.0f,0.0f);
      glScalef(0.8f,1.0f,0.0f);
  glBegin(GL_QUADS);
      glColor3ub(237, 151, 12);
      glVertex2f(0.110f,-0.199f);
      glVertex2f(0.110f, 0.020f);
      glVertex2f(-0.110f, 0.020f);
      glVertex2f(-0.110f,-0.199f);
      glEnd();
      glBegin(GL_LINES);
//window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(0.100f,-0.18f);
      glVertex2f(0.100f, 0.010f);
      glVertex2f(-0.100f, 0.010f);
      glVertex2f(-0.100f,-0.18f);
      glEnd();
      glBegin(GL_LINES);
//DOORS RIGHT,LEFT(1) lines
      glColor3ub(237, 151, 12);
      //horiontal
      glVertex2f(-0.100f,-0.0895f);
      glVertex2f(0.100f, -0.0895f);
      //vertical
      glVertex2f(-0.04f,0.020f);
      glVertex2f(-0.04f,- 0.199f);

      glVertex2f(0.04f,0.020f);
      glVertex2f(0.04f,- 0.199f);
      glEnd();
      glLoadIdentity();

      //
       //DOORS MIDDLE,RIGHT
      glTranslatef(0.270f,0.0f,0.0f);
      glScalef(0.8f,1.0f,0.0f);


  glBegin(GL_QUADS);
      glColor3ub(237, 151, 12);
      glVertex2f(0.110f,-0.199f);
      glVertex2f(0.110f, 0.020f);
      glVertex2f(-0.110f, 0.020f);
      glVertex2f(-0.110f,-0.199f);
      glEnd();
      glBegin(GL_LINES);
//window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(0.100f,-0.18f);
      glVertex2f(0.100f, 0.010f);
      glVertex2f(-0.100f, 0.010f);
      glVertex2f(-0.100f,-0.18f);
      glEnd();
      glBegin(GL_LINES);
//DOORS RIGHT,LEFT(1) lines
      glColor3ub(237, 151, 12);
      //horiontal
      glVertex2f(-0.100f,-0.0895f);
      glVertex2f(0.100f, -0.0895f);
      //vertical
      glVertex2f(-0.04f,0.020f);
      glVertex2f(-0.04f,- 0.199f);

      glVertex2f(0.04f,0.020f);
      glVertex2f(0.04f,- 0.199f);
      glEnd();
      glLoadIdentity();
//doors ends....................................

      //middle
//lines
    glBegin(GL_LINES);
      //glColor3ub(255, 228, 181);
      glColor3ub(238, 196, 113);
      //vertical
      glVertex2f(0.41f, 0.5f);
      glVertex2f(0.41f, -0.2f);

      glVertex2f(-0.41f, 0.5f);
      glVertex2f(-0.41f, -0.2f);
//baseline
      glVertex2f(-1.0f, -0.2f);
      glVertex2f(1.0f, -0.2f);
//vertical
      glVertex2f(0.132f, 0.5f);
      glVertex2f(0.132f, -0.2f);

      glVertex2f(-0.132f, 0.5f);
      glVertex2f(-0.132f, -0.2f);

//horizontal lines
      glVertex2f(0.41f, 0.267f);
      glVertex2f(-0.41f, 0.267f);

      glVertex2f(0.41f, 0.034f);
      glVertex2f(-0.41f, 0.034f);
//right side lines

    //horizontal lines
      glVertex2f(0.55f, 0.267f);
      glVertex2f(1.0f, 0.267f);

      glVertex2f(0.55f, 0.034f);
      glVertex2f(1.0f, 0.034f);

      glVertex2f(-0.55f, 0.267f);
      glVertex2f(-1.0f, 0.267f);

      glVertex2f(-0.55f, 0.034f);
      glVertex2f(-1.0f, 0.034f);
      glEnd();
      //shading in background of empty space left and right in between
/*      glBegin(GL_LINES);
      glColor3ub(240, 178, 122);
      //right
 //     glVertex2f(0.43f, 0.47f);
 //     glVertex2f(0.43f, -0.197f);
      //left
  //    glVertex2f(-0.43f, 0.47f);
    //  glVertex2f(-0.43f, -0.197f);

      glEnd();
*/
      glTranslatef(0.7f,0.2f,0.0f);
    //window RIGHT,LEFT(1) outer border
       glBegin(GL_QUADS);
      glColor3ub(237, 151, 12);
      glVertex2f(0.730f,0.288f);
      glVertex2f(0.730f, 0.462f);
      glVertex2f(0.601f, 0.462f);
      glVertex2f(0.601f, 0.288f);
      glEnd();
      glBegin(GL_LINES);
//window RIGHT,LEFT(1)
   glBegin(GL_QUADS);
      glColor3ub(212, 239, 223);
      glVertex2f(0.724f,0.295f);
      glVertex2f(0.724f, 0.455f);
      glVertex2f(0.6062f, 0.455f);
      glVertex2f(0.6062f, 0.295f);
      glEnd();
      glBegin(GL_LINES);
//DOORS RIGHT,LEFT(1) lines
      glColor3ub(237, 151, 12);
      //horiontal
      glVertex2f(0.6062f,0.375f);
      glVertex2f(0.724f, 0.375f);
      //vertical
      glVertex2f(0.6656f,0.295f);
      glVertex2f(0.6656f, 0.455f);
      glEnd();
      glLoadIdentity();

      //glEnd();



      //glLoadIdentity();

glPopMatrix();

      //glFlush();



}

///resort_done
void resortDisplay()
{
    glLoadIdentity();

     //marine_drive();
     //marine_drive_extra();
     //sea_beach();
     //draw_background();
     resort();
     sea_beach_umbrella();
     float translate_umbrella= 0.37f;
     for(int i=0; i<4; i++)
     {
         glTranslatef(translate_umbrella,0.0,0.0);
         sea_beach_umbrella();
         glLoadIdentity();
         translate_umbrella+=0.37f;
     }
     sea_beach_chair();
     float translate_chair= 0.37f;
     for(int i=0; i<4; i++)
     {
         glTranslatef(translate_chair,0.0,0.0);
         sea_beach_chair();
         glLoadIdentity();
         translate_chair+=0.37f;
     }
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //glLoadIdentity();

     //marine_drive();
    // marine_drive_extra();
     //sea_beach();
     //resort();
    // sea();

    if (timeChange>0)
    {
        //soundPlayer();
         glLoadIdentity();
        glPushMatrix();
        marine_drive_extra();
        glPopMatrix();
      // return;

    }
    if (timeChange>60)
    {
        glLoadIdentity();
        glPushMatrix();
        marine_drive();
         glPopMatrix();

         glLineWidth(2.0);
         glPushMatrix();
    glTranslatef(-0.9,position1, 0.0f);
    rain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8,position1, 0.0f);
    rain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.7,position1, 0.0f);
    rain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.6,position1, 0.0f);
    rain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5,position1, 0.0f);
    rain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4,position1, 0.0f);
    rain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3,position1, 0.0f);
    rain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.2,position1, 0.0f);
    rain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.1,position1, 0.0f);
    rain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,position1, 0.0f);
    rain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.9,position1, 0.0f);
    rain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8,position1, 0.0f);
    rain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.7,position1, 0.0f);
    rain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6,position1, 0.0f);
    rain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5,position1, 0.0f);
    rain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,position1, 0.0f);
    rain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3,position1, 0.0f);
    rain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2,position1, 0.0f);
    rain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.1,position1, 0.0f);
    rain();
    glPopMatrix();
    //return;


    }

    if (timeChange>120)
    {
         glLoadIdentity();
         glPushMatrix();
        sea();
         glPopMatrix();

    }

    if (timeChange>180)
    {
         glLoadIdentity();
         glPushMatrix();
        //sea_beach();
         resortDisplay();
         glPopMatrix();

    }





     if (timeChange>240)
     {
         timeChange=0;
     }

    timeChange++;

    cout<<timeChange<<endl;
    glFlush();
}


int main(int argc, char** argv) {

    soundPlayer();

   glutInit(&argc, argv);

   glutInitWindowSize(1600, 900);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Sea Beach");

   glutDisplayFunc(display);
    //timeChange=150;
   //glutDisplayFunc(display);
   init();
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutTimerFunc(100, update, 0);
   //sndPlaySound("ocean.wav", SND_ASYNC);
   glutMainLoop();
   return 0;
}
