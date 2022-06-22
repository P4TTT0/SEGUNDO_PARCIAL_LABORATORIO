/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "LinkedList.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[8];
	char estadoVuelo[40];
}Passenger;
/// @fn Passenger Passenger_new*()
/// @brief Asigna un espacio en memoria dinamica a un pasajero.
///
/// @return retorna el pasajero.
Passenger* Passenger_new();
/// @fn Passenger Passenger_newParametros*(char*, char*, char*, char*, char*, char*, char*)
/// @brief Recibe por parametro las diferentes variables para luego cargar dentro de los campos de la estructura pasajero.
///
/// @param idStr Puntero a char para cargar ID
/// @param nombreStr Puntero a char para cargar NOMBRE
/// @param apellidoStr Puntero a char para cargar APELLIDO
/// @param precioStr Puntero a char para cargar PRECIO
/// @param tipoPasajeroStr Puntero a char para cargar TIPO DE PASAJERO
/// @param codigoVueloStr Puntero a char para cargar CODIGO DE VUELO
/// @param estadoVueloStr Puntero a char para cargar ESTADO DE VUELO
/// @return Retorna el pasajero con todos sus campos rellenados.
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr,char* estadoVueloStr);
/// @fn void Passenger_delete(Passenger*)
/// @brief Libera el espacio en memoria de un pasajero.
///
/// @param this El pasajero a eliminar.
void Passenger_delete(Passenger* this);

/// @fn int Passenger_setId(Passenger*, int)
/// @brief Toma un id recibido por parametro y lo almacena en el campo id del pasajero.
///
/// @param this Pasajero.
/// @param id Valor de id recibido por parametro
/// @return VALIDACION [0] No se pudo settear | VALIDACION [1] Si se pudo settear
int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

/// @fn int Passenger_setNombre(Passenger*, char*)
/// @brief Toma un nombre recibido por parametro y lo almacena en el campo nombre del pasajero.
///
/// @param this Pasajero
/// @param nombre Valor de nombre recibido por parametro
/// @return VALIDACION [0] No se pudo settear | VALIDACION [1] Si se pudo settear
int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

/// @fn int Passenger_setApellido(Passenger*, char*)
/// @brief Toma un apellido recibido por parametro y lo almacena en el campo apellido del pasajero.
///
/// @param this Pasajero
/// @param apellido Valor de apellido recibido por parametro
/// @return VALIDACION [0] No se pudo settear | VALIDACION [1] Si se pudo settear
int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

/// @fn int Passenger_setCodigoVuelo(Passenger*, char*)
/// @brief Toma un codigo de vuelo recibido por parametro y lo almacena en el campo codigo de vuelo del pasajero.
///
/// @param this Pasajero
/// @param codigoVuelo Valor de codigo de vuelo recibido por parametro.
/// @return VALIDACION [0] No se pudo settear | VALIDACION [1] Si se pudo settear
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/// @fn int Passenger_setTipoPasajero(Passenger*, int)
/// @brief Toma un tipo de pasajero recibido por parametro y lo almacena en el campo tipo de pasajero del pasajero.
///
/// @param this Pasajero
/// @param tipoPasajero Valor del tipo de pasajero recibido por parametro.
/// @return VALIDACION [0] No se pudo settear | VALIDACION [1] Si se pudo settear
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

/// @fn int Passenger_setPrecio(Passenger*, float)
/// @brief Toma un precio recibido por parametro y lo almacena en el campo precio del pasajero.
///
/// @param this Pasajero
/// @param precio Valor del precio recibido por parametro.
/// @return VALIDACION [0] No se pudo settear | VALIDACION [1] Si se pudo settear
int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

/// @fn int Passenger_setEstadoVuelo(Passenger*, char*)
/// @brief Toma un estado de vuelo por parametro y lo almacena en el estado de vuelo del pasajero.
///
/// @param this Pasajero
/// @param estadoVuelo Valor del estado del vuelo recibido por parametro,
/// @return VALIDACION [0] No se pudo settear | VALIDACION [1] Si se pudo settear
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);

/// @fn void Passenger_list(Passenger*)
/// @brief Lista de manera ordenada los diferentes campos de un pasajero.
///
/// @param this Pasajero a listar
void Passenger_list(Passenger* this);

/// @fn int SaveTxt(FILE*, LinkedList*)
/// @brief Recibe un archivo abierto en forma de escritura de texto para realizar un guardado de todos los pasajeros
///
/// @param pFile Puntero a archivo
/// @param pArrayListPassenger Puntero a likedlist que posee todos los pasajeros en un array.
/// @return Retorna [0] si no se pudo guardar | [1] si se pudo guardar
int SaveTxt(FILE* pFile, LinkedList* pArrayListPassenger);
/// @fn int SaveBinary(FILE*, LinkedList*)
/// @brief Recibe un archivo abierto en forma de escritura binaria para realizar un guardado de todos los pasajeros
///
/// @param pFile Puntero a archivo
/// @param pArrayListPassenger Puntero a likedlist que posee todos los pasajeros en un array.
/// @return Retorna [0] si no se pudo guardar | [1] si se pudo guardar
int SaveBinary(FILE* pFile, LinkedList* pArrayListPassenger);

