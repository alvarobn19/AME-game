#include "Francotirador.h"
#include "glut.h"
#include <stdlib.h>
#include <time.h>

Francotirador::~Francotirador(void)
{
}

void Francotirador::Dibuja()
{
	glPushMatrix();
	glTranslatef(x, y, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	
	sprite.setState(1, false);
	sprite.draw();

	glPopMatrix();
}

void Francotirador::atacar(Infanteria* mat[10][6], int x, int y)
{
	ataque(x, y);

	srand(time(NULL));
	int precision=rand()%101;
	if(mat[y][x]!=0)
	{
		if(precision<=this->probheadshot)
			mat[y][x]->SetVida(0);
		else
			mat[y][x]->SetVida((mat[y][x]->GetVida())-this->daño);
	}
}

void Francotirador::ataque(int xdisp, int ydisp)
{
	ETSIDI::play("sonidos/Winchester12-RA_The_Sun_God-1722751268.wav");
/*	glColor3f(0.0f, 0.0f, 0.0f);

	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glVertex3f(xdisp, ydisp, 0);
	glVertex3f(x, y, 0);
	glEnd();
	glEnable(GL_LIGHTING);

	glPushMatrix();
	glTranslatef(x, y, 0);

	glutSolidSphere(0.25f, 20, 20);
	glPopMatrix();	*/
}