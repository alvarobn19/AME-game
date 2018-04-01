#include "Infanteria.h"

Infanteria::Infanteria (unsigned char key, int x, int z)
{
	this->x=x;
	this->z=z;

	switch (key)
	{
	case 's':
	case 'S':
		vida=50;
		ataque=10;
		sanacion=0;
		coste=5;
		break;
	case 'm':
	case 'M':
		vida=50;
		ataque=0;
		sanacion=5;
		coste=10;
		break;
	case 'f':
	case 'F':
		vida=20;
		ataque=20;	//pensar lo del headshot
		sanacion=0;
		coste=20;
		break;
	case 'l':
	case 'L':
		vida=40;
		ataque=5;	//pensar lo del daño en area
		sanacion=0;
		coste=30;
		break;
	default:
		break;
	}
}

int Infanteria::GetX()
{
	return x;
}

int Infanteria::GetZ()
{
	return z;
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