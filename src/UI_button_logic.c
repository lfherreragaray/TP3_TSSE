/************************************************************************************************
Copyright (c) 2025, Luis Francisco Herrera Garay<lf.herreragaray@gmail.com>

SPDX-License-Identifier: MIT
*************************************************************************************************/

/**
 * @file UI_button_logic.c
 * @brief Lógica de procesamiento de entradas de botones
 * @author Luis Francisco Herrera Garay
 * @date 2025
 */

#include "UI_button_logic.h"
#include "API_GPIO_HAL.h"

/**
 * @brief Estructura de estado interno del módulo
 */
static struct {
    GPIO_PinState prev_b3; /**< Estado anterior del botón B3 */
    GPIO_PinState prev_b4; /**< Estado anterior del botón B4 */
    GPIO_PinState prev_b5; /**< Estado anterior del botón B5 */
    int8_t current_menu;   /**< Índice actual del menú */
    int8_t current_sel;    /**< Valor actual de selección */
} state = {.prev_b3 = GPIO_PIN_RESET,
           .prev_b4 = GPIO_PIN_RESET,
           .prev_b5 = GPIO_PIN_RESET,
           .current_menu = 0,
           .current_sel = 0};

/**
 * @brief Procesa las entradas de los botones y actualiza los estados
 * @param params Parámetros de configuración del procesamiento
 * @return OutputData Estados actualizados del sistema
 * @details Implementa:
 * - Navegación en menú con B3/B4 (flanco ascendente)
 * - Selección con B5 solo si está habilitado
 * - Lógica de wraparound para los valores
 */
OutputData ProcesarEntradas(InputParams params) {
    OutputData out;
    GPIO_PinState b3 = HAL_Read_B3();
    GPIO_PinState b4 = HAL_Read_B4();
    GPIO_PinState b5 = HAL_Read_B5();

    // Lógica de navegación en menú
    if (b3 == GPIO_PIN_SET && state.prev_b3 == GPIO_PIN_RESET) {
        state.current_menu = (state.current_menu > params.MenuIndexMinVal) ? state.current_menu - 1
                                                                           : params.MenuIndexMinVal;
    }

    if (b4 == GPIO_PIN_SET && state.prev_b4 == GPIO_PIN_RESET) {
        state.current_menu = (state.current_menu < params.MenuIndexMaxVal) ? state.current_menu + 1
                                                                           : params.MenuIndexMaxVal;
    }

    // Lógica de selección condicional
    if (params.EnSel) {
        if (b5 == GPIO_PIN_SET && state.prev_b5 == GPIO_PIN_RESET) {
            state.current_sel =
                (state.current_sel < params.SelValMaxVal) ? state.current_sel + 1 : SEL_VAL_MIN;
        }
    }

    // Actualizar estados anteriores
    state.prev_b3 = b3;
    state.prev_b4 = b4;
    state.prev_b5 = b5;

    out.MenuIndex = state.current_menu;
    out.SelVal = state.current_sel;

    return out;
}
