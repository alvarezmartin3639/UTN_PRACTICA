/*
 * ClienteMascota.h
 *
 *  Created on: 30 sep. 2020
 *      Author: kenyn
 */

#include "Cliente.h"
#include "Mascota.h"
#include "FuncionesGenerales.h"

#ifndef CLIENTEMASCOTA_H_
#define CLIENTEMASCOTA_H_

void MostrarClientesConSusMascotas(eCliente[], int, eMascota[], int);

int MostrarMascotasQueTenganCliente(eCliente[], int, eMascota[], int, int, int,
		int);

void MostrarMascotasConSusClientes(eCliente[], int, eMascota[], int);

int MostrarClientesQueTenganMascotas(eCliente[], int, eMascota[], int, int, int,
		int);

void CabezeraMostrarMascotaConSusClientes();

int AltaDeMascota(eCliente[], int, eMascota listaMascta[], int);

int AsociarMascotaConCliente(eMascota*, eCliente[], int tamCliente);

int CrearAuxiliaresDeMascota(eMascota*, eCliente[], int tamCliente);

int ModificarMascota(eMascota[], int, eCliente[], int, int, int);

int BajaDeCliente(eCliente[], int, eMascota[], int, int);

int EliminarClienteJuntoSusMascotas(eCliente[], int, eMascota[], int, int, int,
		int);

int ClienteConMasMascotas(eCliente arrayCliente[], int tamCliente, eMascota arrayMascota[], int tamMascota);

int ContarMascotaRelacionadaConCliente(eCliente arrayCliente[], int tamCliente, eMascota arrayMascota[], int tamMascota, int);


#endif /* CLIENTEMASCOTA_H_ */
