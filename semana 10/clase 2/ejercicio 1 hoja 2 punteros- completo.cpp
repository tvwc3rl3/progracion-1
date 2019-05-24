#include "stdafx.h"
#include <conio.h>
#include <iostream>

using namespace System;
using namespace std;

int Factorial(int *numero) {
	int *factorial = new int;
	int *contador = new int;
	*factorial = 1;
	for (*contador = 1; *contador <= *numero; (*contador)++)
		*factorial *= *contador;

	return *factorial;
}

float Exponencial(float *a, int *k) {
	float *suma = new float;
	float *termino = new float;
	int *contador = new int;

	*suma = 1;
	for (*contador = 1; *contador <= *k; (*contador)++) {
		*termino = pow(*a, *contador) / Factorial(contador);
		*suma += *termino;
	}
	return *suma;
}

void Dibuja(int *numRombo) {
	int *fila = new int;
	int *columna = new int;
	int *cantFilas = new int;
	int *numero = new int;
	int *posX = new int;
	int *posY = new int;
	int *cantCaracteres = new int;
	int *posCursor = new int;
	Console::Clear;
	*cantFilas = (*numRombo * 2) - 1;
	*posX = 40;
	*posY = 10;
	*posCursor = 0; //manejara la posicion delcursor en el eje x
	*cantCaracteres = 1;

	for (*fila = 1; *fila <= *cantFilas; (*fila)++)
	{
		//colocamos el cursor
		Console::SetCursorPosition(*posX - *posCursor, *posY);

		//la logica
		*numero = 1;
		for (*columna = 1; *columna <= *cantCaracteres; (*columna)++) {
			if (*columna % 2 == 0)
				cout << " ";	
			else
			{
				cout << *numero;
				(*numero)++;
			}
		}
		if (*fila < *numRombo) {
			*cantCaracteres = *cantCaracteres + 4;
			*posCursor += 2;
		}
		else
		{
			*cantCaracteres -= 4;
			*posCursor -= 2;
		}

		//antes de ir a la sgte iteracion
		(*posY)++;
	}
}

int main()
{

	int *opcion = new int;
	int *elfactorial = new int;
	int *numero = new int;
	int *k = new int;
	int *numRombo = new int;
	float *elexponencial = new float;
	float *a = new float;

	while (1)
	{
		cout << "MENU PRINCIPAL" << endl;
		cout << "1) Determinar el factorial" << endl;
		cout << "2) Calcular el valor de la exponencial" << endl;
		cout << "3) Imprimir el rombo" << endl;
		cout << "4) Salir" << endl;
		while (1)
		{
			cout << "Ingrese la opcion: ";
			cin >> *opcion;
			if (*opcion == 1 || *opcion == 2 || *opcion == 3 || *opcion == 4)
				break;
		}
		if (*opcion == 4)
		{
			break;
		}
		else
		{
			if (*opcion == 1)
			{
				//solicitamos el numero para hallar el factorial
				while (1)
				{
					cout << "Ingrese un numero positivo: ";
					cin >> *numero;
					if (numero > 0) break;
				}
				*elfactorial = Factorial(numero);
				cout << "El factorial es: " << *elfactorial << endl;
			}
			else
				if (*opcion == 2) {
					cout << "Ingresar el valor de a: ";
					cin >> *a;
					while (1)
					{
						cout << "Ingrese el valor de k: ";
						cin >> *k;
						if (*k < 20) break;
					}
					*elexponencial = Exponencial(a, k);
					cout << "El exponencial es: " << *elexponencial << endl << endl;
				}
				else
				{
					while (1)
					{
						cout << "Ingrese un valor entre 1 y 10: ";
						cin >> *numRombo;
						if (*numRombo > 0 && *numRombo < 11) break;
					}
					Dibuja(numRombo);
					cout << endl << endl;
				}

		}
	}

	//liberamos memoria
	delete opcion;
	delete elfactorial;
	delete numero;
	delete k;
	delete numRombo;
	delete elexponencial;
	delete a;
	opcion = NULL;
	elfactorial = NULL;
	numero = NULL;
	k = NULL;
	numRombo = NULL;
	elexponencial = NULL;
	a = NULL;

	_getch();
	return 0;
}
