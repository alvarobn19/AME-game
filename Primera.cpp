#include "Primera.h"


Primera::Primera()
{
	estado = INICIO;
	ETSIDI::playMusica("Musica/Atomic_Bomb.wav", true);
}

void Primera::dibuja()
{
	if (estado == INICIO)
	{
		//CODIGO PARA PINTAR UNA PANTALLA NEGRA CON LETRAS



		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(1, 0, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 22);
		ETSIDI::printxy("AME", -5, 8, 0.01);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA ESPACIO PARA EMPEZAR", -5, 7, 0.01);
		ETSIDI::printxy("PULSE LA TECLA 'esc' PARA SALIR", -5, 6);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::printxy("Alvaro Baena y Marcos Moreno", -1, 1);
	}
	else if (estado == JUEGO)
	{
		ETSIDI::stopMusica();
		mundo.Dibuja();
		/*if (mundo.turno == 0)
		{
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
			ETSIDI::printxy("Turno de uno", 8.1, 1, 0.01);

		}
		else if (mundo.turno == 1)
		{
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
			ETSIDI::printxy("Turno de dos", 8.1, 1, 0.01);
		}*/
	}
	

	if (estado == GAMEOVER)
	{
		mundo.Dibuja();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	}
	else if (estado == FIN)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		mundo.Dibuja();
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", -5, 10, 0.01);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
	}
}




void Primera::tecla(unsigned char key)
{
	if (estado == INICIO)
	{
		if (key == ' ')
		{
			mundo.Inicializa();
			estado = JUEGO;
		}
		if (key == 'p')
			exit(0);
	}
	else if (estado == JUEGO)
	{
		mundo.Tecla(key);
		//if (mundo.estado == false)
			//estado = FIN;
	}
	else if (estado == GAMEOVER)
	{
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == FIN)
	{
		if (key == 'c')
			estado = INICIO;
	}
}


Primera::~Primera(void)
{
}
