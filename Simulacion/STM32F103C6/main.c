/* Main.c file generated by New Project wizard
 *
 * Created:   Fri Sep 17 2021
 * Processor: STM32F103C6
 * Compiler:  Keil for ARM
 */

#include <stm32f103x6.h>
#include <sysinit.h>
#include <keypad.h>
#include <lcd.h>
#include <delay.h>

uint8_t lastkey = 0;

int main (void)
{
   	uint8_t key;
	 key = 0;
	gpio_init();
	keypad_init();
	lcd_init();
   
	lcd_load_buffer_high("Hello");
	lcd_load_buffer_low("There!");
	lcd_refresh();

	while(1)
	{
		if (keypad_update(&key))
		{
			lastkey = key;
			lcd_load_buffer_high("     Fellas     ");
			lcd_load_buffer_low("                ");
			lcd_refresh();
		}
		delay_ms(100);
	}
}
