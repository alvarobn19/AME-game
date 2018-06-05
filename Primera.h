#pragma once
#include "ETSIDI.h"
#include "Mundo.h"

class Primera
{
protected:
	enum Estado {Empezar, Curso, Derrota, Fin };
	Estado estado;
public:
	Mundo mundo;
	Primera();
	virtual ~Primera();
	void tecla(unsigned char key);
	void dibuja();
};

