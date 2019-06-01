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
	int *menorElemento = new int;
	//asignarle memoria
	arrNumeros = new int[MAXELEMENTOS];
	//busqueda de un elemento 
	bool *encontrado = new bool;
	int *valorBuscado = new int;

	//indices de bucle de ordenamiento

	int *indice1 = new int;
	int *indice2 = new int;
	int *numAux = new int;
	
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

	//hallar el menor elemento del arreglo
	*mayorElemento = arrNumeros[0];
	for (*indice = 0; *indice < *numElementos; (*indice)++) {
		if (arrNumeros[*indice] < *menorElemento)
			*menorElemento = arrNumeros[*indice];
	}

	//Buscar un elemento en el arreglo

	// Ingresar un valor a buscar
	cout << "Ingrese un elemento a buscar: ";
	cin >> *valorBuscado;
	*encontrado = false;
	*indice = 0;
	while ((*indice <*numElementos) && (*encontrado == false))
	{
		if (arrNumeros[*indice] == *valorBuscado) {
			*encontrado = true;
		}
		(*indice)++;
	}

	if (*encontrado)
		cout << "Se encontro el elemento en la posicion: " << *indice - 1;
	else
		cout << "no se encontro el elemento";

	//ordenamiento
	for ( (*indice1) = 0; *indice1 < (*numElementos - 1); (*indice1)++)
	{
		for (*indice2 = *indice1 + 1; *indice2 < *numElementos; (*indice2)++)
		{
			if (arrNumeros[*indice2] < arrNumeros[*indice1]) {
				*numAux = arrNumeros[*indice1];
				arrNumeros[*indice1] = arrNumeros[*indice2];
				arrNumeros[*indice2] = *numAux;
			}
		}
	}
	//mostrar los valores del arreglo
	cout << "\nLos elementos del arreglo son: " << endl;
	for (*indice = 0; *indice < *numElementos; (*indice)++)
		cout << "arrNumeros [" << *indice << "] = " << arrNumeros[*indice] << endl;

	//libera memoria
	delete[] arrNumeros;

	_getch();
	return 0;
}
