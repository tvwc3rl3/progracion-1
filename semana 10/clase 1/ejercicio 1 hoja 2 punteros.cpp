// ConsoleApplication1.cpp : main project file.

#include "stdafx.h"
#include <conio.h>
#include <iostream>

using namespace System;
using namespace std;


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
