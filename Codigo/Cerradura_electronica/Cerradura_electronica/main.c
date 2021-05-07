/*
 * Cerradura_electronica.c
 *
 * Created: 04/05/2021 12:30:07
 * Author : Agustín
 */ 

#include <avr/io.h>
#include "lcd.h"
#include <time.h>
#define F_CPU 8000000L
#include <util/delay.h>
#include <string.h>
void mostrarString(const uint8_t *dato, uint8_t x, uint8_t y, uint8_t size ){ //recibe el string, la posición a ser mostrado y la longitud del string
	uint8_t i;
	LCDGotoXY(x,y);
	for(i=0;i<size;i++){ //no se porque -2 pero así si
		LCDsendChar(dato[i]);
	}
}
void muestreoInicial(  ) //muestra en el display el valor por defecto -> en la primera linea la hora y en la segunta "cerrado"
{ 
	uint8_t locked[7] = "CERRADO"; //crea un string con la palabra cerrado
	CopyStringtoLCD(locked, 0, 1); //muestra cerrado en la linea 2 del display
	//time_t t = time(NULL); //crea una variable tiempo
	//struct tm *tm = localtime(&t); //se le da el tiempo actual
	//char tiempo[64]; //variable para almacenar el tiempo como string
	//strftime(tiempo, sizeof(tiempo), "%c", tm); //guarda en el string tiempo lo que hay en tm
	//CopyStringtoLCD(&tiempo[0], 0, 1);
}
int main(void)
{
	uint8_t locked[7] = "CERRADO";//{'c','e','r','r','a','d','o'}; //crea un string con la palabra cerrado
	LCDinit(); //se inicializa el display
	LCDGotoXY(0,0);
	//muestreoInicial();
	mostrarString(locked,0,1, sizeof(locked));
    /* Replace with your application code */
    while (1) 
    {
		
    }
}

