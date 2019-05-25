#include "stdafx.h"
#include <conio.h>
#include <iostream>

using namespace System;
using namespace std;

void Menu(char *opcion) {
	
	cout << "\t\t\t" << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << endl;
	cout << "\t\t\t" "MENU PRINCIPAL" << endl;
	cout << "\t\t\t" << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << endl;
	cout << "\t\tA. Sumar 2 Números Complejos." << endl;
	cout << "\t\tB. Restar 2 Números Complejos." << endl;
	cout << "\t\tX. Salir del Programa" << endl;
	
	switch (*opcion)
	{
	case 'A':
		break;
	case 'B':
		break;
	case 'X':
		break;
	}
}



int main()
{

	char *opcion = new char;

		
	Menu(opcion);
	cout << "Ingrese la opcion";
	cin >> *opcion;

	//liberamos memoria
	delete opcion;
	opcion = NULL;
	
	_getch();
	return 0;
}
