#pragma once
#include "Infanteria.h"
#include"ETSIDI.h"

using ETSIDI::SpriteSequence;

class Soldado: public Infanteria
{
private:
	int daño;
	SpriteSequence sprite;
public:
	Soldado(int x, int y, int jugador): Infanteria(x, y, jugador, 50, 5), daño(10), sprite("imagenes/soldado.png", 3)
	{
		sprite.setCenter(0.25, 0.5);
		sprite.setSize(0.75, 1);
		if(jugador==1)
		sprite.flip(true, false); 
	} 
	~Soldado(void);

	void Dibuja();
	void atacar(Infanteria* mat[10][6], int x, int y);
	void ataque();
};

