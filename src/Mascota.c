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

/*
 * \brief
 * \return
 *
 */

void HardcodeoMascota(eMascota array[], int tam) {

	char nombre[TMASCOTAS][50] = { "Lucia", "Luis", "Fernanda", "Fernando", "Juana", "Juan", "Ludmila", "Lucero" };
	float peso[TMASCOTAS] =
			{ 23, 10, 3, 4, 1, 5, 22.3, 11.1 };
	int edad[TMASCOTAS] = { 18, 22, 21, 33, 11, 44, 55, 66 };
	float sexo[TMASCOTAS]={'f','m','f','m','f','m','f','m'};
	int idMascota[TMASCOTAS]={1,2,3,4,5,6,7,8};
	int idCliente[TMASCOTAS]={1,3,2,1,1,3,4,5};
	int estado[TMASCOTAS] = { LIBRE, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO,
	OCUPADO, OCUPADO };

	int i;
	for (i = 0; i < tam; i++) {
		array[i].estado = estado[i];
		strcpy(array[i].nombre, nombre[i]);
		array[i].peso = peso[i];
		array[i].edad = edad[i];
		array[i].idMascota=	 idMascota[i];
		array[i].idCliente=idCliente[i];
		array[i].sexo=sexo[i];
	}
}


/*
 * \brief
 * \return
 *
 */

int RemplazarAuxiliaresyCrearMascota(eMascota list[], eMascota auxEstructura,
		int indiceParaRemplazar, int valorOcupado) {

	int retorno = 1;

	list[indiceParaRemplazar].edad = auxEstructura.edad;
	list[indiceParaRemplazar].estado = valorOcupado;
	list[indiceParaRemplazar].idMascota = GenerarIdDeMascota();
	list[indiceParaRemplazar].idCliente=auxEstructura.idCliente;
	list[indiceParaRemplazar].peso = auxEstructura.peso;
	strcpy(list[indiceParaRemplazar].nombre, auxEstructura.nombre);

	return retorno;
}

/*
 * \brief
 * \return
 *
 */

int BuscarEstadoDeMascota(eMascota array[], int tam, int valorParaBuscar) {

	int i;
	int indice = ERROR;
	for (i = 0; i < tam; i++) {
		if (array[i].estado == valorParaBuscar) {
			indice = i;
			break;
		}
	}
	return indice;
}



void CabezeraMostrarMascota() {


	printf("%-13s %-13s %-20s %-5s %-14s %-5s %-10s",
					"ID MASCOTA","ID CLIENTE","NOMBRE","EDAD","PESO","SEXO",
					"ESTADO");
}


/*
 * \brief
 * \return
 *
 */

int MostrarListadoDeMascota(eMascota array[], int tam, int valorOcupado) {
	int i;
	int contadorEspaciosOcupados = ERROR;


	CabezeraMostrarMascota();

	for (i = 0; i < tam; i++) {
		contadorEspaciosOcupados = MostrarMascotaMedianteIndice(array,
				i, valorOcupado);
	}

	if (contadorEspaciosOcupados == ERROR) {
		printf("****Error entidad no encontrada****");
	}
	return contadorEspaciosOcupados;
}

/*
 * \brief
 * \return
 *
 */

int MostrarMascotaMedianteIndice(eMascota array[], int indiceDeLaEstructura,
		int valorEstado) {
	int retorno;

retorno=ERROR;

	if (array[indiceDeLaEstructura].estado == valorEstado || valorEstado==INDIFERENTE ) {



		printf("\n%-13d %-13d %-20s %-5d %-14.2f %-5c %-10d",
				array[indiceDeLaEstructura].idMascota,array[indiceDeLaEstructura].idCliente,
				array[indiceDeLaEstructura].nombre,array[indiceDeLaEstructura].edad,
				array[indiceDeLaEstructura].peso,array[indiceDeLaEstructura].sexo,
				array[indiceDeLaEstructura].estado);

		retorno=OK;
	}

	return retorno;
}

/*
 * \brief
 * \return
 *
 */

int MostrarUnaUnicaMascota(eMascota mascota, int valorOcupado) {

	if (mascota.estado == valorOcupado || valorOcupado == INDIFERENTE) {

		CabezeraMostrarMascota();
		printf("\n%-13d %-13d %-20s %-5d %-14.2f %-5c %-10d",
				mascota.idMascota, mascota.idCliente, mascota.nombre,
				mascota.edad, mascota.peso, mascota.sexo, mascota.estado);
	}

	return OK;
}

/*
 * \brief
 * \return
 *
 */

