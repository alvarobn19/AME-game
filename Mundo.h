#pragma once

#include "glut.h"
#include "Tablero.h"
#include "Jugador.h"

class Mundo
{
private:
	float x_ojo, y_ojo, z_ojo;
	float x_mira, y_mira, z_mira;
	float x_eje, y_eje, z_eje;
	Tablero mitab;
	Jugador mijug;
public:
	//métodos:
	void Inicializa();
	void Dibuja();
	void Mueve();
	void Tecla(unsigned char key);
};