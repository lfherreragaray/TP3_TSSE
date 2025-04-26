/************************************************************************************************
Copyright (c) 2025, Luis Francisco Herrera Garay<lf.herreragaray@gmail.com>

SPDX-License-Identifier: MIT
*************************************************************************************************/

/**
 * @file API_GPIO_HAL.c
 * @brief Implementación de funciones de bajo nivel para GPIO
 * @author Luis Francisco Herrera Garay
 * @date 2025
 */

#include "API_GPIO_HAL.h"

/**
 * @brief Inicializa los pines GPIO asociados a los botones
 * @note Configura los pines B3 y B4 como entradas con pull-up
 */
void HAL_Button_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    __HAL_RCC_GPIOB_CLK_ENABLE();

    GPIO_InitStruct.Pin = GPIO_PIN_3 | GPIO_PIN_4;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

/**
 * @brief Implementación de lectura para el botón B3
 */
GPIO_PinState HAL_Read_B3(void) {
    return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3);
}

/**
 * @brief Implementación de lectura para el botón B4
 */
GPIO_PinState HAL_Read_B4(void) {
    return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);
}
