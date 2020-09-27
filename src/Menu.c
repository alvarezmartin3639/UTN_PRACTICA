
/*
 * Menu.c
 *
 *  Created on: 19 sep. 2020
 *      Author: kenyn
 */

#include "Menu.h"

#include <stdio.h>

#include "FuncionesGenerales.h"

int MostrarMenu() {
	int opcion;

	limpiarPantalla();
	printf("\n--------------------------------------------------------------"
		   "\n|                       MENU PRINCIPAL                       |"
		   "\n--------------------------------------------------------------");
	printf("\n1- Cargar estructura.");
	printf("\n2- Mostrar listado de estructura.");
	printf("\n3- Ordenar estructura ");
	printf("\n4- Eliminar estructura.");
	printf("\n5- Modificar estructura. ");
	printf("\n6- Salir."
			"\n--------------------------------------------------------------");

	printf("\n\nElije una opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

int OrdenarEstructuraSubMenu() {
	int opcion;
	limpiarPantalla();
	printf("\n--------------------------------------------------------------"
		   "\n|                      ORDENAR EMPELADOS                     |"
		   "\n--------------------------------------------------------------");

	printf("\n1- Ordenar estructura por nombre");
	printf("\n2- Ordenar estructura por legajo");
	printf("\n\nElije una opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

void CargarEstructuraMenu(eEstructura array[], int tam) {
	limpiarPantalla();
	printf("\n---------------------------------------------------------------"
		   "\n|                       CARGAR ESTRUCTURA                     |"
		   "\n---------------------------------------------------------------");

	CargarEstructura(array, tam);

}

void MostrarEstructuraMenu(eEstructura array[], int tam) {
	limpiarPantalla();
	printf("\n--------------------------------------------------------------"
		   "\n|                       MOSTRAR ESTRUCTURA                   |"
		   "\n--------------------------------------------------------------");
	MostrarListadoDeEstructura(array, tam, OCUPADO);

}

void OrdenarEstructuraPorLegajoAscDespuesPorNombreAscSubMenu(eEstructura array[], int tam) {
	limpiarPantalla();
	printf("\n--------------------------------------------------------------"
		   "\n|             ORDENAR ESTRUCTURA POR NOMBRE                  |"
		   "\n--------------------------------------------------------------");
	OrdenarEstructuraPorStringAscAndIntAsc(array, tam);

}
void OrdenarEstructuraPorSueldoSubMenu(eEstructura array[], int tam) {
	limpiarPantalla();
	printf("\n--------------------------------------------------------------"
		   "\n|             ORDENAR ESTRUCTURA POR SUELDO                  |"
		   "\n--------------------------------------------------------------");
	OrdenarEstructuraPorFloatAsc(array, tam);

}

void EliminarEstructuraMenu(eEstructura array[], int tam, int valorOcupado) {
	limpiarPantalla();
	printf("\n--------------------------------------------------------------"
		   "\n|                    ELIMINAR ESTRUCTURA                     |"
		   "\n--------------------------------------------------------------");
	EliminarEstructura(array, tam,valorOcupado);
}

void ModificarEstructuraMenu(eEstructura array[], int tam, int valorOcupado,int valorLibre) {
	limpiarPantalla();
	printf("\n--------------------------------------------------------------"
		   "\n|                    MODIFICAR ESTRUCTURA                    |"
		   "\n--------------------------------------------------------------");
	ModificarEstructura(array, tam,valorOcupado,valorLibre);
}

int ModificarEstructuraSubMenu() {
	int opcionElegida;

	printf("\n\n\n¿Que desea modificar?"
			"\n\n1. Información cargada en nombre."
			"\n2. Información cargada en sueldo."
			"\n3. Información cargada en edad."
			"\n4. Información cargada en estado."
			"\n5. Guardar y salir.");

	scanf("%d", &opcionElegida);

	return opcionElegida;

}
