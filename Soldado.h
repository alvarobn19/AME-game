#pragma once
#include "infanteria.h"

class Soldado: public Infanteria
{
private:
	int da�o;
public:
	Soldado(int x, int z, int jugador): Infanteria(x, z, jugador, 50, 5), da�o(10) {}
	~Soldado(void);
};

