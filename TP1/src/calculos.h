/*
 * calculos.h
 *
 *  Created on: 7 abr. 2022
 *      Author: lucas
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

void calcularValores (float precioVuelo, float kilometros, float* tarjetaDebito, float* tarjetaCredito, float* bitcoin, float* precioUnitario);
float calcularDiferencia(float precioAerolineas, float precioLatam);
void mostrarInformacion(float precioAerolineas, float kilometros, float aerolineasDebito, float aerolineasCredito, float aerolineasBitcoin, float aerolineasUnitario,float precioLatam, float latamDebito, float latamCredito, float latamBitcoin, float latamUnitario, float diferenciaPrecios);

#endif /* CALCULOS_H_ */
