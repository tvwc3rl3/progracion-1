// ConsoleApplication2.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

const int FILAS = 2;
const int COLUMNAS= 3;

void MostrarValores(int **matriz) {
	cout << "La matriz ingresada es: " << endl;
	for (int indice1 = 0; indice1 < FILAS; indice1++) {
		for (int indice2 = 0; indice2 < COLUMNAS; indice2++)
		{
			cout << matriz[indice1][indice2] << " ";
		}
		cout << endl;
	}
}

void IngresarValores(int **matriz) {
	for (int indice1 = 0; indice1 < FILAS; indice1++) {
		cout << "Ingrese los valores de la fila: " << indice1 << " :" << endl;
		for (int indice2 = 0; indice2 < COLUMNAS; indice2++) {
			cout << "Ingrese los valores de la columna " << indice2 << " : ";
			cin >> matriz[indice1][indice2];
		}
	}
}
int main()
{
	
	//int matriz[3][5];
	//creando matriz de enteros
	int **matriz;
	// asignar memoria
	matriz = new int *[FILAS];
	for (int indice = 0; indice < FILAS; indice++)
		matriz[indice] = new int[COLUMNAS];
	IngresarValores(matriz);
	MostrarValores(matriz);

	//liberamos memoria



    _getch();
    return 0;
}
