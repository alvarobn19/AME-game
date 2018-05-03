#pragma once

class Infanteria
{
private:
	int x, z;
	int xorigen, zorigen;

	int vida, ataque, sanacion, coste;
	bool dañoarea, headshot;

public:
	//métodos
	Infanteria(): x(0), z(0), xorigen(0), zorigen(0) {vida=ataque=sanacion=coste=0; dañoarea=headshot=false;}		//no utilizar, necesario para poner el siguiente constructor.
	Infanteria(unsigned char key, int x, int z);
	int GetX(){return x;}
	int GetZ(){return z;}
	int GetCoste(){return coste;}
	void Dibuja();
	void Borra();
	void Mueve();
};