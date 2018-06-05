#include "Lanzagranadas.h"
#include "glut.h"

Lanzagranadas::~Lanzagranadas(void)
{
}

void Lanzagranadas::Dibuja()
{
	glPushMatrix();
	glTranslatef(x, y, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);

	sprite.setState(1, false);
	sprite.draw();

	glPopMatrix();
}

void Lanzagranadas::atacar(Infanteria* mat[10][6], int x, int y)
{
	ataque(x, y);

	for(int i=-1; i<2; i++)		//recorremos la matriz para hacer daño en area.
	for(int j=-1; j<2; j++)
		if(mat[y+i][x+j]!=0)
			(mat[y+i][x+j])->SetVida((mat[y+i][x+j]->GetVida())-this->dañoarea);
}

void Lanzagranadas::ataque(int xdisp, int ydisp)
{
	ETSIDI::play("sonidos/lanzagranadas.mp3");
/*	glColor3f(0.0f, 0.0f, 0.0f);

	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glVertex3f(xdisp, ydisp, 0.01);
	glVertex3f(x, y, 0.1f);
	glEnd();
	glEnable(GL_LIGHTING);

	glPushMatrix();
	glTranslatef(xdisp, ydisp, 0);
	glutSolidSphere(0.25f, 20, 20);
	glPopMatrix();	*/
}