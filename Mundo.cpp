#include "Mundo.h"
#include <math.h>


void Mundo::Inicializa()
{
	x_ojo=0.0;
	y_ojo=20;
	z_ojo=5;
	x_mira=0.0;
	y_mira=0.0;
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
	
}