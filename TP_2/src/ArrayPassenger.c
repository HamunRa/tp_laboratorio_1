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

int addPassenger(Passenger *list, int len, int id, char name[], char lastName[],
		float price, int typePassenger, char flycode[]) {
	int i = 0;
	for (; i < len; i++) {
		if (list[i].isEmpty == VACIO) {
			list[i].isEmpty = 0;
			list[i].id = id;
			list[i].price = price;
			list[i].typePassenger = typePassenger;
			strcpy(list[i].name, name);
			strcpy(list[i].lastName, lastName);
			strcpy(list[i].flycode, flycode);

			printf("\nEl id del pasajero es %d\n", id);

			i = len + 1;
		}

	}
	return 0;
}

int findPassengerById(Passenger *list, int len, int id) {
	int i;
	int posicionADevolver;

	for (i = 0; i < len; i++) {
		if (list[i].id == id) {
			posicionADevolver = i;
			i = len + 1;
		}
	}

	return posicionADevolver;
}

int removePassenger(Passenger *list, int len, int id) {
	int posicionAVaciar = -1;
	int retorno = 0;
	posicionAVaciar = findPassengerById(list, len, id);

	if (posicionAVaciar == -1) {
		retorno = -1;
	}

	list[posicionAVaciar].isEmpty = -1;

	return retorno;
}

int sortPassengers(Passenger *list, int len, int order) {
	int i;
	int j;
	int value = 0;

	Passenger listAux;

	for (i = 0; i < len; i++) {
		for (j = i + 1; j < len; j++) {
			if (list[j].isEmpty != -1) {
				if (order == 1) {
					if (list[i].typePassenger > list[j].typePassenger) {
						value = 1;
					} else {
						value = strcmp(list[i].lastName, list[j].lastName);
					}
				}

				else {
					if (list[i].typePassenger < list[j].typePassenger) {
						value = strcmp(list[j].lastName, list[i].lastName);
					}
				}

				if (value == 1) {
					listAux.id = list[i].id;
					strcpy(listAux.name, list[i].name);
					strcpy(listAux.lastName, list[i].lastName);
					listAux.price = list[i].price;
					strcpy(listAux.flycode, list[i].flycode);
					listAux.typePassenger = list[i].typePassenger;

					list[i].id = list[j].id;
					strcpy(list[i].name, list[j].name);
					strcpy(list[i].lastName, list[j].lastName);
					list[i].price = list[j].price;
					strcpy(list[i].flycode, list[j].flycode);
					list[i].typePassenger = list[j].typePassenger;

					list[j].id = listAux.id;
					strcpy(list[j].name, listAux.name);
					strcpy(list[j].lastName, listAux.lastName);
					list[j].price = listAux.price;
					strcpy(list[j].flycode, listAux.flycode);
					list[j].typePassenger = listAux.typePassenger;
				}
			}
		}
	}
	return 0;
}
