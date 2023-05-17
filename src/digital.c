/***************************************************************************************************
 * @file    DIGITAL.c
 * @author  eziojognap
 * @date
 * @brief
 **************************************************************************************************/

/************************************* INCLUDES ***************************************************/

#include "digital.h"
#include "chip.h"
#include <stdbool.h>

/************************************* EXTERN VARIABLES *******************************************/

/************************************* PRIVATE MACROS AND DEFINES *********************************/

#ifndef INSTANCIAS_OUTPUT
#define INSTANCIAS_OUTPUT 8
#endif

/************************************* PRIVATE TYPEDEFS *******************************************/
/// estructura para almacenar el descriptor de una salida digital
struct digital_output_estructura {
    uint8_t port; ///< puerto GPIO de la salida digital
    uint8_t pin;  ///< terminal del puerto GPIO de la salida digital
    bool alocado;
};
/************************************* DECLARACION DE FUNCIONES INTERNAS **************************/
digital_output_puntero DigitalOutputAllocated(void);

/************************************* STATIC VARIABLES *******************************************/

/************************************* GLOBAL VARIABLES *******************************************/

/************************************* STATIC FUNCTION PROTOTYPES *********************************/

/************************************* STATIC FUNCTIONS *******************************************/

/************************************* GLOBAL FUNCTIONS *******************************************/
// digital_output_puntero DigitalOutputAllocated(void);

/// @brief Es una funcion parecida a malloc
/// @param
/// @return me devuelve el valor de un puntero donde hay un espacio de memoria disponible
digital_output_puntero DigitalOutputAllocated(void) {

    static struct digital_output_estructura instancias[INSTANCIAS_OUTPUT] = {0};

    digital_output_puntero valor_puntero = NULL;

    for (int i = 0; i < INSTANCIAS_OUTPUT; i++) {
        if (!instancias[i].alocado) {     // si no esta ocupado entra a la condicion
            instancias[i].alocado = true; // como lo voy a ocupar, lo pongo en ocupado
            valor_puntero = &instancias[i];
            break;
        } // else {
          //  printf("No hay espacio en memoria\n");
          // valor_puntero = NULL;
        //}
    }
    return valor_puntero;
}

digital_output_puntero DigitalOutputCreate(uint8_t port, uint8_t pin) {

    digital_output_puntero puntero_salida = DigitalOutputAllocated();

    if (puntero_salida) { // si es null no hace nada.
        puntero_salida->port = port;
        puntero_salida->pin = pin;
        // No necesito poner que esta alocado porque ya lo hace la funcion DigitalOutputAllocated
        Chip_GPIO_SetPinState(LPC_GPIO_PORT, puntero_salida->port, puntero_salida->pin, false);
        Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, puntero_salida->port, puntero_salida->pin, true);
    }

    return puntero_salida;
}

void DigitalOutputActivate(digital_output_puntero output) {
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, output->port, output->pin, true);
}

void DigitalOutputDeactivate(digital_output_puntero output) {
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, output->port, output->pin, false);
}

void DigitalOutputToggle(digital_output_puntero output) {
    Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, output->port, output->pin);
}