#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <time.h>

using namespace System;
using namespace std;

const int FINRANGO = 40;
const int FINPANTALLA = 79;

void GenerarNumeros(int *numero1, int *numero2, int *numero3, int *numero4) {
	//generamos una semilla
	srand(time(NULL));
	//permite generar numeros en el intervalo de 1 , 40
	*numero1 = rand() % FINRANGO + 1;
	while (1)
	{
		*numero2 = rand() % FINRANGO + 1;
		if (*numero2 != *numero1)
			break;
	}
	while (1)
	{
		*numero3 = rand() % FINRANGO + 1;
		if (*numero3 != *numero2 && *numero3 != *numero1)
			break;
	}
	while (1)
	{
		*numero4 = rand() % FINRANGO + 1;
		if (*numero4 != *numero3 && *numero4 != *numero2 && *numero4 != *numero1)
			break;
	}
}

int HallarMayor(int *numero1, int *numero2, int *numero3, int *numero4) {
	int *mayor = new int;
	*mayor = 0;
	if (*numero1 > *numero2 && *numero1 > *numero3 && *numero1 > *numero4)
		*mayor = *numero1;
	else
		if (*numero2 > *numero1 && *numero2 > *numero3 && *numero2 > *numero4)
			*mayor = *numero2;
		else
			if (*numero3 > *numero2 && *numero3 > *numero1 && *numero3 > *numero4)
				*mayor = *numero3;
			else
				*mayor = *numero4;
}

int HallarMenor(int *numero1, int *numero2, int *numero3, int *numero4) {
	int menor = 0;
	if (*numero1 < *numero2 && *numero1 < *numero3 && *numero1 < *numero4)
		menor = *numero1;
	else
		if (*numero2 < *numero1 && *numero2 < *numero3 && *numero2 < *numero4)
			menor = *numero2;
		else
			if (*numero3 < *numero2 && *numero3 < *numero1 && *numero3 < *numero4)
				menor = *numero3;
			else
				menor = *numero4;
}

int HallarAnteriorMayor(int *numero1, int *numero2, int *numero3, int *numero4, int *numeroOrd1, int *numeroOrd4) {
	int anterior = 0;
	// *numeroOrd1 es el mayor
	// *numeroOrd2 es el menor
	if (*numero1 == *numeroOrd1)//cuando el 1 es el mayor 
		if (*numero2 == *numeroOrd4) // 2 es el menor
			if (*numero3 > *numero4)
				anterior = 
}

void Graficar(int *numeroOrd1, int *numeroOrd2, int *numeroOrd3, int *numeroOrd4) {

}
int main()
{
	int *numero1 = new int;
	int *numero2 = new int;
	int *numero3 = new int;
	int *numero4 = new int;

	int *numeroOrd1 = new int; // el numero mayor
	int *numeroOrd2 = new int;
	int *numeroOrd3 = new int;
	int *numeroOrd4 = new int;// el numero menor

	GenerarNumeros(numero1, numero2, numero3, numero4);

	*numeroOrd1 = HallarMayor(numero1, numero2, numero3, numero4);
	*numeroOrd2 = HallarMenor(numero1, numero2, numero3, numero4);
	*numeroOrd3 = HallarAnteriorMayor(numero1, numero2, numero3, numero4, numeroOrd1, numeroOrd4);
	*numeroOrd4	= Graficar(numeroOrd1, numeroOrd2, numeroOrd3, numeroOrd4);
	

	//liberamos memoria
	delete numero1;
	numero1 = NULL;
	
	_getch();
	return 0;
}
