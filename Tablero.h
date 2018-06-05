#pragma once

#include "Infanteria.h"

class Tablero
{
private:
	float x1, x2, x3, x4, y1, y2, y3, y4;
	int suministros1, suministros2;
	int turno;

	Infanteria *mat[10][6];
public:
	//métodos:
	Tablero();
	~Tablero();
	void Dibuja();
	bool crearpieza(unsigned char key, int x, int y, int jugador);
	void atacar(int x, int y, int jugador);
	void borrarpiezas();
	void atacarIA(int jugador);
	bool crearpiezaIA(int jugador);
	void CambiarTurno();
	int getTurno(){return turno;}
	int CondicionesDeVictoria();	//devuelve jugador que gana, si devuelve 0 no gana nadie, si devuelve 3 hay empate
};