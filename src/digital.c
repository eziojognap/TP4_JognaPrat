/***************************************************************************************************
 * @file    DIGITAL.c
 * @author  eziojognap
 * @date
 * @brief
 **************************************************************************************************/

/************************************* INCLUDES ***************************************************/

#include "digital.h"
#include "chip.h"

/************************************* EXTERN VARIABLES *******************************************/

/************************************* PRIVATE MACROS AND DEFINES *********************************/

/************************************* PRIVATE TYPEDEFS *******************************************/
/// estructura para almacenar el descriptor de una salida digital
struct digital_output_estructura {
    uint8_t port; ///< puerto GPIO de la salida digital
    uint8_t pin;  ///< terminal del puerto GPIO de la salida digital
};

/************************************* STATIC VARIABLES *******************************************/

/************************************* GLOBAL VARIABLES *******************************************/

/************************************* STATIC FUNCTION PROTOTYPES *********************************/

/************************************* STATIC FUNCTIONS *******************************************/

/************************************* GLOBAL FUNCTIONS *******************************************/

digital_output_puntero DigitalOutputCreate(uint8_t port, uint8_t pin) {
    static struct digital_output_estructura output;
    output.port = port;
    output.pin = pin;
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, output.port, output.pin, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, output.port, output.pin, true);

    return &output;
}

void DigitalOutputActivate(digital_output_puntero output) {
}

void DigitalOutputDeactivate(digital_output_puntero output) {
}

void DigitalOutputToggle(digital_output_puntero output) {
    Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, output->port, output->pin);
}