/*
 * HLCD_interface.h
 *
 *  Created on: Aug 3, 2023
 *      Author: Mahmoud
 *      Layer: HAL
 *      Module: LCD
 *      Version: 1.00
 */

#ifndef HAL_LCD_HLCD_INTERFACE_H_
#define HAL_LCD_HLCD_INTERFACE_H_

#include <stdlib.h>

void HLCD_voidSendCommand(u8 Copy_u8Command);
void HLCD_voidsendChar(u8 Copy_u8Data);
void HLCD_voidclear(void);
void HLCD_voidsendNumber(u32 Number);
void HLCD_voidsendFloat(float32 Number);
void HLCD_voidsendString(char *string);
void HLCD_voidgotoXY(u8 x_pos, u8 y_pos);
void HLCD_voidinit();

#endif /* HAL_LCD_HLCD_INTERFACE_H_ */
