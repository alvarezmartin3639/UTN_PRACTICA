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

#include "Estructura.h"
#include "FuncionesGenerales.h"
#include "Menu.h"
#include "Validaciones.h"

int main(void) {

	SolucionErrorDeConsola();

	int opcionElegida;
	int opcionElegidaSubMenu;
	eEstructura estructura[TEMPLEADOS];

	InicializarEstructura(estructura, TEMPLEADOS, LIBRE);


	HardcodeoEstructura(estructura, TEMPLEADOS);


	CargarEstructuraMenu(estructura, TEMPLEADOS);
/*
	do {
		opcionElegida = MostrarMenu();
		switch (opcionElegida) {
		case 1:
			CargarEstructuraMenu(estructura, TEMPLEADOS);
			break;

		case 2:
			MostrarEstructuraMenu(estructura, TEMPLEADOS);
			break;

		case 3:

			opcionElegidaSubMenu = OrdenarEstructuraSubMenu();
			switch (opcionElegidaSubMenu) {
			case 1:
				OrdenarEstructuraPorLegajoAscDespuesPorNombreAscSubMenu(estructura, TEMPLEADOS);
				break;
			case 2:
				OrdenarEstructuraPorSueldoSubMenu(estructura, TEMPLEADOS);
				break;
			}

			break;

		case 4:
			EliminarEstructuraMenu(estructura, TEMPLEADOS,OCUPADO);
			break;

		case 5:
			ModificarEstructuraMenu(estructura, TEMPLEADOS,OCUPADO,LIBRE);
			break;

		default:
			printf("\nOPCION NO VALIDA...\n");
			break;
		}
	} while (opcionElegida != 6)
	*/
}
