/************************************************************************************************
Copyright (c) 2025, Luis Francisco Herrera Garay<lf.herreragaray@gmail.com>

SPDX-License-Identifier: MIT
*************************************************************************************************/

/**
 * @file API_GPIO_HAL.h
 * @brief Capa de abstracción de hardware para GPIO
 * @author Luis Francisco Herrera Garay
 * @date 2025
 */

#ifndef API_GPIO_HAL_H
#define API_GPIO_HAL_H

/**
 * @brief Estados posibles de un pin GPIO
 */
typedef enum {
    GPIO_PIN_RESET = 0, /**< Estado lógico bajo */
    GPIO_PIN_SET        /**< Estado lógico alto */
} GPIO_PinState;

/**
 * @brief Inicializa los botones del hardware
 */
void HAL_Button_Init(void);

/**
 * @brief Lee el estado del botón B3
 * @return GPIO_PinState Estado actual del pin
 */
GPIO_PinState HAL_Read_B3(void);

/**
 * @brief Lee el estado del botón B4
 * @return GPIO_PinState Estado actual del pin
 */
GPIO_PinState HAL_Read_B4(void);

/**
 * @brief Lee el estado del botón B5
 * @return GPIO_PinState Estado actual del pin
 */
GPIO_PinState HAL_Read_B5(void);

#endif /* API_GPIO_HAL_H */
