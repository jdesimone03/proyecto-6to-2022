/*
 * user.h
 * Macros y definiciones para los pines del PIC.
 */

#ifndef USER_H
#define USER_H

// Librerias y Archivos.h
#include <stdint.h>     /* para las definiciones de uint8_t por ej.*/

// Macros
// Teclas
#define	PIN_TEC1 PORTBbits.RB0
#define	PIN_TEC2 PORTBbits.RB1
#define	PIN_TEC3 PORTBbits.RB2
#define	PIN_TEC4 PORTBbits.RB3

#define	TRIS_TEC1 TRISBbits.TRISB0
#define	TRIS_TEC2 TRISBbits.TRISB1
#define	TRIS_TEC3 TRISBbits.TRISB2
#define	TRIS_TEC4 TRISBbits.TRISB3

// Leds
#define PIN_LED1 PORTEbits.RE2
#define PIN_LED2 PORTEbits.RE1
#define PIN_LED3 PORTEbits.RE0
#define PIN_LED4 PORTAbits.RA5

#define TRIS_LED1 TRISEbits.TRISE2
#define TRIS_LED2 TRISEbits.TRISE1
#define TRIS_LED3 TRISEbits.TRISE0
#define TRIS_LED4 TRISAbits.TRISA5

// Alias de los leds
#define	PIN_LED_R PIN_LED1
#define	PIN_LED_AM PIN_LED2 
#define PIN_LED_V PIN_LED3        
#define	PIN_LED_AZ PIN_LED4

#define	TRIS_LED_R TRIS_LED1 
#define	TRIS_LED_AM TRIS_LED2
#define	TRIS_LED_V TRIS_LED3
#define	TRIS_LED_AZ TRIS_LED4

/*==================[declaraciones de funciones externas]====================*/
/* TODO: Los prototipos de User level (ej. InitApp) van aquí */
void appInit(void); /* Inicializa las I/O y los periféricos */

/*==================[fin del archivo]========================================*/
#endif// USER_H