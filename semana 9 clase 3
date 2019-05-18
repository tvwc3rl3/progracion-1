// ConsoleApplication1.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>

using namespace System;
using namespace std;

int HallarNumeroInvertido(int *numero) {
	int *digito = new int;
	int *nuevoNumero = new int;

	*nuevoNumero = 0;
	while (*numero > 0)
	{
		*digito = *numero % 10;
		*nuevoNumero = *nuevoNumero * 10 + *digito;
		*numero = *numero / 10;
	}
	return *nuevoNumero;
}

int main()
{
	//El tipo de dato int puede tener hasta 10 cifras
	//El tipo de dato long long puede tenner hasta 19 cifras
	int *numero = new int;
	int *numeroInvertido = new int;
	int *cantCifras = new int;

	while (1)
	{
		cout << "Ingrese un numero: ";
		cin >> *numero;
		if (*numero > 999)
			break;
	}
	*numeroInvertido = HallarNumeroInvertido(numero);
	cout << "El numero de cifras es: " << *numeroInvertido;
    _getch();
    return 0;
}
