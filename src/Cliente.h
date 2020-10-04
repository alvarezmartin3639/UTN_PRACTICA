/*
 * EstructuraMuchos.h
 *
 *  Created on: 30 sep. 2020
 *      Author: kenyn
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct {

	char nombre[50];
	float sueldo;
	int edad;
	int cantMascotasAsociadas;
	int estado;
	int idCliente;

} eCliente;

int InicializarCliente(eCliente[], int, int);
int HardcodeoCliente(eCliente[], int);

//ALTA
int AltaDeCliente(eCliente[], int);
int CrearAuxiliaresDeCliente(eCliente*);
int RemplazarAuxiliaresyCrearUnCliente(eCliente[], eCliente, int, int);
int GenerarIdDeCliente();

//BAJA
//ClienteMascota.h

//MODIFACION
int ModificarCliente(eCliente[], int, int, int);

//LA PARTE DE ARRIBA DE MOSTRAR EL LISTADO
void CabezeraMostrarCliente();

//MOSTRAR ESTRUCTURA
int MostrarListadoDeCliente(eCliente[], int, int);
int MostrarClienteMedianteIndice(eCliente[], int, int);
int MostrarUnUnicoCliente(eCliente, int);

//ORDENAMIENTOS
int OrdenarStringAscenIntAscenUnCliente(eCliente[], int);
int OrdenarPorFloatAscUnCliente(eCliente[], int);

//BUSCAR ELEMENTOS
int BuscarIdDeCliente(eCliente[], int, int, int);
int BuscarEstadoDeCliente(eCliente[], int, int);

int BuscarElMaximoDeMascotasEnCliente(eCliente[], int, int[], int);
int BuscarElIntMaximoEnCliente(eCliente[], int, int);
int BuscarElFloatMaximoEnCliente(eCliente[], int, int);

float AcumularNumeroDeCliente(eCliente[], int);
float PromediarNumeroDeCliente(eCliente[], int);

int ContarEstadoDeCliente(eCliente[], int, int);
int ContarClienteConEdadMayoraX(eCliente[], int, int);

#endif /* CLIENTE_H_ */
