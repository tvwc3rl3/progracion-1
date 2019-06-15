// ConsoleApplication2.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <conio.h>
#include <iostream>

using namespace std;
using namespace System;

const int FILAS = 20;
const int COLUMNAS = 20;
const int ORIGENX = 7;
const int ORIGENY = 7;

void BorrarPersonaje(int *x, int *y) {
	Console::SetCursorPosition(*x, *y);
	cout << " ";
}

void DibujarPersonaje(int *x, int *y) {
	Console::SetCursorPosition(*x, *y);
	Console::ForegroundColor = ConsoleColor::Cyan;
	cout << char(235);
}

void MoverPersonaje(int **mapa, char tecla, int *x, int *y) {

	/*
	M derecha
	K izquierda
	H arriba
	P abajo
	*/

	BorrarPersonaje(x, y);
	if (tecla == 'M') //derecha
	{
		if (mapa[*y][*x + 1] == 0)
			*x = *x + 1;
	}
	else
		if (tecla == 'K') // izquierda
		{
			if (mapa[*y][*x - 1] == 0)
				*x = *x - 1;
		}
		else
			if (tecla == 'H') //arriba
			{
				if (mapa[*y - 1][*x] == 0)
					*y = *y - 1;
			}
			else
				if (tecla == 'P')
				{
					if (mapa[*y + 1][*x] == 0)
						*y = *y + 1;
				}
	DibujarPersonaje(x, y);
}


void DibujarTablero(int **mapa) {
	for (int indice1 = 0; indice1 < FILAS; indice1++) {
		for (int indice2 = 0; indice2 < COLUMNAS; indice2++) {
			if (mapa[indice1][indice2] == 0)
				cout << " ";
			if (mapa[indice1][indice2] == 1) {
				Console::ForegroundColor = ConsoleColor::Magenta;
				cout << char(219);
			}
		}
		cout << endl;
	}
}

void GenerarTablero(int **mapa) {
	int matrizEstatica[20][20] = { 
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
	{ 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0 },
	{ 0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0 },
	{ 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0 },
	{ 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0 },
	{ 0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0 },
	{ 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0 },
	{ 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0 },
	{ 0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0 },
	{ 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0 },
	{ 0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };

	for (int indice1 = 0; indice1 < FILAS; indice1++)
		for (int indice2 = 0; indice2 < COLUMNAS; indice2++)
			mapa[indice1][indice2] = matrizEstatica[indice1][indice2];
}

int main()
{
	Console::SetWindowSize(80, 26);
	Console::CursorVisible = false;
	int **mapa;
	int *x;
	int *y;
	char tecla;
	mapa = new int *[FILAS];
	for (int indice = 0; indice < FILAS; indice++)
		mapa[indice] = new int[COLUMNAS];
	//x, y es laposicion del movil
	x = new int;
	y = new int;
	GenerarTablero(mapa);
	DibujarTablero(mapa);
	//El punto incial donde aparece el movil;
	*x = ORIGENX + 1;
	*y = ORIGENY + 1;
	DibujarPersonaje(x, y);
	while (1)
	{
		if (_kbhit())
		{
			tecla = _getch();
			MoverPersonaje(mapa, tecla, x, y);
		}

	}
	//liberamos meroria

   _getch();
    return 0;
}
