/*
 * Menu.c
 *
 *  Created on: 19 sep. 2020
 *      Author: kenyn
 */

#include "Menu.h"

#include <stdio.h>

#include "FuncionesGenerales.h"
#include "Validaciones.h"
/*
 * \brief
 * \return
 *
 */
int MostrarMenu() {
	int opcion;

	limpiarPantalla();
	printf("\n--------------------------------------------------------------"
			"\n|                       MENU PRINCIPAL                       |"
			"\n--------------------------------------------------------------");
	printf("\n[1] Cargar estructura.");
	printf("\n[2] Mostrar listado de estructura.");
	printf("\n[3] Ordenar estructura ");
	printf("\n[4] Eliminar estructura.");
	printf("\n[5] Modificar estructura. ");
	printf("\n[6] Salir."
			"\n-------------------------------------------------------------");

	printf("\n\nElije una opcion: ");
	scanf("%d", &opcion);

	return opcion;
}
/*
 * \brief
 * \return
 *
 */
int OrdenarEstructuraSubMenu() {
	int opcion;
	limpiarPantalla();
	printf("=======================ORDENAR EMPLEADOS=======================");

	printf("\n1- Ordenar estructura por nombre");
	printf("\n2- Ordenar estructura por legajo");
	printf("\n\nElije una opcion: ");
	scanf("%d", &opcion);

	return opcion;
}
/*
 * \brief
 * \return
 *
 */
void CargarEstructuraMenu(eEstructura array[], int tam) {

	int cantidadDeCargas;
	int i;

	limpiarPantalla();
	/*printf(
			"\n---------------------------------------------------------------"
					"\n|                       CARGAR ESTRUCTURA                     |"
					"\n---------------------------------------------------------------");
*/
	printf("--------============== CARGAR ESTRUCTURA ==============--------");

		CargarEstructura(array, tam);

}
/*
 * \brief
 * \return
 *
 */
void MostrarEstructuraMenu(eEstructura array[], int tam) {

	limpiarPantalla();
	printf("--------============== MOSTRAR ESTRUCTURA ==============--------");
	MostrarListadoDeEstructura(array, tam, OCUPADO);

}
/*
 * \brief
 * \return
 *
 */
void OrdenarEstructuraPorLegajoAscDespuesPorNombreAscSubMenu(
		eEstructura array[], int tam) {
	limpiarPantalla();
	printf("--------============== ORDENAR ESTRUCTURA POR NOMBRE ==============--------");
	OrdenarEstructuraPorStringAscAndIntAsc(array, tam);

}
/*
 * \brief
 * \return
 *
 */
void OrdenarEstructuraPorSueldoSubMenu(eEstructura array[], int tam) {
	limpiarPantalla();
	printf("--------============== ORDENAR ESTRUCTURA POR SUELDO ==============--------");
	OrdenarEstructuraPorFloatAsc(array, tam);

}
/*
 * \brief
 * \return
 *
 */

void EliminarEstructuraMenu(eEstructura array[], int tam, int valorOcupado) {
	limpiarPantalla();
	printf("--------============== ELIMINAR ESTRUCTURA ==============--------");
	EliminarEstructura(array, tam, valorOcupado);
}

/*
 * \brief
 * \return
 *
 */

void ModificarEstructuraMenu(eEstructura array[], int tam, int valorOcupado,
		int valorLibre) {

	limpiarPantalla();
	printf("--------============== MODIFICAR ESTRUCTURA ==============--------");
	ModificarEstructura(array, tam, valorOcupado, valorLibre);

}

/*
 * \brief
 * \return
 *
 */

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
