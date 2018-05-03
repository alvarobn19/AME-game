#pragma once

#include "Infanteria.h"

class Tablero
{
private:
	float x1, x2, x3, x4, z1, z2, z3, z4;
	Infanteria *mat[10][6];
public:
	//métodos:
	Tablero();
	void Dibuja();
};