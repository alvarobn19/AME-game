#pragma once
#include "ETSIDI.h"
#include "Mundo.h"
class Primera
{
protected:
	enum Estado { INICIO, JUEGO, GAMEOVER, FIN };
	Estado estado;

public:
	Primera();
	virtual ~Primera();
	void tecla(unsigned char key);
	void dibuja();
protected:
	Mundo mundo;
};

