/*
 * ArrayPassenger.c
 *
 *  Created on: 11 may. 2022
 *      Author: Luis
 */

#include "ArrayPassenger.h"
#include <string.h>
#include <stdio.h>

int initPassengers(Passenger *list, int len) {

	int i = 0;

	for (; i < len; i++) {
		list[i].isEmpty = VACIO;
	}

	return 0;
}

int addPassenger(Passenger *list, int len, int id, char name[], char lastName[], float price, int typePassenger, int statusFlight, char flycode[]) {

	int i = 0;

	int retorno = -1;
	if (list != NULL){

	for (; i < len; i++) {
		if (list[i].isEmpty == VACIO) {
			list[i].isEmpty = 0;
			list[i].id = id;
			list[i].price = price;
			list[i].typePassenger = typePassenger;
			list[i].statusFlight = statusFlight;
			strcpy(list[i].name, name);
			strcpy(list[i].lastName, lastName);
			strcpy(list[i].flycode, flycode);

			printf("\nEl id del pasajero es %d\n", id);

			i = len + 1;
		}

	}
	}
	return retorno;
}

int findPassengerById(Passenger *list, int len, int id) {

	int i;
	int DevolverPosi;

	for (i = 0; i < len; i++) {
		if (list[i].id == id) {
			DevolverPosi = i;
			i = len + 1;
		}
	}

	return DevolverPosi;
}

int removePassenger(Passenger *list, int len, int id) {

	int EliminarId = -1;
	int retorno = 0;
	EliminarId = findPassengerById(list, len, id);

	if (EliminarId == -1) {
		retorno = -1;
	}

	list[EliminarId].isEmpty = -1;

	return retorno;
}

int sortPassengers(Passenger *list, int len, int order) {

	Passenger auxiliar;
	int retorno = -1;

	if (list != NULL) {
		if (len >= 0) {
			if (order == 1) {
				for (int i = 0; i < len; i++) {
					for (int j = i + 1; j < len - 1; j++) {
						if (strcmp(list[i].lastName, list[j].lastName) > 0) {
							auxiliar = list[j];
							list[j] = list[i];
							list[i] = auxiliar;
						}
						if (strcmp(list[i].lastName, list[j].lastName) == 0) {
							if (list[i].typePassenger > list[j].typePassenger) {
								auxiliar = list[j];
								list[j] = list[i];
								list[i] = auxiliar;
							}
						}
					}
				}
			} else {
				for (int i = 0; i < len; i++) {
					for (int j = i + 1; j < len - 1; j++) {
						if (strcmp(list[i].lastName, list[j].lastName) < 0) {
							auxiliar = list[j];
							list[j] = list[i];
							list[i] = auxiliar;
						}
						if (strcmp(list[i].lastName, list[j].lastName) == 0) {
							if (list[i].typePassenger > list[j].typePassenger) {
								auxiliar = list[j];
								list[j] = list[i];
								list[i] = auxiliar;
							}
						}
					}
				}
			}
			retorno = 0;
		}
	}

	return retorno;
}

int sortPassengersByCode(Passenger *list, int len, int order) {

	Passenger auxiliar;
	int retorno = -1;

	if (list != NULL) {
		if (len >= 0) {
			if (order == 1) {
				for (int i = 0; i < len; i++) {
					for (int j = i + 1; j < len - 1; j++) {
						if (strcmp(list[i].flycode, list[j].flycode) > 0) {
							auxiliar = list[j];
							list[j] = list[i];
							list[i] = auxiliar;
						}
						if (strcmp(list[i].flycode, list[j].flycode) == 0) {
							if (list[i].statusFlight > list[j].statusFlight) {
								auxiliar = list[j];
								list[j] = list[i];
								list[i] = auxiliar;
							}
						}
					}
				}
			} else {
				for (int i = 0; i < len; i++) {
					for (int j = i + 1; j < len - 1; j++) {
						if (strcmp(list[i].flycode, list[j].flycode) < 0) {
							auxiliar = list[j];
							list[j] = list[i];
							list[i] = auxiliar;
						}
						if (strcmp(list[i].flycode, list[j].flycode) == 0) {
							if (list[i].statusFlight > list[j].statusFlight) {
								auxiliar = list[j];
								list[j] = list[i];
								list[i] = auxiliar;
							}
						}
					}
				}
			}
			retorno = 0;
		}
	}

	return retorno;
}

int printPassenger(Passenger *list, int len) {

	int i;
	for (i = 0; i < len; i++) {
		if (list[i].isEmpty != -1) {
			printf("%d | ", list[i].id);
			printf(list[i].lastName);
			printf(" ");
			printf(list[i].name);
			printf(" | Precio: ");
			printf("$%.2f | Codigo de vuelo: ", list[i].price);
			printf(list[i].flycode);
			printf(" | ");

			if (list[i].typePassenger == 1) {
				printf("Ejecutivo | ");
			} else {
				if (list[i].typePassenger == 2) {
					printf("Economico | ");
				} else {
					printf("VIP | ");
				}
			}
			if (list[i].statusFlight == 1) {
				printf("Activo\n");
			} else {
				if (list[i].statusFlight == 2) {
					printf("Inactivo\n");
				}
			}
		}
	}
	return 0;
}

float totalPrecioVuelos(Passenger *valor, int longitud) {

	int i;
	float acumulador;
	for (i = 0; i > longitud; i++) {
		if (valor[i].isEmpty != -1) {
			acumulador = acumulador + valor[i].price;
		}
	}
	return acumulador;
}

float promedioPrecioVuelos(Passenger *valor, int longitud, float precioTotal) {

	float promedio = 0;
	int i;
	int contador = 0;
	for (i = 0; i > longitud; i++) {
		if (valor[i].isEmpty != -1) {
			contador++;
		}
		promedio = precioTotal / contador;
	}
	return promedio;
}

int promedioPasajeroMayor(Passenger *valor, int longitud, float promedioPrecio) {

	int i;
	int contador = 0;
	for (i = 0; i > longitud; i++) {
		if (valor[i].isEmpty != -1) {
			if (valor[i].price > promedioPrecio) {
				contador++;
			}
		}
	}
	return contador;
}
