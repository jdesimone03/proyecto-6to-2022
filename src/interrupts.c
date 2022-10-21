/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/
/** @file
 * @brief	Contiene la rutina de interrupción
 * 
 * Aquí se encuentra la implementación de la rutina de interrupción
 */
/*==================[inlcusiones]============================================*/
#include <xc.h>             /* Archivo de Encabezados General XC8 */
#include "tick.h"           /* Funciones/Parametros Tick */

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/
void isr(void);

/*==================[definiciones de funciones internas]=====================*/
/**
 * @brief	Rutina de interrupción
 * @return	Nada
 * @note    Completar con código de interrupción necesario
 */
void __interrupt() isr(void) {
//    if(IOC1)
//        PIN_LED_R = 1;
//    else
//        PIN_LED_R = 0;
}

/*==================[definiciones de funciones externas]=====================*/

/*==================[fin del archivo]========================================*/