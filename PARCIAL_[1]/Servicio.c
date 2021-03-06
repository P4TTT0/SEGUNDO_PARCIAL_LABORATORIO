/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: PATRICIO PEREZ CARDENAL
 */
#include "Servicio.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "input.h"


eServicio* Servicio_new()
{
	eServicio* this;

	this = (eServicio*) malloc(sizeof(eServicio));

	return this;
}

eServicio* Servicio_newParametros(char* idStr ,char* descripcionStr,char* tipoStr,char* precioUnitarioStr,char* cantidadStr,char* totalServicioStr)
{
	eServicio* this;
	int id;
	float precioUnitario;
	int tipo;
	int cantidad;
	float totalServicio;

	this = Servicio_new(); //ASIGNAMOS ESPACIO EN MEMORIA DINAMICA.

	id = atoi(idStr);
	tipo = atoi(tipoStr);
	precioUnitario = atof(precioUnitarioStr);
	cantidad = atoi(cantidadStr);
	totalServicio = atof(totalServicioStr);

	if (this != NULL)
	{
		if (Servicio_setTotalServicio(this, totalServicio) == 0)
		{
			system("pause");
		}
		if(Servicio_setId(this, id) == 0 ||
		   Servicio_setDescripcion(this, descripcionStr) == 0||
		   Servicio_setTipo(this, tipo) == 0||
		   Servicio_setPrecio(this, precioUnitario) == 0||
		   Servicio_setCantidad(this, cantidad) == 0||
		   Servicio_setTotalServicio(this, totalServicio) == 0)
		{
			Servicio_delete(this);
			this = NULL;
		}
	}

	return this;
}
//-------------------------------- [BORRAR SERVICIO] --------------------------------------
void Servicio_delete(eServicio* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}

//-------------------------------- [ID] --------------------------------------
int Servicio_setId(eServicio* this,int id)
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

int Servicio_getId(eServicio* this,int* id)
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

//-------------------------------- [DESCRIPCION] --------------------------------------
int Servicio_setDescripcion(eServicio* this,char* descripcion)
{
	int retorno;

	retorno = 0;

	if (this != NULL && descripcion != NULL)
	{
		strcpy(this->descripcion, descripcion);
		retorno = 1;
	}

	return retorno;
}

int Servicio_getDescripcion(eServicio* this,char* descripcion)
{
	int retorno;

	retorno = 0;

	if (this != NULL && descripcion != NULL)
	{
		strcpy(descripcion, this->descripcion);
		retorno = 1;
	}

	return retorno;
}

//-------------------------------- [TIPO DE SERVICIO] --------------------------------------
int Servicio_setTipo(eServicio* this,int tipo)
{
	int retorno;

	retorno = 0;

	if (this != NULL && tipo > 0)
	{
		this->tipo = tipo;
		retorno = 1;
	}

	return retorno;
}

int Servicio_getTipo(eServicio* this,int* tipo)
{
	int retorno;

	retorno = 0;

	if (this != NULL && tipo != NULL)
	{
		*tipo = this->tipo;
		retorno = 1;
	}

	return retorno;
}

//-------------------------------- [PRECIO] --------------------------------------
int Servicio_setPrecio(eServicio* this, float precioUnitario)
{
	int retorno;

	retorno = 0;

	if (this != NULL && precioUnitario > 0)
	{
		this->precioUnitario = precioUnitario;
		retorno = 1;
	}

	return retorno;
}

int Servicio_getPrecio(eServicio* this, float* precioUnitario)
{
	int retorno;

	retorno = 0;

	if (this != NULL && precioUnitario != NULL)
	{
		*precioUnitario = this->precioUnitario;
		retorno = 1;
	}

	return retorno;
}

//-------------------------------- [CANTIDAD] --------------------------------------
int Servicio_setCantidad(eServicio* this,int cantidad)
{
	int retorno;

	retorno = 0;

	if (this != NULL && cantidad > 0)
	{
		this->cantidad = cantidad;
		retorno = 1;
	}

	return retorno;
}

int Servicio_getCantidad(eServicio* this,int* cantidad)
{
	int retorno;

	retorno = 0;

	if (this != NULL && cantidad != NULL)
	{
		*cantidad = this->cantidad;
		retorno = 1;
	}

	return retorno;
}

//-------------------------------- [TOTAL SERVICIO] --------------------------------------
int Servicio_setTotalServicio(eServicio* this, float totalServicio)
{
	int retorno;

	retorno = 0;

	if (this != NULL && totalServicio >= 0)
	{
		this->totalServicio = totalServicio;
		retorno = 1;
	}

	return retorno;
}

