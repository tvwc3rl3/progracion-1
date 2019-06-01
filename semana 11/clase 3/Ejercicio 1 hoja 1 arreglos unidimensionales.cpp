// ConsoleApplication8.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <time.h>

using namespace System;
using namespace std;



const int NUMELEMENTOS = 6;

void IngresarValores (float *arrNotas){
	int *indice = new int;
	
	//ingresa valores
	for (*indice = 0; *indice < NUMELEMENTOS; (*indice)++) {
		cout << "Ingrese la nota de la evaluacion " << *indice + 1 << " : ";
		cin >> arrNotas[*indice];
	}
}

float CalcularMenorNota(float *arrNotas) {
	float *menor = new float;
	int *indice = new int;
	//buscando la menor nota
	*menor = arrNotas[0];
	for (*indice = 0; *indice < NUMELEMENTOS; (*indice)++) {
		if (arrNotas[*indice] < *menor)
			*menor = arrNotas[*indice];
	}
	return *menor;
}

float CalcularPromedio(float *arrNotas) {
	float *menor = new float;
	float *promedio = new float;
	float *sumaNotas = new float;
	int *indice = new int;
	for (*indice = 0; *indice < NUMELEMENTOS; (*indice)++)
		*sumaNotas = *sumaNotas + arrNotas[*indice];
	*menor = CalcularMenorNota(arrNotas);
	*promedio = (*sumaNotas - *menor) / (NUMELEMENTOS - 1);
	return *promedio;

	//acumulando los valores
}

int main()
{
	//declarando el arreglo
	float *arrNotas;
	//se asigna memoria
	arrNotas = new float[NUMELEMENTOS];


	_getch();
	return 0;
}
