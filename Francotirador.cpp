#include "Francotirador.h"
#include <stdlib.h>
#include <time.h>

Francotirador::~Francotirador(void)
{
}

void Francotirador::Dibuja()
{
	//dibujo del francotirador.
}

void Francotirador::atacar(Infanteria* mat[10][6], int x, int y)
{
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