/// @fn int Passenger_compareByName(void*, void*)
/// @brief Recibe dos nombre para luego compararlos
///
/// @param nombreUno Primer nombre
/// @param nombreDos Segundo nombre
/// @return retorna [0] si son iguales [1] si el primer nombre es mayor que el segundo y [-1] si el primer nombre es menor que el segundo.
int Passenger_compareByName(void* nombreUno, void* nombreDos);
/// @fn int Passenger_compareByApellido(void*, void*)
/// @brief Recibe dos apellidos para luego compararlos
///
/// @param apellidoUno Primer apellido
/// @param apellidoDos Segundo apellido
/// @return retorna [0] si son iguales [1] si el primer nombre es mayor que el segundo y [-1] si el primer nombre es menor que el segundo.
int Passenger_compareByApellido(void* apellidoUno, void* apellidoDos);
/// @fn int Passenger_compareByPrecio(void*, void*)
/// @brief Recibe dos precios para luego compararlos
///
/// @param precioUno Primer precio
/// @param precioDos Segundo precio
/// @return retorna [0] si son iguales [1] si el primer nombre es mayor que el segundo y [-1] si el primer nombre es menor que el segundo.
int Passenger_compareByPrecio(void* precioUno, void* precioDos);
/// @fn int Passenger_compareById(void*, void*)
/// @brief Recibe dos id para luego comparlos
///
/// @param idUno Primer id
/// @param idDos Segundo id
/// @return retorna [0] si son iguales [1] si el primer nombre es mayor que el segundo y [-1] si el primer nombre es menor que el segundo.
int Passenger_compareById(void* idUno, void* idDos);

/// @fn int criterioOrdenamiento()
/// @brief Printea las opciones de criterio de ordenamiento
///
/// @return retorna la opcion elegida
int criterioOrdenamiento();

/// @fn int Passener_buscarId(LinkedList*, int)
/// @brief Recibe un ID, recorre la lista de pasajeros y busca igualdad entre los ID y el ID recibido
///
/// @param pArrayListPassenger Puntero a likedlist que posee todos los pasajeros en un array.
/// @param id Id a buscar
/// @return retorna la posicion en donde se encuentra el pasajero con dicha igualdad.
int Passener_buscarId(LinkedList* pArrayListPassenger, int id);

/// @fn int Passenger_modificarNombre(LinkedList*, int)
/// @brief Recibe el indice de un pasajero para modificar su nombre
///
/// @param pArrayListPassenger Puntero a likedlist que posee todos los pasajeros en un array.
/// @param indice Indice del pasajero a modificar
/// @return Retorna [1] si se pudo modificar | Retorna [0] si no se pudo modificar
int Passenger_modificarNombre(LinkedList* pArrayListPassenger, int indice);
/// @fn int Passenger_modificarApellido(LinkedList*, int)
/// @brief Recibe el indice de un pasajero para modificar su apellido
///
/// @param pArrayListPassenger Puntero a likedlist que posee todos los pasajeros en un array.
/// @param indice Indice del pasajero a modificar
/// @return  Retorna [1] si se pudo modificar | Retorna [0] si no se pudo modificar
int Passenger_modificarApellido(LinkedList* pArrayListPassenger, int indice);
/// @fn int Passenger_modificarPrecio(LinkedList*, int)
/// @brief Recibe el indice de un pasajero para modificar su precio
///
/// @param pArrayListPassenger Puntero a likedlist que posee todos los pasajeros en un array.
/// @param indice Indice del pasajero a modificar
/// @return  Retorna [1] si se pudo modificar | Retorna [0] si no se pudo modificar
int Passenger_modificarPrecio(LinkedList* pArrayListPassenger, int indice);
/// @fn int Passenger_modificarCodigoVuelo(LinkedList*, int)
/// @brief Recibe el indice de un pasajero para modificar su precio
///
/// @param pArrayListPassenger Puntero a likedlist que posee todos los pasajeros en un array.
/// @param indice Indice del pasajero a modificar
/// @return  Retorna [1] si se pudo modificar | Retorna [0] si no se pudo modificar
int Passenger_modificarCodigoVuelo(LinkedList* pArrayListPassenger, int indice);
/// @fn int Passenger_modificarTipoPasajero(LinkedList*, int)
/// @brief Recibe el indice de un pasajero para modificar su tipo de pasajero
///
/// @param pArrayListPassenger Puntero a likedlist que posee todos los pasajeros en un array.
/// @param indice Indice del pasajero a modificar
/// @return  Retorna [1] si se pudo modificar | Retorna [0] si no se pudo modificar
int Passenger_modificarTipoPasajero(LinkedList* pArrayListPassenger, int indice);
/// @fn int Passenger_modificarEstadoVuelo(LinkedList*, int)
/// @brief Recibe el indice de un pasajero para modificar su estado de vuelo.
///
/// @param pArrayListPassenger Puntero a likedlist que posee todos los pasajeros en un array.
/// @param indice Indice del pasajero a modificar
/// @return  Retorna [1] si se pudo modificar | Retorna [0] si no se pudo modificar
int Passenger_modificarEstadoVuelo(LinkedList* pArrayListPassenger, int indice);

#endif /* PASSENGER_H_ */
