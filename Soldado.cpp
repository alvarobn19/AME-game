#include "Soldado.h"
#include "Infanteria.h"

Soldado::~Soldado(void)
{
}

void Soldado::Dibuja()
{
	//dibujo del soldado
	Infanteria::Dibuja();	//puesto así provisionalmente, si no no se ve nah
}

void Soldado::atacar(Infanteria* mat[10][6], int x, int y)
{
	if(mat[y][x]!=0)
		mat[y][x]->SetVida((mat[y][x]->GetVida())-this->daño);
}