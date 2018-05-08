#include "Infanteria.h"
#include "glut.h"

Infanteria::Infanteria(int x, int y, int jugador, int vida, int coste): x(x), y(y), vida(vida)
{
	if (jugador==1 && jugador==2)
	{
		this->jugador=jugador;
		this->coste=coste;
	}
}

void Infanteria::Dibuja()
{
	glColor3ub(255, 255, 255);
	glTranslatef(x, y, 0);
	glutSolidSphere(0.5, 20, 20);
	glTranslatef(-x, -y, 0);
}

void Infanteria::Mueve()
{
	
}