/*
 * FuncionesGenerales.h
 *
 *  Created on: 22 sep. 2020
 *      Author: kenyn
 */

#ifndef FUNCIONESGENERALES_H_
#define FUNCIONESGENERALES_H_

int elejirEntreDosOpciones(char mensaje[], char condicionParaContinuar[],
		char condicionParaSalir[]);

int elejirEntreDosOpcionesConPuntero(char *pResultado, char *mensaje,
		char opcionUno[], char opcionDos[]);

//void textAndSleep(char *mensaje, int sleepTime);

void SolucionErrorDeConsola();

void limpiarPantalla();

int confirmacionDeCambios();

int ContarCaracteresDeUnEntero();

int ContarCaracteresDeUnFlotante(float num);

#endif /* FUNCIONESGENERALES_H_ */
