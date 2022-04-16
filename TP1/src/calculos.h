/*
 * calculos.h
 *
 *  Created on: 7 abr. 2022
 *      Author: lucas
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/// @fn void calcularValores (float precioVuelo, float kilometros, float* tarjetaDebito, float* tarjetaCredito, float* bitcoin, float* precioUnitario)
/// @brief muestra las opciones
///
/// @param opcion
/// @return retorna la opcion seleccionada
void calcularValores (float precioVuelo, float kilometros, float* tarjetaDebito, float* tarjetaCredito, float* bitcoin, float* precioUnitario);
/// @fn float calcularDiferencia(float, float)
/// @brief se encarga de calcular la diferencia entre el precio de aerolineas y el de latam
///
/// @param precioAerolineas
///	@param precioLatam
/// @return retorna la opcion seleccionada
float calcularDiferencia(float precioAerolineas, float precioLatam);
/// @fn int Opciones(int)
/// @brief muestra las opciones
///
/// @param opcion
/// @return retorna la opcion seleccionada
void mostrarInformacion(float precioAerolineas, float kilometros, float aerolineasDebito, float aerolineasCredito, float aerolineasBitcoin, float aerolineasUnitario,float precioLatam, float latamDebito, float latamCredito, float latamBitcoin, float latamUnitario, float diferenciaPrecios);

#endif /* CALCULOS_H_ */
