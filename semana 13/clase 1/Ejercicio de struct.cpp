// ConsoleApplication2.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

typedef struct {
	char tipo;
	int ancho;
	int alto;
	double tamanho;
} Imagen;

const int NUMIMAGENES = 100;

int menu() {
	int *opcion = new int;
	cout << "MENU" << endl;
	cout << "1. Agregar ficha" << endl;
	cout << "2. Ver ficha" << endl;
	cout << "3. Buscar ficha dado un tipo" << endl;
	cout << "4. Salir" << endl;
	do
	{
		cout << "Seleccione una opcion: ";
		cin >> *opcion;
	} while (*opcion < 1 || *opcion > 4);
	return *opcion;
}

void anadirFicha(Imagen *arrImagenes, int *numElementos, Imagen regImagen) {
	arrImagenes[*numElementos] = regImagen;
	(*numElementos)++;
}

void verFichas(Imagen *arrImagenes, int *numElementos) {
	cout << "Lista de fichas de imagenes: " << endl;
	for (int indice = 0; indice < *numElementos; indice++) {
		 cout << "" << indice + 1 << endl;
		 cout << "Tipo		:" << arrImagenes[indice].tipo << endl;
		 cout << "Ancho		:" << arrImagenes[indice].ancho << endl;
		 cout << "Alto		:" << arrImagenes[indice].alto << endl;
		 cout << "Tamanho	:" << arrImagenes[indice].tamanho << endl;
	}
	_getch();
}
void BuscarFichas(Imagen *arrImagenes, int *numElementos, char *tipoBuscado) {
	cout << "Lista de fichas con tipo " << *tipoBuscado << " : " << endl;
	for (int indice = 0; indice < *numElementos; indice++) {
		if (arrImagenes[indice].tipo == *tipoBuscado)
		{
			cout << "" << indice + 1 << endl;
			cout << "Tipo		:" << arrImagenes[indice].tipo << endl;
			cout << "Ancho		:" << arrImagenes[indice].ancho << endl;
			cout << "Alto		:" << arrImagenes[indice].alto << endl;
			cout << "Tamanho	:" << arrImagenes[indice].tamanho << endl; 
		}

	}
	_getch();
}

int main()
{
	Imagen *arrImagenes;
	arrImagenes = new Imagen[NUMIMAGENES];
	int *numElementos = new int;
	*numElementos = 0;
	char *tipoBuscado = new char;
	int *opcion = new int;
	Imagen regImagen;

	do
	{
		*opcion = menu();
		if (*opcion != 4)
		{
			switch (*opcion)
			{
			case 1:
				if (*numElementos < 99)
				{
					cout << "Ingrese tipo: ";
					cin >> regImagen.tipo;
					cout << "Ingrese ancho: ";
					cin >> regImagen.ancho;
					cout << "Ingrese alto: ";
					cin >> regImagen.alto;
					cout << "Ingrese tamanho: ";
					cin >> regImagen.tamanho;
					anadirFicha(arrImagenes, numElementos, regImagen);
				}
				else
				{
					cout << "Ya se tiene 100 registros";
						break;
				}
			case 2:
				verFichas(arrImagenes, numElementos);
				break;
			default:
				cout << "Ingrese tipo a buscar: ";
				cin >> *tipoBuscado;
				BuscarFichas(arrImagenes, numElementos, tipoBuscado);
				break;
			}

		}
		else
		{

		}
	} while (true);

	delete[] arrImagenes;

    _getch();
    return 0;
}
