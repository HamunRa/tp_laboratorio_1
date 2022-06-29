#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
 Menu:
 1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
 2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
 3. Alta de pasajero
 4. Modificar datos de pasajero
 5. Baja de pasajero
 6. Listar pasajeros
 7. Ordenar pasajeros
 8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
 9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
 10. Salir
 *****************************************************/

int main() {
	setbuf(stdout, NULL);
	int flagDatos = 0;
	int flagCargaDatos = 0;
	int flagGuardar = 0;

	int opcion = 0;

	int contadorIdsAlta = 0;
	int opcionesOrdenado;

	LinkedList *listaPasajeros = ll_newLinkedList();

	do {
		printf(
				"\t\t------------MENU------------\t"
						"\nIngrese la opcion deseada.\n"
						"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
						"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
						"3. Alta de pasajero\n"
						"4. Modificar datos de pasajero\n"
						"5. Baja de pasajero\n"
						"6. Listar pasajeros\n"
						"7. Ordenar pasajeros\n"
						"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
						"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
						"10. Salir\n");

		printf("\nIngrese una opcion:");
		scanf("%d", &opcion);
		fflush(stdin);

		switch (opcion) {
		case 1:
			if (flagCargaDatos == 0) {
				flagCargaDatos = 1;
				controller_loadFromText("data.csv", listaPasajeros);
				if (controller_contador(listaPasajeros, contadorIdsAlta) == 0) {
					printf("se generaron nuevos IDs");

				}
			} else {
				printf("Los datos solo pueden ser cargados una vez\n");
			}
			flagDatos = 1;
			break;
		case 2:
			if (flagCargaDatos == 0) {

				flagCargaDatos = 1;
				controller_loadFromBinary("data.bin", listaPasajeros);

				if (controller_contador(listaPasajeros, contadorIdsAlta) == 0) {
					printf("se generaron nuevos IDs");
				}
			} else {
				printf(
						"Los datos solo pueden ser cargados una vez\n");
			}
			flagDatos = 1;
			break;
		case 3:
			if (controller_addPassenger(listaPasajeros) != 1) {
				printf("Hubo un error al cargar el pasajero");
			} else {
				contadorIdsAlta++;
				flagDatos = 1;
			}
			break;
		case 4:
			if (flagDatos == 0) {
				printf("Primero debe ingresar datos\n");
			} else {
				controller_editPassenger(listaPasajeros);
				printf("se modifico correctamente");

			}
			break;
		case 5:
			if (flagDatos == 0) {
				printf("Primero debe ingresar datos\n");
			} else {
					controller_removePassenger(listaPasajeros);
					printf("Se elimino correctamente");
			}

			break;
		case 6:
			if (flagDatos == 0) {
				printf("Primero debe ingresar datos.\n");
			} else {
				controller_ListPassenger(listaPasajeros);
			}

			break;
		case 7:
				opcionesOrdenado = controller_sortPassenger(listaPasajeros);
				switch (opcionesOrdenado) {
				case 1:
					printf("\nSe ordeno correctamente los pasajeros por id.\n");
					break;
				case 2:
					printf("\nSe ordeno correctamente los pasajeros por apellido.\n");
				}
			break;
		case 8:
			controller_saveAsText("dataNuevo.csv",listaPasajeros);
			printf("\nSe guardo correctamente.\n");
			flagGuardar = 1;

			break;
		case 9:
			controller_saveAsBinary("data.bin", listaPasajeros);
			printf("\nSe guardo correctamente.\n");
			flagGuardar = 1;

			break;
		default:
			if (flagGuardar == 0) {
				printf("\nError. No puede cerrar el sistema sin guardar los datos antes\n");
			} else {
				printf("\nCerrando sistema.\n");
			}

		}
	} while (opcion != 10 || flagGuardar != 1);
	return 0;
}
