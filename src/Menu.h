/*
 * Menu.h
 *
 *  Created on: 19 sep. 2020
 *      Author: kenyn
 */

#include "Cliente.h"
#include "Mascota.h"

#ifndef MENU_H_
#define MENU_H_

int MostrarMenu();

int OrdenarClienteSubMenu();

void CargarClienteMenu(eCliente[], int);

void CargarMascotaMenu(eCliente[], int, eMascota[], int);

void MostrarClienteMenu(eCliente[], int);

void MostrarMascotaMenu(eMascota[], int);

void MostrarMascotasConSuClienteMenu(eCliente[], int, eMascota[], int);

void MostrarClienteConSusMascotasMenu(eCliente[], int, eMascota[], int);

void OrdenarClientePorLegajoyPorNombreSubMenu(eCliente[], int);

void OrdenarClientePorSueldoSubMenu(eCliente[], int);

void EliminarClienteMenu(eCliente[], int, eMascota[], int, int);

void EliminarMascotaMenu(eMascota[], int, int);

void ModificarClienteMenu(eCliente[], int, int, int);

void ModificarMascotaMenu(eCliente[], int, eMascota[], int, int, int);

int ModificarClienteSubMenu();

int ModificarMascotaSubMenu();
#endif /* MENU_H_ */
