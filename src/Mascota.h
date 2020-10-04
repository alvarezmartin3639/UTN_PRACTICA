/*
 * Empleado.h
 *
 *  Created on: 19 sep. 2020
 *      Author: kenyn
 */

#ifndef MASCOTA_H_
#define MASCOTA_H_

typedef struct {

	char nombre[50];
	char sexo;
	float peso;
	int edad;
	int estado;
	int idMascota;
	int idCliente;

} eMascota;

int InicializarMascota(eMascota[], int, int);
int HardcodeoMascota(eMascota[], int);

//ALTA
//CLIENTEMASCOTAS.h
int RemplazarAuxiliaresyCrearMascota(eMascota[], eMascota, int, int);
int GenerarIdDeMascota();

//BAJA
int BajaDeMascota(eMascota[], int, int);

//MODIFICACION
//CLIENTEMASCOTAS.h

//LA PARTE DE ARRIBA DE MOSTRAR EL LISTADO
void CabezeraMostrarMascota();

//MOSTRAR ESTRUCTURA
int MostrarListadoDeMascota(eMascota[], int, int);
int MostrarMascotaMedianteIndice(eMascota[], int, int);
int MostrarUnaUnicaMascota(eMascota, int);

//ORDENAMIENTOS
int OrdenarStringAscenIntAscenUnaMascota(eMascota[], int);
int OrdenarFloatAscenUnaMascota(eMascota[], int);

//BUSCAR ELEMENTOS
int BuscarIdDeMascota(eMascota[], int, int, int);
int BuscarEstadoDeMascota(eMascota[], int, int);

int BuscarElNumeroMaximoEnMascota(eMascota [], int );
float AcumularNumeroEnMascota(eMascota [], int );
float PromediarNumeroEnMascota(eMascota [], int );
int ContarEstadoEnMascota(eMascota [], int ,
		int );
int ContarNumeroMayorEnMascota(eMascota [], int ,
		int );

#endif /* MASCOTA_H_ */
