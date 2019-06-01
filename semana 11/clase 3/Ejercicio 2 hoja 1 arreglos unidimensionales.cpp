// ConsoleApplication8.cpp : main project file.
//incompleto

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
	*mayorPeso = CalcularMayorPeso(arrPesos)
	CalcularCantPersonas(arrPesos, cantDelgados, cantMedianos, cantGruesos);
	
	cout << "El promedio es: " << *promedio << endl;
	cout << "El mayor peso es: " << *mayorPeso << endl;
	cout << "la cantidadad de delgados es: " << *promedio << endl;
	cout << "El promedio es: " << *promedio << endl;

	


	_getch();
	return 0;
}
