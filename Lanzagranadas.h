#pragma once
#include "Infanteria.h"

class Lanzagranadas: public Infanteria
{
private:
	int da�oarea;
public:
	Lanzagranadas(int x, int z, int jugador): Infanteria(x, z, jugador, 40, 30), da�oarea(5) {}
	~Lanzagranadas(void);

	void Dibuja();
	void atacar(Infanteria* mat[10][6], int x, int y);
};

