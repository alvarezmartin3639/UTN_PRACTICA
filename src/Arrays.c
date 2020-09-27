/*
 * Arrays.c
 *
 *  Created on: 24 sep. 2020
 *      Author: kenyn
 */

#include "Arrays.h"

#include <stdio.h>
#include <string.h>

void inicializarArray (int array[], int tam, int valorLibre)
{
  int i;

	for (i = 0; i < tam; i++) {
		array[i] = valorLibre;
	}
}

int buscarLibre(int array[], int tam, int valorLibre) {
	int i;
	int indice = -1;

	for (i = 0; i < tam; i++) {

		if (array[i] == valorLibre) {
			indice = i;
			break;
		}

	}

	return indice;
}

void CargarAleatoriamenteUnArrayEntero(int array[], int tam) {

}

void CargarAleatoriamenteUnArrayCadena(char array[][55], int tam){


}

void CargarSecuencialmenteUnArrayEntero(int array[], int tam){


}

void CargarSecuencialmenteUnArrayCadena(char array[][55], int tam){


}

void ModificarUnaEntidadArray()
{

}

void EliminarUnaEntidadArray()
{

}

void MostrarUnEnteroDeUnArray(int array[], int tam) {
	int i;
	for (i = 0; i < tam; i++) {
		if (array[i] != -1) {
			printf("\n  %d ", array[i]);
		}
	}
}

void MostrarTodosLosEnterosDeUnArray(int array[], int tam) {
	int i;

	for (i = 0; i < tam; i++) {
		printf("\n %d- ", array[i]);
	}

}

void MostrarTodosLosCharsDeUnArray(char array[], int tam) {

	int i;
	for (i = 0; i < tam; i++) {
		printf("\n %c- ", array[i]);
	}

}

void MostrarTodosLosFloatsDeUnArray(float array[], int tam) {

	int i;
	for (i = 0; i < tam; i++) {
		printf("\n %2.f- ", array[i]);
	}

}

int ContarNumerosMayoresaCincoDeUnArray(int array[], int tam) {

	int contador = 0;
	int i;
	for (i = 0; i < tam; i++) {
		if (array[i] > 5) //
				{
			contador++;
		}
	}
	return contador;
}

int ContarIndiceOcupadoDeUnArray(int array[], int tam) {
	int i;
	int contador = 0;
	for (i = 0; i < tam; i++) {
		if (array[i] != -1) {
			contador++;
		}
	}
	return contador;
}

void OrdenarEnteroAscendientementeDeUnArray(int array[], int tam) {
	int i;
	int j;
	int auxiliar;

	for (i = 0; i < tam - 1; i++) // rojo
			{

		for (j = i + 1; j < tam; j++) //  verde
				{

			if (array[i] > array[j]) {

				auxiliar = array[i];
				array[i] = array[j];
				array[j] = auxiliar;
			}

		}

	}

}

/*
 * I=0
 * j=i+1 (osea 1)
 *
 *
 * Pongo un array de 3
 *
 * Seguir hasta que i sea 2
 *
 *
 */
void OrdenarArrayParaleloPorNombre(int legajo[], int nota1[], int nota2[],
		float promedio[], char nombre[][20], int estado[], int tam,
		int valorOcupado) {
	int i;
	int j;

	char auxString[20];
	int auxInt;
	float auxfloat;

	for (i = 0; i < tam - 1; i++) {
		if (estado[i] != valorOcupado) {
			continue;
		}
		for (j = i + 1; j < tam; j++) {
			if (estado[j] != valorOcupado) {
				continue;
			}
			if (strcmp(nombre[i], nombre[j]) < 0) { //criterio
				strcpy(auxString, nombre[i]);
				strcpy(nombre[i], nombre[j]);
				strcpy(nombre[j], auxString);

				auxInt = legajo[i];
				legajo[i] = legajo[j];
				legajo[j] = auxInt;

				auxInt = nota1[i];
				nota1[i] = nota1[j];
				nota1[j] = auxInt;

				auxInt = nota2[i];
				nota2[i] = nota2[j];
				nota2[j] = auxInt;

				auxfloat = promedio[i];
				promedio[i] = promedio[j];
				promedio[j] = auxfloat;

			}
		}
	}
}

int SacarMinimoDeUnArray(int array[],int tam){
    int valorDeRetorno;
    if(array[0]!=-1) //Si el espacio está ocupado
    {
         valorDeRetorno=array[0];
    }
    int i;
    for(i=0;i<tam;i++)
    {
        if(valorDeRetorno>array[i] && array[i]!=-1)
        {
            valorDeRetorno=array[i];
        }
    }
    return valorDeRetorno;

}

int SacarMaximoDeUnArray(int array[],int tam){
    int valorDeRetorno;
    if(array[0]!=-1)
    {
         valorDeRetorno=array[0];
    }
    int i;
    for(i=0;i<tam;i++)
    {
        if(valorDeRetorno<array[i] && array[i]!=-1)
        {
            valorDeRetorno=array[i];
        }
    }
    return valorDeRetorno;

}

int SacarCantidadDeParesDeUnArray(int array[], int tam) {

	int i;
	int valorDeRetorno = 0;
	for (i = 0; i < tam; i++) {
		if (array[i] % 2 == 0) {
			valorDeRetorno++;
		}
	}
	return valorDeRetorno;
}

int SacarAcumuladorDeUnArray(int array[], int tam) {
	int suma = 0;
	int i;
	for (i = 0; i < tam; i++) {
		if (array[i] != -1) {
			suma = suma + array[i];
		}

	}
	return suma;
}

float SacarPromedioDeUnArray(int array[], int tam) {

	return (float) SacarAcumuladorDeUnArray(array, tam)
			/ ContarIndiceOcupadoDeUnArray(array, tam);
}
