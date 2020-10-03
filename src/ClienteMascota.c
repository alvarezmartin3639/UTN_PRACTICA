/*
 * ClienteMascota.c
 *
 *  Created on: 30 sep. 2020
 *      Author: kenyn
 */

#include "ClienteMascota.h"

#include <stdio.h>
#include <string.h>

#include "Menu.h"
#include "Validaciones.h"

/**
 * @brief Imprime los clientes y junto con sus mascotas con estado ocupado
 *
 * @param listaCliente
 * @param tamCliente
 * @param listaMascota
 * @param tamMascota
 *
 * @return void
 */

void MostrarClientesConSusMascotas(eCliente listaCliente[], int tamCliente,
		eMascota listaMascota[], int tamMascota) {

	int i;
	int j;
	int flagTieneAlgoAsociado;

	for (i = 0; i < tamCliente; i++) {
		printf("\n\n\n========Cliente %s========", listaCliente[i].nombre);

		CabezeraMostrarMascota();

		if (listaCliente[i].estado == OCUPADO) {

			//BANDERA ACUMULADORA PARA VER SI TIENE Y LA CANTIDAD DE ENTIDADES ASOSCIADAS
			flagTieneAlgoAsociado = 0;

			for (j = 0; j < tamMascota; j++) {
				//SE SUMA UNO SI ES ASOCIADO
				flagTieneAlgoAsociado += MostrarMascotasQueTenganCliente(
						listaCliente, tamCliente, listaMascota, tamMascota, i,
						j, INDIFERENTE);

			}
		}
		if (flagTieneAlgoAsociado == 0) {
			printf("\n****No tiene nada asociado a el.****");
		}

	}

}

/**
 * @brief imprime las mascotas que tengan clientes asociadas a ellas
 *
 * @param listaCliente
 * @param tamCliente
 * @param listaMascota
 * @param tamMascota
 * @param indiceCliente
 * @param indiceMascota
 * @param valorEstado
 *
 * @return flagTieneAlgoAsociado
 */

int MostrarMascotasQueTenganCliente(eCliente listaCliente[], int tamCliente,
		eMascota listaMascota[], int tamMascota, int indiceCliente,
		int indiceMascota, int valorEstado) {

	int flagTieneAlgoAsociado;

	flagTieneAlgoAsociado = 0;

	if (listaMascota[indiceMascota].idCliente
			== listaCliente[indiceCliente].idCliente) {
		MostrarMascotaMedianteIndice(listaMascota, indiceMascota, valorEstado);
		flagTieneAlgoAsociado++;
	}

	return flagTieneAlgoAsociado;
}

/**
 * @brief imprime las mascotas junto a sus clientes asociados
 *
 * @param listaCliente
 * @param tamCliente
 * @param listaMascota
 * @param tamMascota
 *
 * @return void
 */

void MostrarMascotasConSusClientes(eCliente listaCliente[], int tamCliente,
		eMascota listaMascota[], int tamMascota) {

	int i;
	int j;

	CabezeraMostrarMascotaConSusClientes();
	for (i = 0; i < tamMascota; i++) {
		if (listaMascota[i].estado == OCUPADO) {
			for (j = 0; j < tamCliente; j++) {
				MostrarClientesQueTenganMascotas(listaCliente, tamCliente,
						listaMascota, tamMascota, j, i, OCUPADO);
			}
		}

	}
}

/**
 * @brief imprime unicamente los clientes que tienen mascotas
 *
 * @param listaCliente
 * @param tamCliente
 * @param listaMascota
 * @param tamMascota
 * @param indiceCliente
 * @param indiceMascota
 * @param valorEstado
 *
 * @return flagTieneAlgoAsociado
 */

