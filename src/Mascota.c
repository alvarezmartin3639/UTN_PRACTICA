/*
 * Estructura.c
 *
 *  Created on: 19 sep. 2020
 *      Author: kenyn
 */

#include "Mascota.h"

#include <stdio.h>
#include <string.h>

#include "FuncionesGenerales.h"
#include "Validaciones.h"

/**
 * @brief Harcodea el valor de la entidad mascota
 *
 * @param arrayMascota
 * @param tamMascota
 *
 * @return void
 */

int HardcodeoMascota(eMascota arrayMascota[], int tamMascota) {

	char nombre[TMASCOTAS][50] = { "Lucia", "Luis", "Fernanda", "Fernando",
			"Juana", "Juan", "Ludmila", "Lucero" };
	float peso[TMASCOTAS] = { 23, 10, 3, 4, 1, 5, 22.3, 11.1 };
	int edad[TMASCOTAS] = { 18, 22, 21, 33, 11, 44, 55, 66 };
	float sexo[TMASCOTAS] = { 'f', 'm', 'f', 'm', 'f', 'm', 'f', 'm' };
	int idMascota[TMASCOTAS] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int idCliente[TMASCOTAS] = { 1, 1, 1, 7, 7, 2, 1, 1 };
	int estado[TMASCOTAS] = { LIBRE, OCUPADO, OCUPADO, OCUPADO, OCUPADO,
	OCUPADO,
	OCUPADO, OCUPADO };

	int i;
	for (i = 0; i < tamMascota; i++) {
		arrayMascota[i].estado = estado[i];
		strcpy(arrayMascota[i].nombre, nombre[i]);
		arrayMascota[i].peso = peso[i];
		arrayMascota[i].edad = edad[i];
		arrayMascota[i].idMascota = idMascota[i];
		arrayMascota[i].idCliente = idCliente[i];
		arrayMascota[i].sexo = sexo[i];
	}

	return OK;
}

/**
 *@brief Remplaza los auxiliares creados  sobre la estructura pasados
 * en la mascota
 *
 * @param list
 * @param auxMascota
 * @param indiceParaRemplazar
 * @param valorOcupado
 * @return retorno
 */

int RemplazarAuxiliaresyCrearMascota(eMascota list[], eMascota auxMascota,
		int indiceParaRemplazar, int valorOcupado) {

	int retorno = 1;

	list[indiceParaRemplazar].edad = auxMascota.edad;
	list[indiceParaRemplazar].estado = valorOcupado;
	list[indiceParaRemplazar].idMascota = GenerarIdDeMascota();
	list[indiceParaRemplazar].idCliente = auxMascota.idCliente;
	list[indiceParaRemplazar].peso = auxMascota.peso;
	strcpy(list[indiceParaRemplazar].nombre, auxMascota.nombre);

	return retorno;
}

/**
 * @brief Busca el estado de una mascota
 *
 * @param arrayMascota
 * @param tamMascota
 * @param valorParaBuscar
 * @return indice
 */

int BuscarEstadoDeMascota(eMascota arrayMascota[], int tamMascota,
		int valorParaBuscar) {

	int i;
	int indice = ERROR;
	for (i = 0; i < tamMascota; i++) {
		if (arrayMascota[i].estado == valorParaBuscar) {
			indice = i;
			break;
		}
	}
	return indice;
}

/**
 * @brief muestra la cabezera de el listado eMascota.
 *
 * @return void
 */

void CabezeraMostrarMascota() {

	printf("\n%-13s %-13s %-20s %-5s %-14s %-5s %-10s", "ID MASCOTA",
			"ID CLIENTE", "NOMBRE", "EDAD", "PESO", "SEXO", "ESTADO");
}

/**
 * @brief Muestra el listado del arrayMascota estructura eMascota.
 *
 * @param arrayMascota
 * @param tamMascota
 * @param valorOcupado
 *
 * @return contadorEspaciosOcupados
 */

int MostrarListadoDeMascota(eMascota arrayMascota[], int tamMascota,
		int valorOcupado) {
	int i;
	int contadorEspaciosOcupados = ERROR;
	CabezeraMostrarMascota();

	for (i = 0; i < tamMascota; i++) {
		contadorEspaciosOcupados = MostrarMascotaMedianteIndice(arrayMascota, i,
				valorOcupado);
	}

	if (contadorEspaciosOcupados == ERROR) {
		printf("****Error entidad no encontrada****");
	}
	return contadorEspaciosOcupados;
}

/**
 * @brief Muestra una entidad eMascota dando por parametro su indice
 *
 * @param arrayMascota
 * @param indiceDeLaEstructura
 * @param valorEstado
 *
 * @return retorno
 */

