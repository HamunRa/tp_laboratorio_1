#include "LinkedList.h"
#include "Passenger.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

Passenger* Passenger_new() {
	Passenger *nuevoPasajero = NULL;
	nuevoPasajero = (Passenger*) malloc(sizeof(Passenger));

	if (nuevoPasajero != NULL) {
		nuevoPasajero->id = 0;
		strcpy(nuevoPasajero->nombre, " ");
		strcpy(nuevoPasajero->apellido, " ");
		nuevoPasajero->tipoPasajero = 0;
		nuevoPasajero->precio = 0;
		strcpy(nuevoPasajero->codigoVuelo, " ");
	}

	return nuevoPasajero;

}

Passenger* Passenger_newParametros(char *idStr, char *nombreStr,
		char *apellidoStr, char *tipoPasajeroStr, char *precioStr,
		char *flycodeStr, char *estadoDeVuelo) {
	Passenger *nuevoPasajero = Passenger_new();
	int idAux;
	int tipoAux;
	float precioAux;

	idAux = atoi(idStr);
	tipoAux = strcmp(tipoPasajeroStr, "ExecutiveClass");

	precioAux = atof(precioStr);

	int validacion = 0;

	if (nuevoPasajero != NULL) {

		if (Passenger_setId(nuevoPasajero, idAux) == 0) {
			validacion++;
			if (Passenger_setNombre(nuevoPasajero, nombreStr) == 0) {
				validacion++;
				if (Passenger_setApellido(nuevoPasajero, apellidoStr) == 0) {
					validacion++;
					if (Passenger_setTipoPasajero(nuevoPasajero, tipoAux)
							== 0) {

						validacion++;
						if (Passenger_setPrecio(nuevoPasajero, precioAux)
								== 0) {
							validacion++;
							if (Passenger_setCodigoVuelo(nuevoPasajero,
									flycodeStr) == 0) {
								validacion++;
								if (Passenger_setEstadoVuelo(nuevoPasajero,
										estadoDeVuelo) == 0) {
									validacion++;
								}
							}
						}
					}
				}
			}

			if (validacion != 7) {
				free(nuevoPasajero);
				nuevoPasajero = NULL;
			}
		}

	}
	return nuevoPasajero;
}

int Passenger_setId(Passenger *this, int id) {

	int retorno = -1;

		if(this != NULL && id > 0)
		{
			this->id = id;
			retorno = 0;
		}

		return retorno;
}

int Passenger_getId(Passenger *this, int *id) {

	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int Passenger_setNombre(Passenger *this, char *nombre) {

	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;

}

int Passenger_getNombre(Passenger *this, char *nombre) {

	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setApellido(Passenger *this, char *apellido) {

	int retorno = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		retorno = 0;
	}

	return retorno;
}

int Passenger_getApellido(Passenger *this, char *apellido) {

	int retorno = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido,this->apellido);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setCodigoVuelo(Passenger *this, char *codigoVuelo) {

	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 0;
	}

	return retorno;
}

int Passenger_getCodigoVuelo(Passenger *this, char *codigoVuelo) {

	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setTipoPasajero(Passenger *this, int tipoPasajero) {
	this->tipoPasajero = tipoPasajero;
	if (this->tipoPasajero != tipoPasajero) {

		return 1;
	}

	return 0;
}

int Passenger_getTipoPasajero(Passenger *this, int *tipoPasajero) {
	*tipoPasajero = this->tipoPasajero;
	if (*tipoPasajero != this->tipoPasajero) {
		return 1;
	}
	return 0;
}

int Passenger_setPrecio(Passenger *this, float precio) {

	int retorno = -1;

	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}

int Passenger_getPrecio(Passenger *this, float *precio) {

	int retorno = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}

	return retorno;
}

int Passenger_getEstadoVuelo(Passenger *this, char *estadoVuelo) {

	int retorno = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(estadoVuelo,this->estadoVuelo);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setEstadoVuelo(Passenger *this, char *estadoVuelo) {

	int retorno = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(this->estadoVuelo,estadoVuelo);
		retorno = 0;
	}

	return retorno;
}

