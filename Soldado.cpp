#include "Soldado.h"
#include "Infanteria.h"

Soldado::~Soldado(void)
{
}

void Soldado::Dibuja()
{
	glPushMatrix();
	glTranslatef(x, y, 0.2);
	glColor3f(1.0f, 1.0f, 1.0f);
	

	sprite.setState(1, false);
	sprite.draw();

	glPopMatrix();
}

void Soldado::atacar(Infanteria* mat[10][6], int x, int y)
{
	ataque();
	if(mat[y][x]!=0)
		mat[y][x]->SetVida((mat[y][x]->GetVida())-this->daño);
}
void Soldado::ataque()
{
	ETSIDI::play("sonidos/espada.mp3");
}