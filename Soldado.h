#pragma once
#include "infanteria.h"

class Soldado: public Infanteria
{
private:
	int daño;
public:
	Soldado(int x, int z, int jugador): Infanteria(x, z, jugador, 50, 5), daño(10) {}
	~Soldado(void);
};

