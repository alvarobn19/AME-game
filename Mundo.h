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
	bool estado;
public:
	//métodos:
	void Inicializa();
	void Dibuja();
	int Tecla(unsigned char key);
	int getTurno(){return mitab.getTurno();}

	friend void onMouse(int button, int state, int x, int y);
};

