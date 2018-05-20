#include "ETSIDI.h"
#include "Mundo.h"
#include <math.h>


void Mundo::Inicializa()
{
	x_ojo=2.0;
	y_ojo=4.5;
	z_ojo=20.0;
	x_mira=2.0;
	y_mira=4.5;
	z_mira=0.0;
	x_eje=0.0;
	y_eje=1.0;
	z_eje=0.0;
}

void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,		// posicion del ojo
		x_mira, y_mira, z_mira,			// hacia que punto mira  (0,0,0) 
		x_eje, y_eje, z_eje);			// definimos hacia arriba (eje Y)    

	mitab.Dibuja();
}

void Mundo::Mueve()
{

}

void Mundo::Tecla(unsigned char key)
{
	int jugador=2;

	switch (key)
	{
	case 's':
	case 'S':
	case 'm':
	case 'M':
	case 'f':
	case 'F':
	case 'l':
	case 'L':
		mitab.crearpieza(key, xtab, ytab, jugador);
		break;
	case 'a':
	case 'A':
		mitab.atacar(xtab, ytab, jugador);
		break;
	default:
		break;
	}

	mitab.borrarpiezas();
	mitab.CambiarTurno();
}