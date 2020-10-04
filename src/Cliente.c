/*
 * EstructuraMuchos.c
 *
 *  Created on: 30 sep. 2020
 *      Author: kenyn
 */

#include <stdio.h>
#include <string.h>

#include "Cliente.h"
#include "FuncionesGenerales.h"
#include "Mascota.h"
#include "Menu.h"
#include "Validaciones.h"

/**
 * @brief Harcodea el valor de la entidad mascota
 *
 * @param arrayMascota
 * @param tamMascota
 *
 * @return void
 */

int HardcodeoCliente(eCliente arrayCliente[], int tamCliente) {

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
	for (i = 0; i < tamCliente; i++) {
		arrayCliente[i].idCliente = idCliente[i];
		arrayCliente[i].estado = estado[i];
		strcpy(arrayCliente[i].nombre, nombre[i]);
		arrayCliente[i].sueldo = sueldo[i];
		arrayCliente[i].edad = edad[i];
		arrayCliente[i].cantMascotasAsociadas = cantMascotasAsociadas[i];
	}

	return OK;
}

/**
 * @brief Da de alta a un cliente
 *
 * @param arrayCliente
 * @param tamCliente
 *
 * @return retorno
 */

int AltaDeCliente(eCliente arrayCliente[], int tamCliente) {

	eCliente auxCliente;
	int indiceDelEspacioLibre;
	int retorno = ERROR;
	char deseaContinuar = 'y';

	do {
		LimpiarPantalla();
		printf("--------============== CARGAR CLIENTE ==============--------");

		indiceDelEspacioLibre = BuscarEstadoDeCliente(arrayCliente, tamCliente,
		LIBRE);
		if (indiceDelEspacioLibre != ERROR) {

			CrearAuxiliaresDeCliente(&auxCliente);
			MostrarUnUnicoCliente(auxCliente, OCUPADO);

			if (ConfirmacionDeCambios() == OPCIONUNO) {
				RemplazarAuxiliaresyCrearUnCliente(arrayCliente, auxCliente,
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

/**
 * @brief crea los auxiliares de una estructura eCliente
 *
 * @param auxCliente
 *
 * @return
 */

int CrearAuxiliaresDeCliente(eCliente *auxCliente) {

	GetChar(auxCliente->nombre, "\nIngrese un nombre: ", "Error!!", 'a', 'z',
			2);
	GetFloat(&auxCliente->sueldo, "\nIngrese un precio: ",
			"Error precio invalido.", 1, 100000, 2);
	GetInt(&auxCliente->edad, "\nIngrese una edad: ", "Error edad invalido", 0,
			100, 2);
	auxCliente->idCliente = 0;
	auxCliente->estado = OCUPADO;
	return 0;
}

/**
 * @brief remplaza los auxiliares creados en CrearAuxiliaresDeCliente y crea
 * un eCliente
 *
 * @param arrayCliente
 * @param auxCliente
 * @param indiceParaRemplazar
 * @param valorOcupado
 *
 * @return retorno
 */

int RemplazarAuxiliaresyCrearUnCliente(eCliente arrayCliente[],
		eCliente auxCliente, int indiceParaRemplazar, int valorOcupado) {

	int retorno = 1;

	arrayCliente[indiceParaRemplazar].edad = auxCliente.edad;
	arrayCliente[indiceParaRemplazar].estado = valorOcupado;
	arrayCliente[indiceParaRemplazar].idCliente = GenerarIdDeMascota();
	arrayCliente[indiceParaRemplazar].sueldo = auxCliente.sueldo;
	strcpy(arrayCliente[indiceParaRemplazar].nombre, auxCliente.nombre);

	return retorno;
}

/**
 * @brief busca el primer estado libre y devuelve su indice
 *
 * @param arrayCliente
 * @param tamCliente
 * @param valorLibre
 *
 * @return indice
 */

int BuscarEstadoDeCliente(eCliente arrayCliente[], int tamCliente,
		int valorLibre) {

	int i;
	int indice = ERROR;
	for (i = 0; i < tamCliente; i++) {
		if (arrayCliente[i].estado == valorLibre) {
			indice = i;
			break;
		}
	}
	return indice;
}

/**
 * @brief muestra la cabezera de el listado de eCliente.
 *
 * @return void
 */

void CabezeraMostrarCliente() {

	printf("\n%-13s %-20s %-5s %-14s %-10s", "ID CLIENTE", "NOMBRE", "EDAD",
			"SUELDO", "ESTADO");
}

/**
 * @brief Muestra el listado del arrayCliente estructura eCliente.
 *
 * @param arrayCliente
 * @param tamCliente
 * @param valorOcupado
 *
 * @return contadorEspaciosOcupados
 */

int MostrarListadoDeCliente(eCliente arrayCliente[], int tamCliente,
		int valorOcupado) {
	int i;
	int contadorEspaciosOcupados;
	int retorno = ERROR;

	CabezeraMostrarCliente();

	for (i = 0; i < tamCliente; i++) {
		contadorEspaciosOcupados = MostrarClienteMedianteIndice(arrayCliente, i,
				valorOcupado);
	}

	if (contadorEspaciosOcupados == ERROR) {
		printf("****Error entidad no encontrada****");
	}
	return retorno;
}

/**
 * @brief Muestra una entidad eCliente dando por parametro su indice
 *
 * @param arrayCliente
 * @param indiceDeLaEstructura
 * @param valorOcupado
 *
 * @return retorno
 */

int MostrarClienteMedianteIndice(eCliente arrayCliente[],
		int indiceDeLaEstructura, int valorOcupado) {

	int retorno = ERROR;

	if (arrayCliente[indiceDeLaEstructura].estado
			== valorOcupado|| valorOcupado==INDIFERENTE) {

		printf("\n%-13d %-20s %-5d %-14.2f %-10d",
				arrayCliente[indiceDeLaEstructura].idCliente,
				arrayCliente[indiceDeLaEstructura].nombre,
				arrayCliente[indiceDeLaEstructura].edad,
				arrayCliente[indiceDeLaEstructura].sueldo,
				arrayCliente[indiceDeLaEstructura].estado);

		retorno = OK;
	}

	return retorno;
}

/**
 * @brief muestra una unica estructura eCliente
 *
 * @param arrayCliente
 * @param valorOcupado
 *
 * @return 1
 */

int MostrarUnUnicoCliente(eCliente arrayCliente, int valorOcupado) {

	if (arrayCliente.estado == valorOcupado || valorOcupado == INDIFERENTE) {

		CabezeraMostrarCliente();
		printf("\n %-13d %-20s %-5d %-14.2f %-10d", arrayCliente.idCliente,
				arrayCliente.nombre, arrayCliente.edad, arrayCliente.sueldo,
				arrayCliente.estado);
	}

	return OK;
}

/**
 *@brief Inicializa el estado en un arrayCliente de estructura eCliente
 *
 * @param arrayCliente
 * @param tamCliente
 * @param valorLibre
 *
 * @return 1
 */

int InicializarCliente(eCliente arrayCliente[], int tamCliente, int valorLibre) {
	int i;

	for (i = 0; i < tamCliente; i++) {
		arrayCliente[i].estado = LIBRE;
	}
	return OK;
}

/**
 *@brief Ordena un array de eCliente por abecedario de menor a mayor y
 * por numero entero de menor a mayor.
 *
 * @param arrayCliente
 * @param tamCliente
 *
 * @return
 */

int OrdenarStringAscenIntAscenUnCliente(eCliente arrayCliente[], int tamCliente) {
	int i;
	int j;
	eCliente auxCliente;

	for (i = 0; i < tamCliente - 1; i++) {
		for (j = i + 1; j < tamCliente; j++) {
			if (strcmp(arrayCliente[i].nombre, arrayCliente[j].nombre) > 0) {
				auxCliente = arrayCliente[i];
				arrayCliente[i] = arrayCliente[j];
				arrayCliente[j] = auxCliente;
			} else {
				if (strcmp(arrayCliente[i].nombre, arrayCliente[j].nombre)
						== 0) {
					if (arrayCliente[i].idCliente > arrayCliente[j].idCliente) {
						auxCliente = arrayCliente[i];
						arrayCliente[i] = arrayCliente[j];
						arrayCliente[j] = auxCliente;
					}
				}
			}

		}
	}

	return OK;
}

/**
 *@brief Ordena un array eCliente por flotante de menor a mayor
 *
 * @param arrayCliente
 * @param tamCliente
 * @return
 */

int OrdenarPorFloatAscUnCliente(eCliente arrayCliente[], int tamCliente) {
	int i;
	int j;
	eCliente auxCliente;

	for (i = 0; i < tamCliente - 1; i++) // rojo
			{
		for (j = i + 1; j < tamCliente; j++) //  verde
				{

			if (arrayCliente[i].sueldo > arrayCliente[j].sueldo) {

				auxCliente = arrayCliente[i];
				arrayCliente[i] = arrayCliente[j];
				arrayCliente[j] = auxCliente;
			}
		}
	}

	return OK;
}

/**
 * @brief modifica un eCliente mediante su id
 *
 * @param arrayCliente
 * @param tamCliente
 * @param valorOcupado
 * @param valorLibre
 *
 * @return retorno
 */

int ModificarCliente(eCliente arrayCliente[], int tamCliente, int valorOcupado,
		int valorLibre) {

	int retorno = ERROR;
	int valorBuscado;
	int indiceEncontrado;
	int opcionElegidaMenu;
	char auxEstado[55];

	GetInt(&valorBuscado, "\nIngrese el ID a modificar: \n", "ID INVALIDO!!!",
			1, 6666, 2);

	indiceEncontrado = BuscarIdDeCliente(arrayCliente, tamCliente, valorBuscado,
	OCUPADO);

	if (indiceEncontrado != ERROR) {

		do {

			LimpiarPantalla();
			printf("\n======ID %d ENCONTRADO======", valorBuscado);
			CabezeraMostrarCliente();
			MostrarClienteMedianteIndice(arrayCliente, indiceEncontrado,
					valorOcupado);
			opcionElegidaMenu = ModificarClienteSubMenu();

			switch (opcionElegidaMenu) {
			case 1:
				GetChar(arrayCliente[indiceEncontrado].nombre,
						"Ingrese el nombre a modificar: ", "Nombre invalido",
						'a', 'z', 2);
				break;

			case 2:
				GetFloat(&arrayCliente[indiceEncontrado].sueldo,
						"Ingrese el sueldo a modificar: ", "sueldo invalido",
						1500, 80000, 2);
				break;

			case 3:
				GetInt(&arrayCliente[indiceEncontrado].edad,
						"Ingrese el edad a modificar: ", "edad invalido", 18,
						70, 2);
				break;

			case 4:

				if (elejirEntreDosOpcionesConPuntero(auxEstado,
						"Ingrese 'baja' para dar de baja o 'alta' para dar de alta",
						"baja", "alta") == OPCIONUNO) {
					arrayCliente[indiceEncontrado].estado = LIBRE;
					opcionElegidaMenu = 5;
					break;
				}

				if (ConfirmacionDeCambios() == ACEPTO) {
					arrayCliente[indiceEncontrado].estado = OCUPADO;
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
 *@brief Busca el id de una eCliente, compara su estado con el
 * estado ingresado en la mascota.
 *
 * \param eAlumno arrayCliente[]                La estructura donde trabajar.
 * \param int tamCliente                          El numero de arrays de la estructura.
 * \param int valorBuscado                 El int que deseamos que busque en la variable del arrayCliente de estructura.
 * \return int index                       Devuelve -322 si no se encontró nada  o la posicion dentro del arrayCliente donde se encontró el int
 */

int BuscarIdDeCliente(eCliente arrayCliente[], int tamCliente, int valorBuscado,
		int valorEstadoParaBuscar) {

	int i;
	int retorno = ERROR;

	for (i = 0; i < tamCliente; i++) {
		if ((arrayCliente[i].estado == valorEstadoParaBuscar
				|| valorEstadoParaBuscar == -1)
				&& arrayCliente[i].idCliente == valorBuscado) {
			retorno = i;
			break;
		}
	}

	return retorno;
}

/**
 *@brief genera un numero autoincremental utilizado para dar
 * el id la entidad eCliente
 *
 * @return generarIdDeCliente
 */

int GenerarIdDeCliente() {
	static int generarIdDeCliente = 0;
	generarIdDeCliente++;
	return generarIdDeCliente;
}

/**
 * @brief Busca el numero maximo de mascotas asociadas y almacenadas anteriormente en el array paralelo
 *
 * @param arrayClientes
 * @param tamClientes
 * @param valorEstado
 *
 * @return indiceMaximo
 */

int BuscarElMaximoDeMascotasEnCliente(eCliente arrayClientes[], int tamClientes,
		int arrayParalelo[], int valorEstado) {

	int i;
	int maxInt;
	int indiceMaximo = ERROR;

	for (i = 0; i < tamClientes; i++) {
		if ((arrayParalelo[i] > maxInt && arrayClientes[i].estado == valorEstado)
				|| (valorEstado == INDIFERENTE || i == 0)) {

			maxInt = arrayParalelo[i];
			indiceMaximo = i;
		}
	}

	return indiceMaximo;
}

/**
 * @brief Busca el numero maximo de un array  eMascota
 * y devuelve el indice con el mayor.
 *
 * @param arrayClientes
 * @param tamClientes
 * @param valorEstado
 *
 * @return indiceMaximo
 */

int BuscarElIntMaximoEnCliente(eCliente arrayClientes[], int tamClientes,
		int valorEstado) {

	int i;
	int maxInt;
	int indiceMaximo = ERROR;

	for (i = 0; i < tamClientes; i++) {
		if ((arrayClientes[i].cantMascotasAsociadas > maxInt
				&& arrayClientes[i].estado == valorEstado)
				|| (valorEstado == INDIFERENTE || i == 0)) {
			maxInt = arrayClientes[i].cantMascotasAsociadas;
			indiceMaximo = i;
		}
	}

	return indiceMaximo;
}

/**
 *  * @brief busca el flotante mayor en una variable de un array eCliente
 *
 * @param arrayClientes
 * @param tamClientes
 * @param valorEstado
 *
 * @return indiceMaximo
 */

// ESTO SE PUEDE MEJORAR, PUEDO HACER QUE DETECTE SOLO SI ES FLOAT O INT
int BuscarElFloatMaximoEnCliente(eCliente arrayClientes[], int tamClientes,
		int valorEstado) {

	int i;
	float maxFloat;
	int indiceMaximo = ERROR;

	for (i = 0; i < tamClientes; i++) {
		if ((arrayClientes[i].sueldo > maxFloat
				&& arrayClientes[i].estado == valorEstado)
				|| (valorEstado == INDIFERENTE || i == 0)) {
			maxFloat = arrayClientes[i].sueldo;
			indiceMaximo = i;
		}
	}

	return indiceMaximo;
}

/**
 * @brief acumula flotantes de una variable de un array eCliente
 *
 * @param arrayClientes
 * @param tamClientes
 *
 * @return acumulador
 */

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

/**
 * @brief acumula las variables de un array de eCliente,cuenta la
 * cantidad de estados ocupados dentro de ella y saca un promedio
 *
 * @param arrayClientes
 * @param tamClientes
 *
 * @return numeroAcumulado
 */

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

/**
 * @brief cuenta la cantidad de estados dependiendo lo ingresado en valorDeEstado
 * de un array eCliente
 *
 * @param arrayClientes
 * @param tamClientes
 * @param valorDeEstado
 * @return
 */

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

/**
 * @brief cuenta la cantidad de estados igual a valorParaContar en una
 *  variable de un array eCliente
 *
 * @param arrayClientes
 * @param tamClientes
 * @param valorParaContar
 *
 * @return contador
 */

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
