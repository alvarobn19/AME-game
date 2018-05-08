#pragma once

class Infanteria
{
private:
	int x, y;
	int xorigen, yorigen;

	int jugador;
	int vida, coste;

public:
	//métodos
	Infanteria(): x(0), y(0), xorigen(0), yorigen(0) {vida=coste=0; jugador=0;}		//no utilizar, necesario para poner el siguiente constructor.
	Infanteria(int x, int y, int jugador, int vida, int coste);
	int GetX(){return x;}
	int GetZ(){return y;}
	int GetCoste(){return coste;}
	int GetVida(){return vida;}
	int GetJugador(){return jugador;}
	void Dibuja();
	void Mueve();
};