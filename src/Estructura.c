/*
 * Estructura.c
 *
 *  Created on: 19 sep. 2020
 *      Author: kenyn
 */

#include "Estructura.h"

#include <stdio.h>
#include <string.h>

#include "Auxiliares.h"
#include "FuncionesGenerales.h"
#include "Menu.h"
#include "Validaciones.h"

/*
 * \brief
 * \return
 *
 */

void HardcodeoEstructura(eEstructura array[], int tam) {
	int legajo[8] = { 1012222, 101, 100, 101, 102, 103, 99, 93 };
	int estado[8] = { OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO,
	OCUPADO, OCUPADO };
	char nombre[8][50] = { "C", "B", "A", "A", "R", "D", "A", "A" };
	float sueldo[8] = { 30223200, 243.2, 2004, 2001, 2001, 2002, 2002.3, 2002.1 };
	int edad[8] = { 18, 22, 21, 33, 11, 44, 55, 66 };

	int i;
	for (i = 0; i < tam; i++) {
		array[i].legajo = legajo[i];
		array[i].estado = estado[i];
		strcpy(array[i].nombre, nombre[i]);
		array[i].sueldo = sueldo[i];
		array[i].edad = edad[i];
	}
}

/*
 * \brief
 * \return
 *
 */

int CargarEstructura(eEstructura array[], int tam) {

	int indiceDelEspacioLibre;
	int retorno = ERROR;
	char auxNombre[33];
	int auxEdad;
	float auxPrecio;

	indiceDelEspacioLibre = BuscarEstadoLibreEstructura(array, tam, LIBRE);
	if (indiceDelEspacioLibre != ERROR) {

		cargarAuxiliares(auxNombre, &auxPrecio, &auxEdad);
		mostrarAuxiliares(auxNombre, auxPrecio, auxEdad);

		if (confirmacionDeCambios() == OPCIONUNO) {
			RemplazarAuxiliaresyCrearUnaEstructura(array, indiceDelEspacioLibre,
					auxNombre, auxEdad, auxPrecio, OCUPADO);
		}
	} else {
		elejirEntreDosOpciones(
				"\n\n****No hay espacio libre, presione 'ENTER' para volver al menú****",
				"", "");
	}

	return retorno;
}

/*
 * \brief
 * \return
 *
 */

int BuscarEstadoLibreEstructura(eEstructura array[], int tam, int valorLibre) {

	int i;
	int indice = ERROR;
	for (i = 0; i < tam; i++) {
		if (array[i].estado == valorLibre) {
			indice = i;
			break;
		}
	}
	return indice;
}

/*
 * \brief
 * \return
 *
 */

int MostrarListadoDeEstructura(eEstructura array[], int tam, int valorOcupado) {
	int i;
	int contadorCantidadDeEstadoOcupados;

	for (i = 0; i < tam; i++) {

		contadorCantidadDeEstadoOcupados = MostrarUnaEstructura(array, i,
				valorOcupado);

	}
	if (contadorCantidadDeEstadoOcupados == 0) {
		printf("\n--------------------------------------------------------"
				"\n|Error: no existen datos cargados,cargelos Y reintente.|"
				"\n--------------------------------------------------------");
	}

	elejirEntreDosOpciones("\n\n****Presione 'enter' para continuar****", "",
			"NOENTER");

	return OK;

}



/*
 * \brief
 * \return
 *
 */

int MostrarUnaEstructura(eEstructura array[], int indiceDeLaEstructura,
		int valorOcupado) {
	int contadorCantidadDeEstadoOcupados;

	contadorCantidadDeEstadoOcupados = 0;

	if (array[indiceDeLaEstructura].estado == valorOcupado) {
		printf("\n\n\n========ESTRUCTURA %d========", indiceDeLaEstructura);
		printf("\n--------------------------------------------------------"
				"\n|LEGAJO        NOMBRE               SUELDO       ESTADO|"
				"\n--------------------------------------------------------");
		printf("\n %-14d %-16s %-14.2f %-10d \n\n", array[indiceDeLaEstructura].legajo,
				array[indiceDeLaEstructura].nombre,
				array[indiceDeLaEstructura].sueldo,array[indiceDeLaEstructura].estado);

		contadorCantidadDeEstadoOcupados++;
	}
	return contadorCantidadDeEstadoOcupados;
}

/*
 * \brief
 * \return
 *
 */

int InicializarEstructura(eEstructura array[], int tam, int valorLibre) {
	int i;

	for (i = 0; i < tam; i++) {
		array[i].estado = LIBRE;
	}
	return OK;
}

/*
 * \brief
 * \return
 *
 */

int OrdenarEstructuraPorStringAscAndIntAsc(eEstructura array[], int tam) {
	int i;
	int j;
	eEstructura auxEstructura;

	for (i = 0; i < tam - 1; i++) {
		for (j = i + 1; j < tam; j++) {
			if (strcmp(array[i].nombre, array[j].nombre) > 0) {
				auxEstructura = array[i];
				array[i] = array[j];
				array[j] = auxEstructura;
			} else {
				if (strcmp(array[i].nombre, array[j].nombre) == 0) {
					if (array[i].legajo > array[j].legajo) {
						auxEstructura = array[i];
						array[i] = array[j];
						array[j] = auxEstructura;
					}
				}
			}

		}
	}

	return OK;
}

/*
 * \brief
 * \return
 *
 */

