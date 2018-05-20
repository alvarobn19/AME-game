#pragma once

class Infanteria
{
protected:
	int x, y;
	int xorigen, yorigen;

	int jugador;
	int vida, coste;

public:
	//m�todos
	Infanteria(): x(0), y(0), xorigen(0), yorigen(0) {vida=coste=0; jugador=0;}		//no utilizar, necesario para poner el siguiente constructor.
	Infanteria(int x, int y, int jugador, int vida, int coste);
	virtual ~Infanteria() {}

	int GetX(){return x;}
	int GetZ(){return y;}
	int GetCoste(){return coste;}
	int GetVida(){return vida;}
	int GetJugador(){return jugador;}
	void SetVida(int vida){this->vida=vida;}
	void Mueve();

	virtual void Dibuja();	//no se dibujar� nada hasta que est�n los m�todos de dibuja de cada clase
	virtual void atacar(Infanteria* mat[10][6], int x, int y) = 0;
};