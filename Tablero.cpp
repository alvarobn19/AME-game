#include "Tablero.h"
#include "glut.h"

#include "Infanteria.h"
#include "Soldado.h"
#include "Medico.h"
#include "Lanzagranadas.h"
#include "Francotirador.h"


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

	for(int i=3;i<9;i++)
	{
		crearpieza('s', 4, i, 1);
		crearpieza('s', 3, i, 2);
	}
}

void Tablero::Dibuja()
{
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
		glColor3ub(0,0,255);
		glVertex3f(x1+0.5,y1+0.5,0.0f);
		glVertex3f(x2+0.5,y2+0.5,0.0f);
		glColor3ub(255,0,0);
		glVertex3f(x3+0.5,y3+0.5,0.0f);
		glVertex3f(x4+0.5,y4+0.5,0.0f);
		glColor3ub(255,255,255);
	glEnd();

	glColor3ub(0,255,0);

	for(float i=1.0f; i<10.0f; i++)
	{
		glBegin(GL_LINES);
			glVertex3f(0.5f,i+0.5,0.1f);
			glVertex3f(6.5f,i+0.5,0.1f);
		glEnd();
	}

	for(float i=1.0f; i<6.0f; i++)
	{
		glBegin(GL_LINES);
			glVertex3f(i+0.5,0.5f,0.1f);
			glVertex3f(i+0.5,10.5f,0.1f);
		glEnd();
	}

	glEnable(GL_LIGHTING); 

	for(int i=0; i<10; i++)
		for(int j=0; j<6; j++)
			if(mat[i][j]!=0)
				(mat[i][j])->Dibuja();
}

void Tablero::crearpieza(unsigned char key, int x, int z, int jugador)
{
	if(mat[z][x]==0)
	{
		if((x>=3 && x<=6)&&(z>=0 && z<=10)&&(jugador==1)&&(suministros1>=0) || (x>=0 && x<=3)&&(z>=0 && z<=10)&&(jugador==2)&&(suministros2>=0))
		{
			switch (key)		//revisar la línea de encima por lo de los suministros
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
		}
	}
}

void Tablero::atacar(int x, int y)
{
	for(int i=0; i<10; i++)
		for(int j=0; j<6; j++)
			if(mat[i][j]!=0)
			;//	(mat[i][j])->atacar(x, y);		//Llamada dentro de matriz a la función atacar propia de cada clase de infanteria.
}

void Tablero::borrarpiezas()
{
	for(int i=0; i<10; i++)
		for(int j=0; j<6; j++)
			if(mat[i][j]!=0 && ((mat[i][j])->GetVida()==0))
				delete mat[i][j];
}