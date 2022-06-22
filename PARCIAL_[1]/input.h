/*
 * input.h
 *
 *  Created on: 12 may. 2022
 *      Author: Perez Cardenal Patricio
 */

#ifndef INPUT_H_
#define INPUT_H_

/// @fn int validateCharacter(char[])
/// @brief Recorre un array de string y valida que contenga letras.
///
/// @param string Array a recorrer
/// @return Retorna 0 si se encontro algun numero || Retorna 1 si contiene unicamente letras.
int validateCharacter (char string[]);

/// @fn int orderInteger(char[])
/// @brief Pide un entero.
///
/// @param number array de numeros
/// @return retorna el entero.
int orderInteger(char number[]);

/// @fn int orderFloat(char[])
/// @brief Pide un flotante
///
/// @param numbersFloat
/// @return retorna el flotante
int orderFloat(char numbersFloat[]);

/// @fn int validateNumber(char[])
/// @brief Recorre un array evaluando si contiene digitos
///
/// @param numbers array de numeros
/// @return retorna Retorna 0 si contiene todo lo que no sean digitos || Retorna 1 si contiene unicamente numeros.
int validateNumber (char numbers[]);

/// @fn int toMayus(char*)
/// @brief Recorre un array para transformar cada caracter en mayusculas
///
/// @param string array a recorrer
/// @return Retorna 0
int toMayus (char* string);

#endif /* INPUT_H_ */
