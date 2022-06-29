#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListPassenger) {
	FILE *pFile;
	int validarParseo = 0;

	pFile = fopen(path, "r");
	if (pFile == NULL) {
		return 0;
	}

	validarParseo = parser_PassengerFromText(pFile, pArrayListPassenger);
	fclose(pFile);

	return validarParseo;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListPassenger) {
	FILE *pFile;
	int validarParseo = 0;

	pFile = fopen(path, "rb");
	if (pFile == NULL) {
		printf("\nNo se puedo abrir el archivo.\n");
	} else {
		validarParseo = parser_PassengerFromBinary(pFile, pArrayListPassenger);
	}
	fclose(pFile);

	return validarParseo;
}

/** \brief Alta de pasajero
 *
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList *pArrayListPassenger) {
	int retorno = 0;
	Passenger *nuevo;

	int idAux;
	char idChar[15];
	char nombre[15];
	char apellido[15];
	int precioAux;
	char precioChar[15];
	int tipoAux;
	char tipoChar[15];
	char codigo[15];
	char estado[15];

	idAux = Passenger_idDisponible(pArrayListPassenger);
	itoa(idAux, idChar, 10);

	utn_getName(nombre, "Ingrese el nombre del pasajero.","Error");
	utn_getName(apellido, "Ingrese el apellido del pasajero.","Error");

	utn_getInt(&precioAux, "Ingrese el precio del vuelo.",
			"\nError, ingrese un numero valido.\n", 1, 1000000);
	itoa(precioAux, precioChar, 10);

	utn_getInt(&tipoAux, "Ingrese el tipo de pasajero\n"
			"\n1- Clase economica."
			"\n2. Clase ejecutiva."
			"\n3. Primera clase.", "\nError, ingrese una opcion valida.\n", 1,
			3);
	fflush(stdin);
	switch (tipoAux) {
	case 1:
		strcpy(tipoChar, "EconomyClass");
		break;
	case 2:
		strcpy(tipoChar, "ExecutiveClass");
		break;
	case 3:
		strcpy(tipoChar, "FirstClass");
		break;
	}
	printf("Ingrese el codigo de vuelo.");
	gets(codigo);
	fflush(stdin);

	utn_getName(estado, "Ingrese el estado de vuelo.","Error");

	nuevo = Passenger_newParametros(idChar, nombre, apellido, tipoChar,
			precioChar, codigo, estado);
	if (nuevo != NULL) {
		printf(
				"\nPasajero cargado correctamente.\nEl id correspondiente es %d\n",
				nuevo->id);
		retorno = 1;
		ll_add(pArrayListPassenger, nuevo);
	}

	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList *pArrayListPassenger) {
	Passenger *idAModificar;

	int retorno = 0;

	int id = -1;
	int index;
	int opcion = 0;

	char nombre[15];
	char apellido[15];
	float precio;
	int tipo;
	char codigo[15];

	utn_getInt(&id, "Ingrese el id del pasajero\n",
			"\nId no encontrado\n", 1, ll_len(pArrayListPassenger));
	if (id != -1) {

		index = Passenger_find(pArrayListPassenger, id);

		idAModificar = ll_get(pArrayListPassenger, index);

		printf("El usuario con ese ID es:\n");
		Passenger_lista(idAModificar);
		printf(
				"\n--------------------------------------------------------------\n");
		do {
			printf("\nQue desea modificar a continuacion?\n"
					"1. Nombre\n"
					"2. Apellido\n"
					"3. Precio\n"
					"4. Tipo de pasajero\n"
					"5. Codigo de vuelo\n"
					"6. Salir\n");
			scanf("%d", &opcion);
			fflush(stdin);
			switch (opcion) {
			case 1:
				utn_getName(nombre, "Ingrese el nombre del pasajero.","Error");
				Passenger_setNombre(idAModificar, nombre);
				printf("Nombre modificado con exito");
				break;
			case 2:
				utn_getName(apellido, "Ingrese el apellido del pasajero.","Error");
				Passenger_setApellido(idAModificar, apellido);
				printf("Apellido modificado con exito");
				break;
			case 3:
				utn_getFloat(&precio, "Ingrese el precio del vuelo.",
						"\nError, ingrese un numero valido.\n", 1, 1000000);
				Passenger_setPrecio(idAModificar, precio);
				printf("Precio modificado con exito");
				break;
			case 4:
				utn_getInt(&tipo, "Ingrese el tipo de pasajero\n"
						"\n1- Clase economica."
						"\n2. Clase ejecutiva."
						"\n3. Primera clase.",
						"\nError, ingrese una opcion valida.\n", 1, 3);
				Passenger_setTipoPasajero(idAModificar, tipo);
				printf("Tipo modificado con exito");
				break;
			case 5:
				utn_getName(codigo, "Ingrese el codigo de vuelo.","Error");
				Passenger_setCodigoVuelo(idAModificar, codigo);
				printf("Codigo de vuelo modificado con exito");
				break;
			case 6:
				retorno = 1;
				printf("Saliendo al menu");
				break;
			default:
				printf("opcion no valida\n");
				break;
			}
		} while (opcion != 6);

	}
	return retorno;
}

/** \brief Baja de pasajero
 *
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList *pArrayListPassenger) {
	int idABuscar;
	Passenger *aEliminar;
	int index;
	int respuesta;

	int retorno = 0;

	utn_getInt(&idABuscar, "Ingrese el id del pasajero\n",
			"\nId no encontrado\n", 1, ll_len(pArrayListPassenger));
	if (idABuscar != -1) {

		index = Passenger_find(pArrayListPassenger, idABuscar);

		aEliminar = ll_get(pArrayListPassenger, index);

		printf("El usuario con ese ID es:\n");
		Passenger_lista(aEliminar);
		utn_getInt(&respuesta,
				"desea eliminarlo?\n 1- Si \t 2- No",
				"\nOpcion no valida\n", 1, 2);


			ll_remove(pArrayListPassenger, index);
			retorno = 1;

	}

	return retorno;
}

/** \brief Listar pasajeros
 *
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList *pArrayListPassenger) {

	if (pArrayListPassenger != NULL) {
		Passenger_listCompleta(pArrayListPassenger);
	}
	return 0;
}

/** \brief Ordenar pasajeros
 *
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList *pArrayListPassenger) {
	int retorno = -1;
	int orden;
	int criterio;

	if (pArrayListPassenger != NULL) {
		utn_getInt(&criterio, "\nOpciones de ordenamiento:\n"
				"  1- Ordenar por id.\n"
				"  2- Ordenar por apellido.\n"
				"Como quiere ordenar la lista? ",
				"Error. Ingrese una opcion valida.\n", 1, 2);
		utn_getInt(&orden,
				"Ingrese 1 para orden ascendente o 0 para orden desencente: ",
				"Error. Ingrese una opcion valida.\n", 0, 1);

		switch (criterio) {
		case 1:
			if (ll_sort(pArrayListPassenger, Passenger_sortById, orden) == 0) {
				retorno = 1;
			}
			break;
		case 2:
			if (ll_sort(pArrayListPassenger, Passenger_sortByApellido, orden) == 0) {
				retorno = 2;
			}
			break;
		}
	}

	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListPassenger) {
	FILE *pFile;

	int retorno = 1;
	pFile = fopen(path, "w");
	if (pFile == NULL) {
		retorno = 0;
	}

	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char flycode[8];
	char tipoPasajeroAux[15];
	int tipoPasajero;
	char statusFlight[15];

	Node *indice = pArrayListPassenger->pFirstNode;
	fprintf(pFile, "%s,%s,%s,%s,%s,%s,%s\n", "id", "name", "lastname", "price",
			"flycode", "typePassenger", "statusFlight");

	for (; indice != NULL; indice = indice->pNextNode) {

		Passenger_getId(indice->pElement, &id);
		Passenger_getNombre(indice->pElement, nombre);
		Passenger_getApellido(indice->pElement, apellido);
		Passenger_getPrecio(indice->pElement, &precio);
		Passenger_getCodigoVuelo(indice->pElement, flycode);
		Passenger_getTipoPasajero(indice->pElement, &tipoPasajero);
		Passenger_getEstadoVuelo(indice->pElement, statusFlight);

		switch (tipoPasajero) {
		case -1:
			strcpy(tipoPasajeroAux, "EconomyClass");
			break;
		case 0:
			strcpy(tipoPasajeroAux, "ExecutiveClass");
			break;
		case 1:
			strcpy(tipoPasajeroAux, "FirstClass");
			break;
		}

		fprintf(pFile, "%d,%s,%s,%f,%s,%s,%s\n", id, nombre, apellido, precio,
				flycode, tipoPasajeroAux, statusFlight);

	}

	fclose(pFile);

	return retorno;

}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListPassenger) {
	FILE *pFile;
	int retorno = 1;
	pFile = fopen(path, "wb");
	if (pFile == NULL) {

		retorno = 0;
	}

	Node *indice = pArrayListPassenger->pFirstNode;

	for (; indice != NULL; indice = indice->pNextNode) {
		fwrite(indice->pElement, sizeof(Passenger), 1, pFile);
	}
	fclose(pFile);

	return retorno;

}
/** \brief Un contador de las ID para verificar que no se dupliquen
 *
 * \param pArrayListPassenger LinkedList *
 * \param contador int
 * \return int
 *
 */
int controller_contador(LinkedList *pArrayListPassenger, int contador) {
	int retorno = 0;
	int i;
	Passenger *aux;
	int largo = ll_len(pArrayListPassenger);
	if (contador == 0) {
		retorno = 1;
	}
	for (i = 0; i < contador; i++) {
		aux = ll_get(pArrayListPassenger, i);
		Passenger_setId(aux, (largo + i + contador));
		ll_set(pArrayListPassenger, i, aux);
	}

	return retorno;
}
