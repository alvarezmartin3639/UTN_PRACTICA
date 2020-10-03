/*
 ============================================================================
 Name        : ClaseOcho.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

#include "Cliente.h"
#include "FuncionesGenerales.h"
#include "Mascota.h"

int main(void) {

	SolucionErrorDeConsola();

	int opcionElegida;
	int opcionElegidaSubMenu;
	eMascota mascotas[TMASCOTAS];
	eCliente clientes[TCLIENTES];

	InicializarMascota(mascotas, TMASCOTAS, LIBRE);
	InicializarCliente(clientes,TCLIENTES,LIBRE);

	HardcodeoMascota(mascotas, TMASCOTAS);
	HardcodeoCliente(clientes,TCLIENTES);


	//AsociarMascotaConCliente(&auxmascota,clientes,TCLIENTES);
	//ModificarMascota(mascotas,TMASCOTAS,clientes,TCLIENTES,OCUPADO,LIBRE);

/*

	do {
		opcionElegida = MostrarMenu();
		switch (opcionElegida) {
		case 1:
			CargarEstructuraMenu(clientes, TCLIENTES);
			break;

		case 2:
			MostrarEstructuraMenu(clientes, TCLIENTES);
			break;

		case 3:

			opcionElegidaSubMenu = OrdenarEstructuraSubMenu();
			switch (opcionElegidaSubMenu) {
			case 1:
				OrdenarEstructuraPorLegajoAscDespuesPorNombreAscSubMenu(
						clientes, TCLIENTES);
				break;
			case 2:
				OrdenarEstructuraPorSueldoSubMenu(clientes, TCLIENTES);
				break;
			}

			break;

		case 4:
			EliminarEstructuraMenu(clientes, TCLIENTES, OCUPADO);
			break;

		case 5:
			ModificarEstructuraMenu(clientes, TCLIENTES, OCUPADO, LIBRE);
			break;

		default:
			printf("\n****OPCION NO VALIDA...****\n");
			break;
		}
	} while (opcionElegida != 6);

	*/
}
