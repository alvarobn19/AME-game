#include "Infanteria.h"
#include "glut.h"

Infanteria::Infanteria(int x, int y, int jugador, int vida, int coste): x(x), y(y), vida(vida)
{
	if (jugador==1 || jugador==2)
	{
		this->jugador=jugador;
		this->coste=coste;
	}
}
