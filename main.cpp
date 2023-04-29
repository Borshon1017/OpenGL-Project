#include<windows.h>
#include<GL\glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#define PI 3.1416

///==================================================///
///              ///
///==================================================///

GLint i, j, k;
GLfloat sun_spin=0, sun_x=0, sun_y=0;
GLfloat ax=0,bx=0,cx=0,dx=0,str=500.0,mn=500.0;
GLfloat sr=0.0,sg=0.749,sb=1.0;
GLfloat spin = 0.0;
GLfloat position = 0.0f;
GLfloat speed = 0.1f;
bool isMoving = false;




void init(void)
{
	glClearColor(.40, .110, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000.0, 0.0, 500.0);

}
void handleKeypress(unsigned char key, int x, int y) {
    switch(key) {
        case 27: // Escape key
            exit(0);
            break;
        case ' ': // Spacebar
            // Do something
            break;
        case 13: // Enter key
            // Do something
            break;
        case 37: // Left arrow key

            position -= 0.1f;

            break;
        case 39: // Right arrow key
            position += 0.1f;
            break;
    }
}





void update(int value)
{
    if (isMoving)
    {
        if (position < -4.0f)
        {
            position = 2.0f;
            isMoving = false;
        }
        else
        {
            position -= speed;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(100, update, 0);
}


void Train()
{
glLoadIdentity();




glPushMatrix();
glTranslatef(2,0.4,0);
glTranslatef(position , 0.0f, 1.0f);
    glBegin(GL_QUADS); //line
      glColor3f(0.45f, 1.0f, 0.5f);
      glVertex2f(-0.8f, 0.0f);
      glVertex2f( 0.8f, -0.0f);
      glVertex2f( 0.8f, 0.009f);
      glVertex2f(-0.8f, 0.009f);
   glEnd();
     glBegin(GL_TRIANGLES); //Head
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.8f,0.009f);
      glVertex2f(-0.6f,0.1f);
      glVertex2f(-0.6f,0.009f);
   glEnd();
   glBegin(GL_QUADS); //1 White sq
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.6f,0.009f);
      glVertex2f(-0.6f,0.1f);
      glVertex2f(-0.4f,0.1);
      glVertex2f(-0.4f,0.009f);

   glEnd();
      glBegin(GL_QUADS); //gap1
      glColor3f(0.0f, 0.42f, 0.50f);
      glVertex2f(-0.4f,0.009f);
      glVertex2f(-0.39f,0.009f);
      glVertex2f(-0.39f,0.09);
      glVertex2f(-0.4f,0.09f);

   glEnd();
 glBegin(GL_QUADS); //2 White sq
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.39f,0.009f);
      glVertex2f(-0.39f,0.1f);
      glVertex2f(-0.01f,0.1);
      glVertex2f(-0.01f,0.009f);

   glEnd();
   glBegin(GL_QUADS); //gap2
      glColor3f(0.0f, 0.42f, 0.50f);
      glVertex2f(-0.01f,0.009f);
      glVertex2f(0.0f,0.009f);
      glVertex2f(0.0f,0.09);
      glVertex2f(-0.01f,0.09f);

   glEnd();
    glBegin(GL_QUADS); //white sq 3
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.0f, 0.009);
      glVertex2f( 0.4f, 0.009f);
      glVertex2f( 0.4f, 0.1f);
      glVertex2f(0.0f, 0.1);
   glEnd();
 glBegin(GL_QUADS); //gap3
      glColor3f(0.0f, 0.42f, 0.50f);
      glVertex2f(0.4f, 0.009);
      glVertex2f( 0.41f, 0.009f);
      glVertex2f( 0.41f, 0.09f);
      glVertex2f(0.4f, 0.09);

   glEnd();
glBegin(GL_QUADS); //white sq 3
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.41f, 0.009);
      glVertex2f( 0.8f, 0.009f);
      glVertex2f( 0.8f, 0.1f);
      glVertex2f(0.41f, 0.1);
   glEnd();
   glBegin(GL_QUADS); //glass 1
      glColor3f(0.70f, 0.90f, 1.0f);
      glVertex2f(-0.055f,0.02f);
      glVertex2f(-0.055f,0.09f);
      glColor3f(0.25f, 0.77f, 1.0f);
      glVertex2f(-0.3f,0.09);
      glVertex2f(-0.3f,0.02f);
      glEnd();

      glBegin(GL_QUADS); //glass 2
      glColor3f(0.70f, 0.90f, 1.0f);
      glVertex2f(0.345f,0.02f);
      glVertex2f(0.345f,0.09f);
      glColor3f(0.25f, 0.77f, 1.0f);
      glVertex2f(0.1f,0.09);
      glVertex2f(0.1f,0.02f);
      glEnd();
 glBegin(GL_QUADS); //glass 3
      glColor3f(0.70f, 0.90f, 1.0f);
      glVertex2f(0.745f,0.02f);
      glVertex2f(0.745f,0.09f);
      glColor3f(0.25f, 0.77f, 1.0f);
      glVertex2f(0.5f,0.09);
      glVertex2f(0.5f,0.02f);
      glEnd();


       glBegin(GL_QUADS); //door1
     glColor3f(0.0f, 0.0f, 0.0f);
      glVertex2f(-0.5f,0.02f);
      glVertex2f(-0.5f,0.09f);
      glColor3f(0.20f, 0.20f, 0.20f);
      glVertex2f(-0.56f,0.09);
      glVertex2f(-0.56f,0.02f);
      glEnd();



