/*
 * Auxiliares.h
 *
 *  Created on: 26 sep. 2020
 *      Author: kenyn
 */

#ifndef AUXILIARES_H_
#define AUXILIARES_H_

#include "Estructura.h"



int cargarAuxiliares(char auxNombre[],
		float *auxPrecio, int *auxStock);

void mostrarAuxiliares(char nombre[], float precio, int stock);

int RemplazarAuxiliaresyCrearUnaEstructuraTest(eEstructura list[],
		int indiceParaRemplazar, char auxNombre[], int auxEdad, float auxSueldo,
		int valorLibre);

eEstructura guardarAuxDeProductoEnVariables(char auxNombre[], float auxPrecio,
		int valorOcupado);


#endif /* AUXILIARES_H_ */
