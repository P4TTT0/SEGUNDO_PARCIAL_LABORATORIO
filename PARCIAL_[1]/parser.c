#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "estetica.h"
#include "Servicio.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_ServicioFromText(FILE* pFile , LinkedList* pArrayServicio)
{
	int leido;
	char auxId[50];
	char auxDescripcion[50];
	char auxTipo[50];
	char auxPrecio[30];
	char auxCantidad[50];
	char auxTotalServicio[50];
	eServicio* this;
	int validacion;

	validacion = 0;

	if (pFile == NULL && pArrayServicio == NULL)
	{
		clear();
		printf("========================================[ERROR]==========================================\n"
				"||--------------------------< | [NO EXISTE EL ARCHIVO] | >-----------------------------||\n"
				"=========================================================================================\n");
		exit(1);
	}

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", //FALSA LECTURA
					auxId,
					auxDescripcion,
					auxTipo,
					auxPrecio,
					auxCantidad,
					auxTotalServicio);

	while(!feof(pFile))
	{
		leido = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
				auxId,
				auxDescripcion,
				auxTipo,
				auxPrecio,
				auxCantidad,
				auxTotalServicio);

		if (leido == 6)
		{
			this = Servicio_newParametros(auxId, auxDescripcion, auxTipo, auxPrecio, auxCantidad, auxTotalServicio);
			if (this != NULL)
			{
				ll_add(pArrayServicio, this);
				validacion = 1;
			}
			else
			{
				clear();
				printf("========================================[ERROR]==========================================\n"
						"||-----------------------< | [NO HAY ESPACIO EN MEMORIA] | >---------------------------||\n"
						"=========================================================================================\n");
				Servicio_delete(this);
			}
		}
	}
    return validacion;
}
