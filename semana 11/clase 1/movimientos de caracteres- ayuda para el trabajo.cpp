// Grafico.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <time.h>
#include <Windows.h>

using namespace System;
using namespace std;

void asignarXY(int *x, int *y) {
	*x = rand() % 70 + 1;
	*y = rand() % 20 + 1;
}

int AsignarDesplazamiento() {
	int desp;
	
	desp = 1;
	//desp = rand() % 5 + 1;
	return desp;
}

void BorrarPersonaje(int *x, int *y) {
	Console::SetCursorPosition(*x, *y);
	cout << " ";
}

void moverPersonajeEjeX(int *x, int *desp) {
	if (*x + *desp < 0 || *x + *desp > 79)
		*desp *= -1;
	*x += *desp;
}

void moverPersonajeEjeY(int *y, int *desp) {
	if (*y + *desp < 0 || *y + *desp > 26)
		*desp *= -1;
	*y += *desp;
}

void DibujarPersonaje(int *x, int *y) {
	Console::SetCursorPosition(*x, *y);
	Console::ForegroundColor = ConsoleColor::White;
	cout << char(254);
}

int main()
{
	int *x = new int;
	int *y = new int;
	//Desp controlara el movimiento
	int *desp = new int;

	//generamos la semila para generar numeros aleatorios
	//diferentes en cada corrida del programa
	srand(time(NULL));
	//geberamos de manera aletoria un punto x, y donde aparecera el caracter
	asignarXY(x, y);

	//Asignar desplazamiento
	*desp = AsignarDesplazamiento();

	//le doy untamaño a mi consola
	Console::SetWindowSize(80, 26);
	//
	Console::CursorVisible = false;
	while (true) {
		BorrarPersonaje(x, y);
		moverPersonajeEjeX(x, desp);
		moverPersonajeEjeY(y, desp);
		DibujarPersonaje(x, y);
		Sleep(18);
	}
	
	_getch();
	return 0;
}
