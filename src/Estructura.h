/*
 * Empleado.h
 *
 *  Created on: 19 sep. 2020
 *      Author: kenyn
 */

#ifndef ESTRUCTURA_H_
#define ESTRUCTURA_H_

#define TEMPLEADOS 8
#define OK 1
#define ACEPTO 1
#define NOACEPTO 0
#define OPCIONUNO 1
#define OPCIONDOS 0
#define LIBRE 1
#define BAD 0
#define OCUPADO 0
#define ERROR -1

typedef struct {

	char nombre[50];
	float sueldo;
	int estado;
	int legajo;
	int edad;

} eEstructura;

void HardcodeoEstructura(eEstructura[], int);

int CargarEstructura(eEstructura[], int);

int BuscarEstadoLibreEstructura(eEstructura[], int, int);

int MostrarListadoDeEstructura(eEstructura[], int, int);

int MostrarUnaEstructura(eEstructura [], int , int );

int InicializarEstructura(eEstructura[], int, int);

int OrdenarEstructuraPorStringAscAndIntAsc(eEstructura[], int);

int OrdenarEstructuraPorFloatAsc(eEstructura[], int);

int EliminarEstructura(eEstructura [], int , int );

int BuscarEstructuraPorID(eEstructura[], int, int);

int ModificarEstructura(eEstructura [], int , int , int );

int buscarIdDeUnaEstructura(eEstructura [], int ,
		int );

int generateEstructuraID();



#endif /* ESTRUCTURA_H_ */
