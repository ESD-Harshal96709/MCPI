/*
 * lcd.h
 *
 *  Created on: 27-Mar-2026
 *      Author: sunbeam
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_
#include "main.h"

#ifndef BV
#define BV(n) (1<<n)
#endif

#define data_pin1 4
#define data_pin2 5
#define data_pin3 6
#define data_pin4 7

#define rs_pin 0
#define rw_pin 1
#define en_pin 2
#define bl_pin 3

#define line1 0x80
#define line2 0xc0
#define func_set 0x28
#define disp_on_off 0x0C
#define entry_mode 0x06
#define lcd_clear 0x01

#define lcd_cmd 0
#define lcd_data 1

#define lcd_add (0x27<<1)

void write_byte(char rs ,char val);
void WRITE_NIBBLE(char rs ,char val);
void puts_lcd(char str[],char line);
void shift_lcd(void);
void init_lcd(void);



#endif /* INC_LCD_H_ */
