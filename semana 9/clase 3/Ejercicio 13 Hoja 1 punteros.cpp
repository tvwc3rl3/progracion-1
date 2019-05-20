// Hoja 1 punteros Ejercicio 13

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>

using namespace System;
using namespace std;

void CalcularValores(double *radio, double *area, double *perimetro) {
	*area = 3.1416 * *radio * *radio;
	*perimetro = 2 * 3.1416 * *radio;
}

int main()
{
	//El tipo de dato int puede tener hasta 10 cifras
	//El tipo de dato long long puede tenner hasta 19 cifras
	double *radio = new double;
	double *area = new double;
	double *perimetro = new double;
	cout << "Ingreso el radio";
	cin >> *radio;
	//Esta funcion nos devuelve 2 valores
	CalcularValores(radio, area, perimetro);

	cout << "El area es: " << *area << endl;
	cout << "El perimetro es: " << *perimetro << endl;

	_getch();
	return 0;
}
