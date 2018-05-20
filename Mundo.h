#pragma once

#include "glut.h"
#include "Tablero.h"

class Mundo
{
protected:
	float x_ojo, y_ojo, z_ojo;
	float x_mira, y_mira, z_mira;
	float x_eje, y_eje, z_eje;
	Tablero mitab;
	int xtab, ytab;
public:
	//métodos:
	void Inicializa();
	void Dibuja();
	void Mueve();
	void Tecla(unsigned char key);

	friend void onMouse(int button, int state, int x, int y);
};

