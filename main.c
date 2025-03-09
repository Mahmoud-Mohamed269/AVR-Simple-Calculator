/*
 * main.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Mahmoud
 */

#define __OPTIMIZE__
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "MACROS.h"
#include "App/main_Functions.h"
#include "MCAL/DIO/MDIO_interface.h"
#include "HAL/LCD/HLCD_interface.h"
#include "HAL/Keypad/HKeypad_interface.h"
#include "HAL/Keypad/HKeypad_config.h"

float32 calculate(const u8 *input);

u8 value, input[20] = "", iterator = 0;
float32 result;

int main()
{
	Port_VoidInit();															/*Initialize the ports*/
	HLCD_voidinit();															/*Initialize the LCD*/
	HLCD_voidgotoXY(0, 5);														/*Set the cursor position on LCD at first row and column 5 */
	HLCD_voidsendString("Simple");												/*Print stirng on LCD*/
	HLCD_voidgotoXY(1, 3);														/*Set the cursor position on LCD at second row and column 3 */
	HLCD_voidsendString("Calculator");											/*Print stirng on LCD*/
	_delay_ms(1000);															/*wait for 1sec*/
	HLCD_voidclear();															/*Clear the LCD*/

	while(1)																	/*Infinite loop*/
	{
		value = Hkeypad_u8GetKey();												/*Get the pressed key in keypad*/

		if(value != NO_KEY)														/*check if there is a key is pressed*/
		{

			if(value == '=')
			{
				input[iterator] = '\0';											//terminate the string
				result = calculate(input);										//function to calculate the result
				HLCD_voidclear();
				HLCD_voidsendChar(input);
				HLCD_voidgotoXY(0, 0);
				HLCD_voidsendFloat(result);
				iterator = 0;													//reset the index
				_delay_ms(500);													//wait for 500ms
			}
			else
			{
				input[iterator++] = value;
				HLCD_voidsendChar(value);
			}
		}
	}

}

float32 calculate(const u8 *input)
{
	u32 n1, n2;
	u8 operator;

	if(sscanf(input, "%lu %c %lu", &n1, &operator, &n2) != 3)
	{
		//Invalid format
		return 0;
	}
	switch(operator)
	{
	case '+':
		return n1+n2;
	case '-':
		return n1-n2;
	case 'X':
		return n1*n2;
	case '/':
		if(n2 != 0)
		{
			return ((float32)n1)/n2;
		}
		else
		{
			return 0;
		}
	default:
		return 0;
	}
}
