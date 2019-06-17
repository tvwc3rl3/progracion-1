// ConsoleApplication6.cpp : main project file.

#include "stdafx.h"
#include <conio.h>
#include <iostream>

using namespace System;
using namespace std;

const int FILAS = 4;
const int COLUMNAS = 5;

void IngrearValores(int **matriz) {
	for (int indice1 = 0; indice1 < FILAS; indice1++)
	{
		for (int indice2 = 0; indice2 < COLUMNAS; indice2++)
		{
			cout << "Ingrese voto mesa [" << indice1 + 1 << "]Candidato[" << indice2 + 1 << "]";
			cin >> matriz[indice1][indice2];
		}
	}
}
void MostrarValores(int **matriz) {
	cout.width(38);
	cout << "Candidatos " << endl;
	//Colocamos la cabecera de la tabla Mesa 1 2 3 4 5
	for (int indice = 0; indice < 6; indice++) {
		if (indice == 0) {
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
	for (int indice1 = 0; indice1 < FILAS; indice1++) {
		cout.width(8);
		cout << indice1 + 1;
		for (int indice2 = 0; indice2 < COLUMNAS; indice2++) {
			cout.width(8);
			cout << matriz[indice1][indice2];
		}
		cout << endl;
	}
}
void CalcularTotalVotosYPorcCand(int **matriz, int *votos, float *porcentaje) {
	int suma, sumaTotalVotos;
	for (int indice2 = 0; indice2 < FILAS; indice2++) {
		suma = 0;
		for (int indice1 = 0; indice1 < COLUMNAS; indice1++) {
			suma = suma + matriz[indice1][indice2];
		}
		votos[indice2] = suma;
	}
	//calcular el total de los votos
	sumaTotalVotos = 0;
	for (int indice = 0; indice < COLUMNAS; indice++)
	{
		sumaTotalVotos = sumaTotalVotos + votos[indice];
	}
	//calculando los porcentajes por candidato
	for (int indice = 0; indice < COLUMNAS; indice++)
	{
		porcentaje[indice] = 100.0 * votos[indice] / sumaTotalVotos;
	}
}
int DeterminarCandidatoMayor(int *votos) {

}
int ImprimirCandidatos(float *porcentaje) {

}


int main()
{
	int **matriz, *votos, mayorCand;
	float *porcentaje;
	

	//asignamos memoria
	matriz = new int *[FILAS];
	for (int indice = 0; indice < FILAS; indice++)
	{
		matriz[indice] = new int[COLUMNAS];
	}
	votos = new int [COLUMNAS];
	porcentaje = new float [COLUMNAS];

	IngrearValores(matriz);
	MostrarValores(matriz);
	CalcularTotalVotosYPorcCand(matriz, votos, porcentaje);
	mayorCand = DeterminarCandidatoMayor(votos);
	ImprimirCandidatos(porcentaje);
	
	cout << "El candidacto mas votado fue el candidato: " << mayorCand << endl;

	//eliminamos memoria
	delete[] votos;
	delete[] porcentaje;
	for (int indice = 0; indice < FILAS; indice++)
		delete[] matriz[indice];
	delete[] matriz;
	_getch();
    return 0;
}
