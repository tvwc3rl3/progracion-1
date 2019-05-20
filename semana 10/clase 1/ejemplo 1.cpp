// ConsoleApplication1.cpp : main project file.

#include "stdafx.h"
#include <conio.h>
#include <iostream>

using namespace System;
using namespace std;

int main()
{
	//float *punteroA = new float;
	//float *punteroB = new float;
	//float *suma = new float;

	float *punteroA, *punteroB, *suma;
	//asignamos memoria
	punteroA = new float;
	punteroB = new float;
	suma = new float;

	cout << "Ingrese el primer valor: ";
	cin >> *punteroA;
	cout << "Ingrese el segundo valor: ";
	cin >> *punteroB;

	*suma = *punteroA + *punteroB;
	cout << "El valor de la suma es: " << endl;

	//liberamos la memoria reservada
	delete punteroA;
	delete punteroB;
	delete suma;

    _getch();
    return 0;
}
