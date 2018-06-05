#include "Tablero.h"

#include "Infanteria.h"
#include "Soldado.h"
#include "Medico.h"
#include "Lanzagranadas.h"
#include "Francotirador.h"

#include <stdlib.h>	//para las funciones de números aleatorios
#include "glut.h"	//la glut siempre después de stdlib
#include <time.h>	//para la semilla de srand.

Tablero::Tablero()
{
	x1=0.0;
	y1=0.0;
	x2=0.0;
	y2=10.0;
	x3=6.0;
	y3=10.0;
	x4=6.0;
	y4=0.0;

	suministros1=100;
	suministros2=100;
	turno=1;

	for(int i=2;i<8;i++)
	{
		crearpieza('s', 3, i, 1);
		crearpieza('s', 2, i, 2);
	}
}

Tablero::~Tablero()
{
	for(int i=0; i<10; i++)
		for(int j=0; j<6; j++)
			if(mat[i][j]!=0)
				delete mat[i][j];
}

void Tablero::Dibuja()
{
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
		glColor3ub(0,0,255);
		glVertex3f(x1-0.5,y1-0.5,0.0f);
		glVertex3f(x2-0.5,y2-0.5,0.0f);
		glColor3ub(255,0,0);
		glVertex3f(x3-0.5,y3-0.5,0.0f);
		glVertex3f(x4-0.5,y4-0.5,0.0f);
		glColor3ub(255,255,255);
	glEnd();

	glColor3ub(0,255,0);

	for(float i=1.0f; i<10.0f; i++)
	{
		glBegin(GL_LINES);
			glVertex3f(-0.5f,i-0.5,0.1f);
			glVertex3f(5.5f,i-0.5,0.1f);
		glEnd();
	}

	for(float i=1.0f; i<6.0f; i++)
	{
		glBegin(GL_LINES);
			glVertex3f(i-0.5,-0.5f,0.1f);
			glVertex3f(i-0.5,9.5f,0.1f);
		glEnd();
	}

	glEnable(GL_LIGHTING); 

	for(int i=0; i<10; i++)
		for(int j=0; j<6; j++)
			if(mat[i][j]!=0)
				(mat[i][j])->Dibuja();
}

bool Tablero::crearpieza(unsigned char key, int x, int z, int jugador)
{
	if(mat[z][x]==0)
	{
		if((x>=3 && x<6)&&(z>=0 && z<10)&&(jugador==1)&&(suministros1>0) || (x>=0 && x<3)&&(z>=0 && z<10)&&(jugador==2)&&(suministros2>0))
		{
			switch (key)
			{
			case 's':
			case 'S':
			{
				Soldado *aux= new Soldado(x, z, jugador);
				mat[z][x]= aux;
				break;
			}
			case 'm':
			case 'M':
			{
				Medico *aux= new Medico(x, z, jugador);
				mat[z][x]= aux;
				break;
			}
			case 'l':
			case 'L':
			{
				Lanzagranadas *aux= new Lanzagranadas(x, z, jugador);
				mat[z][x]= aux;
				break;
			}
			case 'f':
			case 'F':
			{
				Francotirador *aux= new Francotirador(x, z, jugador);
				mat[z][x]= aux;
				break;
			}
			default:
				break;
			}
	
			if((mat[z][x])->GetJugador()==1)
				suministros1-=(mat[z][x])->GetCoste();
			else if((mat[z][x])->GetJugador()==2)
				suministros2-=(mat[z][x])->GetCoste();

			return true;
		}
	}
	return false;
}

