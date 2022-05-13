/*
 * funciones.c
 *
 *  Created on: 13 may. 2022
 *      Author: lucas
 */
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void rellenarInt(int *variableRecibida, char textoAMostrar[]) {
	printf(textoAMostrar);
	scanf("%d", variableRecibida);
	fflush(stdin);
}

void rellenarFloat(float *variableRecibida, char textoAMostrar[]) {
	printf(textoAMostrar);
	scanf("%f", variableRecibida);
	fflush(stdin);
}

void rellenarArray(char arrayRecibido[], char textoAMostrar[]) {
	printf(textoAMostrar);
	gets(arrayRecibido);
	fflush(stdin);
}
int validarCadena(char arrayRecibido[], char textoAMostrar[]){

	int retorno;
	retorno = 0;

	printf(textoAMostrar);
	gets(arrayRecibido);
	fflush(stdin);
	if (arrayRecibido != NULL){
		for (int i = 0; i <51; i++){
			if (isalpha(arrayRecibido[i])==0){
				retorno = -1;
				printf("\nError, intentalo ora vez.");
			}
		}
	}
	return retorno;
}

int utn_getInt(int * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo) {
	int retorno = -1;
	int bufferInt;

	while (retorno !=0){
		printf("%s",mensaje);
		if (getInt (&bufferInt) == 0 ){
			if (bufferInt >= minimo && bufferInt <= maximo){
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

