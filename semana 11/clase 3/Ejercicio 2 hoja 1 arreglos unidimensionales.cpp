// ConsoleApplication8.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <time.h>

using namespace System;
using namespace std;

const int NUMELEMENTOS = 10;

void CalcularCantPersonas(float *arrPesos, int *cantDelgados, int *cantMedianos, int *cantGruesos) {
	//devuelve 3 valores
	int *indice = new int;
	*cantDelgados = 0;
	*cantMedianos = 0;
	*cantGruesos = 0;

	for (*indice = 0; *indice < NUMELEMENTOS; (*indice)++) {
		if (arrPesos[*indice] < 53)
			(*cantDelgados)++;
		else
			if (arrPesos[*indice] <= 60)
				(*cantMedianos)++;
			else
				(*cantGruesos)++;
	}
}

void IngresarValores(float *arrPesos) {
	int *indice = new int;
	for (*indice = 0; *indice < NUMELEMENTOS; (*indice)++) {
		cout << "Ingrese el peso del cliente: ";
		cin >> arrPesos[*indice];
	}
}

float CalcularMayorPeso(float *arrPesos) {
	float *mayor = new float;
	int *indice = new int;
	*mayor = arrPesos[0];
	for (*indice = 0; *indice < NUMELEMENTOS; (*indice)++) {
		if (arrPesos[*indice] > *mayor)
			*mayor = arrPesos[*indice];
	}
	return *mayor;
}

float CalcularPesoPromedio(float *arrPesos) {
	
}

int main()
{
	
	float *arrPesos;
	arrPesos = new float[NUMELEMENTOS];
	float *promedio = new float;
	float *mayorPeso = new float;
	int *cantDelgados = new int;
	int *cantMedianos = new int;
	int *cantGruesos = new int;

	IngresarValores(arrPesos);
	*promedio = CalcularPesoPromedio(arrPesos);
	*mayorPeso = CalcularMayorPeso(arrPesos);
	CalcularCantPersonas(arrPesos, cantDelgados, cantMedianos, cantGruesos);
	
	cout << "El promedio es: " << *promedio << endl;
	cout << "El mayor peso es: " << *mayorPeso << endl;
	cout << "La cantidadad de delgados es: " << *cantDelgados << endl;
	cout << "La cantidadad de medianos es: " << *cantMedianos << endl;

	


	_getch();
	return 0;
}
