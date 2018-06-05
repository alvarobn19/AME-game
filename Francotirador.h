#pragma once
#include "ETSIDI.h"
#include "Infanteria.h"

using ETSIDI::SpriteSequence;

class Francotirador: public Infanteria
{
private:
	int daño;
	int probheadshot;
	SpriteSequence sprite;
public:
	Francotirador(int x, int y, int jugador): Infanteria(x, y, jugador, 20, 20), daño(20), probheadshot(20), sprite("imagenes/francotirador.png", 1)
	{
		sprite.setCenter(1, 0.5);
		sprite.setSize(1.5, 1);
		if(jugador==2)
		sprite.flip(true, false); 
	}
	~Francotirador(void);

	void Dibuja();
	void atacar(Infanteria* mat[10][6], int x, int y);
	void ataque(int xdisp, int ydisp);
};

