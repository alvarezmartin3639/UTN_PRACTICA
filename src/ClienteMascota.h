/*
 * ClienteMascota.h
 *
 *  Created on: 30 sep. 2020
 *      Author: kenyn
 */

#include "Cliente.h"
#include "FuncionesGenerales.h"
#include "Mascota.h"

#ifndef CLIENTEMASCOTA_H_
#define CLIENTEMASCOTA_H_

int MostrarClientesConSusMascota(eCliente[], int, eMascota[], int);

int MostrarMascotaQueTenganCliente(eCliente[], int, eMascota[], int, int, int,
		int);

int MostrarMascotasConSuCliente(eCliente[], int, eMascota[], int);

int MostrarClientesQueTenganMascota(eCliente[], int, eMascota[], int, int, int,
		int);

void CabezeraMostrarMascotaConSusCliente();

int AltaDeMascota(eCliente[], int, eMascota[], int);

int AsociarMascotaConCliente(eMascota*, eCliente[], int);

int CrearAuxiliaresDeMascota(eMascota*, eCliente[], int);

int ModificarMascota(eMascota[], int, eCliente[], int, int, int);

int BajaDeCliente(eCliente[], int, eMascota[], int, int);

int EliminarClienteJuntoSusMascota(eCliente[], int, eMascota[], int, int, int,
		int);

int ClienteConMasMascota(eCliente[], int, eMascota[], int);

int ContarNumeroDeMascotaRelacionadaConCliente(eCliente[], int, eMascota[], int,
		int, int);

#endif /* CLIENTEMASCOTA_H_ */
