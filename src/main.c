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

// Definiciones de Tipos

typedef enum {
    E_REPOSO, E_DETECTA, E_ACTIVO, E_VACIO, E_MEDIO, E_LLENO
} estadoMEF_t;

// Definiciones de variables
estadoMEF_t estadoActual;
estadoMEF_t estadoActual2;

// Funciones Internas
void colorMEFInit(void);
void colorMEF(void);

void aguaMEFInit(void);
void aguaMEF(void);

// Funcion Principal

void main(void) {
    appInit();
    colorMEFInit();
    aguaMEFInit();
    while (1) {
        colorMEF();
        aguaMEF();
    }
}

// Otras Funciones

void colorMEFInit(void) {
    estadoActual = E_REPOSO;
}

void colorMEF(void) {
    switch (estadoActual) {
        case E_REPOSO:
            // Espera a que pase el tiempo limite o por un boton (para demostrar)
            // y pasa al estado de DETECTA
            break;
        case E_DETECTA:
            // Funcion que detecta si el plato esta vacio o lleno. Si esta vacio
            // pasa al estado ACTIVO, y si esta lleno (porque no detecta o por
            // sensor infrarojo) vuelve al estado de REPOSO.
            break;
        case E_ACTIVO:
            // Funcion que activa el motor y manda la comida, y cuando detecte
            // que esta lleno vuelve al ACTIVO
            break;
        default:
            // Si cualquier cosa falla, reinicia al estado principal
            colorMEFInit();
    }
}

void aguaMEFInit(void) {
    estadoActual2 = E_VACIO;
}

void aguaMEF(void) {
    switch (estadoActual2) {
        case E_VACIO:
            //esta para que detecte si le queda poca o nada de comida en el almacen
            //espera a que se llene el almacen para que pase de estado 
            //pasa al estado MEDIO
            break;
        case E_MEDIO:
            //detecta el nivel de la comida cuando llega a la mitad del almacen
            //pasa al esatdo lleno
            break;
        case E_LLENO:
            //esta lleno no rompas las bolas 
            break;
        default:
            aguaMEFInit();
    }
}
