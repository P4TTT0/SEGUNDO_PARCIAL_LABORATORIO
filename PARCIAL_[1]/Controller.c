#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "input.h"
#include "estetica.h"
#include "Servicio.h"

int controller_optionsToLoad()
{
	int opcion;
	int carga;

	do
	{
		printf("=========================================================================================\n"
				"||-----------------------------< | [ARCHIVO A CARGAR] | >------------------------------||\n"
				"=========================================================================================\n"
				"||--[1]--|| Cargar [DATA].                        <---|ARCHIVO PREDETERMINADO|---------||\n"
				"||--[2]--|| Cargar [MINORISTAS].                                                       ||\n"
				"||--[3]--|| Cargar [MAYORISTAS].                                                       ||\n"
				"||--[4]--|| Cargar [EXPORTAR].                                                         ||\n"
				"||--[5]--|| [SALIR]->|                                                                 ||\n"
				"=========================================================================================\n"
				"||------------------------------------< | [TTT] | >------------------------------------||\n"
				"=========================================================================================\n"

				"||--->[INGRESAR OPCION]:");

				fflush(stdin);
				scanf("%d", &opcion);

			switch(opcion)
			{
				case 1:
					carga = 1;
					opcion = 5;
				break;
				case 2:
					carga = 2;
					opcion = 5;
				break;
				case 3:
					carga = 3;
					opcion = 5;
				break;
				case 4:
					carga = 4;
					opcion = 5;
				break;
				case 5:
					clear();
					printf("=========================================================================================\n"
							"||-----------------------------< | [VOLVIENDO AL MENU] | >------------------------------||\n"
							"=========================================================================================\n");
					carga = 5;
				break;
				default:
					clear();
					printf("========================================[ERROR]==========================================\n"
							"||-------------------------< | [INGRESE OPCION VALIDA] | >------------------------------||\n"
							"=========================================================================================\n");
					system("pause");
				break;
			}

	}while(opcion != 5);

	return carga;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(int archivo, LinkedList* pArrayServicio)
{
	int validacion;
	FILE* pFile;
	char path[30];

	switch(archivo)
	{
		case 1:
			strcpy(path, "data.csv");
		break;
		case 2:
			strcpy(path, "minorista.csv");
		break;
		case 3:
			strcpy(path, "mayorista.csv");
		break;
		case 4:
			strcpy(path, "exportar.csv");
		break;
	}

	pFile = fopen(path, "r");

	if (pFile == NULL)
	{
		clear();
		printf("========================================[ERROR]==========================================\n"
				"||--------------------------< | [NO EXISTE EL ARCHIVO] | >-----------------------------||\n"
				"=========================================================================================\n");
		system("pause");
		validacion = 0;
	}
	else
	{
		ll_clear(pArrayServicio);
		validacion = parser_ServicioFromText(pFile, pArrayServicio);

		fclose(pFile);
	}

    return validacion;
}

///** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
// *
// * \param path char*
// * \param pArrayListPassenger LinkedList*
// * \return int
// *
// */
int controller_saveAsText(int archivo, LinkedList* pArrayListServicio)
{
	int validacion;
	FILE* pFile;
	char path[30];

	switch(archivo)
	{
		case 1:
			strcpy(path, "data.csv");
		break;
		case 2:
			strcpy(path, "minorista.csv");
		break;
		case 3:
			strcpy(path, "mayorista.csv");
		break;
		case 4:
			strcpy(path, "exportar.csv");
		break;
	}
	pFile = fopen(path, "w");

	if (pFile == NULL)
	{
		printf("========================================[ERROR]==========================================\n"
				"||--------------------< | [NO SE HA PODIDO ABRIR EL ARCHIVO] | >-----------------------||\n"
				"=========================================================================================\n");
		exit(1);
	}

	validacion = SaveTxt(pFile, pArrayListServicio);

	fclose(pFile);

    return validacion;
}
int controller_ListServicio(LinkedList* pArrayServicio)
{
	int longitud;
	int i;
	eServicio* this;

	longitud = ll_len(pArrayServicio);
	printf("||======================================================================================================================||\n"
			"||---[ID]---||------[DESCRIPCION]------||------[TIPO]------||--[PRECIO UNITARIO]--||--[CANTIDAD]--||--[TOTAL SERVICIO]--||\n"
			"||======================================================================================================================||\n");

	for (i = 0; i < longitud; i++)
	{
		this = (eServicio*) ll_get(pArrayServicio, i);
		Servicio_list(this);
		printf("||======================================================================================================================||\n");
	}

    return 1;
}
void controller_subListaFiltrar(LinkedList* nuevaLista, int option)
{
	int respuesta;

	clear();
	controller_ListServicio(nuevaLista);

	printf("=========================================================================================\n"
			"||------------------------------< | [¿DESEA GUARDAR?] | >------------------------------||\n"
			"=========================================================================================\n"
			"||--[1]--|| Guardar.                                                                   ||\n"
			"||--[2]--|| Cancelar y eliminar.                                                       ||\n"
			"=========================================================================================\n"
			"||------------------------------------< | [TTT] | >------------------------------------||\n"
			"=========================================================================================\n"
			"||--->[INGRESAR OPCION]:");

	fflush(stdin);
	scanf("%d", &respuesta);

	clear();

	while (respuesta < 1 || respuesta > 2)
	{
		printf("========================================[ERROR]==========================================\n"
				"||-------------------------< | [INGRESE OPCION VALIDA] | >------------------------------||\n"
				"=========================================================================================\n"
				"||--[1]--|| Guardar.                                                                   ||\n"
				"||--[2]--|| Cancelar y eliminar.                                                       ||\n"
				"=========================================================================================\n"
				"||------------------------------------< | [TTT] | >------------------------------------||\n"
				"=========================================================================================\n"
				"||--->[INGRESAR OPCION]:");

		fflush(stdin);
		scanf("%d", &respuesta);
	}

	animacionCargando();
	clear();

	if (respuesta == 2)
	{
		ll_deleteLinkedList(nuevaLista);
		printf("=========================================================================================\n"
				"||----------------------------< | [ELIMINADO CON EXITO] | >-----------------------------||\n"
				"=========================================================================================\n");
		system("pause");
	}
	else
	{
		int validacion;
		switch(option)
		{
			 case 1:
				 validacion = controller_saveAsText(2, nuevaLista);
			 break;
			 case 2:
				 validacion = controller_saveAsText(3, nuevaLista);
			 break;
			 case 3:
				 validacion = controller_saveAsText(4, nuevaLista);
			 break;
		}
		clear();
		if (validacion == 1)
		{
			printf("=========================================================================================\n"
					"||----------------------------< | [GUARDADO CON EXITO] | >-----------------------------||\n"
					"=========================================================================================\n");
			system("pause");
		}
		else
		{
			printf("========================================[ERROR]==========================================\n"
					"||--------------------< | [NO SE HA PODIDO GUARDAR CON EXITO] | >----------------------||\n"
					"=========================================================================================\n");
			ll_deleteLinkedList(nuevaLista);
			system("pause");
		}
	}
}

int controller_filtrarServicio(LinkedList* pArrayServicio)
{
	int option;
	LinkedList* nuevaLista;

	do
	{
		clear();
		printf("=========================================================================================\n"
				"||------------------------------< | [FILTRAR POR TIPO] | >-----------------------------||\n"
				"=========================================================================================\n"
				"||--[1]--|| Filtrar MINORISTA.                                                         ||\n"
				"||--[2]--|| Filtrar MAYORISTA.                                                         ||\n"
				"||--[3]--|| Filtrar EXPORTAR                                                           ||\n"
				"||--[4]--|| [SALIR]->|                                                                 ||\n"
				"=========================================================================================\n"
				"||------------------------------------< | [TTT] | >------------------------------------||\n"
				"=========================================================================================\n"

				"||--->[INGRESAR OPCION]:");

		fflush(stdin);
		scanf("%d", &option);

		switch(option)
		{
			 case 1:
				 animacionCargando();
				 nuevaLista = ll_filter(pArrayServicio, filtrarMinorista);
				 controller_subListaFiltrar(nuevaLista, option);
			 break;
			 case 2:
				animacionCargando();
				nuevaLista = ll_filter(pArrayServicio, filtrarMayorista);
				controller_subListaFiltrar(nuevaLista, option);
			 break;
			 case 3:
				animacionCargando();
				nuevaLista = ll_filter(pArrayServicio, filtrarExportar);
				controller_subListaFiltrar(nuevaLista, option);
			 break;
			 case 4:
				 clear();
				 printf("=========================================================================================\n"
						"||-----------------------------< | [VOLVIENDO AL MENU] | >------------------------------||\n"
						"=========================================================================================\n");
				 system("pause");
			 break;
			 default:
				clear();
				printf("========================================[ERROR]==========================================\n"
						"||-------------------------< | [INGRESE OPCION VALIDA] | >------------------------------||\n"
						"=========================================================================================\n");
				system("pause");
			 break;
		}
	}
	while (option != 4);


	return 1;
}
int controller_sortService(LinkedList* pArrayListServicio)
{
	int validacion = 0;


	if (pArrayListServicio != NULL)
	{
		validacion = ll_sort(pArrayListServicio, Servicio_compareByDescripcion, 1);
	}
    return validacion;
}