int Servicio_getTotalServicio(eServicio* this, float* totalServicio)
{
	int retorno;

	retorno = 0;

	if (this != NULL && totalServicio != NULL)
	{
		*totalServicio = this->totalServicio;
		retorno = 1;
	}

	return retorno;
}
//-------------------------------- [LISTAR UN PASAJERO] --------------------------------------
void Servicio_list(eServicio* this)
{
	int id;
	char descripcion[50];
	int tipo;
	float precioUnitario;
	int cantidad;
	float totalServicio;

	char tipoStr[20];

	Servicio_getId(this, &id);
	Servicio_getDescripcion(this, descripcion);
	Servicio_getTipo(this, &tipo);
	Servicio_getPrecio(this, &precioUnitario);
	Servicio_getCantidad(this, &cantidad);
	Servicio_getTotalServicio(this, &totalServicio);

	if (tipo == 1)
	{
		strcpy(tipoStr, "MINORISTA");
	}
	else
	{
		if (tipo == 2)
		{
			strcpy(tipoStr, "MAYORISTA");
		}
		else
		{
			strcpy(tipoStr, "EXPORTAR");
		}
	}

	printf("||%-10d||%-25s||%-18s||%-21.2f||%-14d||%-20.2f||\n",
			id,
			descripcion,
			tipoStr,
			precioUnitario,
			cantidad,
			totalServicio);
}

void calcularPrecioFinal(void* elemento)
{
	eServicio* this = elemento;
	float total;

    if(elemento != NULL)
    {
        total = (float)this->cantidad * this->precioUnitario;
        Servicio_setTotalServicio(this, total);
    }
}

int filtrarMinorista(void* elemento)
{
	eServicio* this = elemento;
    int retorno = 0;

    if(this != NULL)
    {
		 if(this->tipo == 1)
		 {
			retorno = 1;
		 }
    }
    return retorno;
}

int filtrarMayorista(void* elemento)
{
	eServicio* this = elemento;
    int retorno = 0;

    if(this != NULL)
    {
		 if(this->tipo == 2)
		 {
			retorno = 1;
		 }
    }
    return retorno;
}

int filtrarExportar(void* elemento)
{
	eServicio* this = elemento;
    int retorno = 0;

    if(this != NULL)
    {
		 if(this->tipo == 3)
		 {
			retorno = 1;
		 }
    }
    return retorno;
}

int Servicio_compareByDescripcion(void* servicioUno, void* servicioDos)
{
	char auxServicioUno[50];
	char auxServicioDos[50];
	int comparacion;

	eServicio* primerServicio = servicioUno;
	eServicio* segundoServicio = servicioDos;

	Servicio_getDescripcion(primerServicio, auxServicioUno);
	Servicio_getDescripcion(segundoServicio, auxServicioDos);

	comparacion = strcmp(auxServicioUno, auxServicioDos);

	return comparacion;
}

int Servicio_compareById(void* idUno, void* idDos)
{
	int auxIdUno;
	int auxIdDos;
	int comparacion;

	eServicio* idServicioUno = (eServicio*) idUno;
	eServicio* idServicioDos = (eServicio*) idDos;

	Servicio_getId(idServicioUno, &auxIdUno);
	Servicio_getId(idServicioDos, &auxIdDos);

	if(auxIdUno == auxIdDos)
		{
			comparacion = 0;
		}
		else
		{
			if (auxIdUno > auxIdDos)
			{
				comparacion = 1;
			}
			else
			{
				comparacion = -1;
			}
		}

	return comparacion;
}

