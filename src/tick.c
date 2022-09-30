/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/
/** @file
 * @brief	Contiene las definiciones de Tick
 * 
 * Aquí se encuentra la implementación de uart, los defines, macros, 
 * datos internos y externos, declaraciones y definiciones de funciones
 * internas y definiciones de funciones externas.
 */

/*==================[inlcusiones]============================================*/
#include <xc.h>         /* Archivo de Encabezados General XC8 */
#include <stdint.h>     /* para las definiciones de uint8_t por ej.*/

#include "system.h"     /* Funciones/Parametros System, como conf de osc/perif */
#include "tick.h"       /* Funciones/Parametros Tick */

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/
volatile tick_t tickCounter;    //Variable global que almacena el tick count

/*==================[declaraciones de funciones internas]====================*/

/*==================[definiciones de funciones internas]=====================*/

/*==================[definiciones de funciones externas]=====================*/
/**
 * @brief	Inicializa la el contador de tick 
 * @return	Nada
 * @note    Las opciones se modifican en el código, por ejemplo con la 
 * constante UART_BAUDRATE
 * @sa      UART_BAUDRATE    
 */
void tickInit(void) {
    //Configura Timer0 para desbordar aproximadamente cada 1 mSeg
    T0CS = 0;       //Internal instruction cycle clock (FOSC/4)
    PSA = 0;        //Prescaler Assignment bit
                    // 1 = Prescaler is assigned to the WDT
                    // 0 = Prescaler is assigned to the Timer0 module
    OPTION_REGbits.PS = 1;  //PS<2:0>: Prescaler Rate Select bits
                            /* 1 : 2
                             * 1 : 4 <-
                             * 1 : 8
                             * 1 : 16
                             * 1 : 32
                             * 1 : 64
                             * 1 : 128
                             * 1 : 256 */
    TMR0IE = 1;     //Habilita interrupción de TMR0
}

/**
 * @brief	Lee Tick Counter
 * @return	El vlor del contador de tick
 */
tick_t tickRead( void ) {
    tick_t aux;
    GIE = 0;                        //Inicia Zona critica
    aux = tickCounter;              //  Operaciones atomicas
    GIE = 1;                        //Finaliza la zona critica
    return aux;
}

/**
 * @brief       Escribe Tick Counter
 * @param[in]   ticks Valor a escribir en el contador de tick
 * @return      Nada
 */
void tickWrite( tick_t ticks ){
    GIE = 0;                        //Inicia Zona critica
    tickCounter = ticks;            //  Operaciones atomicas
    GIE = 1;     
}

/*==================[fin del archivo]========================================*/