/*
 * Auxiliares.c
 *
 *  Created on: 26 sep. 2020
 *      Author: kenyn
 */

#include <stdio.h>
#include <string.h>

#include "Estructura.h"
#include "Validaciones.h"

/*
 * \brief
 * \return
 *
 */

int cargarAuxiliares(char auxNombre[], float *auxPrecio, int *auxStock) {

	int retorno = ERROR;

	GetChar(auxNombre, "\nIngrese un nombre: ", "Error!!", 'a', 'z', 2);

	GetFloat(auxPrecio, "\nIngrese un precio: ", "Error precio invalido.",
			1, 100000, 2);

	GetInt(auxStock, "\nIngrese una edad: ", "Error edad invalido", 0,
			100, 2);

	return retorno;
}

/*
 * \brief
 * \return
 *
 */
void mostrarAuxiliares(char nombre[], float precio, int stock) {

	printf("NOMBRE  PRECIO  STOCK");

	printf("\n %-10s   %-10.3f  %-10.d", nombre, precio, stock);
}

/*
 * \brief
 * \return
 *
 */

int RemplazarAuxiliaresyCrearUnaEstructura(eEstructura list[],
		int indiceParaRemplazar, char auxNombre[], int auxEdad, float auxSueldo,
		int valorOcupado) {
	int retorno = 1;

	list[indiceParaRemplazar].edad = auxEdad;
	list[indiceParaRemplazar].estado = valorOcupado;
	list[indiceParaRemplazar].legajo = generateEstructuraID();
	list[indiceParaRemplazar].sueldo = auxSueldo;
	strcpy(list[indiceParaRemplazar].nombre, auxNombre);

	return retorno;
}

/*
 * \brief
 * \return
 *
 */
eEstructura guardarAuxDeProductoEnVariables(char auxNombre[], float auxPrecio,
		int valorOcupado) {

	eEstructura listadoDeProductos;

	listadoDeProductos.legajo = generateEstructuraID();
	strcpy(listadoDeProductos.nombre, auxNombre);
	listadoDeProductos.sueldo = auxPrecio;
	listadoDeProductos.estado = valorOcupado;

	return listadoDeProductos;
}