int MostrarMascotaMedianteIndice(eMascota arrayMascota[], int indiceParaMostrar,
		int valorEstado) {
	int retorno;

	retorno = ERROR;

	if (arrayMascota[indiceParaMostrar].estado
			== valorEstado|| valorEstado==INDIFERENTE) {

		printf("\n%-13d %-13d %-20s %-5d %-14.2f %-5c %-10d",
				arrayMascota[indiceParaMostrar].idMascota,
				arrayMascota[indiceParaMostrar].idCliente,
				arrayMascota[indiceParaMostrar].nombre,
				arrayMascota[indiceParaMostrar].edad,
				arrayMascota[indiceParaMostrar].peso,
				arrayMascota[indiceParaMostrar].sexo,
				arrayMascota[indiceParaMostrar].estado);

		retorno = OK;
	}

	return retorno;
}

/**
 * @brief muestra una unica estructura eMascota
 *
 * @param mascota
 * @param valorOcupado
 *
 * @return 1
 */

int MostrarUnaUnicaMascota(eMascota mascota, int valorOcupado) {

	if (mascota.estado == valorOcupado || valorOcupado == INDIFERENTE) {
		CabezeraMostrarMascota();
		printf("\n%-13d %-13d %-20s %-5d %-14.2f %-5c %-10d", mascota.idMascota,
				mascota.idCliente, mascota.nombre, mascota.edad, mascota.peso,
				mascota.sexo, mascota.estado);
	}

	return OK;
}

/**
 *@brief Inicializa el estado en un arrayMascota de estructura eMascota
 *
 * @param arrayMascota
 * @param tamMascota
 * @param valorLibre
 *
 * @return 1
 */

int InicializarMascota(eMascota arrayMascota[], int tamMascota, int valorLibre) {
	int i;

	for (i = 0; i < tamMascota; i++) {
		arrayMascota[i].estado = valorLibre;
	}
	return OK;
}

/**
 *@brief Ordena un array de eMascota por abecedario de menor a mayor y
 * por numero entero de menor a mayor.
 *
 * @param arrayMascota
 * @param tamMascota
 *
 * @return 1
 */

int OrdenarStringAscenIntAscEnMascota(eMascota arrayMascota[], int tamMascota) {
	int i;
	int j;
	eMascota auxMascota;

	for (i = 0; i < tamMascota - 1; i++) {
		for (j = i + 1; j < tamMascota; j++) {
			if (strcmp(arrayMascota[i].nombre, arrayMascota[j].nombre) > 0) {
				auxMascota = arrayMascota[i];
				arrayMascota[i] = arrayMascota[j];
				arrayMascota[j] = auxMascota;
			} else {
				if (strcmp(arrayMascota[i].nombre, arrayMascota[j].nombre)
						== 0) {
					if (arrayMascota[i].idMascota > arrayMascota[j].idMascota) {
						auxMascota = arrayMascota[i];
						arrayMascota[i] = arrayMascota[j];
						arrayMascota[j] = auxMascota;
					}
				}
			}

		}
	}

	return OK;
}

/**
 *@brief Ordena un array eMascota por flotante de menor a mayor
 *
 * @param arrayMascota
 * @param tamMascota
 *
 * @return 1
 */

int OrdenarFloatAscEnMascota(eMascota arrayMascota[], int tamMascota) {
	int i;
	int j;
	eMascota auxMascota;

	for (i = 0; i < tamMascota - 1; i++) // rojo
			{
		for (j = i + 1; j < tamMascota; j++) //  verde
				{

			if (arrayMascota[i].peso > arrayMascota[j].peso) {

				auxMascota = arrayMascota[i];
				arrayMascota[i] = arrayMascota[j];
				arrayMascota[j] = auxMascota;
			}
		}
	}

	return OK;
}

/**
 *@brief Se da de baja una entidad de eMascota mediante un id
 *
 * @param arrayMascota
 * @param tamMascota
 * @param valorOcupado
 *
 * @return 1
 */

