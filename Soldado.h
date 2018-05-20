#pragma once
#include "Infanteria.h"

class Soldado: public Infanteria
{
private:
	int daño;
public:
	Soldado(int x, int z, int jugador): Infanteria(x, z, jugador, 50, 5), daño(10) {}
	~Soldado(void);

	void Dibuja();
	void atacar(Infanteria* mat[10][6], int x, int y);
};

