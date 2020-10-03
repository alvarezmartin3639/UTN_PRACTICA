/*
 * Menu.h
 *
 *  Created on: 19 sep. 2020
 *      Author: kenyn
 */

#include "ClienteMascota.h"

#ifndef MENU_H_
#define MENU_H_

int MostrarMenu();
int OrdenarEstructuraSubMenu();
void CargarEstructuraMenu(eCliente[], int);
void MostrarEstructuraMenu(eCliente[], int);
void OrdenarEstructuraPorLegajoAscDespuesPorNombreAscSubMenu(eCliente[], int);
void OrdenarEstructuraPorSueldoSubMenu(eCliente[], int);
void EliminarEstructuraMenu(eCliente [], int , eMascota [], int , int );
void ModificarEstructuraMenu(eCliente[], int, int, int);
int ModificarClienteSubMenu();
int ModificarMascotaSubMenu();
#endif /* MENU_H_ */
