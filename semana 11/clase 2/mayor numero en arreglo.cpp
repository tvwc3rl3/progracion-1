// ConsoleApplication8.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <time.h>

using namespace System;
using namespace std;

const int MAXELEMENTOS = 100;
const int FINRANGO = 200;

int main()
{
	//declarando el arreglo
	int *arrNumeros;
	int *numElementos = new int;
	int *indice = new int;
	int *mayorElemento = new int;
	//asignarle memoria
	arrNumeros = new int[MAXELEMENTOS];

	int *sumaElementos = new int;

	//consultado el numero de elementos que tendra el arreglo
	while (1)
	{
		cout << "Ingrese el numero de elementos del arreglo: ";
		cin >> *numElementos;
		if (*numElementos > 0 && *numElementos <= 100)
			break;
	}
	//generamos una semilla
	srand(time(NULL));

	//generamos los valores aleatorios

	for (*indice = 0; *indice < *numElementos; (*indice)++)
		//generar numeros en el intervalo [1, finrango, -1] = 1,199
		arrNumeros[*indice] = rand() % FINRANGO + 1;

	//mostrar los valores del arreglo
	cout << "\nLos elementos del arreglo son: " << endl;
	for (*indice = 0; *indice < *numElementos; (*indice)++)
		cout << "arrNumeros [" << *indice << "] = " << arrNumeros[*indice] << endl;
	//suma los elementos del arreglo
	*sumaElementos = 0;
	for (*indice = 0; *indice < *numElementos; (*indice)++)
		*sumaElementos = *sumaElementos + arrNumeros[*indice];

	cout << "La suma de los elementos del arreglo es: " << *sumaElementos << endl;

	//Hallar el mayor valor del arreglo
	//inicializo mi variable mayor con el primer elemento del arreglo
	*mayorElemento = arrNumeros[0];
	for (*indice = 0; *indice < *numElementos; (*indice)++) {
		if (arrNumeros[*indice] > *mayorElemento)
			*mayorElemento = arrNumeros[*indice];
	}
	cout << "El mayor numero del arreglo es: " << *mayorElemento << endl;

	//libera memoria
	delete[] arrNumeros;

	_getch();
	return 0;
}
