#pragma once
#include "Infanteria.h"

class Francotirador: public Infanteria
{
private:
	int da�o;
	int probheadshot;
public:
	Francotirador(int x, int z, int jugador): Infanteria(x, z, jugador, 20, 20), da�o(20), probheadshot(20) {}
	~Francotirador(void);

	void Dibuja();
	void atacar(Infanteria* mat[10][6], int x, int y);
};

