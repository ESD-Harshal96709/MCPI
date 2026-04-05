/*
 * lcd.c
 *
 *  Created on: 27-Mar-2026
 *      Author: sunbeam
 */

#include "lcd.h"

extern I2C_HandleTypeDef hi2c1;

void WRITE_NIBBLE(char rs ,char val)
{
char flag = (rs==lcd_data)?BV(rs_pin):0;
char data =(val<<data_pin1)|flag|BV(en_pin)|BV(bl_pin);
HAL_I2C_Master_Transmit(&hi2c1,lcd_add,&data,1,HAL_MAX_DELAY);
HAL_Delay(1);
data =(val<<data_pin1)|flag|BV(bl_pin);
HAL_I2C_Master_Transmit(&hi2c1,lcd_add,&data,1,HAL_MAX_DELAY);

}
void write_byte(char rs,char val)
{
char high =val>>4,low=val&0x0F;
WRITE_NIBBLE(rs, high);
WRITE_NIBBLE(rs, low);
HAL_Delay(3);
}

void init_lcd(void)
{
HAL_Delay(20);
write_byte(lcd_cmd,0x03);
HAL_Delay(5);
write_byte(lcd_cmd,0x03);
HAL_Delay(1);
write_byte(lcd_cmd,0x03);
HAL_Delay(1);
write_byte(lcd_cmd,0x02);
HAL_Delay(1);
write_byte(lcd_cmd,func_set);
write_byte(lcd_cmd,disp_on_off);
write_byte(lcd_cmd,entry_mode);
write_byte(lcd_cmd,lcd_clear);

}

void puts_lcd(char str[],char line)
{
write_byte(lcd_cmd,line);
for (int i=0 ;str[i]!='\0';i++)
{
write_byte(lcd_data,str[i]);
}

}

void shift_lcd(void)
{
write_byte(lcd_cmd,0x18);
}

