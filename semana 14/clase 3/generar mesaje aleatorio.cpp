// asddas.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <conio.h>
#include <time.h>
#include <iostream>

using namespace System;
using namespace std;

const int MAXLONGITUD = 30;

void Generar_Mensaje(char *mensaje, int longMensaje) {
	//A es 65 y < 90
	srand(time(NULL));
	for (int indice = 0; indice < longMensaje; indice++)
		mensaje[indice] = rand() % 26 + 65;
}

void Imprimir_Mensaje(char *mensaje, int longMensaje) {
	for (int indice = 0; indice < longMensaje; indice++)
		cout << mensaje[indice] << " ";
}

bool Existe_mensaje_consecutivo(char *mensaje, int longMensaje) {
	bool consecutivo;
	consecutivo = false;
	for (int indice = 0; indice < longMensaje-2; indice++)
	{
		if (mensaje[indice] == 'U' && mensaje[indice + 1] == 'P' && mensaje[indice + 2] == 'C')
			consecutivo = true;
	}
	return consecutivo;
}

bool Existe_mesaje_alterno(char *mensaje, int longMensaje) {
	bool alterno;
	alterno = false;
	for (int indice = 0; indice < longMensaje + 4; indice++)
	{
		if (mensaje[indice] == 'I' && mensaje[indice + 2] == 'S' && mensaje[indice + 4] == 'I')
			alterno = true;
	}
	return alterno;
}

int main()
{
	char *mensaje;
	mensaje = new char[MAXLONGITUD];
	int longMensaje;
	int contador;
	bool consecutivo, alterno;

	contador = 1;
	while (1)
	{
		//la logica pedidda
		srand(time(NULL));
		//generamos un numero entre 20 y 30
		longMensaje = rand() % 11 + 20;
		Generar_Mensaje(mensaje, longMensaje);
		cout << "Mensaje: " << contador << " : " << endl;
		Imprimir_Mensaje(mensaje, longMensaje);
		cout << endl;
		consecutivo = Existe_mensaje_consecutivo(mensaje, longMensaje);
		alterno = Existe_mesaje_alterno(mensaje, longMensaje);
		if (consecutivo)
			cout << "ES UN ALUMNO" << endl;
		if (alterno)
			cout << "ES UN ALUMNO DE SISTEMAS" << endl;
		contador++;
		cout << endl;
		cout << "Presione una tecla para ver el siguiente mensaje..." << endl;
		_getch();
		
	}
	delete[]mensaje;
    _getch();
    return 0;
}