int MostrarClientesQueTenganMascotas(eCliente listaCliente[], int tamCliente,
		eMascota listaMascota[], int tamMascota, int indiceCliente,
		int indiceMascota, int valorEstado) {

	int flagTieneAlgoAsociado;

	flagTieneAlgoAsociado = 0;

	if (listaMascota[indiceMascota].estado == valorEstado
			&& listaMascota[indiceMascota].idCliente
					== listaCliente[indiceCliente].idCliente) {
		printf("\n%-12d %-15s %-13d %-20s %-5d %-14.2f",
				listaMascota[indiceMascota].idMascota,
				listaMascota[indiceMascota].nombre,
				listaCliente[indiceCliente].idCliente,
				listaCliente[indiceCliente].nombre,
				listaCliente[indiceCliente].edad,
				listaCliente[indiceCliente].sueldo);
		flagTieneAlgoAsociado++;
	}

	return flagTieneAlgoAsociado;
}

/**
 * @brief cabezera de el listado de clientes
 *
 * @return void
 */
void CabezeraMostrarMascotaConSusClientes() {
	printf("\n%-12s %-15s %-13s %-20s %-5s %-14s", "ID MASCOTA",
			"NOMBRE MASCOTA", "ID CLIENTE", "NOMBRE CLIENTE", "EDAD", "SUELDO");

}

/**
 * @brief da de alta una mascota
 *
 * @param listaCliente
 * @param tamCliente
 * @param listaMascota
 * @param tamMascota
 *
 * @return retorno
 */

int AltaDeMascota(eCliente listaCliente[], int tamCliente,
		eMascota listaMascota[], int tamMascota) {

	eMascota auxEstructura;
	int indiceDelEspacioLibre;
	int retorno = ERROR;
	char deseaContinuar;

	deseaContinuar='y';

	do {
		LimpiarPantalla();
		printf("--------============== CARGAR MASCOTA ==============--------");

		indiceDelEspacioLibre = BuscarEstadoDeMascota(listaMascota, tamMascota,
		LIBRE);
		if (indiceDelEspacioLibre != ERROR) {

			CrearAuxiliaresDeMascota(&auxEstructura, listaCliente, tamCliente);
			LimpiarPantalla();
			MostrarUnaUnicaMascota(auxEstructura, OCUPADO);

			if (ConfirmacionDeCambios() == OPCIONUNO) {
				RemplazarAuxiliaresyCrearMascota(listaMascota, auxEstructura,
						indiceDelEspacioLibre,
						OCUPADO);

			}
			if (ElejirEntreDosOpciones(
					"\nDeseas continuar ingresando datos?(y/n): ", "y",
					"n")==NOACEPTO) {

				retorno = OK;
				return retorno;
			}

		} else {
			printf("\n****Error, no hay espacio****");
			PresionarEnterParaContinuar();
			return retorno;
		}
	} while (deseaContinuar == 'y');

	retorno = OK;
	return retorno;
}

/**
 * @brief  crea una eMascota en un auxiliar con puntero y la asocia a un cliente
 *
 * @param auxEstructura
 * @param listaCliente
 * @param tamCliente
 *
 * @return retorno
 */

int CrearAuxiliaresDeMascota(eMascota *auxEstructura, eCliente listaCliente[],
		int tamCliente) {

	int retorno = ERROR;

	GetChar(auxEstructura->nombre, "\nIngrese un nombre: ", "Error!!", 'a', 'z',
			2);
	GetFloat(&auxEstructura->peso, "\nIngrese un peso: ",
			"Error peso invalido.", 1, 100000, 2);
	GetInt(&auxEstructura->edad, "\nIngrese una edad: ", "Error edad invalido",
			0, 100, 2);

	auxEstructura->idMascota = 0;
	retorno = AsociarMascotaConCliente(auxEstructura, listaCliente, tamCliente);
	auxEstructura->estado = OCUPADO;
	return retorno;
}

/**
 * @brief modifica una mascota mediante su id
 *
 * @param arrayMascota
 * @param tamMascota
 * @param arrayCliente
 * @param tamCliente
 * @param valorOcupado
 * @param valorLibre
 *
 * @return retorno
 */

