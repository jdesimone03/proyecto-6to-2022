/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/
/** @file
 * @brief	Contiene macros y definiciones de Tick
 * 
 * Aquí se definen macros, tipos de datos y se declaran las funciones y datos 
 * externos de Tick
 */
#ifndef TICK_H
#define TICK_H
/*==================[inclusiones]============================================*/
#include <stdint.h>     /* para las definiciones de uint8_t por ej.*/

/*==================[macros]=================================================*/

/*==================[tipos de datos declarados por el usuario]===============*/
typedef uint16_t tick_t; // Define tipo de dato para Tick (alcanza a 65535 mSeg)

/*==================[declaraciones de datos externos]========================*/
extern volatile tick_t tickCounter; //Contador de Tick

/*==================[declaraciones de funciones externas]====================*/
void tickInit(void);            /* Inicializa la el contador de tick */
tick_t tickRead( void );        /* Lee Tick Counter */
void tickWrite( tick_t ticks ); /* Escribe Tick Counter */

/*==================[fin del archivo]========================================*/
#endif// TICK_H
