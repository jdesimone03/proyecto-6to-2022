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
    E_REPOSO, E_DETECTA, E_ACTIVO, E_VACIO, E_MEDIO, E_LLENO, E_COMIDA_IN, E_AGUA_IN, E_AGUA_LLENO, E_AGUA_VACIO
} estadoMEF_t;

// Definiciones de variables
estadoMEF_t estadoPlato, estadoComida, estadoAgua;
tick_t tickColor, tHeartbeat;

// Funciones Internas
void platoMEFInit(void);
void platoMEF(void);

void comidaMEFInit(void);
void comidaMEF(void);

void aguaMEFInit(void);
void aguaMEF(void);

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
    platoMEFInit();
    comidaMEFInit();
    while (1) {
        platoMEF();
        comidaMEF();
        aguaMEF();
    }
}

// Otras Funciones

void platoMEFInit(void) {
    estadoPlato = E_REPOSO;
}

void platoMEF(void) {
    switch (estadoPlato) {
        case E_REPOSO:
            if (!PIN_TEC2) {
                estadoPlato = E_DETECTA;
                PIN_COL = 1;
            }
            break;
        case E_DETECTA:
            if (!PLATO_LLENO) {
                estadoPlato = E_REPOSO;
                PIN_COL = 0;
            } else {
                estadoPlato = E_ACTIVO;
                PIN_COL = 0;
            }
            break;
        case E_ACTIVO:
            servoHorario();
            if (!PLATO_LLENO) {
                estadoPlato = E_REPOSO;
            }
            break;
        default:
            // Si cualquier cosa falla, reinicia al estado principal
            platoMEFInit();
    }
}

void comidaMEFInit(void) {
    estadoComida = E_COMIDA_IN;
}

void comidaMEF(void) {
    switch (estadoComida) {
        case E_COMIDA_IN: // Estado Inicial
            if (!BIDON_VACIO && !BIDON_MEDIO) {
                estadoComida = E_LLENO;
            }
            if (!BIDON_VACIO && BIDON_MEDIO) {
                estadoComida = E_MEDIO; //pasa al estado MEDIO
                PIN_LED_R = 0;
            }
            if (BIDON_VACIO && BIDON_MEDIO) {
                estadoComida = E_VACIO;
                PIN_LED_R = 1;
            }
            break;
        case E_LLENO:
            if (!BIDON_VACIO && BIDON_MEDIO) { // Si detecta el IR vacio y no el medio
                estadoComida = E_MEDIO; // Pasa al estado medio
            }
            break;
        case E_MEDIO:
            if (!BIDON_VACIO && !BIDON_MEDIO) {
                estadoComida = E_LLENO;
            } //detecta el nivel de la comida cuando llega a la mitad del almacen
            //pasa al esatdo lleno
            if (BIDON_VACIO && BIDON_MEDIO) {
                estadoComida = E_VACIO;
                PIN_LED_R = 1;
            }
            break;
        case E_VACIO:
            if (!BIDON_VACIO && BIDON_MEDIO) {
                estadoComida = E_MEDIO; //pasa al estado MEDIO
                PIN_LED_R = 0;
            } //esta para que detecte si le queda poca o nada de comida en el almacen
            //espera a que se llene el almacen para que pase de estado 
            break;
        default:
            comidaMEFInit();
    }
}

void aguaMEFInit(void) {
    estadoComida = E_AGUA_IN;
}

void aguaMEF(void) {
    switch (estadoAgua) {
        case E_AGUA_IN: // Estado Inicial
            if (!CAP_AGUA) {
                estadoAgua = E_AGUA_LLENO;
                PIN_LED_AZ = 0;
            }
            else {
                estadoAgua = E_AGUA_VACIO;
                PIN_LED_AZ = 1;
            }
            break;
        case E_AGUA_LLENO:
            if(CAP_AGUA){
                estadoAgua = E_AGUA_VACIO;
                PIN_LED_AZ = 1;
            }
            break;
        case E_AGUA_VACIO:
            if(!CAP_AGUA){
                estadoAgua = E_AGUA_LLENO;
                PIN_LED_AZ = 0;
            }
            break;
        default:
            aguaMEFInit();
    }
}

//uint8_t detectaColorAzul(tick_t periodo) {
//    return; // Despues lo hacemos
//}

void mideColorAzul(void) {
    static tick_t t1 = 0;
    tick_t aux = tickRead();
    int16_t temp;
    temp = aux - t1;
    t1 = aux;
    if (temp < 0)
        return;
    tickColor = temp;
}

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
