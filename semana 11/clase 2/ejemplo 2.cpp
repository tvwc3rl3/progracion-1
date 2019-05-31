// ConsoleApplication8.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace System;
using namespace std;

const int MAXELEMENTOS = 100;
int main()
{
	//declarando el arreglo
	int *arrNumeros;
	int numElementos, indice;
	//asignarle memoria
	arrNumeros = new int[MAXELEMENTOS];

	//consultado el numero de elementos que tendra el arreglo
	do
	{
		cout << "Ingrese el numero de elementos del arreglo: ";
		cin >> numElementos;
	} while (numElementos < 0 || numElementos > 100);

	//ingresar los valores
	for (indice = 0; indice < numElementos; indice++)
	{
		cout << "Ingrese el elemento en la posicion " << indice << " del arreglo: ";
		cin >> arrNumeros[indice];
	}

	//mostrar los valores del arreglo
	cout << "\nLos elementos del arreglo son: " << endl;
	for (indice = 0; indice < numElementos; indice++)
		cout << "arrNumeros [" << indice << "] = " << arrNumeros[indice] << endl;

	//libera memoria
	delete[] arrNumeros;

	_getch();
	return 0;
}
