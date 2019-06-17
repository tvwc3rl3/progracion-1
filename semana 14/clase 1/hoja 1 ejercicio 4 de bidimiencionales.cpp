// ConsoleApplication6.cpp : main project file.

#include "stdafx.h"
#include <conio.h>
#include <iostream>

using namespace System;
using namespace std;

const int FILAS = 12;
const int COLUMNAS = 5;

void IngresaValoresMatriz(float **matriz) {
	for (int indice1 = 0; indice1 < FILAS; indice1++)
	{
		cout << "Ingrese ventas del mes 1: " << indice1 + 1 << endl;
		for (int indice2 = 0; indice2 < COLUMNAS; indice2++)
		{
			cout << "Agencia " << indice2 + 1 << ": ";
			cin >> matriz[indice1][indice2];
		}
	}
}

void MostrarValores(float **matriz) {
	cout << "Resumen de ventas por agencia: " << endl;
	for (int indice2 = 0; indice2 < COLUMNAS; indice2++) {
		cout << "Agencia " << indice2 + 1 << endl;
		for (int indice1 = 0; indice1 < FILAS; indice1++) {
			cout << "Mes " << indice1 + 1 << ": ";
			cout << matriz[indice1][indice2] << endl;
		}
		cout << endl;
	}
}

float CalcularVentasAgencia3(float **matriz) {
	float suma;
	suma = 0;
	for (int indice = 0; indice < FILAS; indice++)
		suma = suma + matriz[indice][2];
	return suma;
}

float CalcularPromDiciembre(float **matriz) {
	float promedio, suma;
	for (int indice = 0; indice < COLUMNAS; indice++)
		suma = suma + matriz[11][indice];
	promedio = suma / 5;
	return promedio;
}

int CalcularMayorMayo(float **matriz) {
	int agenciaMayor;
	float mayorVenta;

	mayorVenta = matriz[4][0];
	//agenciaMayor = 0;
	for (int indice = 0; indice < COLUMNAS; indice++)
	{
		if (matriz[4][indice]>mayorVenta)
		{
			mayorVenta = matriz[4][indice];
			agenciaMayor = indice;
		}
	}
	agenciaMayor++;
	return agenciaMayor;
}

void CalcularMesMenorVenta(float **matriz) {
	float sumaMes, ventaMenor;
	float *ventasMensuales;
	ventasMensuales = new float[FILAS];
	//arreglo que almacena las ventas totales por mes
	for (int indice1 = 0; indice1 < FILAS; indice1++) {
		sumaMes = 0;
		for (int indice2 = 0; indice2 < COLUMNAS; indice2++) {
			sumaMes = sumaMes + matriz[indice1][indice2];
		}
		ventasMensuales[indice1] = sumaMes;
	}

	ventaMenor = ventasMensuales[0];
	for (int indice = 0; indice < FILAS; indice++)
	{
		if (ventasMensuales[indice] < ventaMenor); {
			ventaMenor = ventasMensuales[indice];
		}
	}
	//recorremos el arreglo de ventas totales por mes para 
	//encontrar que mes tienen esa menor ventas 
	//no asumieremos que solo un mes tiene un menor valor
	cout << "Meses con menor venta: ";
	for (int indice = 0; indice < FILAS; indice++) {
		if (ventasMensuales[indice] == ventaMenor) {
			cout << "Mes " << indice++ << endl;//corregir indice++
		}
	}
}

int main()
{
	float **matriz, ventasAgencia3, promDiciembre;
	int agenciaMayorMayo, mesMenorVenta;

	//asignamos memoria
	matriz = new float *[FILAS];
	for (int indice = 0; indice < FILAS; indice++)
	{
		matriz[indice] = new float[COLUMNAS];
	}

	IngresaValoresMatriz(matriz);
	MostrarValores(matriz);
	ventasAgencia3 = CalcularVentasAgencia3(matriz);
	promDiciembre = CalcularPromDiciembre(matriz);
	agenciaMayorMayo = CalcularMayorMayo(matriz);

	 cout << "Las ventas anuales en la agencia 3 fueron: " << ventasAgencia3 << endl;
	 cout << "El promedio de ventas en diciembre fue: " << promDiciembre << endl;
	 cout << "La agencia con mayor venta en mayo fue: " << agenciaMayorMayo << endl;
	 CalcularMesMenorVenta(matriz); // identifica e imprime

	//liberar memoria
	for (int indice = 0; indice < FILAS; indice++)
		delete[] matriz[indice];
	delete[] matriz;
	_getch();
    return 0;
}

