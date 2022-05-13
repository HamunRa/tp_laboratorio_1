/*
 ============================================================================
 Name        : TP_2
 Author      : Soriano Baccarelli Lucas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "funciones.h"

int main(void) {
	setbuf(stdout, NULL);

	int id = 0;
	char nameAux[51];
	char lastNameAux[51];
	float priceAux;
	char flycodeAux[10];
	int typePassengerAux;

	int idABuscar;
	int posicionDada;
	int menu;
	int subMenu;
	int subMenuTres;

	int idABorrar;

	int validar;
	int largo = 2000;

	Passenger pasajeros[largo];
	initPassengers(pasajeros, largo);

	do {
		printf("\n1- Ingresar pasajero.\n"
				"2- Modificar pasajero.\n"
				"3- Eliminar pasajero.\n"
				"4- Informar pasajeros.\n"
				"5- Ingreso forzado de pasajeros.\n"
				"6- Salir.\n"
				"\nIngrese la opcion deseada.");
		scanf("%d", &menu);
		fflush(stdin);

		switch (menu) {
		case 1:
			id++;

			rellenarArray(nameAux, "\nIngrese el nombre del pasajero");

			rellenarArray(lastNameAux, "\nIngrese el apellido del pasajero.");

			rellenarFloat(&priceAux, "\nIngrese el precio del vuelo.");

			rellenarArray(flycodeAux, "\nIngrese el codigo de vuelo");

			utn_getInt(&typePassengerAux,
					"\nIngrese el tipo de pasajero.(1 Ejecutivo,2 Turista,3 VIP)",
					"error", 1, 3);

			addPassenger(pasajeros, largo, id, nameAux, lastNameAux, priceAux,
					typePassengerAux, flycodeAux);

			break;

		case 2:
			if (id != 0) {
				rellenarInt(&idABuscar, "\nIngrese el id a modifcar.\n");

				posicionDada = findPassengerById(pasajeros, largo, idABuscar);

				do {
					printf("\n1- Modificar nombre.\n"
							"2- Modificar apellido.\n"
							"3- Modificar precio.\n"
							"4- Modificar codigo de vuelo.\n"
							"5- Modificar tipo de pasajero.\n"
							"6- Salir.\n"
							"\nIngrese la opcion deseada.");
					scanf("%d", &subMenu);
					fflush(stdin);

					switch (subMenu) {
					case 1:
						validar = validarCadena(pasajeros[posicionDada].name,
								"\nIngrese el nombre modificado\n");
						break;

					case 2:
						rellenarArray(pasajeros[posicionDada].lastName,
								"\nIngrese el apellido modificado\n");
						break;

					case 3:
						rellenarFloat(&pasajeros[posicionDada].price,
								"\nIngrese el precio modificado.\n");
						break;

					case 4:
						rellenarArray(pasajeros[posicionDada].flycode,
								"\nIngrese el codigo de vuelo modificado.\n");
						break;

					case 5:
						rellenarInt(&pasajeros[posicionDada].typePassenger,
								"\nIngrese el tipo de pasajero modificado.\n");
						break;

					case 6:
						printf("\nSaliendo al menu\n");
						break;

					default:
						printf("\nOpcion no valida.");

					}
				} while (subMenu != 6);
			} else {
				printf("\nFalta ingresar los datos de los pasajeros\n");
			}
			break;

		case 3:
			if (id != 0) {
				rellenarInt(&idABorrar, "\nIngrese el id a borrar.\n");

				removePassenger(pasajeros, largo, idABorrar);
			} else {
				printf("\nFalta ingresar los datos de los pasajeros\n");
			}
			break;

		case 4:
			if (id != 0) {
				do {
					printf(
							"Menu para informar: \n"
									"1_ Listado de pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero.\n"
									"2_ Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio.\n"
									"3_ Listado de los pasajeros por Codigo de vuelo y estados de vuelo 'ACTIVO'.\n"
									"4_ Volver al menu.\n");
					fflush(stdin);
					scanf("%d", &subMenuTres);
					switch (subMenuTres) {
					case 1:
						sortPassengers(pasajeros, largo, 1);

						printf(pasajeros[0].name);
						printf(pasajeros[1].name);
						printf(pasajeros[2].name);
						printf(pasajeros[3].name);
						printf(pasajeros[4].name);
						break;
					case 2:

						break;
					case 3:
						break;
					case 4:
						printf("\nRegresando al menu principal.\n");
						break;
					default:
						printf("\nElija una opcion valida.\n");
					}
				} while (subMenuTres != 4);

			} else {
				printf("\nFalta ingresar los datos de los pasajeros\n");
			}
			break;

		case 5:
			break;

		case 6:
			printf("\n¡Hasta la proxima!");
			break;

		default:

			printf("\nOpcion no valida.\n");
			break;

		}

	} while (menu != 6);

	return 0;
}
