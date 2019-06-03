// ConsoleApplication4.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <time.h>

using namespace System;
using namespace std;

const int NUMELEMENTOS = 200;
const int MAXVALOR = 500;
const int MINVALOR = 25;

void GenerarArregloMontos(int *numPersonas, int *arrMontos) {

	int *indice = new int;
	//teneramos semilla
	srand(time(NULL));
	for (*indice = 0; *indice < *numPersonas; (*indice)++) {
		//un monto aleatorio entre 25 y 500 Nuevos soles
		//si queremos un numero entre 1, finrango - 1
		//rand() % FINRANGO +1
		arrMontos[*indice] = rand() % MAXVALOR + MINVALOR;
	}
}

void GenerarArregloMontosFORMA2(int *numPersonas, int *arrMontos) {

	int *indice = new int;
	for (*indice = 0; *indice < *numPersonas; (*indice)++) {
		//un monto aleatorio entre 25 y 500 Nuevos soles
		
		arrMontos[*indice] = Random::Random().Next(25, 501);
	}
}

void MostrarArreglo(int *numPersonas, int *arrMontos) {
	int *indice = new int;
	for (*indice = 0; *indice < *numPersonas; (*indice)++) {
		cout << arrMontos[*indice] << " ";
	}
	cout << endl;
}
void OrdenarArreglo(int *numPersonas, int *arrMontos) {
	int *numAux = new int;
	int *indice1 = new int;
	int *indice2 = new int;

	for ( *indice1 = 0; *indice1 < *numPersonas -1; (*indice1)++) {
		for (*indice2 = *indice1 + 1; *indice2 < *numPersonas; (*indice2)++) {
			if (arrMontos[*indice2] < arrMontos[*indice1]) {
				*numAux = arrMontos[*indice1];
				arrMontos[*indice1] = arrMontos[*indice2];
				arrMontos[*indice2] = *numAux;
			}
		}
	}
}

int CalcularPersonasRango(int *arrMontos, int *numPersonas) {
	int *cantPersonasRango = new int;
	int *indice = new int;
	*cantPersonasRango = 0;

	for (*indice = 0; *indice < *numPersonas; (*indice)++)
	{
		if (arrMontos[*indice] >= 100 && arrMontos[*indice] <= 300)
			(*cantPersonasRango)++;
	}
	return *cantPersonasRango;
}
int CalcularMontosImpar(int *arrMontos, int *numPersonas) {
	int *cantMontosImpar = new int;
	int *indice = new int;
	*cantMontosImpar = 0;
	for (*indice = 0; *indice < *numPersonas; (*indice)++) {
		if (arrMontos[*indice] % 2 != 0)
			(*cantMontosImpar)++;
	}
	return *cantMontosImpar;
}

int main()
{
	int *arrMontos;
	arrMontos = new int[NUMELEMENTOS];
	int *numPersonas = new int;
	int *numPersonasRango = new int;
	int *cantMontosImpar = new int;

	while (1)
	{
		cout << "Ingrese el numero de personas a evaluar: ";
		cin >> *numPersonas;
		if (*numPersonas > 0 && *numPersonas < NUMELEMENTOS)
			break;
	}
	GenerarArregloMontos(numPersonas, arrMontos);
	MostrarArreglo(numPersonas, arrMontos);
	OrdenarArreglo(numPersonas, arrMontos);
	MostrarArreglo(numPersonas, arrMontos);
	*numPersonasRango = CalcularPersonasRango(arrMontos, numPersonas);
	*cantMontosImpar = CalcularMontosImpar(arrMontos, numPersonas);

	cout << endl;
	cout << "Resultados" << endl;
	cout << "El numero de personas que gastaron entre 100 y 300 soles en bebidas es: " << *numPersonasRango << endl;
	cout << "La cantidad de montos que tienen asociadas una cantidad impar. es: " << *cantMontosImpar << endl;

	

    _getch();
    return 0;
}