int BajaDeMascota(eMascota arrayMascota[], int tamMascota, int valorOcupado) {
	int legajoParaEliminar;
	int indiceLegajoParaEliminar;

	GetInt(&legajoParaEliminar, "Ingrese el numero de legajo a eliminar: ",
			"Error legajo invalido ", 0, 200, 2);

	indiceLegajoParaEliminar = BuscarIdDeMascota(arrayMascota, tamMascota,
			legajoParaEliminar,
			OCUPADO);

	if (indiceLegajoParaEliminar != ERROR) {

		CabezeraMostrarMascota();
		MostrarMascotaMedianteIndice(arrayMascota, indiceLegajoParaEliminar,
				valorOcupado);

		if (ConfirmacionDeCambios() == ACEPTO) {
			arrayMascota[indiceLegajoParaEliminar].estado = LIBRE;
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
		return ERROR;
	}

	return OK;
}

/**
 *@brief Busca el id de una eMascota, compara su estado con el
 * estado ingresado en la mascota.
 *
 * @param estructura
 * @param tamEstructura
 * @param valorBuscado
 * @param valorEstadoParaBuscar
 *
 * @return retorno
 */

int BuscarIdDeMascota(eMascota estructura[], int tamEstructura,
		int valorBuscado, int valorEstadoParaBuscar) {

	int i;
	int retorno = ERROR;

	for (i = 0; i < tamEstructura; i++) {
		if ((estructura[i].estado == valorEstadoParaBuscar
				|| valorEstadoParaBuscar == INDIFERENTE)
				&& estructura[i].idMascota == valorBuscado) {
			retorno = i;
			break;
		}
	}

	return retorno;

}

/**
 *@brief genera un numero autoincremental utilizado para dar
 * el id la entidad eMascota
 *
 * @return generarIdDeMascota
 */

int GenerarIdDeMascota() {
	static int generarIdDeMascota = 0;
	generarIdDeMascota++;
	return generarIdDeMascota;
}

/**
 * @brief Busca el numero maximo de un array entidad eMascota
 * y devuelve el indice con el mayor.
 *
 * @param arrayMascota
 * @param tamMascota
 * @param valorEstado
 *
 * @return indiceMaximo
 */

int BuscarElIntMaximoEnMascota(eMascota arrayMascota[], int tamMascota,
		int valorEstado) {

	int i;
	int maxInt;
	int indiceMaximo = ERROR;

	for (i = 0; i < tamMascota; i++) {
		if ((arrayMascota[i].edad > maxInt
				&& arrayMascota[i].estado == valorEstado)
				|| (valorEstado == INDIFERENTE || i == 0)) {
			maxInt = arrayMascota[i].edad;
			indiceMaximo = i;
		}
	}

	return indiceMaximo;
}

/**
 * @brief busca el flotante mayor en una variable de un array eMascota
 *
 * @param arrayMascota
 * @param tamMascota
 * @param valorEstado
 *
 * @return indiceMaximo
 */

// ESTO SE PUEDE MEJORAR, PUEDO HACER QUE DETECTE SOLO SI ES FLOAT O INT
int BuscarElFloatMaximoEnMascota(eMascota arrayMascota[], int tamMascota,
		int valorEstado) {

	int i;
	float maxFloat;
	int indiceMaximo = ERROR;

	for (i = 0; i < tamMascota; i++) {
		if ((arrayMascota[i].peso > maxFloat
				&& arrayMascota[i].estado == valorEstado)
				|| (valorEstado == INDIFERENTE || i == 0)) {
			maxFloat = arrayMascota[i].peso;
			indiceMaximo = i;
		}
	}

	return indiceMaximo;
}

/**
 * @brief acumula flotantes de una variable de un array eMascota
 *
 * @param arrayMascota
 * @param tamMascota
 *
 * @return acumulador
 */

float AcumularNumeroEnMascota(eMascota arrayMascota[], int tamMascota) {

	float acumulador;
	int i;
	acumulador = 0;

	for (i = 0; i < tamMascota; i++) {

		if (arrayMascota[i].estado == OCUPADO) {
			acumulador = arrayMascota[i].peso + acumulador;

		}
	}

	return acumulador;
}

/**
 * @brief acumula las variables de un array de eMascotas, cuenta la
 * cantidad de estados ocupados dentro de ella y saca un promedio
 *
 * @param arrayMascota
 * @param tamMascota
 *
 * @return numeroAcumulado
 */

float PromediarNumeroEnMascota(eMascota arrayMascota[], int tamMascota) {

	float numeroAcumulado;
	int contadorDeEstadosOcupados;

	//ACUMULO NUM
	numeroAcumulado = AcumularNumeroEnMascota(arrayMascota, tamMascota);
	//BUSCO LA CANTIDAD DE OCUPADOS
	contadorDeEstadosOcupados = ContarEstadoEnMascota(arrayMascota, tamMascota,
	OCUPADO);

	//PROMEDIO
	numeroAcumulado = (float) numeroAcumulado / contadorDeEstadosOcupados;
	return numeroAcumulado;
}

/**
 * @brief cuenta la cantidad de estados dependiendo lo ingresado en valorDeEstado
 * de un array eMascota
 *
 * @param arrayMascota
 * @param tamMascota
 * @param valorDeEstado
 *
 * @return contadorEstados
 */

int ContarEstadoEnMascota(eMascota arrayMascota[], int tamMascota,
		int valorDeEstado) {

	int i;
	int contadorEstados;

	contadorEstados = 0;

	for (i = 0; i < tamMascota; i++) {
		if (arrayMascota[i].estado == valorDeEstado) {
			contadorEstados++;

		}
	}

	return contadorEstados;

}

/**
 * @brief cuenta la cantidad de estados igual a valorParaContar en una
 *  variable de un array eMascota
 *
 * @param arrayMascota
 * @param tamMascota
 * @param valorParaContar
 *
 * @return contador
 */

int ContarNumeroMayorEnMascota(eMascota arrayMascota[], int tamMascota,
		int valorParaContar) {

	int i;
	int contador;

	contador = 0;

	for (i = 0; i < tamMascota; i++) {

		if (arrayMascota[i].edad
				> valorParaContar&& arrayMascota[i].estado==OCUPADO) {
			contador++;
		}
	}

	return contador;
}
