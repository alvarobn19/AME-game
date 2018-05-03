#include "Infanteria.h"

Infanteria::Infanteria (unsigned char key, int x, int z): x(x), z(z), xorigen(0), zorigen(0)
{
	switch (key)
	{
	case 's':
	case 'S':
		vida=50;
		ataque=10;
		sanacion=0;
		coste=5;
		dañoarea=false;
		headshot=false;
		break;
	case 'm':
	case 'M':
		vida=50;
		ataque=0;
		sanacion=5;
		coste=10;
		dañoarea=false;
		headshot=false;
		break;
	case 'f':
	case 'F':
		vida=20;
		ataque=20;	
		sanacion=0;
		coste=20;
		dañoarea=false;
		headshot=true;
		break;
	case 'l':
	case 'L':
		vida=40;
		ataque=5;	
		sanacion=0;
		coste=30;
		dañoarea=true;
		headshot=false;
		break;
	default:
		break;
	}
}

void Infanteria::Dibuja()
{

}

void Infanteria::Borra()
{

}

void Infanteria::Mueve()
{
	
}