#include "stdafx.h"
#include <conio.h>
#include <iostream>

using namespace System;
using namespace std;



int main()
{

	char *opcion = new char;
	int *elfactorial = new int;
	int *numero = new int;
	int *k = new int;
	int *numRombo = new int;
	float *elexponencial = new float;
	float *a = new float;
	
	cout << "\t\t\t" << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << endl;
	cout << "\t\t\t" "MENU PRINCIPAL" << endl;
	cout << "\t\t\t" << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << endl;
	cout << "\t\tA. Sumar 2 Números Complejos." << endl;
	cout << "\t\tB. Restar 2 Números Complejos." << endl;
	cout << "\t\tX. Salir del Programa" << endl;
	
	switch (switch_on)
	{
	case 1:
		break;
	case 2:
		break;
	default:
		break;
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
