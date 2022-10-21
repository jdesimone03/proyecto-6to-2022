/*
 * user.c
 * Incluye las inicializaciones de todo el proyecto.
 */

// Librerias y Archivos.h
#include <xc.h>
#include <stdint.h>     /* para las definiciones de uint8_t por ej.*/

#include "system.h"
#include "user.h"

// Funciones
void appInit(void) {
    /* Configura funciones analógicas y dirección de los Ports de I/O */
    ANSEL = 0;
    ANSELH = 0;
    IOCB5 = 1;
    
    TRIS_TEC1 = 1;
    TRIS_TEC2 = 1;
    TRIS_TEC3 = 1;
    TRIS_TEC4 = 1;
    
    TRIS_B_MEDIO = 1;
    TRIS_B_VACIO = 1;
    TRIS_P_LLENO = 1;
    
    TRIS_CAP1 = 1;
    TRIS_CAP2 = 1;
    TRIS_CAP3 = 1;
    
    TRIS_COL = 1;

    TRIS_LED_R = 0;
    TRIS_LED_AM = 0;
    TRIS_LED_V = 0;
    TRIS_LED_AZ = 0;
    
    TRIS_SERVO = 0;

    __delay_ms(100); //Espera que se estabilice la fuente

    /* TODO: Habilita Interrupciones si es necesario*/
    TMR0IE = 1; //Habilita interrupcion para tick
    //PEIE = 1;
    GIE = 1;
}
