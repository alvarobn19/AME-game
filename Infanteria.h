class Infanteria
{
private:
	float x, z;

	int vida, ataque, sanacion, coste;

public:
	//métodos
	Infanteria() {;}		//no utilizar, necesario para poner el siguiente constructor.
	Infanteria(unsigned char key, int x, int z);
	int GetX();
	int GetZ();
	void Dibuja();
	void Borra();
	void Mueve();
};