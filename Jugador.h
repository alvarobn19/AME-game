#pragma once

#include "Infanteria.h"

class Jugador
{
private:
	int suministros, npiezas;
	Infanteria piezas[10][3];
public:
	//métodos
	void inicio(unsigned char key);
	void crearpieza(unsigned char key);
	void destruirpieza(Infanteria miinf);
	void atacar();
};