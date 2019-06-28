// camino.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include  <iostream>
#include <conio.h>

using namespace System;
using namespace std;

const int MAXLONGITUD = 19;

struct SalidaBus
{
	int hora;
	int cantBuses;
};

void genera_arreglo(SalidaBus *arrSalidaBus, int *longArreglo) {
	Random objRandom;
	*longArreglo = objRandom.Next(10, 20);//la longitud debe de ser entre 10 y 20
	for (int indice = 0; indice < *longArreglo; indice++)
	{
		arrSalidaBus[indice].hora = indice + 5;
		arrSalidaBus[indice].cantBuses = objRandom.Next(5, 41);
	}
}
void imprime_arreglo(SalidaBus *arrSalidaBus, int *longArreglo) {
	cout.width(8);
	cout << "Hora" ;
	cout.width(8);
	cout << "Cantidad" << endl;
	for (int indice = 0; indice < *longArreglo; indice++) {
		cout.width(8);
		cout << arrSalidaBus[indice].hora;
		cout.width(8);
		cout << arrSalidaBus[indice].cantBuses << endl;
	}
}
void hallar_mayor_salidas(SalidaBus *arrSalidaBus, int *longArreglo) {
	int mayorCantBuses;
	mayorCantBuses = arrSalidaBus[0].cantBuses;
	for (int indice = 0; indice < *longArreglo; indice++) {
		if (arrSalidaBus[indice].cantBuses > mayorCantBuses) {
			mayorCantBuses = arrSalidaBus[indice].cantBuses;
		}
	}
	cout << "La hora u horas con mayor cantidad de salidas de los buses es: " << endl;
	cout.width(8);
	cout << "Hora";
	cout.width(8);
	cout << "Cantidad" << endl;
	for (int indice = 0; indice < *longArreglo; indice++) {
		if (arrSalidaBus[indice].cantBuses == mayorCantBuses) {
			cout.width(8);
			cout << arrSalidaBus[indice].hora;
			cout.width(8);
			cout << arrSalidaBus[indice].cantBuses << endl;
		}
	}
}
double promedio_de_salidas(SalidaBus *arrSalidaBus) {
	double suma;
	suma = 0;
	for (int indice = 0; indice < 8; indice++)
		suma = suma + arrSalidaBus[indice].cantBuses;
	return suma / 8;
}
void ordena_arreglo(SalidaBus *arrSalidaBus, int *longArreglo) {
	SalidaBus objeSalidaBus;
	for (int indice1 = 0; indice1 < *longArreglo-1; indice1++)
	{
		for (int indice2 = indice1 + 1; indice2 < *longArreglo; indice2++)
		{
			if (arrSalidaBus[indice1].cantBuses < arrSalidaBus[indice2].cantBuses ||
				(arrSalidaBus[indice1].cantBuses == arrSalidaBus[indice2].cantBuses &&
				arrSalidaBus[indice1].hora > arrSalidaBus[indice2].hora)) 
			{
				objeSalidaBus = arrSalidaBus[indice1];
				arrSalidaBus[indice1] = arrSalidaBus[indice2];
				arrSalidaBus[indice2] = objeSalidaBus;
			}
		}
	}
}

int main()
{
	SalidaBus *arrSalidaBus;
	arrSalidaBus = new SalidaBus[MAXLONGITUD];
	int *longArreglo;
	longArreglo = new int;
	double promSalidas;

	genera_arreglo(arrSalidaBus, longArreglo);
	imprime_arreglo(arrSalidaBus, longArreglo);
	hallar_mayor_salidas(arrSalidaBus, longArreglo);
	promSalidas = promedio_de_salidas(arrSalidaBus);//solo de 5 a 12
	cout << "El promedio de salidas es: " << promSalidas << endl;
	ordena_arreglo(arrSalidaBus, longArreglo);
	imprime_arreglo(arrSalidaBus, longArreglo);
	_getch();
	return 0;
}
