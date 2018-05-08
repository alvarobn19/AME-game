#pragma once

#include "Infanteria.h"

class Tablero
{
private:
	float x1, x2, x3, x4, y1, y2, y3, y4;
	int suministros1, suministros2;
	Infanteria *mat[10][6];
public:
	//métodos:
	Tablero();
	void Dibuja();
	void crearpieza(unsigned char key, int x, int y, int jugador);
	void atacar(int x, int y);
	void borrarpiezas();
};