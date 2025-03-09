/*
 * main_Functions.c
 *
 *  Created on: Aug 6, 2023
 *      Author: Mahmoud
 */

#include "../STD_TYPES.h"
#include "../MACROS.h"
#include "main_Functions.h"

void sum(u8 x, u8 y, u16 *result)
{
	*result = x + y;
}

void subtract(u8 x, u8 y, u16 *result)
{
	*result = x - y;
}

void multiply(u8 x, u8 y, u16 *result)
{
	*result = x * y;
}

void division(u8 x, u8 y, float32 *r)
{
	*r = x / y;
}

s32 strToNumb(char str[])
{
	u8 i=0;
	s32 sum=0;
	while(str[i]!='\0')
	{
		if(str[i]<48 || str[i]>57)      //48-57 -> 0-9
		{
			//printf("unable to convert\n");
		}
		else
		{
			sum=sum*10+(str[i]-48);
			i++;
		}
	}
	return sum;
}
