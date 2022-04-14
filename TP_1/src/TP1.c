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

	float kilometros;
	int opcion;
	float precioVueloAerolineas;
	float aerolineasCredito;
	float aerolineasDebito;
	float aerolineasBitcoin;
	float aerolineasUnitario;
	float precioVueloLatam;
	float latamCredito;
	float latamDebito;
	float latamBitcoin;
	float latamUnitario;
	char aerolineasOLatam;
	int kilometrosForzado;
	int precioAerolineaForzado;
	int precioLatamForzado;
	float diferenciaPrecios;

	kilometros = 0;
	precioVueloAerolineas = 0;
	precioVueloLatam = 0;
	kilometrosForzado = 7090;
	precioAerolineaForzado = 162965;
	precioLatamForzado = 159339;

	do{
	printf("\n1. Ingresar kilometros"
	"\n2. Ingresar precio de vuelos"
	"\n3. Calcular todos los costos"
	"\n4. Informar resultados"
	"\n5. Carga forzada de datos"
	"\n6. Salir\n"

	"\nSeleccione una opcion:");
	fflush(stdin);
	scanf("%d", &opcion);

	switch(opcion){
	case 1:

		do {
			printf("\nIngrese la cantidad de kilometros:");
			fflush(stdin);
			scanf("%f",&kilometros);
		} while (kilometros <= 0);
		break;
	case 2:

		do {
			printf("\nDesea ingresar el precio de Aerolineas o Latam?"
					"\n'a' para aerolineas o 'l' para latam) ");
			fflush(stdin);
			scanf("%c",&aerolineasOLatam);

			switch(aerolineasOLatam){
			case 'a':
				do {
					printf("Ingrese el precio del vuelo: ");
					fflush(stdin);
					scanf("%f",&precioVueloAerolineas);
				}while (precioVueloAerolineas <= 0);
				break;
			case 'l':
				do {
					printf("Ingrese el precio del vuelo: ");
					fflush(stdin);
					scanf("%f",&precioVueloLatam);
				}while (precioVueloLatam <= 0);
				break;
			}
		}while (aerolineasOLatam != 'a' && aerolineasOLatam !='l');
		break;
	case 3:
		if (kilometros > 0 && (precioVueloAerolineas > 0 || precioVueloLatam >0 )){
			calcularValores (precioVueloAerolineas, kilometros, &aerolineasDebito, &aerolineasCredito, &aerolineasBitcoin, &aerolineasUnitario);
			calcularValores (precioVueloLatam, kilometros, &latamDebito, &latamCredito, &latamBitcoin, &latamUnitario);
			diferenciaPrecios = calcularDiferencia(precioVueloAerolineas, precioVueloLatam);
			printf("\nYa estan realizadas las cuentas\n");
		}else {
			printf("\nNo ingreso los kilometros o el precio del vuelo\n");
		}
		break;
	case 4:
		mostrarInformacion (precioVueloAerolineas, kilometros, aerolineasDebito, aerolineasCredito, aerolineasBitcoin, aerolineasUnitario, precioVueloLatam, latamDebito, latamCredito, latamBitcoin, latamUnitario, diferenciaPrecios);
		break;
	case 5:
		calcularValores (precioAerolineaForzado, kilometrosForzado, &aerolineasDebito, &aerolineasCredito, &aerolineasBitcoin, &aerolineasUnitario);
		calcularValores (precioLatamForzado, kilometrosForzado, &latamDebito, &latamCredito, &latamBitcoin, &latamUnitario);
		diferenciaPrecios = calcularDiferencia(precioAerolineaForzado, precioLatamForzado);

		mostrarInformacion (precioAerolineaForzado, kilometrosForzado, aerolineasDebito, aerolineasCredito, aerolineasBitcoin, aerolineasUnitario, precioLatamForzado, latamDebito, latamCredito, latamBitcoin, latamUnitario, diferenciaPrecios);
		break;
	case 6:
		printf("\n¡Hasta la proxima!");
		break;
	default:
		printf("\nError, ingrese una opcion valida\n");
	}
	} while (opcion != 6 ) ;

return EXIT_SUCCESS;
}
