// ConsoleApplication2.cpp : main project file.

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <time.h>

using namespace System;
using namespace std;

const int FILAS = 2;
const int COLUMNAS = 3;

void GenerarValores(int **matriz) {
	srand(time(NULL));
	for (int indice1 = 0; indice1 < FILAS; indice1++)
		for (int indice2 = 0; indice2 < COLUMNAS; indice2++)
			matriz[indice1][indice2] = rand() % 100 + 1;
			//genera valores del 1 al 100
}

void MostrarValores(int **matriz) {
	cout << "La matriz ingresada es: " << endl;
	for (int  indice1 = 0; indice1 < FILAS; indice1++)
	{
		for (int indice2 = 0; indice2 < COLUMNAS; indice2++)
		{
			cout << matriz[indice1][indice2] << " ";
		}
		cout << endl;
	}
}

bool BuscarValor(int **matriz, int *valorBuscado) {
	bool encontrado = false;
	int indice1, indice2;
	indice1 = 0;
	while (indice1 < FILAS && encontrado == false)
	{
		indice2 = 0; 
		while (indice2 < COLUMNAS && encontrado ==false)
		{
			if (matriz[indice1][indice2] == *valorBuscado)
				encontrado = true;
			indice2++;
		}
		indice1++;
	}
	return encontrado;
}

int IdentificadorMayor(int **matriz) {
	int mayor;
	mayor = matriz[0][0]; //el elemnto en fila 0, columna 0
	for(int indice1= 0; indice1  < FILAS; indice1++)
		for (int indice2 = 0; indice2 < COLUMNAS; indice2++)
		{
			if (matriz[indice1][indice2] > mayor)
				mayor = matriz[indice1][indice2];

		}
	return mayor;
}

int IdentificarMenor(int **matriz) {
	int menor;
	menor = matriz[0][0]; //el elemnto en fila 0, columna 0
	for (int indice1 = 0; indice1 < FILAS; indice1++)
		for (int indice2 = 0; indice2 < COLUMNAS; indice2++)
		{
			if (matriz[indice1][indice2] < menor)
				menor = matriz[indice1][indice2];
		}
	return menor;
}

int main()
{
	int **matriz;
	int *valorBuscado = new int;
	bool *evaluacion = new bool;
	int *mayor = new int;
	int *menor = new int;

	//asignar memoria
	matriz = new int *[FILAS];

	for (int indice = 0; indice < FILAS; indice++)
		matriz = new int *[FILAS];

	GenerarValores(matriz);
	MostrarValores(matriz);

	//solicitar un valor a buscar
	cout << "Ingrese valor a buscar: ";
	cin >> *valorBuscado;
	*evaluacion = BuscarValor(matriz, valorBuscado);
	if (*evaluacion)
		cout << "\nSe encontro el valor buscado";
	else
		cout << "\nNo se encontro el valor buscado";

	//liberamos meorias
	for (int indice = 0; indice < FILAS; indice++)
		delete[] matriz[indice];
	delete[] matriz;

	_getch();
    return 0;
}
