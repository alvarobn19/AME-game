#include "Medico.h"

Medico::~Medico(void)
{
}

void Medico::Dibuja()
{
	//dibujo del medico.
}

void Medico::atacar(Infanteria* mat[10][6], int x, int y)
{
	//el médico busca al más herido a su alcance y le cura
	int xcura, ycura;
	int vidamin=500;
	int vidainstant;

	for(int i=-1; i<2; i++)		//recorremos la matriz para buscar la pieza más herida.
	for(int j=-1; j<2; j++)
		if(mat[this->y+i][this->x+j]!=0 && (mat[this->y+i][this->x+j])->GetJugador()==this->jugador)	//la pieza existe y pertenece al mismo jugador que el médico
		{
			vidainstant=(mat[this->y+i][this->x+j])->GetVida();
			if(vidainstant<vidamin)
			{
				vidamin=vidainstant;
				xcura=this->x+j;
				ycura=this->y+i;
			}
		}

	mat[ycura][xcura]->SetVida((mat[ycura][xcura]->GetVida())+this->sanacion);
}