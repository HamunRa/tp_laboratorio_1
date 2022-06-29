#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct {
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	char estadoVuelo[10];

} Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char *idStr, char *nombreStr,
		char *apellidoStr, char *tipoPasajeroStr, char *precioStr,
		char *flycodeStr, char *estadoDeVuelo);
void Passenger_delete();

int Passenger_setId(Passenger *this, int id);
int Passenger_getId(Passenger *this, int *id);

int Passenger_setNombre(Passenger *this, char *nombre);
int Passenger_getNombre(Passenger *this, char *nombre);

int Passenger_setApellido(Passenger *this, char *apellido);
int Passenger_getApellido(Passenger *this, char *apellido);

int Passenger_setCodigoVuelo(Passenger *this, char *codigoVuelo);
int Passenger_getCodigoVuelo(Passenger *this, char *codigoVuelo);

int Passenger_setTipoPasajero(Passenger *this, int tipoPasajero);
int Passenger_getTipoPasajero(Passenger *this, int *tipoPasajero);

int Passenger_setPrecio(Passenger *this, float precio);
int Passenger_getPrecio(Passenger *this, float *precio);

int Passenger_setEstadoVuelo(Passenger *this, char *estadoVuelo);
int Passenger_getEstadoVuelo(Passenger *this, char *estadoVuelo);

int Passenger_listCompleta(LinkedList *pArrayListPassenger);
void Passenger_lista(Passenger *lecturaDeDato);
int Passenger_idDisponible(LinkedList *pArrayListPassenger);

int Passenger_find(LinkedList *pArrayListPassenger, int idABuscar);
int Passenger_sortById(void* pasajeroUno, void* pasajeroDos);
int Passenger_sortByApellido(void* pasajeroUno, void* pasajeroDos);
#endif /* PASSENGER_H_ */
