// ConsoleApplication1.cpp : main project file.

#include "stdafx.h"
#include <conio.h>
#include <iostream>

using namespace System;
using namespace std;

void RealizarCalculos(float *punteroA, float *punteroB, float *suma, float *producto) {
	*suma = *punteroA + *punteroB;
	*producto = *punteroA * *punteroB;
}

int main()
{
	//float *punteroA = new float;
	//float *punteroB = new float;
	//float *suma = new float;

	float *punteroA, *punteroB, *producto, *suma;
	//asignamos memoria
	punteroA = new float;
	punteroB = new float;
	suma = new float;
	producto = new float;

	cout << "Ingrese el primer valor: ";
	cin >> *punteroA;
	cout << "Ingrese el segundo valor: ";
	cin >> *punteroB;

	RealizarCalculos(punteroA, punteroB, suma, producto);
	cout << "El valor de la suma es: " << *suma << endl;
	cout << "El valor del producto es: " << *producto << endl;

	//liberamos la memoria reservada
	delete punteroA;
	delete punteroB;
	delete suma;
	delete producto;

    _getch();
    return 0;
}
