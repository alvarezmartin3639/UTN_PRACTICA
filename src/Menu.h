/*
 * Menu.h
 *
 *  Created on: 19 sep. 2020
 *      Author: kenyn
 */

#include "Estructura.h"

#ifndef MENU_H_
#define MENU_H_

int MostrarMenu();
int OrdenarEstructuraSubMenu();
void CargarEstructuraMenu(eEstructura [], int );
void MostrarEstructuraMenu(eEstructura [], int );
void OrdenarEstructuraPorLegajoAscDespuesPorNombreAscSubMenu(eEstructura [], int );
void OrdenarEstructuraPorSueldoSubMenu(eEstructura [], int );
void EliminarEstructuraMenu(eEstructura [], int , int );
void ModificarEstructuraMenu(eEstructura [], int , int ,int );
int ModificarEstructuraSubMenu();

#endif /* MENU_H_ */
