// Hoja 1 punteros Ejercicio 15

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>

using namespace System;
using namespace std;

int CalcularFactorial(int *n) {
	int *factorial = new int;
	int *contador = new int;
	*factorial = 1;
	*contador = 1;
	while (*contador <= *n)
	{
		*factorial = *factorial * *contador;
		*contador = *contador + 1;
	}
	return *	factorial;
}

double CalcularCombinatorio(int *n, int *k) {
	double *combinatorio = new double;
	int *numerador = new int;
	int *denominador = new int;
	int *resta = new int;

	*numerador = CalcularFactorial(n);
	*resta = *n - *k;
	*denominador = CalcularFactorial(k)*CalcularFactorial(resta);
	*combinatorio = *numerador / *denominador;
	return *combinatorio;
}

int main()
{
	//El tipo de dato int puede tener hasta 10 cifras
	//El tipo de dato long long puede tenner hasta 19 cifras
	int *n = new int;
	int *k = new int;
	double *combinatorio = new double;

	cout << "Ingreso n: ";
	cin >> *n;
	
	cout << "Ingreso k: ";
	cin >> *k;
	//Esta funcion nos devuelve 2 valores
	*combinatorio = CalcularCombinatorio(n, k);

	cout << "El combinatorio es: " << *combinatorio << endl;


	_getch();
	return 0;
}