glPopMatrix();



   glFlush();
}











///============================================================================================================///

///=================///
///*** All_Model ***///
///=================///



///*** Circle_Model***///
void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}

/// *** Sun_Model **///
void Sun_Model(){
    glPushMatrix();
    glTranslatef(500,0,0);
    circle(30);
    glPopMatrix();

}
void Moving_Sun_Model(){
    glPushMatrix();
    glRotatef(-sun_spin, 0,0,-.009);
    Sun_Model();
    glPopMatrix();

}
///*** Cloud_Model***///
void cloud_model_one(){

    glColor3f(1.25, 0.924, 0.930);

    ///Top_Left

    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Top

    glPushMatrix();
    glTranslatef(340, 225, 0);
    circle(16);
    glPopMatrix();

    ///Right

    glPushMatrix();
    glTranslatef(360,210,0);
    circle(16);
    glPopMatrix();


    ///middle_Fill
    glPushMatrix();
    glTranslatef(355,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(350,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(345,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(335,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(330,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(325,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(315,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(310,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(305,204,0);
    circle(10);
    glPopMatrix();

    ///****Fill End****

}

void cloud_model_Two(){
    glColor3f(1.25, 0.924, 0.930);

    ///Left_Part
    glPushMatrix();
    glTranslatef(305,205,0);
    circle(10);
    glPopMatrix();

    ///Top

    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(334,207,0);
    circle(10);
    glPopMatrix();

    ///Bottom_Part
    glPushMatrix();
    glTranslatef(320,207,0);
    circle(10);
    glPopMatrix();



}

void cloud_model_Three(){
    glColor3f(1.25, 0.924, 0.930);

    ///Left_Part
    glPushMatrix();
    glTranslatef(300,200,0);
    circle(15);
    glPopMatrix();

    ///Top_Left

    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Top
    glPushMatrix();
    glTranslatef(340,220,0);
    circle(16);
    glPopMatrix();

    ///Top_Right
    glPushMatrix();
    glTranslatef(360,210,0);
    circle(15);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(380,200,0);
    circle(15);
    glPopMatrix();

    ///Bottom_Right
    glPushMatrix();
    glTranslatef(360,190,0);
    circle(20);
    glPopMatrix();

    ///Bottom_Left
    glPushMatrix();
    glTranslatef(320,190,0);
    circle(20);
    glPopMatrix();

    ///Bottom
    glPushMatrix();
    glTranslatef(340,190,0);
    circle(20);
    glPopMatrix();




    ///****Fill End****

}
///*** Hill_Model***///
void hill_big(){

    ///Hill
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(70, 70);
	glVertex2i(200, 225);
	glVertex2i(330, 70);

	glEnd();

	///Hill_Snow
    glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);

	glVertex2i(200, 225);
	glVertex2i(230, 190);
	glVertex2i(220, 180);
	glVertex2i(200, 190);
	glVertex2i(190, 180);
	glVertex2i(170, 190);

	glEnd();

}
void hill_small(){
    ///Hill_Small
	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(250, 100);
	glVertex2i(310, 175);
	glVertex2i(370, 100);

	glEnd();

    ///Hill_Small_Snow
	glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);
    glVertex2i(290, 150);
	glVertex2i(310, 175);
	glVertex2i(330, 150);
	glVertex2i(325, 140);
	glVertex2i(310, 150);
	glVertex2i(300, 140);


	glEnd();
}
///*** Tilla_Model ***///
void Tilla_One_Model(){
    ///Tilla
	glBegin(GL_POLYGON);
	glColor3f(0.1, 1.293, 0.0);
	glVertex2i(125, 70);
	glVertex2i(150, 80);
	glVertex2i(160, 90);
	glVertex2i(170, 90);
	glVertex2i(180, 100);
	glVertex2i(190, 105);
	glVertex2i(200, 108);
	glVertex2i(300, 110);
	glVertex2i(300, 70);

	glEnd();

}

void Tilla_Two_Model(){

	glColor3f(0.1, 1.293, 0.0);
    /// Left_Part
    glPushMatrix();
    glTranslatef(430,90,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(420,87,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(410,80,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(400,80,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(390,70,0);
    circle(30);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(445,80,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(455,75,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(465,70,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(470,65,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(480,60,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(485,55,0);
    circle(20);
    glPopMatrix();



}
///*** House_Model ***///
void house(){
    ///House_Roof
	glBegin(GL_POLYGON);
    glColor3f(.990, 0.0, 0.0);
	glVertex2i(285, 105);
	glVertex2i(285, 130);
	glVertex2i(380, 115);
	glVertex2i(380, 105);

	glEnd();

    ///House_Roof_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.890, 0.0, 0.0);
	glVertex2i(285, 105);
	glVertex2i(285, 120);
	glVertex2i(380, 105);
	glVertex2i(380, 105);

	glEnd();

    ///House_Fence
	glBegin(GL_POLYGON);
    glColor3f(.555, 1.0, 1.0);
	glVertex2i(290, 70);
	glVertex2i(290, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);

	glEnd();

    ///House_Fence_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.555, 0.924, 0.930);
	glVertex2i(310, 70);
	glVertex2i(350, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);

	glEnd();

    ///House_Door
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(330, 70);
	glVertex2i(330, 100);
	glVertex2i(350, 100);
	glVertex2i(350, 70);

	glEnd();

    ///House_Window1
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(295, 75);
	glVertex2i(295, 90);
	glVertex2i(310, 90);
	glVertex2i(310, 75);

	glEnd();

    ///House_Window2
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(312, 75);
	glVertex2i(312, 90);
	glVertex2i(327, 90);
	glVertex2i(327, 75);

	glEnd();

    ///House_Window3
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(355, 75);
	glVertex2i(355, 90);
	glVertex2i(370, 90);
	glVertex2i(370, 75);

	glEnd();

    ///House_Small_Roof
	glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
	glVertex2i(250, 90);
	glVertex2i(257, 104);
	glVertex2i(290, 104);
	glVertex2i(290, 90);

	glEnd();

    ///House_Small_Fence
	glBegin(GL_POLYGON);
    glColor3f(.555, .724, .930);
	glVertex2i(255, 70);
	glVertex2i(255, 90);
	glVertex2i(290, 90);
	glVertex2i(290, 70);

	glEnd();

    ///House_Small_Door
	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(260, 70);
	glVertex2i(260, 80);
	glVertex2i(285, 80);
	glVertex2i(285, 70);

	glEnd();


}
///*** Field_Model ***///
void field(){
    ///Field
	glBegin(GL_POLYGON);
    glColor3f(0.533, 1.293, 0.0);
	glVertex2i(0, 50);
	glVertex2i(0, 70);
	glVertex2i(1000, 70);
	glVertex2i(1000, 50);

	glEnd();


    ///Field_Shadow
	glBegin(GL_POLYGON);
	glColor3f(0.1, 1.293, 0.0);
	glVertex2i(0, 0);
	glVertex2i(0, 50);
	glVertex2i(1000, 50);
	glVertex2i(1000, 0);

	glEnd();


}
///*** Tree_Model ***///
void Tree_Model_One(){


    glPushMatrix();
    glTranslatef(110,110,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(110,100,0);
    circle(15);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(109, 70);
	glVertex2f(109, 90);
	glVertex2f(111, 90);
	glVertex2f(111, 70);

    glEnd();

}
void Tree_Model_Two(){

    glPushMatrix();
    glTranslatef(130,130,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(125,126,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(135,126,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130,125,0);
    circle(5);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(129, 110);
	glVertex2f(129, 124);
	glVertex2f(131, 124);
	glVertex2f(131, 110);

    glEnd();
}

void Tree_Model_Three(){


    glBegin(GL_POLYGON);

	glVertex2f(125, 123);
	glVertex2f(133, 145);
	glVertex2f(141, 123);

	glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(132, 110);
	glVertex2f(132, 124);
	glVertex2f(134, 124);
	glVertex2f(134, 110);

    glEnd();
}

/// *** Windmill_Stand_Model ***///
void Windmill_Stand_Model(){

    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);
    glVertex2i(375, 100);
    glVertex2i(380, 240);
    glVertex2i(384, 240);
    glVertex2i(390, 100);
    glEnd();
}

///*** Windmill_Blades_Model ***///

void Windmill_Blade(){

    ///Blade_One
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    ///Blade_Two
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    ///Blade_Three
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();

}
///*** Windmill_Final_Model ***///
void Windmill(){



        ///Windmill_Stand
    glColor3f(0.38, 0.41, 0.36);
    glPushMatrix();
    Windmill_Stand_Model();
    glPopMatrix();

    ///Windmill_MotorCloud
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(380,250,0);
    circle(10);
    glPopMatrix();

    ///Windmill_Rotary_Blades
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(380,251,0);
    Windmill_Blade();
    glPopMatrix();




}


///Model_End
///=======================================================================================================///


///=================///
///***   Object  ***///
///=================///

///*** Sun ***///
void Sun(){
    glColor3f(1, 1, 0);
    glPushMatrix();
    Moving_Sun_Model();
    glPopMatrix();
}
///*** Cloud_One_Model_One ***///
void cloud_one(){
    glPushMatrix();
    glTranslatef(cx,-40,0);
    cloud_model_one();
    glPopMatrix();

}

///*** Cloud_Two_Model_one ***///

void cloud_two(){
    glPushMatrix();
    glTranslatef(bx+100,150,0);
    cloud_model_one();
    glPopMatrix();

}

///*** Cloud_Three_Model_Two ***///

void cloud_three(){
    glPushMatrix();
    glTranslatef(ax-80,80,0);
    cloud_model_Two();
    glPopMatrix();

}
///*** Cloud_Four_Model_Two ***///

void cloud_four(){
    glPushMatrix();
    glTranslatef(dx+300,125,0);
    cloud_model_Two();
    glPopMatrix();

}
///*** Cloud_Five_Model_Three ***///
void cloud_five(){

    glPushMatrix();
    glTranslatef(ax+-300,170,0);
    cloud_model_Three();
    glPopMatrix();
}
///*** Cloud_Six_Model_Three ***///
void cloud_six(){

    glPushMatrix();
    glTranslatef(cx+-500,20,0);
    cloud_model_Three();
    glPopMatrix();
}


///*** Hill_big_One ***///
void Hill_Big_One(){
    glPushMatrix();
    glTranslatef(0,0,0);
    hill_big();
    glPopMatrix();
}
///*** Hill_big_Two ***///
void Hill_Big_Two(){
    glPushMatrix();
    glTranslatef(550,-20,0);
    hill_big();
    glPopMatrix();
}
///*** Hill_Small_One ***///
void Hill_Small_One(){
    glPushMatrix();
    glTranslatef(0,0,0);
    hill_small();
    glPopMatrix();

}
/// *** Tilla_One_Model_One ***///

void Tilla_One(){

    glPushMatrix();
    glTranslatef(0,0,0);
    Tilla_One_Model();
    glPopMatrix();

}
/// *** Tilla_Two_Model_Two ***///
void Tilla_Two(){

    glPushMatrix();
    glTranslatef(0,0,0);
    Tilla_Two_Model();
    glPopMatrix();


}
/// *** Tilla_Three_Model_Two ***///
void Tilla_Three(){

    glPushMatrix();
    glTranslatef(400,0,0);
    Tilla_Two_Model();
    glPopMatrix();


}
/// *** Tilla_Four_Model_One ***///
void Tilla_Four(){

    glColor3f(0.833, 1., 0.0);
    glPushMatrix();
    glTranslatef(380,0,0);
    Tilla_One_Model();
    glPopMatrix();


}
///*** Tree_1 ***///
void Tree_One(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(0,0,0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_2 ***///
void Tree_Two(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(540,0,0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_3 ***///
void Tree_Three(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(750,0,0);
    Tree_Model_One();
    glPopMatrix();
}
///*** Tree_4 ***///
void Tree_Four(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(292,40,0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_5 ***///
void Tree_Five(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(30,-20,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_6 ***///
void Tree_Six(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(50,-10,0);
    Tree_Model_Two();
    glPopMatrix();
}
///*** Tree_7 ***///
void Tree_Seven(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(322,0,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_8 ***///
void Tree_Eight(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(350,-15,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_9 ***///
void Tree_Nine(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(760,-25,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_10 ***///
void Tree_Ten(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(90,-2,0);
    Tree_Model_Three();
    glPopMatrix();
}

///*** Tree_11 ***///
void Tree_Eleven(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(125,0,0);
    Tree_Model_Three();
    glPopMatrix();
}

///*** Tree_12 ***///
void Tree_Twelve(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(408,-22,0);
    Tree_Model_Three();
    glPopMatrix();
}

/// *** Windmill ***///
void Windmill_One(){
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(0,-10,0);
    Windmill();
    glPopMatrix();

}

void Windmill_Two(){
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(508,-70,0);
    Windmill();
    glPopMatrix();

}
void Windmill_Three(){
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(108,-90,0);
    Windmill();
    glPopMatrix();

}
Bridge()
{


glBegin(GL_QUADS);
//--------------Bridge---------------

// -------------------1st piler start------------------------

glColor3ub(255, 198, 130);
glVertex2i(150, 0);
glVertex2i(200, 0);
glColor3ub(226, 135, 79);
glVertex2i(200, 280);
glVertex2i(150, 280);

glColor3ub(173, 80, 10);
glVertex2i(150, 0);
glVertex2i(160, 0);
glColor3ub(226, 135, 79);
glVertex2i(160, 280);
glVertex2i(150, 280);

glColor3ub(226, 135, 79);
glVertex2i(150, 280);
glVertex2i(200, 280);
glVertex2i(220, 295);
glVertex2i(130, 295);

glColor3ub(96, 36, 10);
glVertex2i(127, 310);
glVertex2i(223, 310);
glVertex2i(223, 335);
glVertex2i(127, 335);

glColor3ub(226, 135, 79);
glVertex2i(130, 295);
glVertex2i(220, 295);
glVertex2i(220, 335);
glVertex2i(130, 335);

glColor3ub(162, 81, 18);
glVertex2i(140, 315);
glVertex2i(210, 315);
glVertex2i(210, 330);
glVertex2i(140, 330);

glColor3ub(110, 45, 14);
glVertex2i(140, 315);
glVertex2i(210, 315);
glVertex2i(210, 320);
glVertex2i(140, 320);

glColor3ub(96, 36, 10);
glVertex2i(155, 302);
glVertex2i(195, 302);
glVertex2i(195, 310);
glVertex2i(155, 310);

glColor3ub(192, 64, 15);
glVertex2i(150, 280);
glVertex2i(155, 280);
glVertex2i(155, 315);
glVertex2i(150, 315);

glVertex2i(195, 280);
glVertex2i(200, 280);
glVertex2i(200, 315);
glVertex2i(195, 315);

glVertex2i(155, 310);
glVertex2i(195, 310);
glVertex2i(195, 315);
glVertex2i(155, 315);


// -------------------1st piler end------------------------


// -------------------2nd piler start------------------------

glColor3ub(255, 198, 130);
glVertex2i(450, 0);
glVertex2i(500, 0);
glColor3ub(226, 135, 79);
glVertex2i(500, 280);
glVertex2i(450, 280);

glColor3ub(173, 80, 10);
glVertex2i(450, 0);
glVertex2i(460, 0);
glColor3ub(226, 135, 79);
glVertex2i(460, 280);
glVertex2i(450, 280);

glColor3ub(226, 135, 79);
glVertex2i(450, 280);
glVertex2i(500, 280);
glVertex2i(520, 295);
glVertex2i(430, 295);

glColor3ub(96, 36, 10);
glVertex2i(427, 310);
glVertex2i(523, 310);
glVertex2i(523, 335);
glVertex2i(427, 335);

glColor3ub(226, 135, 79);
glVertex2i(430, 295);
glVertex2i(520, 295);
glVertex2i(520, 335);
glVertex2i(430, 335);

glColor3ub(162, 81, 18);
glVertex2i(440, 315);
glVertex2i(510, 315);
glVertex2i(510, 330);
glVertex2i(440, 330);

glColor3ub(110, 45, 14);
glVertex2i(440, 315);
glVertex2i(510, 315);
glVertex2i(510, 320);
glVertex2i(440, 320);

glColor3ub(96, 36, 10);
glVertex2i(455, 302);
glVertex2i(495, 302);
glVertex2i(495, 310);
glVertex2i(455, 310);

glColor3ub(192, 64, 15);
glVertex2i(450, 280);
glVertex2i(455, 280);
glVertex2i(455, 315);
glVertex2i(450, 315);

glVertex2i(495, 280);
glVertex2i(500, 280);
glVertex2i(500, 315);
glVertex2i(495, 315);

glVertex2i(455, 310);
glVertex2i(495, 310);
glVertex2i(495, 315);
glVertex2i(455, 315);


// -------------------2nd piler end------------------------

// -------------------3rd piler start------------------------

glColor3ub(255, 198, 130);
glVertex2i(750, 0);
glVertex2i(800, 0);
glColor3ub(226, 135, 79);
glVertex2i(800, 280);
glVertex2i(750, 280);

glColor3ub(173, 80, 10);
glVertex2i(750, 0);
glVertex2i(760, 0);
glColor3ub(226, 135, 79);
glVertex2i(760, 280);
glVertex2i(750, 280);

glColor3ub(226, 135, 79);
glVertex2i(750, 280);
glVertex2i(800, 280);
glVertex2i(820, 295);
glVertex2i(730, 295);

glColor3ub(96, 36, 10);
glVertex2i(727, 310);
glVertex2i(823, 310);
glVertex2i(823, 335);
glVertex2i(727, 335);

glColor3ub(226, 135, 79);
glVertex2i(730, 295);
glVertex2i(820, 295);
glVertex2i(820, 335);
glVertex2i(730, 335);

glColor3ub(162, 81, 18);
glVertex2i(740, 315);
glVertex2i(810, 315);
glVertex2i(810, 330);
glVertex2i(740, 330);

glColor3ub(110, 45, 14);
glVertex2i(740, 315);
glVertex2i(810, 315);
glVertex2i(810, 320);
glVertex2i(740, 320);

glColor3ub(96, 36, 10);
glVertex2i(755, 302);
glVertex2i(795, 302);
glVertex2i(795, 310);
glVertex2i(755, 310);

glColor3ub(192, 64, 15);
glVertex2i(750, 280);
glVertex2i(755, 280);
glVertex2i(755, 315);
glVertex2i(750, 315);

glVertex2i(795, 280);
glVertex2i(800, 280);
glVertex2i(800, 315);
glVertex2i(795, 315);

glVertex2i(755, 310);
glVertex2i(795, 310);
glVertex2i(795, 315);
glVertex2i(755, 315);


// -------------------3rd piler end------------------------

// -------------------4th piler start------------------------

glColor3ub(255, 198, 130);
glVertex2i(1050, 0);
glVertex2i(1100, 0);
glColor3ub(226, 135, 79);
glVertex2i(1100, 280);
glVertex2i(1050, 280);

glColor3ub(173, 80, 10);
glVertex2i(1050, 0);
glVertex2i(1060, 0);
glColor3ub(226, 135, 79);
glVertex2i(1060, 280);
glVertex2i(1050, 280);

glColor3ub(226, 135, 79);
glVertex2i(1050, 280);
glVertex2i(1100, 280);
glVertex2i(1120, 295);
glVertex2i(1030, 295);

glColor3ub(96, 36, 10);
glVertex2i(1027, 310);
glVertex2i(1123, 310);
glVertex2i(1123, 335);
glVertex2i(1027, 335);

glColor3ub(226, 135, 79);
glVertex2i(1030, 295);
glVertex2i(1120, 295);
glVertex2i(1120, 335);
glVertex2i(1030, 335);

glColor3ub(162, 81, 18);
glVertex2i(1040, 315);
glVertex2i(1110, 315);
glVertex2i(1110, 330);
glVertex2i(1040, 330);

glColor3ub(110, 45, 14);
glVertex2i(1040, 315);
glVertex2i(1110, 315);
glVertex2i(1110, 320);
glVertex2i(1040, 320);

glColor3ub(96, 36, 10);
glVertex2i(1055, 302);
glVertex2i(1095, 302);
glVertex2i(1095, 310);
glVertex2i(1055, 310);

glColor3ub(192, 64, 15);
glVertex2i(1050, 280);
glVertex2i(1055, 280);
glVertex2i(1055, 315);
glVertex2i(1050, 315);

glVertex2i(1095, 280);
glVertex2i(1100, 280);
glVertex2i(1100, 315);
glVertex2i(1095, 315);

glVertex2i(1055, 310);
glVertex2i(1095, 310);
glVertex2i(1095, 315);
glVertex2i(1055, 315);

// -------------------4th piler end------------------------

//--------------------bridge body--------------------------

glColor3ub(221, 133, 70);
glVertex2i(0, 335);
glVertex2i(1240, 335);
glVertex2i(1240, 360);
glVertex2i(0, 360);

glColor3ub(173, 80, 10);
glVertex2i(0, 335);
glVertex2i(1240, 335);
glVertex2i(1240, 338);
glVertex2i(0, 338);

glColor3ub(173, 80, 10);
glVertex2i(0, 356);
glVertex2i(1240, 356);
glVertex2i(1240, 360);
glVertex2i(0, 360);

glColor3ub(96, 36, 10);
glVertex2i(0, 380);
glVertex2i(1240, 380);
glVertex2i(1240, 382);
glVertex2i(0, 382);

//------------------grill----------------------

glColor3ub(96, 36, 10);
glVertex2i(7, 360);
glVertex2i(9, 360);
glVertex2i(9, 380);
glVertex2i(7, 380);

glVertex2i(19, 360);
glVertex2i(21, 360);
glVertex2i(21, 380);
glVertex2i(19, 380);

glVertex2i(31, 360);
glVertex2i(33, 360);
glVertex2i(33, 380);
glVertex2i(31, 380);

glVertex2i(43, 360);
glVertex2i(45, 360);
glVertex2i(45, 380);
glVertex2i(43, 380);

glVertex2i(55, 360);
glVertex2i(57, 360);
glVertex2i(57, 380);
glVertex2i(55, 380);

glVertex2i(67, 360);
glVertex2i(69, 360);
glVertex2i(69, 380);
glVertex2i(67, 380);

glVertex2i(79, 360);
glVertex2i(81, 360);
glVertex2i(81, 380);
glVertex2i(79, 380);

glVertex2i(91, 360);
glVertex2i(93, 360);
glVertex2i(93, 380);
glVertex2i(91, 380);

glVertex2i(103, 360);
glVertex2i(105, 360);
glVertex2i(105, 380);
glVertex2i(103, 380);

glVertex2i(115, 360);
glVertex2i(117, 360);
glVertex2i(117, 380);
glVertex2i(115, 380);

glVertex2i(127, 360);
glVertex2i(129, 360);
glVertex2i(129, 380);
glVertex2i(127, 380);

glVertex2i(139, 360);
glVertex2i(141, 360);
glVertex2i(141, 380);
glVertex2i(139, 380);

glVertex2i(151, 360);
glVertex2i(153, 360);
glVertex2i(153, 380);
glVertex2i(151, 380);

glVertex2i(163, 360);
glVertex2i(165, 360);
glVertex2i(165, 380);
glVertex2i(163, 380);

glVertex2i(175, 360);
glVertex2i(177, 360);
glVertex2i(177, 380);
glVertex2i(175, 380);

glVertex2i(187, 360);
glVertex2i(189, 360);
glVertex2i(189, 380);
glVertex2i(187, 380);

glVertex2i(199, 360);
glVertex2i(201, 360);
glVertex2i(201, 380);
glVertex2i(199, 380);

glVertex2i(211, 360);
glVertex2i(213, 360);
glVertex2i(213, 380);
glVertex2i(211, 380);

glVertex2i(223, 360);
glVertex2i(225, 360);
glVertex2i(225, 380);
glVertex2i(223, 380);

glVertex2i(235, 360);
glVertex2i(237, 360);
glVertex2i(237, 380);
glVertex2i(235, 380);

glVertex2i(247, 360);
glVertex2i(249, 360);
glVertex2i(249, 380);
glVertex2i(247, 380);

glVertex2i(259, 360);
glVertex2i(261, 360);
glVertex2i(261, 380);
glVertex2i(259, 380);

glVertex2i(271, 360);
glVertex2i(273, 360);
glVertex2i(273, 380);
glVertex2i(271, 380);

glVertex2i(283, 360);
glVertex2i(285, 360);
glVertex2i(285, 380);
glVertex2i(283, 380);

glVertex2i(295, 360);
glVertex2i(297, 360);
glVertex2i(297, 380);
glVertex2i(295, 380);

glVertex2i(307, 360);
glVertex2i(309, 360);
glVertex2i(309, 380);
glVertex2i(307, 380);

glVertex2i(319, 360);
glVertex2i(321, 360);
glVertex2i(321, 380);
glVertex2i(319, 380);

glVertex2i(331, 360);
glVertex2i(333, 360);
glVertex2i(333, 380);
glVertex2i(331, 380);

glVertex2i(343, 360);
glVertex2i(345, 360);
glVertex2i(345, 380);
glVertex2i(343, 380);

glVertex2i(355, 360);
glVertex2i(357, 360);
glVertex2i(357, 380);
glVertex2i(355, 380);

glVertex2i(367, 360);
glVertex2i(369, 360);
glVertex2i(369, 380);
glVertex2i(367, 380);

glVertex2i(379, 360);
glVertex2i(381, 360);
glVertex2i(381, 380);
glVertex2i(379, 380);

glVertex2i(391, 360);
glVertex2i(393, 360);
glVertex2i(393, 380);
glVertex2i(391, 380);

glVertex2i(403, 360);
glVertex2i(405, 360);
glVertex2i(405, 380);
glVertex2i(403, 380);

glVertex2i(415, 360);
glVertex2i(417, 360);
glVertex2i(417, 380);
glVertex2i(415, 380);

glVertex2i(427, 360);
glVertex2i(429, 360);
glVertex2i(429, 380);
glVertex2i(427, 380);

glVertex2i(439, 360);
glVertex2i(441, 360);
glVertex2i(441, 380);
glVertex2i(439, 380);

glVertex2i(451, 360);
glVertex2i(453, 360);
glVertex2i(453, 380);
glVertex2i(451, 380);

glVertex2i(463, 360);
glVertex2i(465, 360);
glVertex2i(465, 380);
glVertex2i(463, 380);

glVertex2i(475, 360);
glVertex2i(477, 360);
glVertex2i(477, 380);
glVertex2i(475, 380);

glVertex2i(487, 360);
glVertex2i(489, 360);
glVertex2i(489, 380);
glVertex2i(487, 380);

glVertex2i(499, 360);
glVertex2i(501, 360);
glVertex2i(501, 380);
glVertex2i(499, 380);

glVertex2i(511, 360);
glVertex2i(513, 360);
glVertex2i(513, 380);
glVertex2i(511, 380);

glVertex2i(523, 360);
glVertex2i(525, 360);
glVertex2i(525, 380);
glVertex2i(523, 380);

glVertex2i(535, 360);
glVertex2i(537, 360);
glVertex2i(537, 380);
glVertex2i(535, 380);

glVertex2i(547, 360);
glVertex2i(549, 360);
glVertex2i(549, 380);
glVertex2i(547, 380);

glVertex2i(559, 360);
glVertex2i(561, 360);
glVertex2i(561, 380);
glVertex2i(559, 380);

glVertex2i(571, 360);
glVertex2i(573, 360);
glVertex2i(573, 380);
glVertex2i(571, 380);

glVertex2i(583, 360);
glVertex2i(585, 360);
glVertex2i(585, 380);
glVertex2i(583, 380);

glVertex2i(595, 360);
glVertex2i(597, 360);
glVertex2i(597, 380);
glVertex2i(595, 380);

glVertex2i(607, 360);
glVertex2i(609, 360);
glVertex2i(609, 380);
glVertex2i(607, 380);

glVertex2i(619, 360);
glVertex2i(621, 360);
glVertex2i(621, 380);
glVertex2i(619, 380);

glVertex2i(631, 360);
glVertex2i(633, 360);
glVertex2i(633, 380);
glVertex2i(631, 380);

glVertex2i(643, 360);
glVertex2i(645, 360);
glVertex2i(645, 380);
glVertex2i(643, 380);

glVertex2i(655, 360);
glVertex2i(657, 360);
glVertex2i(657, 380);
glVertex2i(655, 380);

glVertex2i(667, 360);
glVertex2i(669, 360);
glVertex2i(669, 380);
glVertex2i(667, 380);

glVertex2i(679, 360);
glVertex2i(681, 360);
glVertex2i(681, 380);
glVertex2i(679, 380);

glVertex2i(691, 360);
glVertex2i(693, 360);
glVertex2i(693, 380);
glVertex2i(691, 380);

glVertex2i(703, 360);
glVertex2i(705, 360);
glVertex2i(705, 380);
glVertex2i(703, 380);

glVertex2i(715, 360);
glVertex2i(717, 360);
glVertex2i(717, 380);
glVertex2i(715, 380);

glVertex2i(727, 360);
glVertex2i(729, 360);
glVertex2i(729, 380);
glVertex2i(727, 380);

glVertex2i(739, 360);
glVertex2i(741, 360);
glVertex2i(741, 380);
glVertex2i(739, 380);

glVertex2i(751, 360);
glVertex2i(753, 360);
glVertex2i(753, 380);
glVertex2i(751, 380);

glVertex2i(763, 360);
glVertex2i(765, 360);
glVertex2i(765, 380);
glVertex2i(763, 380);

glVertex2i(775, 360);
glVertex2i(777, 360);
glVertex2i(777, 380);
glVertex2i(775, 380);

glVertex2i(787, 360);
glVertex2i(789, 360);
glVertex2i(789, 380);
glVertex2i(787, 380);

glVertex2i(799, 360);
glVertex2i(801, 360);
glVertex2i(801, 380);
glVertex2i(799, 380);

glVertex2i(811, 360);
glVertex2i(813, 360);
glVertex2i(813, 380);
glVertex2i(811, 380);

glVertex2i(823, 360);
glVertex2i(825, 360);
glVertex2i(825, 380);
glVertex2i(823, 380);

glVertex2i(835, 360);
glVertex2i(837, 360);
glVertex2i(837, 380);
glVertex2i(835, 380);

glVertex2i(847, 360);
glVertex2i(849, 360);
glVertex2i(849, 380);
glVertex2i(847, 380);

glVertex2i(859, 360);
glVertex2i(861, 360);
glVertex2i(861, 380);
glVertex2i(859, 380);

glVertex2i(871, 360);
glVertex2i(873, 360);
glVertex2i(873, 380);
glVertex2i(871, 380);

glVertex2i(883, 360);
glVertex2i(885, 360);
glVertex2i(885, 380);
glVertex2i(883, 380);

glVertex2i(895, 360);
glVertex2i(897, 360);
glVertex2i(897, 380);
glVertex2i(895, 380);

glVertex2i(907, 360);
glVertex2i(909, 360);
glVertex2i(909, 380);
glVertex2i(907, 380);

glVertex2i(919, 360);
glVertex2i(921, 360);
glVertex2i(921, 380);
glVertex2i(919, 380);

glVertex2i(931, 360);
glVertex2i(933, 360);
glVertex2i(933, 380);
glVertex2i(931, 380);

glVertex2i(943, 360);
glVertex2i(945, 360);
glVertex2i(945, 380);
glVertex2i(943, 380);

glVertex2i(955, 360);
glVertex2i(957, 360);
glVertex2i(957, 380);
glVertex2i(955, 380);

glVertex2i(967, 360);
glVertex2i(969, 360);
glVertex2i(969, 380);
glVertex2i(967, 380);

glVertex2i(979, 360);
glVertex2i(981, 360);
glVertex2i(981, 380);
glVertex2i(979, 380);

glVertex2i(991, 360);
glVertex2i(993, 360);
glVertex2i(993, 380);
glVertex2i(991, 380);

glVertex2i(1003, 360);
glVertex2i(1005, 360);
glVertex2i(1005, 380);
glVertex2i(1003, 380);

glVertex2i(1015, 360);
glVertex2i(1017, 360);
glVertex2i(1017, 380);
glVertex2i(1015, 380);

glVertex2i(1027, 360);
glVertex2i(1029, 360);
glVertex2i(1029, 380);
glVertex2i(1027, 380);

glVertex2i(1039, 360);
glVertex2i(1041, 360);
glVertex2i(1041, 380);
glVertex2i(1039, 380);

glVertex2i(1051, 360);
glVertex2i(1053, 360);
glVertex2i(1053, 380);
glVertex2i(1051, 380);

glVertex2i(1063, 360);
glVertex2i(1065, 360);
glVertex2i(1065, 380);
glVertex2i(1063, 380);

glVertex2i(1075, 360);
glVertex2i(1077, 360);
glVertex2i(1077, 380);
glVertex2i(1075, 380);

glVertex2i(1087, 360);
glVertex2i(1089, 360);
glVertex2i(1089, 380);
glVertex2i(1087, 380);

glVertex2i(1099, 360);
glVertex2i(1101, 360);
glVertex2i(1101, 380);
glVertex2i(1099, 380);

glVertex2i(1111, 360);
glVertex2i(1113, 360);
glVertex2i(1113, 380);
glVertex2i(1111, 380);

glVertex2i(1123, 360);
glVertex2i(1125, 360);
glVertex2i(1125, 380);
glVertex2i(1123, 380);

glVertex2i(1135, 360);
glVertex2i(1137, 360);
glVertex2i(1137, 380);
glVertex2i(1135, 380);

glVertex2i(1147, 360);
glVertex2i(1149, 360);
glVertex2i(1149, 380);
glVertex2i(1147, 380);

glVertex2i(1159, 360);
glVertex2i(1161, 360);
glVertex2i(1161, 380);
glVertex2i(1159, 380);

glVertex2i(1171, 360);
glVertex2i(1173, 360);
glVertex2i(1173, 380);
glVertex2i(1171, 380);

glVertex2i(1183, 360);
glVertex2i(1185, 360);
glVertex2i(1185, 380);
glVertex2i(1183, 380);

glVertex2i(1195, 360);
glVertex2i(1197, 360);
glVertex2i(1197, 380);
glVertex2i(1195, 380);

glVertex2i(1207, 360);
glVertex2i(1209, 360);
glVertex2i(1209, 380);
glVertex2i(1207, 380);

glVertex2i(1219, 360);
glVertex2i(1221, 360);
glVertex2i(1221, 380);
glVertex2i(1219, 380);

glVertex2i(1231, 360);
glVertex2i(1233, 360);
glVertex2i(1233, 380);
glVertex2i(1231, 380);



glEnd();
glFlush ();
}



///weather
void rain()
{

    glColor3ub (128, 128, 128);
    glBegin(GL_LINES);
glVertex2i(0.0f, 0.0f);
glVertex2i(0.1f, 0.1f);

glEnd();
glFlush ();
}


///Object_End
///=========================================================================================================///


///========================///
///*** Display Function ***///
///========================///

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	init();

    ///*** Object_Layer ***///

    Sun();

    Windmill_Three();

    Hill_Big_One();
    Tilla_Four();



    Hill_Big_Two();
    Hill_Small_One();

    cloud_three();
    cloud_four();

    Windmill_One();
    Windmill_Two();


    Tilla_One();
    Tilla_Two();
    Tilla_Three();



    cloud_one();



    Tree_One();
    Tree_Two();
    Tree_Three();
    Tree_Four();
    Tree_Five();
    Tree_Six();
    Tree_Seven();
    Tree_Eight();
    Tree_Nine();
    Tree_Ten();
    Tree_Eleven();
    Tree_Twelve();



    cloud_two();
    cloud_five();
    cloud_six();

    field();
    Bridge();

    Train();
    rain();



	glFlush();

}
///========================///
///*** Speed & Movement ***///
///========================///
///*** Sun_Move ***///
void sun_move(){

    sun_spin = sun_spin + 0.0008;

}
void move_right(){

    sun_move();

    spin = spin +.1;
    ax = ax + .05;
    bx = bx + .08;
    cx = cx + .10;
    dx = dx + .15;

    if(cx>1000){
        cx = -300;
    }
    if(bx>1000){
            bx= -400;

    }
    if(cx>1000){
            cx= -400;

    }
    if(dx>1000){
            dx= -500;

    }


    glutPostRedisplay();
}
void keyboard(int key, int x, int y)
{
    if (key == GLUT_KEY_LEFT)
    {
        printf("pressed");
        isMoving = true;

        glutPostRedisplay();
    }
}


void mouse(int key, int state, int x, int y){
    switch (key)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(move_right);
        }
        break;
    case GLUT_MIDDLE_BUTTON:
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
        }
        break;
    default:
        break;
    }
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(-1, -1);
	glutInitWindowSize( 1240, 750);
	glutCreateWindow("Smart Village");
	init();
	glutDisplayFunc(display);
    glutSpecialFunc(keyboard);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(mouse);
    glutTimerFunc(1000, update, 0);
	glutMainLoop();
}
