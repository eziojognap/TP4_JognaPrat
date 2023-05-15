/***************************************************************************************************
 * @file    DIGITAL.H
 * @author  eziojognap
 * @date   
 * @brief   
 **************************************************************************************************/

/************************************* C++ compilar como C ****************************************/
#ifdef __cplusplus /*Esta definición se usa para compilar en c codigo que es de c++*/
extern "C" {
#endif

/************************************* INCLUDES ***************************************************/
#include <stdint.h>

/************************************* MACROS AND DEFINES *****************************************/
#ifndef DIGITAL_H
#define DIGITAL_H
#endif

/************************************* TYPEDEFS ***************************************************/
//! Referencia a un descriptor para gestionar una salida digital 
typedef struct digital_output_estructura * digital_output_puntero;
/************************************* EXPORTED VARIABLES *****************************************/

/************************************* GLOBAL FUNCTION PROTOTYPES *********************************/
/// crea una salida
digital_output_puntero DigitalOutputCreate(uint8_t port, uint8_t pin);

/// @brief  activa una salida
/// @param output 
void DigitalOutputActivate(digital_output_puntero output);

/// @brief desactiva una salida
/// @param output 
void DigitalOutputDeactivate(digital_output_puntero output);

/// @brief cambia la salida
/// @param output 
void DigitalOutputToggle(digital_output_puntero output);


#ifdef __cplusplus /*Con esto se cierra la la def condicional para compilar en c codigo que es de  \
                      c++*/
}
#endif