// EJ5 (Hoja 1 Arreglos Bidimensionales).cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace System;
using namespace std;

const int FILAS = 4;
const int COLUMNAS = 5;

void IngresarValores(int **matriz)
{
	for (int indice1=0; indice1<FILAS; indice1++)
		for (int indice2 = 0; indice2 < COLUMNAS; indice2++)
		{
			cout << "Ingrese voto mesa [" << indice1 + 1 << "] Candidato [" << indice2 + 1 << "]";
			cin >> matriz[indice1][indice2];
		}
}

void MostrarValores(int **matriz)
{
	cout.width(38);
	cout << "Candidatos " << endl;
	for (int indice = 0; indice < 6; indice++)
	{
		if (indice == 0)
		{
			cout.width(8);
			cout << "Mesa";
		}
		else
		{
			cout.width(8);
			cout << indice;
		}
	}
	cout << endl;
	for (int indice1 = 0; indice1 < FILAS; indice1++)
	{
		cout.width(8);
		cout << indice1 + 1;
		for (int indice2 = 0; indice2 < COLUMNAS; indice2++)
		{
			cout.width(8);
			cout << matriz[indice1][indice2];
		}
		cout << endl;
	}

}

void CalcularVotosTotPorcentCand(int **matriz, int *votos, float *porcentaje)
{
	int suma, sumaTotalVotos;
	//calculamos la suma de votos por candidato y las asignamos al arreglo votos
	for (int indice2 = 0; indice2 < COLUMNAS; indice2++)
	{
		suma = 0;
		for (int indice1 = 0; indice1 < FILAS; indice1++)
		{
			suma += matriz[indice1][indice2];
		}
		votos[indice2] = suma;
	}

	//calcular el total de los votos
	for (int indice = 0; indice < COLUMNAS; indice++)
		sumaTotalVotos += +votos[indice];

	//calculando los porcentajes por candidato
	for (int indice = 0; indice < COLUMNAS; indice++)
		porcentaje[indice] = 100.0*votos[indice] / sumaTotalVotos;
}

int DeterminarCandidatoMayor(int *votos)
{
	int mayorCand, mayorCantVotos;
	mayorCantVotos = votos[0];
	mayorCand = 0;
	for (int indice = 1;indice < COLUMNAS;indice++)
	{
		if (votos[indice] > mayorCantVotos)
		{
			mayorCantVotos = votos[indice];
			mayorCand = indice;
		}
	}
	mayorCand++;
	return mayorCand;
}

void ImprimirCandidatos(float *porcentajes)
{
	float auxPorcVotos;
	int auxCand;
	int *arrCandidatos;
	int indice;
	//creando el arreglo con el numero de candidato
	arrCandidatos = new int[COLUMNAS];
	for (int indice = 0; indice < COLUMNAS;indice++)
		arrCandidatos[indice] = indice + 1;

	//ordenar los valores del arreglo descendentemente
	for (int indice1=0; indice1<COLUMNAS-1;indice1++)
		for (int indice2 = indice1 + 1;indice2 < COLUMNAS;indice2++)
		{
			if (porcentajes[indice2] > porcentajes[indice1])
			{
				auxPorcVotos = porcentajes[indice1];
				auxCand = arrCandidatos[indice1];
				porcentajes[indice1] = porcentajes[indice2];
				arrCandidatos[indice1] = arrCandidatos[indice2];
				porcentajes[indice2] = auxPorcVotos;
				arrCandidatos[indice2] = auxCand;
			}
		}
	if (porcentajes[0] > 50)
	{
		cout << "Gano el candidato " << arrCandidatos[0];
	}
	else
	{
		cout << "\n\nSegunda vuelta: " << endl;
		cout << "El candidato " << arrCandidatos[0] << endl;
		cout << "El candidato " << arrCandidatos[1] << endl;
	}
	delete[]arrCandidatos;
}

int main()
{
	int **matriz, *votos, mayorCand;
	float *porcentajes;

	matriz = new int *[FILAS];
	for (int indice = 0; indice < FILAS; indice++)
		matriz[indice] = new int[COLUMNAS];
	votos = new int[COLUMNAS];
	porcentajes = new float[COLUMNAS];

	IngresarValores(matriz);
	MostrarValores(matriz);
	CalcularVotosTotPorcentCand(matriz, votos, porcentajes);
	cout.width(8);
	cout << "Totales";
	for (int indice = 0; indice < COLUMNAS;indice++)
	{
		cout.width(8);
		cout << votos[indice];
	}
	mayorCand = DeterminarCandidatoMayor(votos);
	ImprimirCandidatos(porcentajes);

	cout << "El candidato mas votado fue el candidato: " << mayorCand << endl;

	//liberamos memoria
	delete[]votos;
	delete[]porcentajes;
	for (int indice = 0; indice < FILAS; indice++)
		delete[] matriz[indice];
	delete[]matriz;

	_getch();
    return 0;
}
