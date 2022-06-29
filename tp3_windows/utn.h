/*
 * utn.h
 *
 *  Created on: 9 jun. 2022
 *      Author: lucas
 */

#ifndef UTN_H_
#define UTN_H_


/// @brief Le pide al usuario que ingrese el codigo del vuelo
///
/// @param arrayRecibido devuelve el codigo de vuelo ingresado
/// @param textoAMostrar mensaje que donde se imprime

void ingresarCodigo(char arrayRecibido[], char *textoAMostrar);
/// @brief pide al usuario un dato a traves de string y cambia el ultimo bit de '\n' a '\0'
///
/// @param cadena por donde se devuelve el string
/// @param longitud tama�o del string
/// @return devuelve -1 si hay error - 0 si esta bien

int myGets(char *cadena, int longitud);

/// @brief transforma el string de esNumerica y myGets a un entero
///
/// @param pResultado donde se devuelve el entero obtenido
/// @return devuelve -1 si hay error - 0 si esta bien

int getInt(int *pResultado);

/// @brief verifica que todos sus digitos sson numericos
///
/// @param cadena por donde devuelve el string
/// @return devuelve 0 si hay error o - 1 si esta bien

int esNumerica(char *cadena);

/// @brief pide al usuario ingresar un entero usando getInt, lo verifica y lo devuelve
///
///
/// @param pResultado por el cual devuelve el entero
/// @param mensaje que se imprime para pedir el dato al usuario
/// @param mensajeError se imprime cuando el usuario no ingreso un entero
/// @param minimo delimita el numero minimo a ingresar
/// @param maximo delimita el numero maximo a ingresar
/// @return devuelve -1 si hay error - 0 si esta bien

int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo);

/// @brief transforma el string de esNumerica y myGets a un flotante
///
/// @param pResultado  por donde se devuelve el flotante
/// @return devuelve -1 si hay error- 0 si esta bien

int getFloat(float *pResultado);

/// @brief pide al usuario ingresar un flotante usando getFloat, lo verifica y lo devuelve
///
///
/// @param pResultado por el cual devuelve el flotante
/// @param mensaje que se imprime para pedir el dato al usuario
/// @param mensajeError se imprime cuando el usuario no ingresa un flotante
/// @param minimo delimita el numero minimo a ingresar
/// @param maximo delimita el numero maximo a ingresar
/// @return devuelve -1 si hay un error - 0 si esta bien

int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo);

/// @brief pide al usuario ingresar un nombre o apellido, lo verifica y devuelve el nombre o apellido
///
///
/// @param cadena por donde se devuelve el nombre o apellido
/// @param mensaje se imprime para pedirle al usuario que ingrese el nombre o apellido
/// @param mensajeError se imprime si hay caracteres que no son letras
/// @return devuelve -1 si hay error - 0 si esta bien

int utn_getName(char *cadena, char *mensaje, char *mensajeError);
#endif /* UTN_H_ */