int Passenger_idDisponible(LinkedList *pArrayListPassenger) {
	Node *indice = pArrayListPassenger->pFirstNode;
	Passenger *ultimo;
	int devolver = 0;

	if (ll_len(pArrayListPassenger) == 0) {
		devolver = 1;
	} else {
		for (; indice != NULL; indice = indice->pNextNode) {
			ultimo = indice->pElement;
		}
		devolver = ultimo->id + 1;
	}

	return devolver;
}

int Passenger_listCompleta(LinkedList *pArrayListPassenger) {
	Node *indice = pArrayListPassenger->pFirstNode;
	Passenger *leer;

	printf(
			"\nID  || Apellido Nombre || Precio \t|| Tipo De Pasajero   || Codigo De Vuelo: \n");
	for (; indice != NULL; indice = indice->pNextNode) {
		leer = indice->pElement;
		Passenger_lista(leer);

	}
	return 1;
}

void Passenger_lista(Passenger *lecturaDeDato) {
	char tipoPasajeroAux[15];
	if (lecturaDeDato != NULL) {
		switch (lecturaDeDato->tipoPasajero) {
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

		printf("%d  ||  ", lecturaDeDato->id);
		printf(lecturaDeDato->apellido);
		printf(" ");
		printf(lecturaDeDato->nombre);
		printf("  ||  ");
		printf("%.2f", lecturaDeDato->precio);
		printf("  ||  ");
		printf(tipoPasajeroAux);
		printf("  ||  ");
		printf(lecturaDeDato->codigoVuelo);
		printf("  ||  ");
		printf(lecturaDeDato->estadoVuelo);
		printf("\n");
	}

}

int Passenger_find(LinkedList *pArrayListPassenger, int idABuscar) {
	int retorno = -1;
	int len;
	Passenger* pasajeroAux;
	if(pArrayListPassenger != NULL && idABuscar > 0)
	{
		len = ll_len(pArrayListPassenger);
		for(int i = 0; i < len; i++)
		{
			pasajeroAux = ll_get(pArrayListPassenger, i);
			if(pasajeroAux->id == idABuscar)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int Passenger_sortById(void* pasajeroUno, void* pasajeroDos)
{
	int retorno = -1;
	int idPasajeroUno;
	int idPasajeroDos;

	if(pasajeroUno != NULL && pasajeroDos != NULL)
	{
		if(Passenger_getId(pasajeroUno, &idPasajeroUno) == 0)
		{
			if(Passenger_getId(pasajeroDos, &idPasajeroDos) == 0)
			{
				if(idPasajeroUno > idPasajeroDos)
				{
					retorno = 1;
				}
				else
				{
					retorno = -1;
				}
			}
		}
	}

	return retorno;
}

int Passenger_sortByApellido(void* pasajeroUno, void* pasajeroDos)
{
	int retorno = -1;
	char apellidoAuxUno[50];
	char nombreAuxUno[50];
	char apellidoAuxDos[50];
	char nombreAuxDos[50];

	if(pasajeroUno != NULL && pasajeroDos != NULL)
	{
		if(Passenger_getApellido(pasajeroUno, apellidoAuxUno) == 0)
		{
			if(Passenger_getApellido(pasajeroDos, apellidoAuxDos) == 0)
			{
				retorno = strcmp(apellidoAuxUno, apellidoAuxDos);
				if(retorno == 0)
				{
					if(Passenger_getNombre(pasajeroUno, nombreAuxUno) == 0)
					{
						if(Passenger_getNombre(pasajeroDos, nombreAuxDos) == 0)
						{
							retorno = strcmp(nombreAuxUno, nombreAuxDos);
							if(retorno == 0)
							{
								retorno = Passenger_sortById(pasajeroUno, pasajeroDos);
							}
						}
					}
				}
			}
		}
	}

	return retorno;
}
