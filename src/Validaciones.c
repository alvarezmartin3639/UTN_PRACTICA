/*
 * Validaciones.c
 *
 *  Created on: 19 sep. 2020
 *      Author: kenyn
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cadenas.h"
#include "FuncionesGenerales.h"

/**
 * @brief muestra un mensaje ingresado en *mensaje, lo valida por int y si no hay errores
 * lo remplaza a la variable ingresada en el puntero *pResultado
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @param reintentos
 *
 * @return retorno
 *
 */

int GetInt(int *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos) {
	do {
		int contadorDeNumeros;
		int auxPresultado;
		int i;
		char stringNumero[40];
		int cantidadChars;
		int retorno = ERROR;

		contadorDeNumeros = 0;

		FgetsComprimido(stringNumero, mensaje, 100);
		cantidadChars = strlen(stringNumero);
		auxPresultado = atoi(stringNumero);

		for (i = 0; i < cantidadChars; i++) {
			if (auxPresultado >= minimo && auxPresultado <= maximo
					&& pResultado != NULL && mensaje != NULL
					&& mensajeError != NULL && minimo <= maximo
					&& reintentos >= 0) {
				contadorDeNumeros++;
			}
		}
		if (cantidadChars == contadorDeNumeros) {

			*pResultado = auxPresultado;

			retorno = OK;
			return retorno;

		} else {

			printf(
					"\n\n****%s, elija un numero entre %d y %d, quedan %d reintentos****\n",
					mensajeError, minimo, maximo, reintentos);
			reintentos--;
		}
	} while (reintentos >= 0);
	printf(
			"\n\n****Se acabaron los reintentos vuelva a intentarlo mas tarde.****");
	return ERROR;
}

/**
 * @brief muestra un mensaje ingresado en *mensaje, lo valida por char y si no hay errores
 * lo remplaza a la variable ingresada en el puntero *pResultado
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @param reintentos
 *
 * @return retorno
 */

int GetChar(char *pResultado, char *mensaje, char *mensajeError, char minimo,
		char maximo, int reintentos) {

	do {
		int contadorDeCharsValidados;
		int i;
		char auxPresultado[40];
		int cantidadChars;
		int retorno = ERROR;

		contadorDeCharsValidados = 0;

		FgetsComprimido(auxPresultado, mensaje, 100);
		cantidadChars = strlen(auxPresultado);

		for (i = 0; i < cantidadChars; i++) {
			if (auxPresultado[i] >= minimo && auxPresultado[i] <= maximo
					&& pResultado != NULL && mensaje != NULL
					&& mensajeError != NULL && minimo <= maximo
					&& reintentos >= 0) {

				contadorDeCharsValidados++;
			}
		}
		if (cantidadChars == contadorDeCharsValidados) {
			strcpy(pResultado, auxPresultado);
			retorno = 0;
			return retorno;
		} else {

			printf(
					"\n\n****%s, solo letras entre la '%c' a la '%c', quedan %d reintentos****\n",
					mensajeError, minimo, maximo, reintentos);
			reintentos--;
		}
	} while (reintentos >= 0);

	printf(
			"\n\n****Se acabaron los reintentos vuelva a intentarlo mas tarde.****");
	return ERROR;
}

/**
 * @brief muestra un mensaje ingresado en *mensaje, lo valida por flotante y si no hay errores
 * lo remplaza a la variable ingresada en el puntero *pResultado
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @param reintentos
 *
 * @return retorno
 */

int GetFloat(float *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos) {

	char buffer[100];
	double value;
	char *endptr;
	int retorno = ERROR;

	fgets(buffer, sizeof(buffer), stdin);

	do {
		printf("\n%s", mensaje);
		fgets(buffer, sizeof(buffer), stdin);

		if (buffer == NULL) {
			return retorno; /* Unexpected error */
		}

		value = strtod(buffer, &endptr);
		if (((*endptr == '\0') || (isspace(*endptr) != 0))
				&& (value - (int) value != 0) && minimo <= maximo
				&& reintentos >= 0) {
			*pResultado = value;

			retorno =ERROR;
			return retorno;

		} else {
			printf(
					"\n\n****%s, elija un numero decimal entre %d y %d, quedan %d reintentos****\n",
					mensajeError, minimo, maximo, reintentos);
			reintentos--;
		}

	} while (reintentos >= 0);

	printf(
			"\n\n****Se acabaron los reintentos vuelva a intentarlo mas tarde.****");
	return ERROR;

}

