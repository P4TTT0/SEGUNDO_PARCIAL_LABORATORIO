/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: PATRICIO PEREZ CARDENAL
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "input.h"


Passenger* Passenger_new()
{
	Passenger* this;

	this = (Passenger*) malloc(sizeof(Passenger));

	return this;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr,char* estadoVueloStr)
{
	Passenger* this;
	int id;
	float precio;
	int tipoPasajero;

	this = Passenger_new(); //ASIGNAMOS ESPACIO EN MEMORIA DINAMICA.

	id = atoi(idStr);

	precio = atof(precioStr);

	if (strcmp(tipoPasajeroStr, "FirstClass") == 0)
	{
		tipoPasajero = 1;
	}
	else
	{
		if(strcmp(tipoPasajeroStr, "ExecutiveClass") == 0)
		{
			tipoPasajero = 2;
		}
		else
		{
			if (strcmp(tipoPasajeroStr, "EconomyClass") == 0)
			{
				tipoPasajero = 3;
			}
		}
	}
	if (this != NULL)
	{
		if(Passenger_setId(this, id) == 0 ||
		   Passenger_setNombre(this, nombreStr) == 0||
		   Passenger_setApellido(this, apellidoStr) == 0||
		   Passenger_setPrecio(this, precio) == 0||
		   Passenger_setTipoPasajero(this, tipoPasajero) == 0||
		   Passenger_setCodigoVuelo(this, codigoVueloStr) == 0||
		   Passenger_setEstadoVuelo(this, estadoVueloStr) == 0)
		{
			Passenger_delete(this);
			this = NULL;
		}
	}

	return this;
}
//-------------------------------- [BORRAR PASAJERO] --------------------------------------
void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}

//-------------------------------- [ID] --------------------------------------
int Passenger_setId(Passenger* this,int id)
{
	int retorno;

	retorno = 0;

	if (this != NULL && id > 0)
	{
		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int Passenger_getId(Passenger* this,int* id)
{
	int retorno;

	retorno = 0;

	if (this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}

//-------------------------------- [NOMBRE] --------------------------------------
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno;

	retorno = 0;

	if (this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno;

	retorno = 0;

	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 1;
	}

	return retorno;
}

//-------------------------------- [APELLIDO] --------------------------------------
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno;

	retorno = 0;

	if (this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno;

	retorno = 0;

	if (this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		retorno = 1;
	}

	return retorno;
}

//-------------------------------- [CODIGO DE VUELO] --------------------------------------
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;

	retorno = 0;

	if (this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;

	retorno = 0;

	if (this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 1;
	}

	return retorno;
}

//-------------------------------- [TIPO DE PASAJERO] --------------------------------------
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno;

	retorno = 0;

	if (this != NULL && tipoPasajero > 0)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 1;
	}

	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno;

	retorno = 0;

	if (this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 1;
	}

	return retorno;
}

//-------------------------------- [PRECIO] --------------------------------------
int Passenger_setPrecio(Passenger* this, float precio)
{
	int retorno;

	retorno = 0;

	if (this != NULL && precio > 0)
	{
		this->precio = precio;
		retorno = 1;
	}

	return retorno;
}

int Passenger_getPrecio(Passenger* this, float* precio)
{
	int retorno;

	retorno = 0;

	if (this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 1;
	}

	return retorno;
}

//-------------------------------- [ESTADO DE VUELO] --------------------------------------
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno;

	retorno = 0;

	if (this != NULL && estadoVuelo != NULL)
	{
		strcpy(this->estadoVuelo, estadoVuelo);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno;

	retorno = 0;

	if (this != NULL && estadoVuelo != NULL)
	{
		strcpy(estadoVuelo, this->estadoVuelo);
		retorno = 1;
	}

	return retorno;
}
//-------------------------------- [LISTAR UN PASAJERO] --------------------------------------
void Passenger_list(Passenger* this)
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[8];
	char estadoVuelo[40];

	char tipoPasajeroStr[20];

	Passenger_getId(this, &id);
	Passenger_getNombre(this, nombre);
	Passenger_getApellido(this, apellido);
	Passenger_getPrecio(this, &precio);
	Passenger_getCodigoVuelo(this, codigoVuelo);
	Passenger_getTipoPasajero(this, &tipoPasajero);
	Passenger_getEstadoVuelo(this, estadoVuelo);

	if (tipoPasajero == 1)
	{
		strcpy(tipoPasajeroStr, "FirstClass");
	}
	else
	{
		if (tipoPasajero == 2)
		{
			strcpy(tipoPasajeroStr, "ExecutiveClass");
		}
		else
		{
			strcpy(tipoPasajeroStr, "EconomyClass");
		}
	}

	printf("||%-10d||%-16s||%-18s||%-12.2f||%-18s||%-19s||%-18s||\n",
			id,
			nombre,
			apellido,
			precio,
			codigoVuelo,
			tipoPasajeroStr,
			estadoVuelo);
}

