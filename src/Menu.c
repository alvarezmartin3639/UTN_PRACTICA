/*
 * Menu.c
 *
 *  Created on: 19 sep. 2020
 *      Author: kenyn
 */

#include "Menu.h"

#include <stdio.h>

#include "ClienteMascota.h"
#include "FuncionesGenerales.h"

/*
 * \brief
 * \return
 *
 */
int MostrarMenu() {
	int opcion;

	LimpiarPantalla();
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
	LimpiarPantalla();
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
void CargarEstructuraMenu(eCliente array[], int tam) {


	LimpiarPantalla();

	printf("--------============== CARGAR ESTRUCTURA ==============--------");

		AltaDeCliente(array, tam);

}
/*
 * \brief
 * \return
 *
 */
void MostrarEstructuraMenu(eCliente array[], int tam) {

	LimpiarPantalla();
	printf("--------============== MOSTRAR LISTADO DE MASCOTA ==============--------");
	MostrarListadoDeCliente(array, tam, OCUPADO);

}
/*
 * \brief
 * \return
 *
 */
void OrdenarEstructuraPorLegajoAscDespuesPorNombreAscSubMenu(
		eCliente array[], int tam) {
	LimpiarPantalla();
	printf("--------============== ORDENAR ESTRUCTURA POR NOMBRE ==============--------");
	OrdenarStringAscenIntAscenUnCliente(array,tam);

}
/*
 * \brief
 * \return
 *
 */
void OrdenarEstructuraPorSueldoSubMenu(eCliente array[], int tam) {
	LimpiarPantalla();
	printf("--------============== ORDENAR ESTRUCTURA POR SUELDO ==============--------");
	OrdenarPorFloatAscUnCliente(array, tam);

}
/*
 * \brief
 * \return
 *
 */

void EliminarEstructuraMenu(eCliente arrayClientes[], int tamClientes, eMascota arrayMascotas[], int tamMascotas, int valorOcupado) {
	LimpiarPantalla();
	printf("--------============== ELIMINAR ESTRUCTURA ==============--------");
	BajaDeCliente(arrayClientes, tamClientes,arrayMascotas,tamMascotas,valorOcupado);
}

/*
 * \brief
 * \return
 *
 */

void ModificarEstructuraMenu(eCliente array[], int tam, int valorOcupado,
		int valorLibre) {

	LimpiarPantalla();
	printf("--------============== MODIFICAR ESTRUCTURA ==============--------");
	ModificarCliente(array, tam, valorOcupado, valorLibre);

}

/*
 * \brief
 * \return
 *
 */

int ModificarClienteSubMenu() {
	int opcionElegida;

	printf("\n\n\n¿Que desea modificar?"
			"\n\n1. Información cargada en nombre."
			"\n2. Información cargada en peso."
			"\n3. Información cargada en edad."
			"\n4. Guardar y salir.");

	printf("\n\nElije una opcion: ");
	scanf("%d", &opcionElegida);

	return opcionElegida;

}


/*
 * \brief
 * \return
 *
 */

int ModificarMascotaSubMenu() {
	int opcionElegida;

	printf("\n\n\n¿Que desea modificar?"
			"\n\n1. Información cargada en nombre."
			"\n2. Información cargada en sueldo."
			"\n3. Información cargada en edad."
			"\n4. Informacion cargada en dueño de mascota."
			"\n5. Guardar y salir.");

	printf("\n\nElije una opcion: ");
	scanf("%d", &opcionElegida);

	return opcionElegida;

}



