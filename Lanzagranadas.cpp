#include "Lanzagranadas.h"

Lanzagranadas::~Lanzagranadas(void)
{
}

void Lanzagranadas::Dibuja()
{
	//dibujo del lanzagranadas.
}

void Lanzagranadas::atacar(Infanteria* mat[10][6], int x, int y)
{
	for(int i=-1; i<2; i++)		//recorremos la matriz para hacer daño en area.
	for(int j=-1; j<2; j++)
		if(mat[y+i][x+j]!=0)
			mat[y+i][x+j]->SetVida((mat[y][x]->GetVida())-this->dañoarea);
}