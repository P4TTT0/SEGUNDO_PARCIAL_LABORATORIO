/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

#include "Servicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

typedef struct
{
	int id;
	char descripcion[50];
	int tipo;
	float precioUnitario;
	int cantidad;
	float totalServicio;
}eServicio;

/// @fn Passenger Passenger_new*()
/// @brief Asigna un espacio en memoria dinamica a un pasajero.
///
/// @return retorna el pasajero.
eServicio* Servicio_new();
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
eServicio* Servicio_newParametros(char* idStr ,char* descripcionStr,char* tipoStr,char* precioUnitarioStr,char* cantidadStr,char* totalServicioStr);
/// @fn void Passenger_delete(Passenger*)
/// @brief Libera el espacio en memoria de un pasajero.
///
/// @param this El pasajero a eliminar.
void Servicio_delete(eServicio* this);
/// @fn int Passenger_setId(Passenger*, int)
/// @brief Toma un id recibido por parametro y lo almacena en el campo id del pasajero.
///
/// @param this Pasajero.
/// @param id Valor de id recibido por parametro
/// @return VALIDACION [0] No se pudo settear | VALIDACION [1] Si se pudo settear
int Servicio_setId(eServicio* this,int id);
int Servicio_getId(eServicio* this,int* id);

/// @fn int Passenger_setNombre(Passenger*, char*)
/// @brief Toma un nombre recibido por parametro y lo almacena en el campo nombre del pasajero.
///
/// @param this Pasajero
/// @param nombre Valor de nombre recibido por parametro
/// @return VALIDACION [0] No se pudo settear | VALIDACION [1] Si se pudo settear
int Servicio_setDescripcion(eServicio* this,char* descripcion);
int Servicio_getDescripcion(eServicio* this,char* descripcion);
/// @fn int Passenger_setApellido(Passenger*, char*)
/// @brief Toma un apellido recibido por parametro y lo almacena en el campo apellido del pasajero.
///
/// @param this Pasajero
/// @param apellido Valor de apellido recibido por parametro
/// @return VALIDACION [0] No se pudo settear | VALIDACION [1] Si se pudo settear
int Servicio_setTipo(eServicio* this,int tipo);
int Servicio_getTipo(eServicio* this,int* tipo);

/// @fn int Passenger_setCodigoVuelo(Passenger*, char*)
/// @brief Toma un codigo de vuelo recibido por parametro y lo almacena en el campo codigo de vuelo del pasajero.
///
/// @param this Pasajero
/// @param codigoVuelo Valor de codigo de vuelo recibido por parametro.
/// @return VALIDACION [0] No se pudo settear | VALIDACION [1] Si se pudo settear
int Servicio_setPrecio(eServicio* this, float precioUnitario);
int Servicio_getPrecio(eServicio* this, float* precioUnitario);

/// @fn int Passenger_setTipoPasajero(Passenger*, int)
/// @brief Toma un tipo de pasajero recibido por parametro y lo almacena en el campo tipo de pasajero del pasajero.
///
/// @param this Pasajero
/// @param tipoPasajero Valor del tipo de pasajero recibido por parametro.
/// @return VALIDACION [0] No se pudo settear | VALIDACION [1] Si se pudo settear
int Servicio_setCantidad(eServicio* this,int cantidad);
int Servicio_getCantidad(eServicio* this,int* cantidad);

/// @fn int Passenger_setPrecio(Passenger*, float)
/// @brief Toma un precio recibido por parametro y lo almacena en el campo precio del pasajero.
///
/// @param this Pasajero
/// @param precio Valor del precio recibido por parametro.
/// @return VALIDACION [0] No se pudo settear | VALIDACION [1] Si se pudo settear
int Servicio_setTotalServicio(eServicio* this, float totalServicio);
int Servicio_getTotalServicio(eServicio* this, float* totalServicio);

/// @fn void Passenger_list(Passenger*)
/// @brief Lista de manera ordenada los diferentes campos de un pasajero.
///
/// @param this Pasajero a listar
void Servicio_list(eServicio* this);

void calcularPrecioFinal(void* elemeto);
int filtrarMinorista(void* elemento);
int filtrarMayorista(void* elemento);
int filtrarExportar(void* elemento);

int Servicio_compareByDescripcion(void* servicioUno, void* servicioDos);
int Servicio_compareById(void* idUno, void* idDos);

/// @fn int SaveTxt(FILE*, LinkedList*)
/// @brief Recibe un archivo abierto en forma de escritura de texto para realizar un guardado de todos los pasajeros
///
/// @param pFile Puntero a archivo
/// @param pArrayListPassenger Puntero a likedlist que posee todos los pasajeros en un array.
/// @return Retorna [0] si no se pudo guardar | [1] si se pudo guardar
int SaveTxt(FILE* pFile, LinkedList* pArrayListServicio);

#endif /* SERVICIO_H_ */
