#include "Primera.h"
#include "glut.h"


Primera::Primera()
{
	estado = Empezar;
	mundo.Inicializa();
	ETSIDI::playMusica("Musica/heavy-rain-daniel_simon.mp3");
}

void Primera::dibuja()
{
	if (estado == Empezar)
	{
		gluLookAt(2.0, 4.5, 10.0,		// posicion del ojo
			0.0, 0.0, 0.0,			// hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);			// definimos hacia arriba (eje Y)		

	/*	ETSIDI::setTextColor(1.0f, 0.0f, 1.0f);
		glTranslatef(-5, 8, 0.01);
		ETSIDI::print("AME", "fuentes/Lactosa.ttf", 24);
		glTranslatef(5, -8, -0.01); 
		
		ETSIDI::setFont("fuentes/Lactosa.ttf", 24);
		ETSIDI::printxy("AME", -5, 8, 0.01);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Lactosa.ttf", 11);
		ETSIDI::printxy("PULSE LA TECLA ESPACIO PARA COMENZAR", -5, 7, 0.01);
		ETSIDI::printxy("PULSE LA TECLA 'S' PARA SALIR", -5, 6);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::printxy("Alvaro Baena y Marcos Moreno", -1, 1);
	*/	glEnable(GL_LIGHTING);
	}
	else if (estado == Curso)
	{
		ETSIDI::stopMusica();
		mundo.Dibuja();
		if (mundo.getTurno() == 0)
		{
		/*	ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/.ttf", 14);
			ETSIDI::printxy("Turno de uno", 8.1, 1, 0.01);
		*/}
		else if (mundo.getTurno() == 1)
		{
		/*	ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/.ttf", 14);
			ETSIDI::printxy("Turno de dos", 8.1, 1, 0.01);
		*/}
	}

	if (estado == Derrota)
	{
		mundo.Dibuja();
	/*	ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Lactosa.ttf", 16);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	*/}
	else if (estado == Fin)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		mundo.Dibuja();
	/*	ETSIDI::setFont("fuentes/Lactosa.ttf", 12);
		ETSIDI::printxy("ENHORABUENA, ¡Has ganado!", -5, 10, 0.01);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
	*/}
}

void Primera::tecla(unsigned char key)
{
	if (estado == Empezar)
	{
		if (key == ' ')
		{
			mundo.Inicializa();
			estado = Curso;
		}
		if (key == 'S')
			exit(0);
	}
	else if (estado == Curso)
	{
		int ganador=mundo.Tecla(key);
		if (ganador == 1)
		{
			estado = Fin;
			//pintar que gana el jugador 1.
		}
		else if(ganador == 2)
		{
			estado = Fin;
			//pintar que gana el jugador 2.
		}
		else if(ganador == 3)
		{
			estado=Fin;
			//pintar que ha habido empate.
		}
	}
	else if (estado == Fin)
	{
		if (key == 'c')
			estado = Empezar;
	}
}


Primera::~Primera(void)
{
}