int ModificarMascota(eMascota arrayMascota[], int tamMascota,
		eCliente arrayCliente[], int tamCliente, int valorOcupado,
		int valorLibre) {

	int retorno = ERROR;
	int valorBuscado;
	int indiceEncontradoMascota;
	int opcionElegidaMenu;
	eMascota auxMascota;

	MostrarListadoDeMascota(arrayMascota, tamMascota, OCUPADO);
	GetInt(&valorBuscado, "\nIngrese el ID a modificar: ", "ID INVALIDO!!!", 1,
			6666, 2);
//SE BUSCA EL ID DE LA MASCOTA
	indiceEncontradoMascota = BuscarIdDeMascota(arrayMascota, tamMascota,
			valorBuscado, OCUPADO);

//SI SE ENCUENTRA SE COPIA EN UN AUXILIAR
	if (indiceEncontradoMascota != ERROR) {
		auxMascota = arrayMascota[indiceEncontradoMascota];
		do {

			LimpiarPantalla();
			MostrarUnaUnicaMascota(auxMascota, OCUPADO);

			opcionElegidaMenu = ModificarMascotaSubMenu();

			switch (opcionElegidaMenu) {
			case 1:
				GetChar(auxMascota.nombre, "Ingrese el nombre a modificar: ",
						"Nombre invalido", 'a', 'z', 2);
				break;

			case 2:
				GetFloat(&auxMascota.peso, "Ingrese el peso a modificar: ",
						"peso invalido", 1500, 80000, 2);
				break;

			case 3:
				GetInt(&auxMascota.edad, "Ingrese el edad a modificar: ",
						"edad invalido", 18, 70, 2);
				break;

			case 4:
				AsociarMascotaConCliente(&auxMascota, arrayCliente, tamCliente);
				break;
			case 5:
				if (ConfirmacionDeCambios() == NOACEPTO) {
//SI NO SE VUELVE A SU ESTADO ANTERIOR.
					arrayMascota[indiceEncontradoMascota] = auxMascota;
				}
				break;

			default:
				printf("\n****OPCION NO VALIDA!!!****");
				PresionarEnterParaContinuar();
				break;

			}

		} while (opcionElegidaMenu != 5);

	} else {

		ElejirEntreDosOpciones(
				"****Id no encontrado!!!, presione 'ENTER' para ser redirigido al menú",
				"", "");

		return retorno;
	}

	retorno = OK;
	return retorno;

}

/**
 * @brief asocia una mascota con un cliente mediante su id
 *
 * @param auxEstructura
 * @param listaCliente
 * @param tamCliente
 *
 * @return retorno
 */

int AsociarMascotaConCliente(eMascota *auxEstructura, eCliente listaCliente[],
		int tamCliente) {

	int retorno = ERROR;
	int auxId;
	char condicionParaContinuar[10];

	do {
		LimpiarPantalla();
		MostrarListadoDeCliente(listaCliente, tamCliente, OCUPADO);
		//SE GUARDA EL VALOR EN UN AUXILIAR
		GetInt(&auxId, "\nIngrese el id del dueño de la mascota:",
				"Error eso no es un numero valido", 0, 1000, 2);
		if (BuscarIdDeCliente(listaCliente, tamCliente, auxId, OCUPADO) != ERROR) {
			//SE REMPLAZAN
			auxEstructura->idCliente = auxId;
			strcpy(condicionParaContinuar, "no");
			retorno = OK;

		} else {

			elejirEntreDosOpcionesConPuntero(condicionParaContinuar,
					"\n****Error no se encontró id, desea intentar otra vez?(si/no)****",
					"si", "no");
		}
		//SE LE DA LA OPORTUNIDAD DE REINGRESAR DATOS HASTA QUE ESCRIBA NO
	} while (strcmp(condicionParaContinuar, "si") == 0);

	return retorno;
}

/**
 * @brief da de baja un cliente mediante su id junto con todas las mascotas asociadas a el
 *
 * @param arrayCliente
 * @param tamCliente
 * @param arrayMascota
 * @param tamMascota
 * @param valorOcupado
 *
 * @return retorno
 */