void Tablero::atacar(int x, int y, int jugador)
{
	if((x>=0 && x<6)&&(y>=0 && y<10))
	for(int i=0; i<10; i++)
	for(int j=0; j<6; j++)
		if(mat[i][j]!=0 && (mat[i][j])->GetJugador()==jugador)
		{	
			//decidir a que punto ataca (por aquello de la probabilidad de fallo)
			srand(time(NULL));
			int num1=rand()%2;
			if(num1==0)
				(mat[i][j])->atacar(mat, x, y);
			else
			{
				int num2=rand()%8;
				switch (num2)
				{
				case 0:
					(mat[i][j])->atacar(mat, x, y+1);
					break;
				case 1:
					(mat[i][j])->atacar(mat, x+1, y+1);
					break;
				case 2:
					(mat[i][j])->atacar(mat, x+1, y);
					break;
				case 3:
					(mat[i][j])->atacar(mat, x+1, y-1);
					break;
				case 4:
					(mat[i][j])->atacar(mat, x, y-1);
					break;
				case 5:
					(mat[i][j])->atacar(mat, x-1, y-1);
					break;
				case 6:
					(mat[i][j])->atacar(mat, x-1, y);
					break;
				case 7:
					(mat[i][j])->atacar(mat, x-1, y+1);
					break;
				default:
					break;
				}
			}
		}
}

void Tablero::borrarpiezas()
{
	for(int i=0; i<10; i++)
		for(int j=0; j<6; j++)
			if((mat[i][j]!=0) && ((mat[i][j])->GetVida()<=0))
			{
				delete mat[i][j];
				mat[i][j]=0;
			}
}

void Tablero::atacarIA(int jugador)
{
	int jugenem;

	if(jugador==1)
		jugenem=2;
	else
		jugenem=1;

	int xmin, ymin;
	int vidamin=500;
	int vidainstant;

	for(int i=0; i<10; i++)
	for(int j=0; j<6; j++)
	if(mat[i][j]!=0 && (mat[i][j])->GetJugador()==jugador)
	{
		for(int k=0; k<10; k++)
		for(int l=0; l<6; l++)
		if(mat[k][l]!=0 && (mat[k][l])->GetJugador()==jugenem)
		{
			vidainstant=(mat[k][l])->GetVida();
			if(vidainstant<vidamin && vidainstant>0)			//La IA busca la pieza con menos vida del campo enemigo.
			{
				vidamin=vidainstant;
				xmin=l;
				ymin=k;
			}
		}

		srand(time(NULL));
		int num=rand()%2;
		if(num==0)
			(mat[i][j])->atacar(mat, xmin, ymin);	//La IA también puede fallar, pero si falla no le da a nadie, a diferencia del jugador (IA en modo fácil)
	}
}

bool Tablero::crearpiezaIA(int jugador)
{
	int sum= jugador==1? suministros1: suministros2;

	//La IA elige qué pieza crear y busca un hueco libre para ella.
	char adalid;

	if(sum>=50)
		adalid='l';
	else if(sum>=20)
		adalid='f';
	else if(sum>=10)
		adalid='m';
	else
		adalid='s';

	int x=-1, y=-1;

	for(int i=0; i<10 && y==-1; i++)
	for(int j=0; j<6 && x==-1; j++)
		if(mat[i][j]==0)
		{
			x=j;
			y=i;
		}

	bool res=crearpieza(adalid, x, y, jugador);

	return res;
}

void Tablero::CambiarTurno()
{
	if (turno==1)
		turno=2;
	else
		turno=1;

	suministros1+=10;
	suministros2+=10;
}

int Tablero::CondicionesDeVictoria()
{
	int haypieza1=0, haypieza2=0;
	int ganador=0;

	for(int i=0; i<10; i++)
	for(int j=0; j<6; j++)
		if(mat[i][j]!=0) 
			if(mat[i][j]->GetJugador()==1)
				haypieza1=1;
			else if(mat[i][j]->GetJugador()==2)
				haypieza2=1;

	if(haypieza1==haypieza2==1)
		ganador=0;		//continúa el juego
	else if(haypieza1==haypieza2==0)
		ganador=3;		//empate
	else if(haypieza1==1 && haypieza2==0)
		ganador=1;		//gana el jugador 1
	else if(haypieza1==0 && haypieza2==1)
		ganador=2;		//gana el jugador 2

	return ganador;
}