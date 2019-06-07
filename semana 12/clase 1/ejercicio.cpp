// ConsoleApplication4.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <time.h>

using namespace System;
using namespace std;

//La estructura tiene como alias "Persona" y tiene 2 miembros: edad y sexo

typedef struct {
	int edad;
	char sexo;
} Persona;

int main()
{
	//creamos un arreglo de la estructura persona
	Persona *arrPersona;
	arrPersona = new Persona[5];

	int *indice = new int;
	//Ingresar los datos a cada elemnto del arreglo
	for (*indice = 0; *indice < 5; (*indice)++)
	{
		cout << "Ingrese la edad del elemento " << *indice + 1 << " : ";
		cin >> arrPersona[*indice].edad;
		cout << "Ingrese el sexo: " << *indice + 1 << " : ";
		cin >> arrPersona[*indice].sexo;
	}
	//mostrar los datos
	for (*indice = 0; *indice < 5; (*indice)++) {
		cout << "arrPersonas [" << *indice + 1 << "] . edad =" << arrPersona[*indice].edad << endl;
		cout << "arrPersonas [" << *indice + 1 << "] . sexo =" << arrPersona[*indice].sexo << endl;
	}
	_getch();
	return 0;
}
