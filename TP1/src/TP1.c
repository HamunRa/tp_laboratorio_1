/*
 ============================================================================
 Name        : TP1.c
 Author      : Soriano Baccarelli Lucas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

int main(void) {

	setbuf(stdout, NULL);

	int kilometros;
	int opcion;
	int precioAerolineas;
	float aerolineasCredito;
	float aerolineasDebito;
	float aerolineasBitcoin;
	float aerolineasUnitario;
	int precioLatam;
	float latamCredito;
	float latamDebito;
	float latamBitcoin;
	float latamUnitario;

	while (opcion != 6) {
	printf("\n1. Ingresar kilometros"
	"\n2. Ingresar precio de vuelos"
	"\n3. Calcular todos los costos"
	"\n4. Informar resultados"
	"\n5. Carga forzada de datos"
	"\n6. Salir\n"

	"\nSeleccione una opcion:");
	scanf("%d", &opcion);

	switch(opcion){
	case 1:

		printf("\nIngrese la cantidad de kilometros:");
		scanf("%d",&kilometros);

		break;
	case 2:

		printf("\nIngrese el costo del vuelo con Aerolineas: ");
		scanf("%d",&precioAerolineas);

		printf("\nIngrese el costo del vuelo con Latam: ");
		scanf("%d",&precioLatam);

		break;
	case 3:

		break;
	case 4:

		break;
	case 5:

		break;
	case 6:

		break;
	}
	}
return EXIT_SUCCESS;
}
