#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace System;
using namespace std;

int main()
{
	//declarando el arreglo
	int *arrNotas;
	int indice;

	//asignar memoria
	//un arreglo de 5 elementos
	arrNotas = new int[5];

	//inicializar valores del arreglo en 0;
	for (indice = 0; indice < 5; indice++)
		arrNotas[indice] = 0;

	//ingresar valores
	for (indice = 0; indice < 5; indice++)
	{
		cout << "Ingrese el elemento en la posicion " << indice << " del arreglo: ";
		cin >> arrNotas[indice];
	}

	//mostrar los elementos del arreglo
	cout << "\nLos elementos del arreglo son: " << endl;
	for (indice = 0; indice < 5;indice++)
		cout << "\narrNotas["<<indice<<"] = "<<arrNotas[indice] << endl;

	//se libera la memoria
	delete[] arrNotas;

	_getch();
    return 0;
}