int SaveTxt(FILE* pFile, LinkedList* pArrayListPassenger)
{
	int longitud;
	int i;
	int auxId;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	int auxTipoPasajero;
	char auxTipoPasajeroStr[50];
	char auxCodigoVuelo[8];
	char auxEstadoVuelo[40];
	int validacion;

	validacion = 0;

	Passenger* this;

	if (pFile == NULL && pArrayListPassenger == NULL)
	{
		printf("[ERROR] - NO EXISTE EL ARCHIVO");
		exit(1);
	}

	longitud = ll_len(pArrayListPassenger);

	if (longitud > 0)
	{
		fprintf(pFile, "ID,NOMBRE,APELLIDO,PRECIO,CODIGOVUELO,TIPOPASAJERO,ESTADOVUELO\n");

		for(i = 0; i < longitud; i++)
		{
			this = (Passenger*) ll_get(pArrayListPassenger, i);
			if (this != NULL)
			{
				Passenger_getId(this, &auxId);
				Passenger_getNombre(this, auxNombre);
				Passenger_getApellido(this, auxApellido);
				Passenger_getPrecio(this, &auxPrecio);
				Passenger_getCodigoVuelo(this, auxCodigoVuelo);
				Passenger_getTipoPasajero(this, &auxTipoPasajero);
				Passenger_getEstadoVuelo(this, auxEstadoVuelo);

				if (auxTipoPasajero == 1)
					{
						strcpy(auxTipoPasajeroStr, "FirstClass");
					}
					else
					{
						if (auxTipoPasajero == 2)
						{
							strcpy(auxTipoPasajeroStr, "ExecutiveClass");
						}
						else
						{
							strcpy(auxTipoPasajeroStr, "EconomyClass");
						}
					}

				fprintf(pFile, "%d,%s,%s,%f,%s,%s,%s\n", auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajeroStr, auxEstadoVuelo);

				validacion = 1;
			}
		}
	}

	return validacion;
}

int SaveBinary(FILE* pFile, LinkedList* pArrayListPassenger)
{
	int longitud;
	int i;
	int validacion;

	validacion = 0;

	Passenger* this;

	if (pFile == NULL && pArrayListPassenger == NULL)
	{
		printf("[ERROR] - NO EXISTE EL ARCHIVO");
		exit(1);
	}

	longitud = ll_len(pArrayListPassenger);

	if (longitud > 0)
	{
		for(i = 0; i < longitud; i++)
		{
			this = (Passenger*) ll_get(pArrayListPassenger, i);
			if (this != NULL)
			{
				fwrite(this, sizeof(Passenger), 1, pFile);

				validacion = 1;
			}
		}
	}

	return validacion;
}

int Passenger_compareByName(void* nombreUno, void* nombreDos)
{
	int validacion;
	char auxNombreUno[50];
	char auxNombreDos[50];

	Passenger* nombrePasajeroUno;
	Passenger* nombrePasajeroDos;

	nombrePasajeroUno = (Passenger*) nombreUno;
	nombrePasajeroDos = (Passenger*) nombreDos;

	Passenger_getNombre(nombrePasajeroUno, auxNombreUno);
	Passenger_getNombre(nombrePasajeroDos, auxNombreDos);

	if(strcmp(auxNombreUno, auxNombreDos) == 0)
	{
		validacion = 0;
	}
	else
	{
		if (strcmp(auxNombreUno, auxNombreDos) > 0)
		{
			validacion = 1;
		}
		else
		{
			validacion = -1;
		}
	}
	return validacion;
}

int Passenger_compareByApellido(void* apellidoUno, void* apellidoDos)
{
	int validacion;
	char auxApellidoUno[50];
	char auxApellidoDos[50];

	Passenger* apellidoPasajeroUno;
	Passenger* apellidoPasajeroDos;

	apellidoPasajeroUno = (Passenger*) apellidoUno;
	apellidoPasajeroDos = (Passenger*) apellidoDos;

	Passenger_getApellido(apellidoPasajeroUno, auxApellidoUno);
	Passenger_getApellido(apellidoPasajeroDos, auxApellidoDos);

	if(strcmp(auxApellidoUno, auxApellidoDos) == 0)
	{
		validacion = 0;
	}
	else
	{
		if (strcmp(auxApellidoUno, auxApellidoDos) > 0)
		{
			validacion = 1;
		}
		else
		{
			validacion = -1;
		}
	}
	return validacion;
}

