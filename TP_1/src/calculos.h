/*
 * calculos.h
 *
 *  Created on: 7 abr. 2022
 *      Author: lucas
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_


/// @fn void calcularValores (float, float, float*, float*, float*, float*)
/// @brief Se encarga de calcular los precios de los disintos medios de pago, mediante el precio de vuelo y los kilometros
///luego lo retorna a traves de su puntero
/// @param precioVuelo
/// @param kilometros
/// @param tarjetaDebito
/// @param tarjetaCredito
/// @param bitcoin
/// @param precioUnitario
void calcularValores (float precioVuelo, float kilometros, float* tarjetaDebito, float* tarjetaCredito, float* bitcoin, float* precioUnitario);


/// @fn float calcularDiferencia(float, float)
/// @brief Se encarga de calcular la diferencia entre dos precios y devuelve el valor.
/// @param precioAerolineas
/// @param precioLatam
/// @return la diferencia entre los dos numeros
float calcularDiferencia(float precioAerolineas, float precioLatam);


/// @fn void mostrarInformacion(float, float, float, float, float, float, float, float, float, float, float, float)
/// @brief Se encarga de mostrar los datos ya calculados, para que el usuario lo pueda visualizar y avisa si no se ingreso ningun valor
/// @param precioAerolineas
/// @param kilometros
/// @param aerolineasDebito
/// @param aerolineasCredito
/// @param aerolineasBitcoin
/// @param aerolineasUnitario
/// @param precioLatam
/// @param latamDebito
/// @param latamCredito
/// @param latamBitcoin
/// @param latamUnitario
/// @param diferenciaPrecios
void mostrarInformacion(float precioAerolineas, float kilometros, float aerolineasDebito, float aerolineasCredito, float aerolineasBitcoin, float aerolineasUnitario,float precioLatam, float latamDebito, float latamCredito, float latamBitcoin, float latamUnitario, float diferenciaPrecios);

#endif /* CALCULOS_H_ */
