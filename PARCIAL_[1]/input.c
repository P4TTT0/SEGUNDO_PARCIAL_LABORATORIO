/*
 * input.c
 *
 *  Created on: 12 may. 2022
 *      Author: Perez Cardenal Patricio
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

//1 = NO CONTIENE NUMEROS
//0 = SI CONTIENE NUMEROS
int validateCharacter (char string[])
{
	int validator;
	int i;

	validator = 1;

	for(i = 0; i < strlen(string); i++)
	{
		if (isdigit(string[i]))
		{
			validator = 0;
		}
	}
	return validator;
}

int orderInteger(char message[])
{
	int integer;

	char number[1000];

	printf(message);
	scanf("%s", number);

	while(!validateNumber(number))
	{
		printf("\nERROR");
		printf(message);
		scanf("%s",number);
	}

	integer = atoi(number);

	return integer;
}

int orderFloat(char message[])
{
	int numberFloat;

	char numbersFloat[1000];

	printf(message);
	scanf("%s", numbersFloat);

	while(!validateNumber(numbersFloat))
	{
		printf("\n(ERROR)");
		printf(message);
		scanf("%s",numbersFloat);
	}

	numberFloat = atof(numbersFloat);

	return numberFloat;
}

int validateNumber (char numbers[])
{
	int validator;
	int i;

	validator = 1;

	for(i = 0; i < strlen(numbers); i++)
	{
		if (!(isdigit(*(numbers + i))))
		{
			validator = 0;
		}
	}
	return validator;
}

int toMayus (char* string)
{
	int validacion;
	int i;

	validacion = 1;

	for (i = 0; i < strlen(string); i++)
	{
		(*(string + i)) = toupper((*(string + i)));
		validacion = 0;
	}

	return validacion;
}
