#pragma once
#include"ETSIDI.h"
#include "Infanteria.h"

using ETSIDI::SpriteSequence;
class Lanzagranadas: public Infanteria
{
private:
	int dañoarea;
	SpriteSequence sprite;
public:
	Lanzagranadas(int x, int y, int jugador): Infanteria(x, y, jugador, 40, 30), dañoarea(5), sprite("imagenes/lanzagranadas.png", 1) 
	{
		sprite.setCenter(0.45, 0.60);
		sprite.setSize(0.75, 1);
		if(jugador==1)
		sprite.flip(true, false); 
	}
	~Lanzagranadas(void);

	void Dibuja();
	void atacar(Infanteria* mat[10][6], int x, int y);
	void ataque(int xdisp, int ydisp);
};

