#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "estetica.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    int validacion = 0;
    int banderaTexto = 0;
//    int banderaGuardadoTexto = 1;


    LinkedList* listaServicio = ll_newLinkedList();

    do
    {
    	clear();
    	printf("=========================================================================================\n"
    			"||-----------------------------------< | [MENU] | >------------------------------------||\n"
    			"=========================================================================================\n"
    			"||--[1]--|| Cargar archivo.                                                            ||\n"
    			"||--[2]--|| Imprimir lista.                                                            ||\n"
    			"||--[3]--|| Asignar totales.                                                           ||\n"
    			"||--[4]--|| Filtrar por tipo.                                                          ||\n"
    			"||--[5]--|| Mostrar servicios.                                                         ||\n"
    			"||--[6]--|| Guardar servicios.                                                         ||\n"
    			"||--[7]--|| [SALIR]->|                                                                 ||\n"
    			"=========================================================================================\n"
    			"||------------------------------------< | [TTT] | >------------------------------------||\n"
    			"=========================================================================================\n"

    			"||--->[INGRESAR OPCION]:");

    			fflush(stdin);
    			scanf("%d", &option);

        switch(option)
        {
            case 1:
            	clear();

            	if (ll_isEmpty(listaServicio) || banderaTexto == 0)
            	{
            		animacionCargando();
            		validacion = controller_loadFromText("data.csv", listaServicio);

					if (validacion == 1)
					{
						clear();
						printf("=========================================================================================\n"
								"||------------------------------< | [DATOS CARGADOS] | >-------------------------------||\n"
								"=========================================================================================\n");
//						ll_sort(listaServicio, Passenger_compareById, 1);
						system("pause");
						banderaTexto = 1;
					}
					else
					{
						clear();
						printf("========================================[ERROR]==========================================\n"
								"||-------------------< | [NO SE HAN PODIDO CARGAR LOS DATOS] | >-----------------------||\n"
								"=========================================================================================\n");
						system("pause");
					}
            	}
            	else
            	{
            		clear();
            		printf("========================================[ERROR]==========================================\n"
							"||---------------------< | [LOS DATOS YA HAN SIDO CARGADOS] | >------------------------||\n"
							"=========================================================================================\n");
					system("pause");
            	}
			break;

            case 2:
            	clear();

				if (!ll_isEmpty(listaServicio))
				{
					controller_ListServicio(listaServicio);
				}
				else
				{
					printf("========================================[ERROR]==========================================\n"
							"||-----------------------< | [NO HAY PASAJEROS CARGADOS] | >---------------------------||\n"
							"=========================================================================================\n");
					system("pause");
				}

				system("pause");
			break;

//            case 3:
//            	if (ll_isEmpty(listaPasajeros) || (banderaTexto == 0 && banderaBinario == 0))
//				{
//					validacion = controller_loadFromText("backup.csv",listaPasajeros);
//
//					if (validacion == 1)
//					{
//						printf("||----< [DATOS CARGADOS CORRECTAMENTES] >----\n");
//						ll_sort(listaPasajeros, Passenger_compareById, 1);
//						system("pause");
//						banderaTexto = 1;
//					}
//					else
//					{
//						printf("||----< [ERROR] - NO SE HAN PODIDO CARGAR LOS DATOS. >----\n");
//						system("pause");
//					}
//				}
//				else
//				{
//					printf("||----< [ERROR] - LOS DATOS YA HAN SIDO CARGADOS. >----\n");
//					system("pause");
//				}
//			break;
//
//            case 4:
//            	controller_addPassenger(listaPasajeros);
//            	banderaGuardadoTexto = 0;
//            	banderaGuardadoBinario = 0;
//			break;
//
//            case 5:
//            	if (!ll_isEmpty(listaPasajeros))
//            	{
//            		controller_editPassenger(listaPasajeros);
//            		banderaGuardadoTexto = 0;
//					banderaGuardadoBinario = 0;
//            	}
//            	else
//            	{
//            		printf("||----< [ERROR] - NO HAY PASAJEROS CARGADOS. >----\n");
//					system("pause");
//            	}
//			break;
//
//            case 6:
//            	if (!ll_isEmpty(listaPasajeros))
//				{
//            		controller_removePassenger(listaPasajeros);
//            		banderaGuardadoTexto = 0;
//					banderaGuardadoBinario = 0;
//				}
//				else
//				{
//					printf("||----< [ERROR] - NO HAY PASAJEROS CARGADOS. >----\n");
//					system("pause");
//				}
//			break;
//
//            case 8:
//            	if (!ll_isEmpty(listaPasajeros))
//				{
//            		controller_sortPassenger(listaPasajeros);
//				}
//				else
//				{
//					printf("||----< [ERROR] - NO HAY PASAJEROS CARGADOS. >----\n");
//					system("pause");
//				}
//			break;
//
//            case 9:
//            	validacion = controller_saveAsText("data.csv", listaPasajeros);
//
//            	if (validacion == 1)
//				{
//					printf("||----< [DATOS GUARDADOS CORRECTAMENTES] >----\n");
//					system("pause");
//					banderaGuardadoTexto = 1;
//				}
//				else
//				{
//					printf("||----< [ERROR] - NO SE HAN PODIDO GUARDAR LOS DATOS >----\n");
//					system("pause");
//				}
//			break;
//
//            case 10:
//            	validacion = controller_saveAsBinary("data.bin", listaPasajeros);
//
//            	if (validacion == 1)
//				{
//					printf("||----< [DATOS GUARDADOS CORRECTAMENTES] >----\n");
//					system("pause");
//					banderaGuardadoBinario = 1;
//				}
//				else
//				{
//					printf("||----< [ERROR] - NO SE HAN PODIDO GUARDAR LOS DATOS >----\n");
//					system("pause");
//				}
//			break;
//
//            case 11:
//
//				if (!ll_containsAll(listaPasajeros, cloneArray))
//				{
//					cloneArray = ll_clone(listaPasajeros);
//					validacion = controller_saveAsText("backup.csv", cloneArray);
//
//					if (validacion == 1)
//					{
//						printf("||----< [COPIA DE SEGURIDAD REALIZADA] >----\n");
//						system("pause");
//					}
//					else
//					{
//						printf("||----< [ERROR] - NO SE HA PODIDO REALIZAR LA COPIA DE SEGURIDAD>----\n");
//						system("pause");
//					}
//				}
//				else
//				{
//					printf("||----< [ERROR] - LA COPIA DE SEGURIDAD YA HA SIDO REALIZADA>----\n");
//					system("pause");
//				}
//
//			break;
//
//            case 12:
//            	if (banderaGuardadoTexto == 1 && banderaGuardadoBinario == 1)
//            	{
//            		printf("|| - [SALIENDO] - ||");
//            		ll_deleteLinkedList(listaPasajeros);
//            		ll_deleteLinkedList(cloneArray);
//            	}
//            	else
//            	{
//            		printf("||[ERROR] | DEBES GUARDAR LOS CAMBIOS ANTES DE SALIR.\n");
//            		option = 1;
//            		system("pause");
//            	}
//			break;
        }
    }while(option != 3);

    return 0;
}
