//#include <iostream>
#include <math.h>
#include "Primera.h"
#include "glut.h"

Primera prim;

//los callback, funciones que seran llamadas automaticamente por la glut cuando sucedan eventos.
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	


int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(onMouse);
	
	//inicializaci�n de los datos de la simulaci�n

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}

void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	//aqui es donde hay que poner el c�digo de dibujo
	prim.dibuja();		//este m�todo sit�a la vista y dibuja el mundo

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el c�digo de teclado
	prim.tecla(key);

	glutPostRedisplay();
}

void OnTimer(int value)
{
	//poner aqui el c�digo de animacion
	
	//no borrar estas lineas
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay(); 
}

void onMouse(int button, int state, int x, int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		for(int i=9; i>=0; i--)
			if(y>=93+i*41 && y<=93+(i+1)*41)
				prim.mundo.ytab=9-i;
		for(int i=0; i<6; i++)
			if(x>=298+i*41 && x<=298+(i+1)*41)
				prim.mundo.xtab=i;
	}
}