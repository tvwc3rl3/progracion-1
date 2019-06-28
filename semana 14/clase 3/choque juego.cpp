// camino.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include  <iostream>
#include <conio.h>

using namespace System;
using namespace std;

const int FILAS = 20;
const int COLUMNAS = 23;
const int ARRIBA = 72;
const int ABAJO = 80;
const int DERECHA = 77;
const int IZQUIERDA = 75;

void borraMovil(int *posMovil) {
	Console::SetCursorPosition(posMovil[0], posMovil[1]);
	Console::ForegroundColor = ConsoleColor::Cyan;
	cout << char(219);
}

void dibujaMovil(int *posMovil)
{
	Console::SetCursorPosition(posMovil[0], posMovil[1]);
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << char(3);
}

void dibujaEnemigo(int *posEnemigo)
{
	Console::SetCursorPosition(posEnemigo[0], posEnemigo[1]);
	Console::ForegroundColor = ConsoleColor::Magenta;
	cout << char(1);
}

void borraEnemigo(int *posEnemigo)
{
	Console::SetCursorPosition(posEnemigo[0], posEnemigo[1]);
	Console::ForegroundColor = ConsoleColor::Cyan;
	cout << char(219);
}

void moverEnemigo(int **mapa, int *posEnemigo, int &avance, int *posMovil)
{
	//colisiona con el enemigo
	if (posEnemigo[0] == posMovil[0] && posEnemigo[1] == posMovil[1])
	{
		//el movil se va a su posicion inicial
		posMovil[0] = 10; //x
		posMovil[1] = 8;//y
	}
	//movimiento del movil
	borraEnemigo(posEnemigo);
	//vamos avanzando
	if (mapa[posEnemigo[1] + avance][posEnemigo[0]] == 1)
		posEnemigo[1] = posEnemigo[1] + avance;
	//cambiamos de direccion de arriba hacia abajo y viceversa
	if (mapa[posEnemigo[1] + avance][posEnemigo[0]] == 0)
		avance = avance *-1;
	dibujaEnemigo(posEnemigo);
}




void moverPersonaje(int **mapa, int *posMovil, char tecla)
{
	borraMovil(posMovil);
	//mover
	if (tecla == DERECHA) {
		if (mapa[posMovil[1]][posMovil[0]+1]==1)
		{
			posMovil[0] = posMovil[0] + 1;
		}
		else
		{
			posMovil[0] = 10;
			posMovil[1] = 8;
		}
	}
	else 
	{
		if (tecla == IZQUIERDA) {
			if (mapa[posMovil[1]][posMovil[0] - 1] == 1)
			{
				posMovil[0] = posMovil[0] - 1;
			}
			else
			{
				posMovil[0] = 10;
				posMovil[1] = 8;
			}
		}
		else
		{
			if (tecla == ARRIBA) {
				if (mapa[posMovil[1]-1][posMovil[0]] == 1)
				{
					posMovil[1] = posMovil[1] - 1;
				}
				else
				{
					posMovil[0] = 10;
					posMovil[1] = 8;
				}
			}
			else
			{
				if (tecla == ABAJO) {
					if (mapa[posMovil[1]+1][posMovil[0]] == 1)
					{
						posMovil[1] = posMovil[1] + 1;
					}
					else
					{
						posMovil[0] = 10;
						posMovil[1] = 8;
					}
				}
			}
		}
	}

	//dibujar
	dibujaMovil(posMovil);

}

void desplazar_movil_y_enemigo(int **mapa)
{
	int *posMovil, *posEnemigo, avance;
	char tecla;

	posMovil = new int[2];
	posEnemigo = new int[2];
	//Posicion Inicial Movil
	posMovil[0] = 10; //x;
	posMovil[1] = 8; //y
					 //POsicion Inicial Enemigo
	posEnemigo[0] = 19; //x
	posEnemigo[1] = 8; //y
					   //dibujamos al movil
	dibujaMovil(posMovil);
	//dibujamos al enemigo
	dibujaEnemigo(posEnemigo);
	//avance del enemigo
	avance = 1;

	//Desplazamiento
	while (1)
	{
		moverEnemigo(mapa, posEnemigo, avance, posMovil);
		_sleep(50);
		if (kbhit())
		{
			tecla = _getch();
			moverPersonaje(mapa, posMovil, tecla);
		}
	}
	delete[]posMovil;
	delete[]posEnemigo;
}

void genera_muestra_matriz(int **mapa)
{
	int matriz[20][23] = {
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0 },
		{ 0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,0,1,0,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0 },
		{ 0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };

	for (int indice1 = 0; indice1 < FILAS; indice1++)
		for (int indice2 = 0; indice2 < COLUMNAS; indice2++)
			mapa[indice1][indice2] = matriz[indice1][indice2];

	//generamos tablero

	for (int indice1 = 0; indice1 < FILAS; indice1++)
	{
		for (int indice2 = 0; indice2 < FILAS; indice2++)
		{
			if (mapa[indice1][indice2] == 1)
			{
				Console::ForegroundColor = ConsoleColor::Cyan;
				cout << char(219);
			}
			if (mapa[indice1][indice2] == 0)
			{
				cout << " ";
			}
		}
		cout << endl;
	}

}

int main()
{
	int **mapa;
	mapa = new int *[FILAS];
	for (int indice = 0; indice < FILAS; indice++)
		mapa[indice] = new int[COLUMNAS];

	genera_muestra_matriz(mapa);
	desplazar_movil_y_enemigo(mapa);

	for (int indice = 0; indice < FILAS; indice++)
		delete[] mapa[indice];
	delete[]mapa;
	_getch();
	return 0;
}
