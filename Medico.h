#pragma once
#include "Infanteria.h"

class Medico: public Infanteria
{
private:
	int sanacion;
public:
	Medico(int x, int z, int jugador): Infanteria(x, z, jugador, 50, 10), sanacion(5) {}
	~Medico(void);

	void Dibuja();
	void atacar(Infanteria* mat[10][6], int x, int y);
};

