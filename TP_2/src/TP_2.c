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
	char nombre[51];
	char apellido[51];
	float precioVuelo;
	char codigoDeVuelo[10];
	int tipoPasajero;
	int estadoVuelo;

	int idABuscar;
	int posicionDada;
	int menu;
	int subMenu;
	int subMenuTres;
	float precioTotal;
	float promedioPrecio;
	int totalPromedio;

	int idABorrar;

	int largo = 2000;

	Passenger pasajeros[largo];
	initPassengers(pasajeros, largo);

	do {
		printf("\n1- ALTA de pasajero.\n"
				"2- MODIFICAR pasajero.\n"
				"3- BAJA de pasajero.\n"
				"4- INFORMAR.\n"
				"5- Carga forzada.\n"
				"6- Salir.\n"
				"\nIngrese la opcion deseada.");
		scanf("%d", &menu);
		fflush(stdin);

		switch (menu) {
		case 1:
			id++;

			utn_getName(nombre, "\nIngrese el nombre del pasajero", "Error");

			utn_getName(apellido, "\nIngrese el apellido del pasajero.",
					"Error");

			utn_getFloat(&precioVuelo, "\nIngrese el precio del vuelo.",
					"Error", 1, 100000000);

			ingresarCodigo(codigoDeVuelo, "\nIngrese el codigo de vuelo");

			utn_getInt(&tipoPasajero,
					"\nIngrese el tipo de pasajero.(1 Ejecutivo,2 Turista,3 VIP)",
					"Error, ingrese una opcion valida", 1, 3);

			utn_getInt(&estadoVuelo,
					"\nIngrese el estado del vuelo.(1 Activo,2 Inactivo)",
					"Error, ingrese una opcion valida", 1, 2);

			addPassenger(pasajeros, largo, id, nombre, apellido, precioVuelo,
					tipoPasajero, estadoVuelo, codigoDeVuelo);

			break;

		case 2:
			if (id != 0) {
				printf("\nIngrese el id a modifcar.\n");
				fflush(stdin);
				scanf("%d", &idABuscar);

				posicionDada = findPassengerById(pasajeros, largo, idABuscar);

				do {
					printf("\n1- Modificar .\n"
							"2- Modificar apellido.\n"
							"3- Modificar precio.\n"
							"4- Modificar codigo de vuelo.\n"
							"5- Modificar tipo de pasajero.\n"
							"6- Modificar estado de vuelo.\n"
							"7- Regresar al menu principal.\n"
							"\nIngrese la opcion deseada.");
					scanf("%d", &subMenu);
					fflush(stdin);

					switch (subMenu) {
					case 1:
						utn_getName(pasajeros[posicionDada].name,
								"\nIngrese el  modificado\n", "Error");
						break;

					case 2:
						utn_getName(pasajeros[posicionDada].lastName,
								"\nIngrese el apellido modificado\n", "Error");
						break;

					case 3:
						utn_getFloat(&pasajeros[posicionDada].price,
								"\nIngrese el precio modificado.\n", "Error", 1,
								1000000000);
						break;

					case 4:
						ingresarCodigo(pasajeros[posicionDada].flycode,
								"\nIngrese el codigo de vuelo modificado.\n");
						break;

					case 5:
						utn_getInt(&pasajeros[posicionDada].typePassenger,
								"\nIngrese el tipo de pasajero modificado.(1 Ejecutivo,2 Turista,3 VIP)\n",
								"Error", 1, 3);
						break;

					case 6:
						utn_getInt(&pasajeros[posicionDada].statusFlight,
								"\nIngrese el estado de vuelo.(1 Activo,2 Inactivo)\n",
								"Error", 1, 2);
						break;
					case 7:
						printf("\nRegresando al menu principal.\n");
						break;

					default:
						printf("\nOpcion no valida.");

					}
				} while (subMenu != 7);
			} else {
				printf("\nFalta ingresar los datos de los pasajeros\n");
			}
			break;

		case 3:
			if (id != 0) {
				printf("\nIngrese el id a borrar.\n");
				fflush(stdin);
				scanf("%d", &idABorrar);

				removePassenger(pasajeros, largo, idABorrar);
			} else {
				printf("\nFalta ingresar los datos de los pasajeros\n");
			}
			break;

		case 4:
			if (id != 0) {
				do {
					printf(
							"\nMenu para informar: \n"
									"\n1_ Listado de pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero.\n"
									"2_ Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio.\n"
									"3_ Listado de los pasajeros por Codigo de vuelo y estados de vuelo 'ACTIVO'.\n"
									"4_ Volver al menu.\n");
					fflush(stdin);
					scanf("%d", &subMenuTres);
					switch (subMenuTres) {
					case 1:
						if (sortPassengers(pasajeros, largo, 1) == 0) {
							if (printPassenger(pasajeros, largo) != 0) {
								printf("Lista Vacia");
							}
						}
						break;
					case 2:
						precioTotal = totalPrecioVuelos(pasajeros, largo);
						printf("\nEl precio total es: %.2f\n", precioTotal);
						promedioPrecio = promedioPrecioVuelos(pasajeros, largo,
								precioTotal);
						printf("El promedio de los precios es: %.2f\n",
								promedioPrecio);
						totalPromedio = promedioPasajeroMayor(pasajeros, largo,
								promedioPrecio);
						printf("La cantidad de pasajeros que superan el promedio es: %d\n",
								totalPromedio);
						break;
					case 3:
						if (sortPassengersByCode(pasajeros, largo, 1) == 0) {
							if (printPassenger(pasajeros, largo) != 0) {
								printf("Lista Vacia");
							}
						}
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
			id++;
			strcpy(nombre, "Lucas");
			strcpy(apellido, "Soriano");
			precioVuelo = 9000;
			tipoPasajero = 2;
			estadoVuelo = 1;
			strcpy(codigoDeVuelo, "RIO 302");
			addPassenger(pasajeros, largo, id, nombre, apellido, precioVuelo,
					tipoPasajero, estadoVuelo, codigoDeVuelo);

			id++;
			strcpy(nombre, "Mateo");
			strcpy(apellido, "Ocampo");
			precioVuelo = 10200;
			tipoPasajero = 1;
			estadoVuelo = 2;
			strcpy(codigoDeVuelo, "USH 420");
			addPassenger(pasajeros, largo, id, nombre, apellido, precioVuelo,
					tipoPasajero, estadoVuelo, codigoDeVuelo);

			id++;
			strcpy(nombre, "Jose");
			strcpy(apellido, "Quiroga");
			precioVuelo = 8600;
			tipoPasajero = 3;
			estadoVuelo = 1;
			strcpy(codigoDeVuelo, "BSA 210");
			addPassenger(pasajeros, largo, id, nombre, apellido, precioVuelo,
					tipoPasajero, estadoVuelo, codigoDeVuelo);

			id++;
			strcpy(nombre, "Julian");
			strcpy(apellido, "Nybroe");
			precioVuelo = 18000;
			tipoPasajero = 1;
			estadoVuelo = 1;
			strcpy(codigoDeVuelo, "SNF 110");
			addPassenger(pasajeros, largo, id, nombre, apellido, precioVuelo,
					tipoPasajero, estadoVuelo, codigoDeVuelo);

			id++;
			strcpy(nombre, "Lautaro");
			strcpy(apellido, "Acuña");
			precioVuelo = 15000;
			tipoPasajero = 3;
			estadoVuelo = 2;
			strcpy(codigoDeVuelo, "MEX 710");
			addPassenger(pasajeros, largo, id, nombre, apellido, precioVuelo,
					tipoPasajero, estadoVuelo, codigoDeVuelo);
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
