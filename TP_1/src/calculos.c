/*
 * calculos.c
 *
 *  Created on: 7 abr. 2022
 *      Author: lucas
 */
#include <stdio.h>
#include <stdlib.h>

void calcularValores (float precioVuelo, float kilometros, float* tarjetaDebito, float* tarjetaCredito, float* bitcoin, float* precioUnitario){

	float bitcoinValor;
	float descuentoDebito;
	float interesCredito;

	bitcoinValor = 4606954.55;
	descuentoDebito = 0.9;
	interesCredito = 1.25;

	*tarjetaDebito = precioVuelo * descuentoDebito;
	*tarjetaCredito = precioVuelo * interesCredito;
	*bitcoin = precioVuelo / bitcoinValor;
	*precioUnitario = precioVuelo / kilometros;

}

float calcularDiferencia (float precioAerolineas, float precioLatam){

	float retorno;

	if (precioAerolineas > precioLatam){
		retorno = precioAerolineas - precioLatam;
	}else {
		retorno = precioLatam - precioAerolineas;
	}

	return retorno;
}

void mostrarInformacion(float precioAerolineas, float kilometros, float aerolineasDebito, float aerolineasCredito, float aerolineasBitcoin, float aerolineasUnitario, float precioLatam, float latamDebito, float latamCredito, float latamBitcoin, float latamUnitario, float diferenciaPrecios){

	if (precioAerolineas > 0){
		printf("\nKMs Ingresados: %.2f km\n", kilometros);
		printf("\nPrecio Aerolineas: $%.2f",precioAerolineas);
		printf("\na)Precio con tarjeta de debito: $%.2f",aerolineasDebito);
		printf("\nb)Precio con tarjeta de credito: $%.2f",aerolineasCredito);
		printf("\nc)Precio pagando con bitcoin: %.2f BTC",aerolineasBitcoin);
		printf("\nd)Mostrar precio unitario: $%.2f\n",aerolineasUnitario);
	}else {
		printf("\nNo ingresaron ningun valor para Aerolineas\n");
	}

	if (precioLatam > 0){
			printf("\nPrecio Aerolineas: $%.2f",precioLatam);
			printf("\na)Precio con tarjeta de debito: $%.2f",latamDebito);
			printf("\nb)Precio con tarjeta de credito: $%.2f",latamCredito);
			printf("\nc)Precio pagando con bitcoin: %.2f BTC",latamBitcoin);
			printf("\nd)Mostrar precio unitario: $%.2f\n",latamUnitario);
			printf("\nLa diferencia de precio es: %.2f\n",diferenciaPrecios);
		}else {
			printf("\nNo ingresaron ningun valor para Latam\n");
		}

}

