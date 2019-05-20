// ConsoleApplication1.cpp : main project file.

#include "stdafx.h"
#include <conio.h>
#include <iostream>

using namespace System;
using namespace std;


int main()
{
	
	int *punteroA;
	
	punteroA = new int;

	if (punteroA == NULL)
		cout << "No se pudo reservar espacio en la memoria";
	else
	{
		cout << "Ingrese un numero: ";
		cin >> *punteroA;
		*punteroA = *punteroA + 5;
		cout << "El numero es: " << *punteroA << endl;
		//liberamos la memoria
		delete punteroA;
		//colocamos puntero a NULL
		punteroA = NULL;
	}

    _getch();
    return 0;
}