int OrdenarEstructuraPorFloatAsc(eEstructura array[], int tam) {
	int i;
	int j;
	eEstructura auxEstructura;

	for (i = 0; i < tam - 1; i++) // rojo
			{
		for (j = i + 1; j < tam; j++) //  verde
				{

			if (array[i].sueldo > array[j].sueldo) {

				auxEstructura = array[i];
				array[i] = array[j];
				array[j] = auxEstructura;
			}
		}
	}

	return OK;
}

/*
 * \brief
 * \return
 *
 */

int EliminarEstructura(eEstructura array[], int tam, int valorOcupado) {
	int legajoParaEliminar;
	int indiceLegajoParaEliminar;

	GetInt(&legajoParaEliminar,"Ingrese el numero de legajo a eliminar: ","Error legajo invalido ",0,200,2);

	indiceLegajoParaEliminar = BuscarEstructuraPorID(array, tam,
			legajoParaEliminar);

	if (indiceLegajoParaEliminar != ERROR) {
		MostrarUnaEstructura(array,indiceLegajoParaEliminar,valorOcupado);

		if (confirmacionDeCambios() == ACEPTO) {
			array[indiceLegajoParaEliminar].estado = LIBRE;
			printf("\n*******Se eliminó con exito*******");
		}else{
			elejirEntreDosOpciones(
							"\n\n****Legajo no borrado presione 'ENTER' para continuar.****",							"", "");
		}

	} else {
		elejirEntreDosOpciones(
				"\n\n****Legajo no encontrado presione 'ENTER' para continuar.****",
				"", "");
		return ERROR;
	}

	return OK;
}

/*
 * \brief
 * \return
 *
 */

int BuscarEstructuraPorID(eEstructura array[], int tam, int numParaBuscar) {

	int i;

	for (i = 0; i < tam; i++) {
		if (array[i].legajo == numParaBuscar) {
			printf(""
					"\n*******Estructura encontrado con exito.*******");
			return i;
		}
	}

	return ERROR;
}

/*
 * \brief
 * \return
 *
 */

int ModificarEstructura(eEstructura arrayEstructura[], int tamEstructura,
		int valorOcupado, int valorLibre) {

	int retorno = ERROR;
	int valorBuscado;
	int indiceEncontrado;
	int opcionElegidaMenu;
	char auxEstado[55];

	GetInt(&valorBuscado, "\nIngrese el ID a modificar: \n", "ID INVALIDO!!!",
			1, 6666, 2);

	indiceEncontrado = buscarIdDeUnaEstructura(arrayEstructura, tamEstructura,
			valorBuscado);

	if (indiceEncontrado != ERROR) {

		do {

			limpiarPantalla();
			printf("\n======ID %d ENCONTRADO======", valorBuscado);
			MostrarUnaEstructura(arrayEstructura, indiceEncontrado,
					valorOcupado);
			opcionElegidaMenu = ModificarEstructuraSubMenu();
			switch (opcionElegidaMenu) {
			case 1:
				GetChar(arrayEstructura[indiceEncontrado].nombre,
						"Ingrese el nombre a modificar", "Nombre invalido", 'a',
						'z', 2);
				break;

			case 2:
				GetFloat(&arrayEstructura[indiceEncontrado].sueldo,
						"Ingrese el sueldo a modificar", "sueldo invalido",
						1500, 80000, 2);
				break;

			case 3:
				GetInt(&arrayEstructura[indiceEncontrado].edad,
						"Ingrese el edad a modificar", "edad invalido", 18, 70,
						2);
				break;

			case 4:
				elejirEntreDosOpcionesConPuntero(auxEstado,
						"Ingrese 'baja' para dar de baja o 'alta' para dar de alta",
						"baja", "alta");

				if (elejirEntreDosOpcionesConPuntero(auxEstado,
						"Ingrese 'baja' para dar de baja o 'alta' para dar de alta",
						"baja", "alta") == OPCIONUNO) {

					arrayEstructura[indiceEncontrado].estado = LIBRE;
					break;

				}
				if (confirmacionDeCambios() == ACEPTO) {

					arrayEstructura[indiceEncontrado].estado = OCUPADO;

				}
				break;

			}
		} while (opcionElegidaMenu != 5);
	} else {
		elejirEntreDosOpciones(
				"****Id no encontrado!!!, presione 'ENTER' para ser redirigido al menú",
				"", "");
		return retorno;

	}
	retorno = OK;
	return retorno;

}


/**
 * \brief Busca un valor int en la variable int de una estructura.
 *
 * \param eAlumno listado[]                La estructura donde trabajar.
 * \param int tam                          El numero de arrays de la estructura.
 * \param int valorBuscado                 El int que deseamos que busque en la variable del array de estructura.
 * \return int index                       Devuelve -322 si no se encontró nada  o la posicion dentro del array donde se encontró el int
 */

int buscarIdDeUnaEstructura(eEstructura estructura[], int tamEstructura,
		int valorBuscado) {

	int i;
	int retorno = ERROR;

	for (i = 0; i < tamEstructura; i++) {
		if (estructura[i].estado == OCUPADO
				&& estructura[i].legajo == valorBuscado) {
			retorno = i;
			break;
		}
	}

	return retorno;
}

/*
 * \brief
 * \return
 *
 */
int generateEstructuraID() {
	static int generarId = 0;
	generarId++;
	return generarId;
}

