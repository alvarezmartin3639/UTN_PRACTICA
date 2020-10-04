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
#include "ClienteMascota.h"
#include "FuncionesGenerales.h"
#include "Mascota.h"
#include "Menu.h"

int main(void) {

	SolucionErrorDeConsola();

	int opcionElegida;
	int opcionElegidaSubMenu;
	eMascota mascotas[TMASCOTAS];
	eCliente clientes[TCLIENTES];

	InicializarMascota(mascotas, TMASCOTAS, LIBRE);
	InicializarCliente(clientes, TCLIENTES, LIBRE);

	HardcodeoMascota(mascotas, TMASCOTAS);
	HardcodeoCliente(clientes, TCLIENTES);

	ClienteConMasMascota(clientes, TCLIENTES, mascotas, TMASCOTAS);

	do {
		opcionElegida = MostrarMenu();
		switch (opcionElegida) {
		case 1:
			CargarClienteMenu(clientes, TCLIENTES);
			break;

		case 2:
			MostrarClienteMenu(clientes, TCLIENTES);
			break;

		case 3:

			opcionElegidaSubMenu = OrdenarClienteSubMenu();
			switch (opcionElegidaSubMenu) {
			case 1:
				OrdenarClientePorLegajoyPorNombreSubMenu(clientes, TCLIENTES);
				break;
			case 2:
				OrdenarClientePorSueldoSubMenu(clientes, TCLIENTES);
				break;
			}

			break;

		case 4:
			EliminarClienteMenu(clientes, TCLIENTES, mascotas, TMASCOTAS,
			OCUPADO);
			break;

		case 5:
			ModificarClienteMenu(clientes, TCLIENTES, OCUPADO, LIBRE);
			break;

		case 6:
			CargarMascotaMenu(clientes, TCLIENTES, mascotas, TMASCOTAS);
			break;
		case 7:
			ModificarMascotaMenu(clientes, TCLIENTES, mascotas, TMASCOTAS,
			OCUPADO, LIBRE);
			break;
		case 8:
			BajaDeMascota(mascotas, TMASCOTAS, OCUPADO);
			break;

		case 9:
			MostrarMascotasConSuClienteMenu(clientes, TCLIENTES, mascotas,
					TMASCOTAS);
			break;

		case 10:
			MostrarClienteConSusMascotasMenu(clientes, TCLIENTES, mascotas,
					TMASCOTAS);
			break;

		default:
			printf("\n****OPCION NO VALIDA...****\n");
			break;
		}
	} while (opcionElegida != 11);
}
