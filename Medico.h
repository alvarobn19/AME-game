#pragma once
#include "infanteria.h"

class Medico: public Infanteria
{
private:
	int sanacion;
public:
	Medico(int x, int z, int jugador): Infanteria(x, z, jugador, 50, 10), sanacion(5) {}
	~Medico(void);
};

