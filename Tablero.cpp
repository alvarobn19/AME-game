#include "Tablero.h"
#include "glut.h"


Tablero::Tablero()
{
	x1=-3.0;
	z1=-5.0;
	x2=-3.0;
	z2=5.0;
	x3=3.0;
	z3=5.0;
	x4=3.0;
	z4=-5.0;
}

void Tablero::Dibuja()
{
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
		glColor3ub(0,0,255);
		glVertex3f(x1,0.0f,z1);
		glVertex3f(x2,0.0f,z2);
		glColor3ub(255,0,0);
		glVertex3f(x3,0.0f,z3);
		glVertex3f(x4,0.0f,z4);
		glColor3ub(255,255,255);
	glEnd();

	glColor3ub(0,255,0);

	for(float i=-4.0f; i<5.0f; i++)
	{
		glBegin(GL_LINES);
			glVertex3f(-3.0f,0.1f,i);
			glVertex3f(3.0f,0.1f,i);
		glEnd();
	}

	for(float i=-2.0f; i<3.0f; i++)
	{
		glBegin(GL_LINES);
			glVertex3f(i,0.1f,-5.0f);
			glVertex3f(i,0.1f,5.0f);
		glEnd();
	}

	glEnable(GL_LIGHTING); 
}