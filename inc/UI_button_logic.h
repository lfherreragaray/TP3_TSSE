/************************************************************************************************
Copyright (c) 2025, Luis Francisco Herrera Garay<lf.herreragaray@gmail.com>

SPDX-License-Identifier: MIT
*************************************************************************************************/

/**
 * @file UI_button_logic.h
 * @brief Definición de estructuras y función para el manejo de botones en la interfaz
 * @author Luis Francisco Herrera Garay
 * @date 2025
 */

#ifndef UI_BUTTON_LOGIC_H
#define UI_BUTTON_LOGIC_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Valor mínimo fijo para la selección
 */
#define SEL_VAL_MIN 0

/**
 * @brief Parámetros de entrada para la función de procesamiento
 */
typedef struct {
    int8_t MenuIndexMinVal; /**< Valor mínimo permitido para el índice del menú */
    int8_t MenuIndexMaxVal; /**< Valor máximo permitido para el índice del menú */
    int8_t SelValMaxVal;    /**< Valor máximo permitido para la selección */
    bool EnSel;             /**< Habilitador del procesamiento de selección */
} InputParams;

/**
 * @brief Datos de salida del procesamiento
 */
typedef struct {
    int8_t MenuIndex; /**< Índice actual del menú */
    int8_t SelVal;    /**< Valor actual de selección */
} OutputData;

/**
 * @brief Procesa las entradas de los botones y actualiza los estados del sistema
 * @param params Parámetros de configuración para el procesamiento
 * @return OutputData Estructura con los estados actualizados
 */
OutputData ProcesarEntradas(InputParams params);

#endif /* UI_BUTTON_LOGIC_H */
