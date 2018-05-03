#include "Jugador.h"

void Jugador::inicio(unsigned char key)
{
	suministros=0;
	npiezas=0;
	for(int i=0; i<5; i++)
		crearpieza (key);
}

void Jugador::crearpieza(unsigned char key)
{
	//preguntar qué tipo de pieza y la posición
	int x, z;

	Infanteria miinf(key, x, z);
	piezas[x][z]=miinf;
	npiezas++;
	suministros-=miinf.GetCoste();
}

void Jugador::destruirpieza(Infanteria miinf)
{
//	piezas[miinf.GetX()][miinf.GetZ()]=;
	npiezas--;
}

void Jugador::atacar()
{
//	float x, z;

}