int SaveTxt(FILE* pFile, LinkedList* pArrayListServicio)
{
	int longitud;
	int i;
	int auxId;
	char auxDescripcion[50];
	int auxTipo;
	float auxPrecioUnitario;
	int auxCantidad;
	float auxTotalServicio;
	int validacion;

	validacion = 0;

	eServicio* this;

	if (pFile == NULL && pArrayListServicio == NULL)
	{
		printf("========================================[ERROR]==========================================\n"
				"||--------------------------< | [NO EXISTE EL ARCHIVO] | >-----------------------------||\n"
				"=========================================================================================\n");
		exit(1);
	}

	longitud = ll_len(pArrayListServicio);

	if (longitud > 0)
	{
		fprintf(pFile, "ID_SERVICIO,DESCRIPCION,TIPO,PRECIO UNITARIO,CANTIDAD,TOTAL SERVICIO\n");

		for(i = 0; i < longitud; i++)
		{
			this = (eServicio*) ll_get(pArrayListServicio, i);
			if (this != NULL)
			{
				Servicio_getId(this, &auxId);
				Servicio_getDescripcion(this, auxDescripcion);
				Servicio_getTipo(this, &auxTipo);
				Servicio_getPrecio(this, &auxPrecioUnitario);
				Servicio_getCantidad(this, &auxCantidad);
				Servicio_getTotalServicio(this, &auxTotalServicio);


				fprintf(pFile, "%d,%s,%d,%f,%d,%f\n", auxId, auxDescripcion, auxTipo, auxPrecioUnitario, auxCantidad, auxTotalServicio);

				validacion = 1;
			}
		}
	}

	return validacion;
}
//
//int SaveBinary(FILE* pFile, LinkedList* pArrayListPassenger)
//{
//	int longitud;
//	int i;
//	int validacion;
//
//	validacion = 0;
//
//	Passenger* this;
//
//	if (pFile == NULL && pArrayListPassenger == NULL)
//	{
//		printf("[ERROR] - NO EXISTE EL ARCHIVO");
//		exit(1);
//	}
//
//	longitud = ll_len(pArrayListPassenger);
//
//	if (longitud > 0)
//	{
//		for(i = 0; i < longitud; i++)
//		{
//			this = (Passenger*) ll_get(pArrayListPassenger, i);
//			if (this != NULL)
//			{
//				fwrite(this, sizeof(Passenger), 1, pFile);
//
//				validacion = 1;
//			}
//		}
//	}
//
//	return validacion;
//}
//
//int Passenger_compareByName(void* nombreUno, void* nombreDos)
//{
//	int validacion;
//	char auxNombreUno[50];
//	char auxNombreDos[50];
//
//	Passenger* nombrePasajeroUno;
//	Passenger* nombrePasajeroDos;
//
//	nombrePasajeroUno = (Passenger*) nombreUno;
//	nombrePasajeroDos = (Passenger*) nombreDos;
//
//	Passenger_getNombre(nombrePasajeroUno, auxNombreUno);
//	Passenger_getNombre(nombrePasajeroDos, auxNombreDos);
//
//	if(strcmp(auxNombreUno, auxNombreDos) == 0)
//	{
//		validacion = 0;
//	}
//	else
//	{
//		if (strcmp(auxNombreUno, auxNombreDos) > 0)
//		{
//			validacion = 1;
//		}
//		else
//		{
//			validacion = -1;
//		}
//	}
//	return validacion;
//}
//
//int Passenger_compareByApellido(void* apellidoUno, void* apellidoDos)
//{
//	int validacion;
//	char auxApellidoUno[50];
//	char auxApellidoDos[50];
//
//	Passenger* apellidoPasajeroUno;
//	Passenger* apellidoPasajeroDos;
//
//	apellidoPasajeroUno = (Passenger*) apellidoUno;
//	apellidoPasajeroDos = (Passenger*) apellidoDos;
//
//	Passenger_getApellido(apellidoPasajeroUno, auxApellidoUno);
//	Passenger_getApellido(apellidoPasajeroDos, auxApellidoDos);
//
//	if(strcmp(auxApellidoUno, auxApellidoDos) == 0)
//	{
//		validacion = 0;
//	}
//	else
//	{
//		if (strcmp(auxApellidoUno, auxApellidoDos) > 0)
//		{
//			validacion = 1;
//		}
//		else
//		{
//			validacion = -1;
//		}
//	}
//	return validacion;
//}
//
//int Passenger_compareByPrecio(void* precioUno, void* precioDos)
//{
//	int validacion;
//	float auxPrecioUno;
//	float auxPrecioDos;
//
//	Passenger* precioPasajeroUno;
//	Passenger* precioPasajeroDos;
//
//	precioPasajeroUno = (Passenger*) precioUno;
//	precioPasajeroDos = (Passenger*) precioDos;
//
//	Passenger_getPrecio(precioPasajeroUno, &auxPrecioUno);
//	Passenger_getPrecio(precioPasajeroDos, &auxPrecioDos);
//
//	if(auxPrecioUno == auxPrecioDos)
//	{
//		validacion = 0;
//	}
//	else
//	{
//		if (auxPrecioUno > auxPrecioDos)
//		{
//			validacion = 1;
//		}
//		else
//		{
//			validacion = -1;
//		}
//	}
//	return validacion;
//}
//
//int Passenger_compareById(void* idUno, void* idDos)
//{
//	int validacion;
//	int auxIdUno;
//	int auxIdDos;
//
//	Passenger* idPasajeroUno;
//	Passenger* idPasajeroDos;
//
//	idPasajeroUno = (Passenger*) idUno;
//	idPasajeroDos = (Passenger*) idDos;
//
//	Passenger_getId(idPasajeroUno, &auxIdUno);
//	Passenger_getId(idPasajeroDos, &auxIdDos);
//
//	if(auxIdUno == auxIdDos)
//	{
//		validacion = 0;
//	}
//	else
//	{
//		if (auxIdUno > auxIdDos)
//		{
//			validacion = 1;
//		}
//		else
//		{
//			validacion = -1;
//		}
//	}
//	return validacion;
//}
//
//int criterioOrdenamiento()
//{
//	int opcion;
//
//	printf("||----< | [CRITERIO] | >---||\n\n"
//
//	"[0] | Ordenar en [DESCENDENTE]\n"
//	"[1] | Ordenar en [ASCENDENTE]\n\n"
//
//	"||--->[INGRESAR OPCION]:");
//
//	fflush(stdin);
//	scanf("%d", &opcion);
//
//	return opcion;
//}
//
//int Passener_buscarId(LinkedList* pArrayListPassenger, int id)
//{
//	int indice;
//	int i;
//	int longitud;
//	Passenger* this;
//
//	indice = -1;
//
//	if (pArrayListPassenger != NULL)
//	{
//		longitud = ll_len(pArrayListPassenger);
//
//		if (longitud > 0)
//		{
//			for (i = 0; i < longitud; i++)
//			{
//				this = (Passenger*) ll_get(pArrayListPassenger, i);
//
//				if (this->id == id)
//				{
//					indice = i;
//					break;
//				}
//			}
//		}
//	}
//
//	return indice;
//}
//
//int Passenger_modificarNombre(LinkedList* pArrayListPassenger, int indice)
//{
//	char auxNombre[50];
//	int validacion;
//	int retorno;
//
//	retorno = 0;
//
//	Passenger* this;
//
//	if (pArrayListPassenger != NULL)
//	{
//		printf("[1] | Modificar [NOMBRE]\n\n"
//				"|| Ingrese el nuevo nombre ->|:");
//
//		fflush(stdin);
//		gets(auxNombre);
//
//		validacion = validateCharacter(auxNombre);
//
//		if (validacion == 0)
//		{
//			printf("||[ERROR] -> Ingrese el nuevo nombre ->|:");
//
//			fflush(stdin);
//			gets(auxNombre);
//		}
//
//		this = (Passenger*) ll_get(pArrayListPassenger, indice);
//
//		if (this != NULL)
//		{
//			Passenger_setNombre(this, auxNombre);
//			retorno = 1;
//		}
//	}
//
//	return retorno;
//}
//
//int Passenger_modificarApellido(LinkedList* pArrayListPassenger, int indice)
//{
//	char auxApellido[50];
//	int validacion;
//	int retorno;
//
//	retorno = 0;
//
//	Passenger* this;
//
//	if (pArrayListPassenger != NULL)
//	{
//		printf("[2] | Modificar [APELLIDO]\n\n"
//				"|| Ingrese el nuevo apellido ->|:");
//
//		fflush(stdin);
//		gets(auxApellido);
//
//		validacion = validateCharacter(auxApellido);
//
//		if (validacion == 0)
//		{
//			printf("||[ERROR] -> Ingrese el nuevo apellido ->|:");
//
//			fflush(stdin);
//			gets(auxApellido);
//		}
//
//		this = (Passenger*) ll_get(pArrayListPassenger, indice);
//
//		if (this != NULL)
//		{
//			Passenger_setApellido(this, auxApellido);
//			retorno = 1;
//		}
//	}
//
//	return retorno;
//}
//
//int Passenger_modificarPrecio(LinkedList* pArrayListPassenger, int indice)
//{
//	float auxPrecio;
//	int retorno;
//
//	retorno = 0;
//
//	Passenger* this;
//
//	if (pArrayListPassenger != NULL)
//	{
//		auxPrecio = orderFloat("[3] | Modificar [PRECIO]\n\n"
//								"|| Ingrese el nuevo precio -> (500 - 10.000) |:");
//
//		while (auxPrecio < 500 || auxPrecio > 100000)
//		{
//			auxPrecio = orderFloat("||[ERROR] -> Ingrese el nuevo precio -> (500 - 10.000) |:");
//		}
//
//		this = (Passenger*) ll_get(pArrayListPassenger, indice);
//
//		if (this != NULL)
//		{
//			Passenger_setPrecio(this, auxPrecio);
//			retorno = 1;
//		}
//	}
//
//	return retorno;
//}
//
//int Passenger_modificarCodigoVuelo(LinkedList* pArrayListPassenger, int indice)
//{
//	char auxCodigoVuelo[8];
//	int retorno;
//
//	retorno = 0;
//
//	Passenger* this;
//
//	if (pArrayListPassenger != NULL)
//	{
//		printf("[4] | Modificar [CODIGO DE VUELO]\n\n"
//				"|| Ingrese el nuevo codigo de vuelo -> (7 Caracteres) |:");
//
//		fflush(stdin);
//		gets(auxCodigoVuelo);
//		toMayus(auxCodigoVuelo);
//
//		while (strlen(auxCodigoVuelo) != 7)
//		{
//			printf("||[ERROR] -> Ingrese el [CODIGO DE VUELO] | (7 Caracteres)");
//
//			fflush(stdin);
//			gets(auxCodigoVuelo);
//			toMayus(auxCodigoVuelo);
//		}
//
//		this = (Passenger*) ll_get(pArrayListPassenger, indice);
//
//		if (this != NULL)
//		{
//			Passenger_setCodigoVuelo(this, auxCodigoVuelo);
//			retorno = 1;
//		}
//	}
//
//	return retorno;
//}
//
//int Passenger_modificarTipoPasajero(LinkedList* pArrayListPassenger, int indice)
//{
//	int auxTipoPasajero;
//	int retorno;
//
//	retorno = 0;
//
//	Passenger* this;
//
//	if (pArrayListPassenger != NULL)
//	{
//		auxTipoPasajero = orderInteger("[5] | Modificar [TIPO DE PASAJERO]\n\n"
//										"[1] - FirstClass\n"
//										"[2] - ExecutiveClass\n"
//										"[3] - EconomyClass");
//
//		while (auxTipoPasajero < 1 || auxTipoPasajero > 3)
//		{
//			auxTipoPasajero = orderInteger("[5] |[ERROR] -> Ingrese un [TIPO DE PASAJERO]\n\n"
//												"[1] - FirstClass\n"
//												"[2] - ExecutiveClass\n"
//												"[3] - EconomyClass");
//		}
//
//		this = (Passenger*) ll_get(pArrayListPassenger, indice);
//
//		if (this != NULL)
//		{
//			Passenger_setTipoPasajero(this, auxTipoPasajero);
//			retorno = 1;
//		}
//	}
//
//	return retorno;
//}
//
//int Passenger_modificarEstadoVuelo(LinkedList* pArrayListPassenger, int indice)
//{
//	int auxEstadoVuelo;
//	char auxEstadoVueloStr[30];
//	int retorno;
//
//	retorno = 0;
//
//	Passenger* this;
//	if (pArrayListPassenger != NULL)
//	{
//		auxEstadoVuelo = orderInteger("[6] | Modificar [ESTADO DE VUELO]\n\n"
//									"[1] - En Horario\n"
//									"[2] - Demorado\n"
//									"[3] - Aterrizado");
//
//		while(auxEstadoVuelo < 1 || auxEstadoVuelo > 3)
//		{
//			auxEstadoVuelo = orderInteger("[6]|[ERROR] -> Ingrese un [ESTADO DE VUELO]\n\n"
//											"[1] - En Horario\n"
//											"[2] - Demorado\n"
//											"[3] - Aterrizado");
//		}
//
//		//-----------------[ELVAUA OPCION ELEGIDA]--------------------
//		switch (auxEstadoVuelo)
//		{
//			case 1:
//				strcpy(auxEstadoVueloStr, "En Horario");
//			break;
//
//			case 2:
//				strcpy(auxEstadoVueloStr, "Demorado");
//			break;
//
//			default:
//				strcpy(auxEstadoVueloStr, "Aterrizado");
//			break;
//		}
//
//			this = (Passenger*) ll_get(pArrayListPassenger, indice);
//
//			if (this != NULL)
//			{
//				Passenger_setEstadoVuelo(this, auxEstadoVueloStr);
//				retorno = 1;
//			}
//	}
//
//	return retorno;
//}
