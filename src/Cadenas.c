/*
 * Cadenas.c
 *
 *  Created on: 19 sep. 2020
 *      Author: kenyn
 */

#include "Cadenas.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

void FgetsComprimido(char *pResultado, char *mensaje, int cantidadDeLetras) {

	printf("\n%s", mensaje);
	//puts(mensaje);
	fflush(stdin);
	fgets(pResultado, cantidadDeLetras, stdin);
	pResultado[strlen(pResultado) - 1] = '\0';

}

void ConvertirTodoMayuscula(char cadena[], int tam) {
	int i;

	for (i = 0; i < tam; i++) {
		cadena[i] = toupper(cadena[i]);
	}
}

void ConvertirTodoMinuscula(char cadena[], int tam) {
	int i;

	for (i = 0; i < tam; i++) {
		cadena[i] = tolower(cadena[i]);
	}
}

void ConvertirPrimerLetraEnMayuscula(char cadena[], int tam) {

	int i;

	ConvertirTodoMinuscula(cadena, tam);

	cadena[0] = toupper(cadena[0]);

	for (i = 0; i < tam; i++) {
		if (cadena[i] == ' ') {
			cadena[i + 1] = toupper(cadena[i + 1]);
		}
	}

}
