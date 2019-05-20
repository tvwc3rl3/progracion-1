// ConsoleApplication1.cpp : main project file.

#include "stdafx.h"
#include <conio.h>
#include <iostream>

using namespace System;
using namespace std;


int main()
{
	
	int *punteroA;
	
	cout << "Al declarar el puntero: " << endl;
	cout << "La direcion que apunta el puntero es: " << punteroA << endl;

	punteroA = new int;

	cout << "Al hacer new al puntero: " << endl;
	cout << "la direccion que apunta el puntero es: " << punteroA << endl;

	*punteroA = 5;

	cout << "El valor de la variable referenciada por el puntero es: " << *punteroA << endl;

	delete punteroA;
	
	cout << "Al hacer delete al puntero: " << endl;
	cout << "la direccion que contiene el puntero es: " << punteroA << endl;

	punteroA = NULL;

	cout << "Al hacer NULL al puntero: " << endl;
	cout << "la direccion que contiene el puntero es: " << punteroA << endl;

    _getch();
    return 0;
}
