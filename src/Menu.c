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

/**
 * @brief muestra las opciones del menu principal y hace un scanf con la opcion elegida
 *
 * @return opcion
 */

int MostrarMenu() {
	int opcion;

	LimpiarPantalla();
	printf("\n--------------------------------------------------------------"
			"\n|                       MENU PRINCIPAL                       |"
			"\n--------------------------------------------------------------");
	printf("\n[1] Cargar cliente.");
	printf("\n[2] Mostrar listado de cliente.");
	printf("\n[3] Ordenar cliente ");
	printf("\n[4] Eliminar cliente.");
	printf("\n[5] Modificar cliente. ");
	printf("\n[6] Carga mascota. ");
	printf("\n[7] Modificar mascota. ");
	printf("\n[8] baja mascota. ");
	printf("\n[9] Salir."
			"\n-------------------------------------------------------------");

	printf("\n\nElije una opcion: ");
	scanf("%d", &opcion);

	return opcion;
}
/**
 * @brief muestra las opciones del submenu ordenar cliente y hace un scanf con la opcion elegida
 *
 * @return opcion
 */

int OrdenarClienteSubMenu() {
	int opcion;
	LimpiarPantalla();
	printf("=======================ORDENAR EMPLEADOS=======================");

	printf("\n1- Ordenar cliente por nombre");
	printf("\n2- Ordenar cliente por legajo");
	printf("\n\nElije una opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

/**
 * @brief muestra la cabezera de cargar cliente y llama a AltaDeCliente()
 *
 * @param arrayCliente
 * @param tamCliente
 *
 * @return void
 */

void CargarClienteMenu(eCliente arrayCliente[], int tamCliente) {

	LimpiarPantalla();

	printf("--------============== CARGAR CLIENTE ==============--------");

	AltaDeCliente(arrayCliente, tamCliente);

}

/**
 * @brief muestra la cabezera de cargar mascota y llama a AltaDeMascota()
 *
 * @param arrayCliente
 * @param tamCliente
 * @param arrayMascota
 * @param tamMascota
 *
 * @return void
 */

void CargarMascotaMenu(eCliente arrayCliente[], int tamCliente,
		eMascota arrayMascota[], int tamMascota) {

	LimpiarPantalla();

	printf("--------============== CARGAR MASCOTA ==============--------");

	AltaDeMascota(arrayCliente, tamCliente, arrayMascota, tamMascota);

}

/**
 * @brief muestra la cabezera de mostrar estructura y llama a MostrarListadoDeCliente
 *
 * @param arrayCliente
 * @param tamCliente
 *
 * @return void
 */

void MostrarClienteMenu(eCliente arrayCliente[], int tamCliente) {

	LimpiarPantalla();
	printf(
			"--------============== MOSTRAR LISTADO DE CLIENTE ==============--------");
	MostrarListadoDeCliente(arrayCliente, tamCliente, OCUPADO);

}

/**
 * @brief muestra la cabezera de OrdenarEstructuraPorLegajoPorNombreSubMenu  y llama a
 * OrdenarStringAscenIntAscenUnCliente
 *
 * @param arrayCliente
 * @param tamCliente
 *
 * @return void
 */

void OrdenarClientePorLegajoyPorNombreSubMenu(eCliente arrayCliente[],
		int tamCliente) {
	LimpiarPantalla();
	printf(
			"--------============== ORDENAR CLIENTE POR NOMBRE ==============--------");
	OrdenarStringAscenIntAscenUnCliente(arrayCliente, tamCliente);

}

/**
 * @brief muestra  la cabezera de OrdenarEstructuraPorSueldoSubMenu y llama a OrdenarPorFloatAscUnCliente
 *
 * @param arrayCliente
 * @param tamCliente
 *
 * @return void
 */

void OrdenarClientePorSueldoSubMenu(eCliente arrayCliente[], int tamCliente) {
	LimpiarPantalla();
	printf(
			"--------============== ORDENAR CLIENTE POR SUELDO ==============--------");
	OrdenarPorFloatAscUnCliente(arrayCliente, tamCliente);

}

/**
 * @brief muestra la cabezera de EliminarEstructuraMenu y llama a BajaDeCliente
 *
 * @param arrayCliente
 * @param tamCliente
 * @param arrayMascota
 * @param tamMascota
 * @param valorOcupado
 *
 * @return void
 */

void EliminarClienteMenu(eCliente arrayCliente[], int tamCliente,
		eMascota arrayMascota[], int tamMascota, int valorOcupado) {
	LimpiarPantalla();
	printf("--------============== ELIMINAR CLIENTE ==============--------");
	BajaDeCliente(arrayCliente, tamCliente, arrayMascota, tamMascota,
			valorOcupado);
}

/**
 * @brief muestra la cabezera de EliminarMascotaMenu y llama a BajaDeMascota
 *
 * @param arrayMascota
 * @param tamMascota
 * @param valorOcupado
 *
 * @return void
 */

void EliminarMascotaMenu(eMascota arrayMascota[], int tamMascota,
		int valorOcupado) {
	LimpiarPantalla();
	printf("--------============== ELIMINAR MASCOTA ==============--------");
	BajaDeMascota(arrayMascota, tamMascota, valorOcupado);
}

/**
 * @brief muestra la cabezera de ModificarClienteMenu y llama a ModificarCliente[]
 *
 * @param arrayCliente
 * @param tamCliente
 * @param valorOcupado
 * @param valorLibre
 *
 * @return void
 */

void ModificarClienteMenu(eCliente arrayCliente[], int tamCliente,
		int valorOcupado, int valorLibre) {

	LimpiarPantalla();
	printf("--------============== MODIFICAR CLIENTE ==============--------");
	ModificarCliente(arrayCliente, tamCliente, valorOcupado, valorLibre);

}

/**
 * @brief muestra la cabezera de ModificarMascotaMenu y llama a ModificarMascota()
 *
 * @param arrayCliente
 * @param tamCliente
 * @param arrayMascota
 * @param tamMascota
 * @param valorOcupado
 * @param valorLibre
 *
 * @return void
 */

void ModificarMascotaMenu(eCliente arrayCliente[], int tamCliente,
		eMascota arrayMascota[], int tamMascota, int valorOcupado,
		int valorLibre) {

	LimpiarPantalla();
	printf("--------============== MODIFICAR MASCOTA ==============--------");
	ModificarMascota(arrayMascota, tamMascota, arrayCliente, tamCliente,
			valorOcupado, valorLibre);
}

/**
 * @brief muestra las opciones de  ModificarClienteSubMenu y hace un scanf con la opcion elegida
 *
 * @return opcionElegida
 */

int ModificarClienteSubMenu() {
	int opcionElegida;

	printf("\n\n\n�Que desea modificar?"
			"\n\n1. Informaci�n cargada en nombre."
			"\n2. Informaci�n cargada en peso."
			"\n3. Informaci�n cargada en edad."
			"\n4. Guardar y salir.");

	printf("\n\nElije una opcion: ");
	scanf("%d", &opcionElegida);

	return opcionElegida;

}

/**
 * @brief muestra las opciones de ModificarMascotaSubMenu y hace un scanf con la opcion elegida
 *
 * @return opcionElegida
 */

int ModificarMascotaSubMenu() {
	int opcionElegida;

	printf("\n\n\n�Que desea modificar?"
			"\n\n1. Informaci�n cargada en nombre."
			"\n2. Informaci�n cargada en sueldo."
			"\n3. Informaci�n cargada en edad."
			"\n4. Informacion cargada en due�o de mascota."
			"\n5. Guardar y salir.");

	printf("\n\nElije una opcion: ");
	scanf("%d", &opcionElegida);

	return opcionElegida;

}

