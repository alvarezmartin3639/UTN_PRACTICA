/*
 * EstructuraMuchos.c
 *
 *  Created on: 30 sep. 2020
 *      Author: kenyn
 */

#include "Cliente.h"

#include <stdio.h>
#include <string.h>

#include "FuncionesGenerales.h"
#include "Mascota.h"
#include "Menu.h"
#include "Validaciones.h"

/*
 * \brief
 * \return
 *
 */

void HardcodeoCliente(eCliente array[], int tam) {

	char nombre[TCLIENTES][50] = { "Hernesto", "Jose", "Susana", "Roberto",
			"Pepe", "Hernan", "Isabell", "Martin" };
	float sueldo[TCLIENTES] = { 30223200, 243.2, 222.5, 211, 444, 222.4, 2.3,
			3.1 };
	int edad[TCLIENTES] = { 18, 22, 21, 33, 11, 44, 55, 66 };
	int cantMascotasAsociadas[TCLIENTES] = { 0, 0, 0, 0, 0, 0, 0, 0 };

	int idCliente[TCLIENTES] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int estado[TCLIENTES] = { LIBRE, OCUPADO, OCUPADO, OCUPADO, OCUPADO,
	OCUPADO,
	OCUPADO, OCUPADO };

	int i;
	for (i = 0; i < tam; i++) {
		array[i].idCliente = idCliente[i];
		array[i].estado = estado[i];
		strcpy(array[i].nombre, nombre[i]);
		array[i].sueldo = sueldo[i];
		array[i].edad = edad[i];
		array[i].cantMascotasAsociadas = cantMascotasAsociadas[i];
	}
}

/*
 * \brief
 * \return
 *
 */

int AltaDeCliente(eCliente array[], int tam) {

	eCliente auxEstructura;
	int indiceDelEspacioLibre;
	int retorno = ERROR;
	char deseaContinuar = 'y';

	do {
		LimpiarPantalla();
		printf(
				"--------============== CARGAR ESTRUCTURA ==============--------");

		indiceDelEspacioLibre = BuscarEstadoDeCliente(array, tam, LIBRE);
		if (indiceDelEspacioLibre != ERROR) {

			CrearAuxiliaresDeCliente(&auxEstructura);
			MostrarUnUnicoCliente(auxEstructura, OCUPADO);

			if (ConfirmacionDeCambios() == OPCIONUNO) {
				RemplazarAuxiliaresyCrearUnCliente(array, auxEstructura,
						indiceDelEspacioLibre,
						OCUPADO);

				if (ElejirEntreDosOpciones(
						"\nDeseas continuar ingresando datos?(y/n): ", "y",
						"n")==NOACEPTO) {

					deseaContinuar = 'n';
					retorno = OK;
					return retorno;
				}

			}
		} else {
			printf("***Error, no hay espacio****");
			PresionarEnterParaContinuar();

			return retorno;
		}
	} while (deseaContinuar == 'y');

	retorno = OK;
	return retorno;
}

/*
 * \brief
 * \return
 *
 */

int CrearAuxiliaresDeCliente(eCliente *auxEstructura) {

	GetChar(auxEstructura->nombre, "\nIngrese un nombre: ", "Error!!", 'a', 'z',
			2);
	GetFloat(&auxEstructura->sueldo, "\nIngrese un precio: ",
			"Error precio invalido.", 1, 100000, 2);
	GetInt(&auxEstructura->edad, "\nIngrese una edad: ", "Error edad invalido",
			0, 100, 2);
	auxEstructura->idCliente = 0;
	auxEstructura->estado = OCUPADO;
	return 0;
}

/*
 * \brief
 * \return
 *
 */

int RemplazarAuxiliaresyCrearUnCliente(eCliente list[], eCliente auxEstructura,
		int indiceParaRemplazar, int valorOcupado) {

	int retorno = 1;

	list[indiceParaRemplazar].edad = auxEstructura.edad;
	list[indiceParaRemplazar].estado = valorOcupado;
	list[indiceParaRemplazar].idCliente = GenerarIdDeMascota();
	list[indiceParaRemplazar].sueldo = auxEstructura.sueldo;
	strcpy(list[indiceParaRemplazar].nombre, auxEstructura.nombre);

	return retorno;
}

