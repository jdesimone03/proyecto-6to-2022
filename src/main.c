/* ===================================================================
 * Proyecto Final 2022 "AlimenCat"
 * Agustin Bondonno, Josue De Simone, Matias Fernandez, Franco Ferraro
 ===================================================================== */

// Librerias y Archivos .h
#include <stdio.h>
#include <stdint.h>
#include <xc.h>

#include "system.h"
#include "user.h"
#include "tick.h"

// Definiciones de Tipos

typedef enum {
    E_REPOSO, E_DETECTA, E_ACTIVO, E_VACIO, E_MEDIO, E_LLENO
} estadoMEF_t;

// Definiciones de variables
estadoMEF_t estadoColor;
estadoMEF_t estadoComida;
tick_t tickServo;

// Funciones Internas
void colorMEFInit(void);
void colorMEF(void);

void comidaMEFInit(void);
void comidaMEF(void);

//void giraServo(void);
void servoHorario(void);
void servoAntiHorario(void);

// Funcion Principal

void main(void) {
    appInit();
    PIN_LED_AM = 0;
    PIN_LED_AZ = 0;
    PIN_LED_V = 0;
    PIN_LED_R = 0;
        colorMEFInit();
        comidaMEFInit();
    while (1) {
        colorMEF();
        comidaMEF();
    }
}

// Otras Funciones

void colorMEFInit(void) {
    estadoColor = E_REPOSO;
}

void colorMEF(void) {
    switch (estadoColor) {
        case E_REPOSO:
            if (!PIN_TEC1) {
                estadoColor = E_DETECTA;
                PIN_COL = 1;
            }
            break;
        case E_DETECTA:
            //            if (detectaColor()) {
            //                estadoColor = E_ACTIVO;
            //                PIN_COL = 0;
            //            } else {
            //                estadoColor = E_REPOSO;
            //                PIN_COL = 0;
            //            }
            break;
        case E_ACTIVO:
            // activaServo();
            if (!BIDON_MEDIO) {
                estadoColor = E_REPOSO;
            }
            break;
        default:
            // Si cualquier cosa falla, reinicia al estado principal
            colorMEFInit();
    }
}

void comidaMEFInit(void) {
    estadoComida = E_VACIO;
}

void comidaMEF(void) {
    switch (estadoComida) {
        case E_VACIO:
                  if(!BIDON_VACIO){
                      estadoComida = E_MEDIO;       //pasa al estado MEDIO
                      
                  }                  //esta para que detecte si le queda poca o nada de comida en el almacen
                                   //espera a que se llene el almacen para que pase de estado 
            break;
        case E_MEDIO:
               if(!BIDON_MEDIO){
                   estadoComida = E_LLENO ;
               }                              //detecta el nivel de la comida cuando llega a la mitad del almacen
                                             //pasa al esatdo lleno
            break;
//        case E_LLENO:
//                                              //esta lleno no rompas las bolas 
//            break;
        default:
            comidaMEFInit();
    }
}

//uint8_t detectaColor(void) {
//    return; // Despues lo hacemos
//}

//void giraServo(void){
//    /* Tiene que girar el servo en sentido horario y despues antihorario por un
//       rato */
//    // Va a ser maquina de estado
//}

void servoHorario(void) {
    // TODO implementar con tick
    PIN_SERVO = 1;
    __delay_us(1390);
    PIN_SERVO = 0;
    __delay_ms(10);
}

void servoAntiHorario(void) {
    // TODO implementar con tick
    PIN_SERVO = 1;
    __delay_us(1570);
    PIN_SERVO = 0;
    __delay_ms(10);
}