int Passenger_compareByPrecio(void* precioUno, void* precioDos)
{
	int validacion;
	float auxPrecioUno;
	float auxPrecioDos;

	Passenger* precioPasajeroUno;
	Passenger* precioPasajeroDos;

	precioPasajeroUno = (Passenger*) precioUno;
	precioPasajeroDos = (Passenger*) precioDos;

	Passenger_getPrecio(precioPasajeroUno, &auxPrecioUno);
	Passenger_getPrecio(precioPasajeroDos, &auxPrecioDos);

	if(auxPrecioUno == auxPrecioDos)
	{
		validacion = 0;
	}
	else
	{
		if (auxPrecioUno > auxPrecioDos)
		{
			validacion = 1;
		}
		else
		{
			validacion = -1;
		}
	}
	return validacion;
}

int Passenger_compareById(void* idUno, void* idDos)
{
	int validacion;
	int auxIdUno;
	int auxIdDos;

	Passenger* idPasajeroUno;
	Passenger* idPasajeroDos;

	idPasajeroUno = (Passenger*) idUno;
	idPasajeroDos = (Passenger*) idDos;

	Passenger_getId(idPasajeroUno, &auxIdUno);
	Passenger_getId(idPasajeroDos, &auxIdDos);

	if(auxIdUno == auxIdDos)
	{
		validacion = 0;
	}
	else
	{
		if (auxIdUno > auxIdDos)
		{
			validacion = 1;
		}
		else
		{
			validacion = -1;
		}
	}
	return validacion;
}

int criterioOrdenamiento()
{
	int opcion;

	printf("||----< | [CRITERIO] | >---||\n\n"

	"[0] | Ordenar en [DESCENDENTE]\n"
	"[1] | Ordenar en [ASCENDENTE]\n\n"

	"||--->[INGRESAR OPCION]:");

	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}

int Passener_buscarId(LinkedList* pArrayListPassenger, int id)
{
	int indice;
	int i;
	int longitud;
	Passenger* this;

	indice = -1;

	if (pArrayListPassenger != NULL)
	{
		longitud = ll_len(pArrayListPassenger);

		if (longitud > 0)
		{
			for (i = 0; i < longitud; i++)
			{
				this = (Passenger*) ll_get(pArrayListPassenger, i);

				if (this->id == id)
				{
					indice = i;
					break;
				}
			}
		}
	}

	return indice;
}

int Passenger_modificarNombre(LinkedList* pArrayListPassenger, int indice)
{
	char auxNombre[50];
	int validacion;
	int retorno;

	retorno = 0;

	Passenger* this;

	if (pArrayListPassenger != NULL)
	{
		printf("[1] | Modificar [NOMBRE]\n\n"
				"|| Ingrese el nuevo nombre ->|:");

		fflush(stdin);
		gets(auxNombre);

		validacion = validateCharacter(auxNombre);

		if (validacion == 0)
		{
			printf("||[ERROR] -> Ingrese el nuevo nombre ->|:");

			fflush(stdin);
			gets(auxNombre);
		}

		this = (Passenger*) ll_get(pArrayListPassenger, indice);

		if (this != NULL)
		{
			Passenger_setNombre(this, auxNombre);
			retorno = 1;
		}
	}

	return retorno;
}

int Passenger_modificarApellido(LinkedList* pArrayListPassenger, int indice)
{
	char auxApellido[50];
	int validacion;
	int retorno;

	retorno = 0;

	Passenger* this;

	if (pArrayListPassenger != NULL)
	{
		printf("[2] | Modificar [APELLIDO]\n\n"
				"|| Ingrese el nuevo apellido ->|:");

		fflush(stdin);
		gets(auxApellido);

		validacion = validateCharacter(auxApellido);

		if (validacion == 0)
		{
			printf("||[ERROR] -> Ingrese el nuevo apellido ->|:");

			fflush(stdin);
			gets(auxApellido);
		}

		this = (Passenger*) ll_get(pArrayListPassenger, indice);

		if (this != NULL)
		{
			Passenger_setApellido(this, auxApellido);
			retorno = 1;
		}
	}

	return retorno;
}

