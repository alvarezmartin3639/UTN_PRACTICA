/*
 * Validaciones.h
 *
 *  Created on: 19 sep. 2020
 *      Author: kenyn
 */

#ifndef VALIDACIONES_H_
#include "Estructura.h"
#define VALIDACIONES_H_


int GetChar(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos);

int GetFloat(float *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos);

int GetInt(int *, char *, char *, int ,
		int , int );

#endif /* VALIDACIONES_H_ */
