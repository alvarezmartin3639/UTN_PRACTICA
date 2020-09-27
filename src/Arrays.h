/*
 * Arrays.h
 *
 *  Created on: 24 sep. 2020
 *      Author: kenyn
 */

#ifndef ARRAYS_H_
#define ARRAYS_H_

void inicializarArray(int[], int, int);

int buscarLibre(int [], int , int );

void CargarAleatoriamenteUnArray(int[], int);

void CargarAleatoriamenteUnArrayCadena(char[][55], int);

void CargarSecuencialmenteUnArrayEntero(int[], int);

void CargarSecuencialmenteUnArrayCadena(char[][55], int);

void ModificarUnaEntidadArray();

void EliminarUnaEntidadArray();

void MostrarTodosLosEnterosDeUnArray(int[], int);

void MostrarTodosLosCharsDeUnArray(char[], int);

void MostrarTodosLosFloatsDeUnArray(float[], int);

int ContarNumerosMayoresaCincoDeUnArray(int[], int);

int ContarIndiceOcupadoDeUnArray(int[], int);

void OrdenarEnteroDeMenoraMayor(int[], int);

void OrdenarArrayParaleloPorNombre(int [], int [], int [], float [], char [][20], int [], int , int );

int SacarMinimoDeUnArray(int [],int );

int SacarMaximoDeUnArray(int [],int );

int SacarCantidadDeParesDeUnArray(int[], int);

int SacarAcumuladorDeUnArray(int[], int);

float SacarPromedioDeUnArray(int[], int);

#endif /* ARRAYS_H_ */
