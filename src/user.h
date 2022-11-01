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
#define	PIN_TEC2 PORTDbits.RD7
#define	PIN_TEC3 PORTDbits.RD6
#define	PIN_TEC4 PORTDbits.RD5

#define	TRIS_TEC1 TRISBbits.TRISB0
#define	TRIS_TEC2 TRISDbits.TRISD7
#define	TRIS_TEC3 TRISDbits.TRISD6
#define	TRIS_TEC4 TRISDbits.TRISD5

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

// Sensores Infrarojo
#define PIN_IR1 PORTAbits.RA2       //bidon arriba
#define PIN_IR2 PORTAbits.RA3       //bidon abajo 
#define PIN_IR3 PORTAbits.RA4       //plato

#define TRIS_IR1 TRISAbits.TRISA2
#define TRIS_IR2 TRISAbits.TRISA3       
#define TRIS_IR3 TRISAbits.TRISA4
// alias sensores imfrarojos
#define BIDON_VACIO PIN_IR1
#define BIDON_MEDIO PIN_IR2    
#define PLATO_LLENO PIN_IR3  

#define TRIS_B_VACIO TRIS_IR1                   //B es de bidon xdddddddddddd
#define TRIS_B_MEDIO TRIS_IR2  
#define TRIS_P_LLENO TRIS_IR3                  //P es de POLO o de PLATO 

// Sensores Capacitivos
#define PIN_CAP1 PORTDbits.RD0
#define PIN_CAP2 PORTDbits.RD1
#define PIN_CAP3 PORTDbits.RD2

#define TRIS_CAP1 TRISDbits.TRISD0
#define TRIS_CAP2 TRISDbits.TRISD1
#define TRIS_CAP3 TRISDbits.TRISD2

#define CAP_AGUA PIN_CAP3
#define TRIS_AGUA TRIS_CAP3

// Sensor de Color
#define PIN_COL PORTBbits.RB2
#define TRIS_COL TRISBbits.TRISB2

// Servo
#define PIN_SERVO PORTBbits.RB1
#define TRIS_SERVO TRISBbits.TRISB1

/*==================[declaraciones de funciones externas]====================*/
/* TODO: Los prototipos de User level (ej. InitApp) van aquí */
void appInit(void); /* Inicializa las I/O y los periféricos */

/*==================[fin del archivo]========================================*/
#endif// USER_H