int InicializarMascota(eMascota array[], int tam, int valorLibre) {
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

int OrdenarStringAscenIntAscEnMascota(eMascota array[], int tam) {
	int i;
	int j;
	eMascota auxEstructura;

	for (i = 0; i < tam - 1; i++) {
		for (j = i + 1; j < tam; j++) {
			if (strcmp(array[i].nombre, array[j].nombre) > 0) {
				auxEstructura = array[i];
				array[i] = array[j];
				array[j] = auxEstructura;
			} else {
				if (strcmp(array[i].nombre, array[j].nombre) == 0) {
					if (array[i].idMascota > array[j].idMascota) {
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

int OrdenarFloatAscEnMascota(eMascota array[], int tam) {
	int i;
	int j;
	eMascota auxEstructura;

	for (i = 0; i < tam - 1; i++) // rojo
			{
		for (j = i + 1; j < tam; j++) //  verde
				{

			if (array[i].peso > array[j].peso) {

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

int BajaDeMascota(eMascota array[], int tam, int valorOcupado) {
	int legajoParaEliminar;
	int indiceLegajoParaEliminar;

	GetInt(&legajoParaEliminar, "Ingrese el numero de legajo a eliminar: ",
			"Error legajo invalido ", 0, 200, 2);

	indiceLegajoParaEliminar = BuscarIdDeMascota(array, tam, legajoParaEliminar,
			OCUPADO);

	if (indiceLegajoParaEliminar != ERROR) {
		MostrarMascotaMedianteIndice(array, indiceLegajoParaEliminar,
				valorOcupado);

		if (ConfirmacionDeCambios() == ACEPTO) {
			array[indiceLegajoParaEliminar].estado = LIBRE;
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
 * \brief Busca un valor int en la variable int de una estructura.
 *
 * \param eAlumno listado[]                La estructura donde trabajar.
 * \param int tam                          El numero de arrays de la estructura.
 * \param int valorBuscado                 El int que deseamos que busque en la variable del array de estructura.
 * \param int valorEstadoParaBuscar        El valor de estado para buscar, 0 = ocupado, 1 = 0 libre, -1 = indiferente(libre y ocupado a la vez).
 * \return int index                       Devuelve -322 si no se encontró nada  o la posicion dentro del array donde se encontró el int
 */

int BuscarIdDeMascota(eMascota estructura[], int tamEstructura,
		int valorBuscado, int valorEstadoParaBuscar) {

	int i;
	int retorno = ERROR;

		for (i = 0; i < tamEstructura; i++) {
			if ((estructura[i].estado == valorEstadoParaBuscar || valorEstadoParaBuscar==-1)
					&& estructura[i].idMascota == valorBuscado) {
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
int GenerarIdDeMascota() {
	static int generarIdDeMascota = 0;
	generarIdDeMascota++;
	return generarIdDeMascota;
}


int BuscarElIntMaximoEnMascota(eMascota arrayMascota[], int tamMascota, int valorEstado) {

	int i;
	int maxInt;
	int indiceMaximo=ERROR;

	for (i = 0; i < tamMascota; i++) {
		if ((arrayMascota[i].edad > maxInt && arrayMascota[i].estado==valorEstado ) || (valorEstado ==INDIFERENTE || i == 0)) {
			maxInt = arrayMascota[i].edad;
			indiceMaximo=i;
		}
	}

	return indiceMaximo;
}

// ESTO SE PUEDE MEJORAR, PUEDO HACER QUE DETECTE SOLO SI ES FLOAT O INT
int BuscarElFloatMaximoEnMascota(eMascota arrayMascota[], int tamMascota, int valorEstado) {

	int i;
	float maxFloat;
	int indiceMaximo=ERROR;

	for (i = 0; i < tamMascota; i++) {
		if ((arrayMascota[i].peso > maxFloat && arrayMascota[i].estado==valorEstado ) || (valorEstado ==INDIFERENTE || i == 0)) {
			maxFloat = arrayMascota[i].peso;
			indiceMaximo=i;
		}
	}

	return indiceMaximo;
}

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

float PromediarNumeroEnMascota(eMascota arrayMascota[], int tamMascota) {

	float numeroAcumulado;
	int contadorDeEstadosOcupados;

	//ACUMULO NUM
	numeroAcumulado = AcumularNumeroEnMascota(arrayMascota, tamMascota);
	//BUSCO LA CANTIDAD DE OCUPADOS
	contadorDeEstadosOcupados = ContarEstadoEnMascota(arrayMascota,
			tamMascota, OCUPADO);

	//PROMEDIO
	numeroAcumulado = (float) numeroAcumulado / contadorDeEstadosOcupados;
	return numeroAcumulado;
}

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
