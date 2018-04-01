#include "Infanteria.h"


class Jugador
{
private:
	int suministros, npiezas;
	Infanteria piezas[10][3];
public:
	//métodos
	Jugador();
	void crearpieza();
	void destruirpieza(Infanteria miinf);
};