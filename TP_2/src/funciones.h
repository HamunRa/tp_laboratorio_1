/*
 * funciones.h
 *
 *  Created on: 13 may. 2022
 *      Author: lucas
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

void rellenarInt(int *variableRecibida, char textoAMostrar[]);

void rellenarFloat(float *variableRecibida, char textoAMostrar[]);

void rellenarArray(char arrayRecibido[], char textoAMostrar[]);

int validarCadena(char arrayRecibido[], char textoAMostrar[]);

int utn_getNumeroFlotante(float * pResultado, char * mensaje, char *mensajeError, int minimo, int maximo);

int utn_getInt(int * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo);
#endif /* FUNCIONES_H_ */