int Passenger_modificarPrecio(LinkedList* pArrayListPassenger, int indice)
{
	float auxPrecio;
	int retorno;

	retorno = 0;

	Passenger* this;

	if (pArrayListPassenger != NULL)
	{
		auxPrecio = orderFloat("[3] | Modificar [PRECIO]\n\n"
								"|| Ingrese el nuevo precio -> (500 - 10.000) |:");

		while (auxPrecio < 500 || auxPrecio > 100000)
		{
			auxPrecio = orderFloat("||[ERROR] -> Ingrese el nuevo precio -> (500 - 10.000) |:");
		}

		this = (Passenger*) ll_get(pArrayListPassenger, indice);

		if (this != NULL)
		{
			Passenger_setPrecio(this, auxPrecio);
			retorno = 1;
		}
	}

	return retorno;
}

int Passenger_modificarCodigoVuelo(LinkedList* pArrayListPassenger, int indice)
{
	char auxCodigoVuelo[8];
	int retorno;

	retorno = 0;

	Passenger* this;

	if (pArrayListPassenger != NULL)
	{
		printf("[4] | Modificar [CODIGO DE VUELO]\n\n"
				"|| Ingrese el nuevo codigo de vuelo -> (7 Caracteres) |:");

		fflush(stdin);
		gets(auxCodigoVuelo);
		toMayus(auxCodigoVuelo);

		while (strlen(auxCodigoVuelo) != 7)
		{
			printf("||[ERROR] -> Ingrese el [CODIGO DE VUELO] | (7 Caracteres)");

			fflush(stdin);
			gets(auxCodigoVuelo);
			toMayus(auxCodigoVuelo);
		}

		this = (Passenger*) ll_get(pArrayListPassenger, indice);

		if (this != NULL)
		{
			Passenger_setCodigoVuelo(this, auxCodigoVuelo);
			retorno = 1;
		}
	}

	return retorno;
}

int Passenger_modificarTipoPasajero(LinkedList* pArrayListPassenger, int indice)
{
	int auxTipoPasajero;
	int retorno;

	retorno = 0;

	Passenger* this;

	if (pArrayListPassenger != NULL)
	{
		auxTipoPasajero = orderInteger("[5] | Modificar [TIPO DE PASAJERO]\n\n"
										"[1] - FirstClass\n"
										"[2] - ExecutiveClass\n"
										"[3] - EconomyClass");

		while (auxTipoPasajero < 1 || auxTipoPasajero > 3)
		{
			auxTipoPasajero = orderInteger("[5] |[ERROR] -> Ingrese un [TIPO DE PASAJERO]\n\n"
												"[1] - FirstClass\n"
												"[2] - ExecutiveClass\n"
												"[3] - EconomyClass");
		}

		this = (Passenger*) ll_get(pArrayListPassenger, indice);

		if (this != NULL)
		{
			Passenger_setTipoPasajero(this, auxTipoPasajero);
			retorno = 1;
		}
	}

	return retorno;
}

int Passenger_modificarEstadoVuelo(LinkedList* pArrayListPassenger, int indice)
{
	int auxEstadoVuelo;
	char auxEstadoVueloStr[30];
	int retorno;

	retorno = 0;

	Passenger* this;
	if (pArrayListPassenger != NULL)
	{
		auxEstadoVuelo = orderInteger("[6] | Modificar [ESTADO DE VUELO]\n\n"
									"[1] - En Horario\n"
									"[2] - Demorado\n"
									"[3] - Aterrizado");

		while(auxEstadoVuelo < 1 || auxEstadoVuelo > 3)
		{
			auxEstadoVuelo = orderInteger("[6]|[ERROR] -> Ingrese un [ESTADO DE VUELO]\n\n"
											"[1] - En Horario\n"
											"[2] - Demorado\n"
											"[3] - Aterrizado");
		}

		//-----------------[ELVAUA OPCION ELEGIDA]--------------------
		switch (auxEstadoVuelo)
		{
			case 1:
				strcpy(auxEstadoVueloStr, "En Horario");
			break;

			case 2:
				strcpy(auxEstadoVueloStr, "Demorado");
			break;

			default:
				strcpy(auxEstadoVueloStr, "Aterrizado");
			break;
		}

			this = (Passenger*) ll_get(pArrayListPassenger, indice);

			if (this != NULL)
			{
				Passenger_setEstadoVuelo(this, auxEstadoVueloStr);
				retorno = 1;
			}
	}

	return retorno;
}
