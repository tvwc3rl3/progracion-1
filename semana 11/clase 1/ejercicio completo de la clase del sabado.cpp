// Grafico.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <time.h>

using namespace System;
using namespace std;

const int FINRANGO = 40;
const int FINPANTALLA = 79;

void GenerarNumeros(int *numero1, int *numero2, int *numero3, int *numero4)
{
	//Generamos una semilla
	srand(time(NULL));
	//PERMITE GENERAR NuMEROS EN EL INTERVALO 1, 40
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

int HallarMayor(int *numero1, int *numero2, int *numero3, int *numero4)
{
	int *mayor = new int;
	*mayor = 0;

	if (*numero1 > *numero2 && *numero1 > *numero3 && *numero1 > *numero4)
		*mayor = *numero1;
	else
		if (*numero2 > *numero1 && *numero2 > *numero3 && *numero2 > *numero4)
			*mayor = *numero2;
		else
			if (*numero3 > *numero1 && *numero3 > *numero2 && *numero3 > *numero4)
				*mayor = *numero3;
			else
				*mayor = *numero4;
	return *mayor;
}

int  HallarMenor(int *numero1, int *numero2, int *numero3, int *numero4)
{
	int menor = 0;

	if (*numero1 < *numero2 && *numero1 < *numero3 && *numero1 < *numero4)
		menor = *numero1;
	else
		if (*numero2 < *numero1 && *numero2 < *numero3 && *numero2 < *numero4)
			menor = *numero2;
		else
			if (*numero3 < *numero1 && *numero3 < *numero2 && *numero3 < *numero4)
				menor = *numero3;
			else
				menor = *numero4;

	return menor;
}

int HallarAnteriorMayor(int *numero1, int *numero2, int *numero3, int *numero4,
	int *numeroOrd1, int *numeroOrd4)
{
	int anterior = 0;
	// *numeroOrd1 es el mayor
	// *numeroOrd4 es el menor
	if (*numero1 == *numeroOrd1) //Cuando el 1 es el mayor
		if (*numero2 == *numeroOrd4) //2 es el menor
			if (*numero3 > *numero4)
				anterior = *numero3;
			else
				anterior = *numero4;
		else
			if (*numero3 == *numeroOrd4) // 3 es el menor
				if (*numero2 > *numero4)
					anterior = *numero2;
				else
					anterior = *numero4;
			else //4 es el menor
				if (*numero2 > *numero3)
					anterior = *numero2;
				else
					anterior = *numero3;
	else
		if (*numero2 == *numeroOrd1) //Cuando el 2 es el mayor
			if (*numero1 == *numeroOrd4) //1 es el menor
				if (*numero3 > *numero4)
					anterior = *numero3;
				else
					anterior = *numero4;
			else
				if (*numero3 == *numeroOrd4) // 3 es el menor
					if (*numero1 > *numero4)
						anterior = *numero1;
					else
						anterior = *numero4;
				else //4 es el menor
					if (*numero1 > *numero3)
						anterior = *numero1;
					else
						anterior = *numero3;
		else
			if (*numero3 == *numeroOrd1) //Cuando el 3 es el mayor
				if (*numero1 == *numeroOrd4) //1 es el menor
					if (*numero2 > *numero4)
						anterior = *numero2;
					else
						anterior = *numero4;
				else
					if (*numero2 == *numeroOrd4) // 2 es el menor
						if (*numero1 > *numero4)
							anterior = *numero1;
						else
							anterior = *numero4;
					else //4 es el menor
						if (*numero1 > *numero2)
							anterior = *numero1;
						else
							anterior = *numero2;
			else //Cuando el 4 es el mayor
				if (*numero1 == *numeroOrd4) //1 es el menor
					if (*numero2 > *numero3)
						anterior = *numero2;
					else
						anterior = *numero3;
				else
					if (*numero2 == *numeroOrd4) // 2 es el menor
						if (*numero1 > *numero3)
							anterior = *numero1;
						else
							anterior = *numero3;
					else //3 es el menor
						if (*numero1 > *numero2)
							anterior = *numero1;
						else
							anterior = *numero2;
	return anterior;
}

void Graficar(int *numeroOrd1, int *numeroOrd2, int *numeroOrd3, int * numeroOrd4)
{
	int columna;

	Console::Clear();

	if (*numeroOrd4 < 10)
		Console::SetCursorPosition(FINPANTALLA- *numeroOrd4, 2);
	else 
		Console::SetCursorPosition(FINPANTALLA - (*numeroOrd4 + 1), 2);
	cout << *numeroOrd4;
	for (columna = 1; columna <= *numeroOrd4; columna++)
		cout << "*";

	if (*numeroOrd3 < 10)
		Console::SetCursorPosition(FINPANTALLA - *numeroOrd3, 3);
	else 
		Console::SetCursorPosition(FINPANTALLA - (*numeroOrd3 + 1), 3);
	cout << *numeroOrd3;
	for (columna = 1; columna <= *numeroOrd3; columna++)
		cout << "*";

	if (*numeroOrd2 < 10)
	Console::SetCursorPosition(FINPANTALLA - *numeroOrd2, 4);
	else
		Console::SetCursorPosition(FINPANTALLA - (*numeroOrd2 + 1), 4);
	cout << *numeroOrd2;
	for (columna = 1; columna <= *numeroOrd2; columna++)
		cout << "*";

	if (*numeroOrd1 < 10)
	Console::SetCursorPosition(FINPANTALLA - *numeroOrd1, 5);
	else
		Console::SetCursorPosition(FINPANTALLA - (*numeroOrd1 + 1), 5);
	cout << *numeroOrd1;
	for (columna = 1; columna <= *numeroOrd1; columna++)
		cout << "*";

}



int main()
{
	int *numero1 = new int;
	int *numero2 = new int;
	int *numero3 = new int;
	int *numero4 = new int;

	int *numeroOrd1 = new int;  //el numero mayor
	int *numeroOrd2 = new int;
	int *numeroOrd3 = new int;
	int *numeroOrd4 = new int;  //el numero menor

	GenerarNumeros(numero1, numero2, numero3, numero4);
	cout << *numero1 << " " << *numero2 << " " << *numero3 << " " << *numero4;
	*numeroOrd1 = HallarMayor(numero1, numero2, numero3, numero4);
	*numeroOrd4 = HallarMenor(numero1, numero2, numero3, numero4);
	*numeroOrd2 = HallarAnteriorMayor(numero1, numero2, numero3, numero4, numeroOrd1, numeroOrd4);
	*numeroOrd3 = (*numero1 + *numero2 + *numero3 + *numero4) - *numeroOrd1 - *numeroOrd4 - *numeroOrd2;
	Graficar(numeroOrd1, numeroOrd2, numeroOrd3, numeroOrd4);
	_getch();
	return 0;
}
