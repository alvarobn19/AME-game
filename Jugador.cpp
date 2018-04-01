#include "Jugador.h"

Jugador::Jugador()
{
	suministros=0;
	npiezas=0;
	for(int i=0; i<5; i++)
		crearpieza ();
}

void Jugador::crearpieza()
{
	//preguntar qué tipo de pieza y la posición
	unsigned char key;
	int x, z;

	Infanteria miinf(key, x, z);
	piezas[x][z]=miinf;
	npiezas++;
}

void Jugador::destruirpieza(Infanteria miinf)
{
//	piezas[miinf.GetX()][miinf.GetZ()]=NULL;
	npiezas--;
}