int BajaDeCliente(eCliente arrayCliente[], int tamCliente,
		eMascota arrayMascota[], int tamMascota, int valorOcupado) {

	int IdParaEliminar;
	int indiceIdParaEliminar;
	int retorno = ERROR;

	GetInt(&IdParaEliminar, "Ingrese el numero de ID a eliminar: ",
			"Error legajo invalido ", 0, 200, 2);

	indiceIdParaEliminar = BuscarIdDeCliente(arrayCliente, tamCliente,
			IdParaEliminar,
			OCUPADO);

	if (indiceIdParaEliminar != ERROR) {
		MostrarClienteMedianteIndice(arrayCliente, indiceIdParaEliminar,
				valorOcupado);

		if (ConfirmacionDeCambios() == ACEPTO) {

			EliminarClienteJuntoSusMascotas(arrayCliente, tamCliente,
					arrayMascota, tamMascota, indiceIdParaEliminar,
					arrayCliente[indiceIdParaEliminar].idCliente, OCUPADO);

			printf("\n*******Se eliminó con exito*******");
		} else {
			ElejirEntreDosOpciones(
					"\n\n****Legajo no borrado presione 'ENTER' para continuar.****",
					"", "");
		}

	} else {
		ElejirEntreDosOpciones(
				"\n\n****Legajo no encontrado presione 'ENTER' para continuar.****",
				"", "");
		return retorno;
	}

	retorno = OK;
	return retorno;
}

/**
 * @brief elimina un cliente y a todas las mascotas asociadas a el.
 *
 * @param arrayCliente
 * @param tamCliente
 * @param arrayMascota
 * @param tamMascota
 * @param indiceDelCliente
 * @param idCliente
 * @param valorOcupado
 *
 * @return contadorMascotasEliminadas
 */

int EliminarClienteJuntoSusMascotas(eCliente arrayCliente[], int tamCliente,
		eMascota arrayMascota[], int tamMascota, int indiceDelCliente,
		int idCliente, int valorOcupado) {

	int indiceMascotaParaEliminar;
	int contadorMascotasEliminadas;

	contadorMascotasEliminadas = 0;

	arrayCliente[indiceDelCliente].estado = LIBRE;

	do {
		indiceMascotaParaEliminar = BuscarIdDeMascota(arrayMascota, tamMascota,
				idCliente, OCUPADO);

		contadorMascotasEliminadas++;
	} while (indiceMascotaParaEliminar != ERROR);

	//DEVUELVE LA CANTIDAD DE MASCOTAS E ITERACIONES.
	return contadorMascotasEliminadas;
}

/**
 * @brief cuenta cuantas mascotas tiene cada dueño, luego las guarda en una variable
 * dentro de la estructura eCliente, busca el maximo de mascotas que tiene un cliente y devuelve
 * el indice del cliente con el maximo numero de mascotas
 *
 * @param arrayCliente
 * @param tamCliente
 * @param arrayMascota
 * @param tamMascota
 *
 * @return indiceDeClienteConMasMascotas
 */

int ClienteConMasMascotas(eCliente arrayCliente[], int tamCliente,
		eMascota arrayMascota[], int tamMascota) {

	int indiceDeClienteConMasMascotas = ERROR;

	ContarMascotaRelacionadaConCliente(arrayCliente, tamCliente, arrayMascota,
			tamMascota, OCUPADO);

	indiceDeClienteConMasMascotas = BuscarElMaximoDeMascotasEnCliente(
			arrayCliente, tamCliente, OCUPADO);

	return indiceDeClienteConMasMascotas;
}

/**
 * @brief cuenta la cantidad de mascotas que tiene cada cliente y luego
 * guarda ese numero en una variable dentro de su entidad.
 *
 * @param arrayCliente
 * @param tamCliente
 * @param arrayMascota
 * @param tamMascota
 * @param valorEstado
 *
 * @return contadorDeMascotas
 */

int ContarMascotaRelacionadaConCliente(eCliente arrayCliente[], int tamCliente,
		eMascota arrayMascota[], int tamMascota, int valorEstado) {
	int i;
	int j;
	int contadorDeMascotas;

	contadorDeMascotas = 0;

	for (i = 0; i < tamCliente; i++) {

		if (arrayCliente[i].estado == valorEstado || valorEstado == -1) {

			for (j = 0; j < tamMascota; j++) {

				if (arrayCliente[i].idCliente == arrayMascota[j].idCliente) {

					contadorDeMascotas++;
				}

			}
			arrayCliente[i].cantMascotasAsociadas = contadorDeMascotas;
			contadorDeMascotas = 0;
		}
	}
	return contadorDeMascotas;
}
