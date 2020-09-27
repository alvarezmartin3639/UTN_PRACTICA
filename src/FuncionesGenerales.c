/*
 * FuncionesGenerales.c
 *
 *  Created on: 22 sep. 2020
 *      Author: kenyn
 */

#include "FuncionesGenerales.h"

#include <conio.h>
#include <stdio.h>
#include <string.h>

#include "Estructura.h"

/**
 * \brief Soluciona error dentro de eclipse
 *
 * \param void
 * \return void
 */

void SolucionErrorDeConsola() {

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
}

/**
 * \brief Simular una limpieza de pantalla agregando espacios en blanco.
 *
 * \param void
 * return void
 */

void limpiarPantalla() {
	printf("\n \n\n \n\n \n\n \n\n \n\n \n\n \n\n \n\n \n\n");
}

/**
 * \brief Crea una validación con dos arrays uno para continuar y otro para salir.
 *
 * \param char mensaje[]				   El mensaje para imprimir al usuario.
 * \param char condicionParaContinuar[]    La condicion para confirmar el mensaje.
 * \param char condicionParaSalir[]		   La condicion para rechazar el mensaje y salir del bucle.
 * \return -2   						   Cuando el usuario aceptó(Eligio condicionParaContinuar).
 * \return -333                            Cuando el usuario rechazó(Eligio condicionParaSalir).
 */

int elejirEntreDosOpciones(char mensaje[], char condicionParaContinuar[],
		char condicionParaSalir[]) {

	int retorno;
	char respuestaUsuario[66];

	do {
		puts(mensaje);
		fflush(stdin);
		gets(respuestaUsuario);
	} while ((strcmp(condicionParaContinuar, respuestaUsuario) != 0)
			&& (strcmp(condicionParaSalir, respuestaUsuario) != 0));

	//Si ingresó correctamente la condicion para continuar retorná 1, sinó 0(si no ingresó el de continuar, ingresó el de salir).
	if (strcmp(condicionParaContinuar, respuestaUsuario) == 0) {
		retorno = ACEPTO;
	} else {
		retorno = NOACEPTO;
	}
	return retorno;
}

int elejirEntreDosOpcionesConPuntero(char *pResultado, char *mensaje,
		char opcionUno[], char opcionDos[]) {
	int retorno = ERROR;
	char respuestaUsuario[66];

	do {
		puts(mensaje);
		fflush(stdin);
		gets(respuestaUsuario);
	} while ((strcmp(opcionUno, respuestaUsuario) != 0)
			&& (strcmp(opcionDos, respuestaUsuario) != 0));

	//Si ingresó correctamente la condicion para continuar retorná 1, sinó 0(si no ingresó el de continuar, ingresó el de salir).
	if (strcmp(opcionUno, respuestaUsuario) == 0) {
		retorno = ACEPTO;

	} else {
		retorno = NOACEPTO;
	}

	strcpy(pResultado, respuestaUsuario);

	return retorno;
}
/**
 * \brief Hace esperar al usuario tres segundos
 *
 * \param char mensaje[]				   El mensaje para imprimir al usuario.
 * \return void


void textAndSleep(char *mensaje, int sleepTime) {

	puts(mensaje);
	Sleep(sleepTime);

}
*/
/**
 * \brief Confirma los cambios
 *
 * \param void
 * \return int retorno   La respuesta del usuario.
 */

int confirmacionDeCambios() {
	int respuestaDeseaContinuar;
	int retorno;
	respuestaDeseaContinuar = elejirEntreDosOpciones(
			"\n\n-------------------------------------------------"
					"\nESTOS CAMBIOS NO SE PUEDEN DESHACER, ESTÁ SEGURO "
					"\nQUE DESEA CONTINUAR?(si/no)"
					"\n-------------------------------------------------", "si",
			"no");

	if (respuestaDeseaContinuar == ACEPTO) {

		retorno = ACEPTO;
	}
	if (respuestaDeseaContinuar == NOACEPTO) {

		limpiarPantalla();
	  elejirEntreDosOpciones("\n****Cambios no guardados, presione 'ENTER' para continuar.****","","exit");
		retorno = NOACEPTO;
	}

	return retorno;
}


int ContarCaracteresDeUnEntero() {

	int num;
	int contador;

	contador = 1;
	printf(
			"Este programa te va a decir cuantos digitos tiene un numero. Introduce uno: ");
	scanf("%d", &num);

	while (num / 10 > 0) {
		num = num / 10;
		contador++;
	}
	printf("Tiene %u caracteres", contador);
	getch();
	return contador;

}


