#pragma once
#include "Infanteria.h"
#include"ETSIDI.h"

using ETSIDI::SpriteSequence;

class Medico: public Infanteria
{
private:
	int sanacion;
	SpriteSequence sprite;
public:
	Medico(int x, int y, int jugador): Infanteria(x, y, jugador, 50, 10), sanacion(5), sprite("imagenes/ambulancia.png", 3)
	{
		sprite.setCenter(0.5, 0.5);
		sprite.setSize(1, 1);
		if(jugador==1)
		sprite.flip(true, false); 
	}
	~Medico(void);

	void Dibuja();
	void atacar(Infanteria* mat[10][6], int x, int y);
	void ataque();
};