/*
 * \brief
 * \return
 *
 */

int BuscarEstadoDeCliente(eCliente array[], int tam, int valorLibre) {

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
void CabezeraMostrarCliente() {

	printf("%-13s %-20s %-5s %-14s %-10s", "ID CLIENTE", "NOMBRE", "EDAD",
			"SUELDO", "ESTADO");
}

/*
 * \brief
 * \return
 *
 */

int MostrarListadoDeCliente(eCliente array[], int tam, int valorOcupado) {
	int i;
	int contadorCantidadDeEstadoOcupados;
	int retorno = ERROR;

	CabezeraMostrarCliente();

	for (i = 0; i < tam; i++) {
		contadorCantidadDeEstadoOcupados = MostrarClienteMedianteIndice(array,
				i, valorOcupado);
	}

	if (contadorCantidadDeEstadoOcupados == ERROR) {
		printf("****Error entidad no encontrada****");
	}
	return retorno;
}

/*
 * \brief
 * \return
 *
 */

int MostrarClienteMedianteIndice(eCliente array[], int indiceDeLaEstructura,
		int valorOcupado) {

	int retorno = ERROR;

	if (array[indiceDeLaEstructura].estado
			== valorOcupado|| valorOcupado==INDIFERENTE) {

		printf("\n%-13d %-20s %-5d %-14.2f %-10d",
				array[indiceDeLaEstructura].idCliente,
				array[indiceDeLaEstructura].nombre,
				array[indiceDeLaEstructura].edad,
				array[indiceDeLaEstructura].sueldo,
				array[indiceDeLaEstructura].estado);

		retorno = OK;
	}

	return retorno;
}

/*
 * \brief
 * \return
 *
 */

int MostrarUnUnicoCliente(eCliente array, int valorOcupado) {

	if (array.estado == valorOcupado || valorOcupado == INDIFERENTE) {

		CabezeraMostrarCliente();
		printf("\n %-13d %-20s %-5d %-14.2f %-10d", array.idCliente,
				array.nombre, array.edad, array.sueldo, array.estado);
	}

	return OK;
}

/*
 * \brief
 * \return
 *
 */

int InicializarCliente(eCliente array[], int tam, int valorLibre) {
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

int OrdenarStringAscenIntAscenUnCliente(eCliente array[], int tam) {
	int i;
	int j;
	eCliente auxEstructura;

	for (i = 0; i < tam - 1; i++) {
		for (j = i + 1; j < tam; j++) {
			if (strcmp(array[i].nombre, array[j].nombre) > 0) {
				auxEstructura = array[i];
				array[i] = array[j];
				array[j] = auxEstructura;
			} else {
				if (strcmp(array[i].nombre, array[j].nombre) == 0) {
					if (array[i].idCliente > array[j].idCliente) {
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

int OrdenarPorFloatAscUnCliente(eCliente array[], int tam) {
	int i;
	int j;
	eCliente auxEstructura;

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

int ModificarCliente(eCliente arrayEstructura[], int tamEstructura,
		int valorOcupado, int valorLibre) {

	int retorno = ERROR;
	int valorBuscado;
	int indiceEncontrado;
	int opcionElegidaMenu;
	char auxEstado[55];

	GetInt(&valorBuscado, "\nIngrese el ID a modificar: \n", "ID INVALIDO!!!",
			1, 6666, 2);

	indiceEncontrado = BuscarIdDeCliente(arrayEstructura, tamEstructura,
			valorBuscado, OCUPADO);

	if (indiceEncontrado != ERROR) {

		do {

			LimpiarPantalla();
			printf("\n======ID %d ENCONTRADO======", valorBuscado);
			MostrarClienteMedianteIndice(arrayEstructura, indiceEncontrado,
					valorOcupado);
			opcionElegidaMenu = ModificarClienteSubMenu();

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

				if (ConfirmacionDeCambios() == ACEPTO) {
					arrayEstructura[indiceEncontrado].estado = OCUPADO;
				}

				break;
			}
		} while (opcionElegidaMenu != 5);

	} else {

		printf("\n****EXITO!!****");
		PresionarEnterParaContinuar();

		retorno = OK;
		return retorno;
	}
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

int BuscarIdDeCliente(eCliente estructura[], int tamEstructura,
		int valorBuscado, int valorEstadoParaBuscar) {

	int i;
	int retorno = ERROR;

	for (i = 0; i < tamEstructura; i++) {
		if ((estructura[i].estado == valorEstadoParaBuscar
				|| valorEstadoParaBuscar == -1)
				&& estructura[i].idCliente == valorBuscado) {
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
int GenerarIdDeCliente() {
	static int generarIdDeCliente = 0;
	generarIdDeCliente++;
	return generarIdDeCliente;
}


int BuscarElMaximoDeMascotasEnCliente(eCliente arrayClientes[], int tamClientes, int valorEstado) {

	int i;
	int maxInt;
	int indiceMaximo=ERROR;

	for (i = 0; i < tamClientes; i++) {
		if ((arrayClientes[i].cantMascotasAsociadas > maxInt && arrayClientes[i].estado==valorEstado ) || (valorEstado ==INDIFERENTE || i == 0)) {
			maxInt = arrayClientes[i].cantMascotasAsociadas;
			indiceMaximo=i;
		}
	}

	return indiceMaximo;
}

int BuscarElIntMaximoEnCliente(eCliente arrayClientes[], int tamClientes, int valorEstado) {

	int i;
	int maxInt;
	int indiceMaximo=ERROR;

	for (i = 0; i < tamClientes; i++) {
		if ((arrayClientes[i].cantMascotasAsociadas > maxInt && arrayClientes[i].estado==valorEstado ) || (valorEstado ==INDIFERENTE || i == 0)) {
			maxInt = arrayClientes[i].cantMascotasAsociadas;
			indiceMaximo=i;
		}
	}

	return indiceMaximo;
}

// ESTO SE PUEDE MEJORAR, PUEDO HACER QUE DETECTE SOLO SI ES FLOAT O INT
int BuscarElFloatMaximoEnCliente(eCliente arrayClientes[], int tamClientes, int valorEstado) {

	int i;
	float maxFloat;
	int indiceMaximo=ERROR;

	for (i = 0; i < tamClientes; i++) {
		if ((arrayClientes[i].sueldo > maxFloat && arrayClientes[i].estado==valorEstado ) || (valorEstado ==INDIFERENTE || i == 0)) {
			maxFloat = arrayClientes[i].sueldo;
			indiceMaximo=i;
		}
	}

	return indiceMaximo;
}

float AcumularNumeroDeCliente(eCliente arrayClientes[], int tamClientes) {

	float acumulador;
	int i;
	acumulador = 0;

	for (i = 0; i < tamClientes; i++) {

		if (arrayClientes[i].estado == OCUPADO) {
			acumulador = arrayClientes[i].sueldo + acumulador;

		}
	}

	return acumulador;
}

float PromediarNumeroDeCliente(eCliente arrayClientes[], int tamClientes) {

	float numeroAcumulado;
	int contadorDeEstadosOcupados;

	//ACUMULO NUM
	numeroAcumulado = AcumularNumeroDeCliente(arrayClientes, tamClientes);
	//BUSCO LA CANTIDAD DE OCUPADOS
	contadorDeEstadosOcupados = ContarEstadoDeCliente(arrayClientes,
			tamClientes, OCUPADO);

	//PROMEDIO
	numeroAcumulado = (float) numeroAcumulado / contadorDeEstadosOcupados;
	return numeroAcumulado;
}

int ContarEstadoDeCliente(eCliente arrayClientes[], int tamClientes,
		int valorDeEstado) {

	int i;
	int contadorEstados;

	contadorEstados = 0;

	for (i = 0; i < tamClientes; i++) {
		if (arrayClientes[i].estado == valorDeEstado) {
			contadorEstados++;

		}
	}

	return contadorEstados;

}

int ContarNumeroMayorEnCliente(eCliente arrayClientes[], int tamClientes,
		int valorParaContar) {

	int i;
	int contador;

	contador = 0;

	for (i = 0; i < tamClientes; i++) {

		if (arrayClientes[i].edad
				> valorParaContar&& arrayClientes[i].estado==OCUPADO) {
			contador++;
		}
	}

	return contador;
}
