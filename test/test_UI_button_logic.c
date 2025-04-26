#include "unity.h"
#include "UI_button_logic.h"
#include "mock_API_GPIO_HAL.h"

void setUp(void) {
    // Se ejecuta antes de cada prueba
}

void tearDown(void) {
    // Se ejecuta después de cada prueba
}

void test_MenuIndex_deberia_incrementar_cuando_b4_es_presionado(void) {
    InputParams params = {
        .MenuIndexMinVal = 0, .MenuIndexMaxVal = 2, .SelValMaxVal = 2, .EnSel = false};

    // Configurar mocks para simular:
    // - B3 no presionado (RESET)
    // - B4 presionado (SET) con flanco de bajada
    // - B5 no presionado (RESET)
    HAL_Read_B3_ExpectAndReturn(GPIO_PIN_RESET);
    HAL_Read_B4_ExpectAndReturn(GPIO_PIN_SET);
    HAL_Read_B5_ExpectAndReturn(GPIO_PIN_RESET);
    OutputData result = ProcesarEntradas(params);

    // Verificar que el MenuIndex se incrementó correctamente
    TEST_ASSERT_EQUAL_INT8(1, result.MenuIndex);
    TEST_ASSERT_EQUAL_INT8(0, result.SelVal);
}

void test_MenuIndex_deberia_decrementar_cuando_b3_es_presionado(void) {
    InputParams params = {
        .MenuIndexMinVal = 0, .MenuIndexMaxVal = 2, .SelValMaxVal = 2, .EnSel = false};

    // Configurar mocks para simular:
    // - B3 presionado (SET) con flanco de bajada
    // - B4 no presionado (RESET)
    // - B5 no presionado (RESET)
    HAL_Read_B3_ExpectAndReturn(GPIO_PIN_SET);
    HAL_Read_B4_ExpectAndReturn(GPIO_PIN_RESET);
    HAL_Read_B5_ExpectAndReturn(GPIO_PIN_RESET);
    OutputData result = ProcesarEntradas(params);

    // Verificar que el MenuIndex se incrementó correctamente
    TEST_ASSERT_EQUAL_INT8(0, result.MenuIndex);
    TEST_ASSERT_EQUAL_INT8(0, result.SelVal);
}

void test_SelVal_no_deberia_incrementar_cuando_b5_es_presionado(void) {
    InputParams params = {.MenuIndexMinVal = 0,
                          .MenuIndexMaxVal = 2,
                          .SelValMaxVal = 2,
                          // - .EnSel definido en (false) no debe permitir quese escriba en SelVal
                          .EnSel = false};

    // Configurar mocks para simular:
    // - B3 no presionado (RESET)
    // - B4 no presionado (RESET)
    // - B5 presionado (SET) con flanco de bajada
    HAL_Read_B3_ExpectAndReturn(GPIO_PIN_RESET);
    HAL_Read_B4_ExpectAndReturn(GPIO_PIN_RESET);
    HAL_Read_B5_ExpectAndReturn(GPIO_PIN_SET);
    OutputData result = ProcesarEntradas(params);

    // Verificar que el MenuIndex se incrementó correctamente
    TEST_ASSERT_EQUAL_INT8(0, result.MenuIndex);
    TEST_ASSERT_EQUAL_INT8(0, result.SelVal);
}

void test_SelVal_deberia_incrementar_cuando_b5_es_presionado(void) {
    InputParams params = {.MenuIndexMinVal = 0,
                          .MenuIndexMaxVal = 2,
                          .SelValMaxVal = 2,
                          // - .EnSel definido en (true) debe permitir que se escriba en SelVal
                          .EnSel = true};

    // Configurar mocks para simular:
    // - B3 no presionado (RESET)
    // - B4 no presionado (RESET)
    // - B5 presionado (SET) con flanco de bajada
    HAL_Read_B3_ExpectAndReturn(GPIO_PIN_RESET);
    HAL_Read_B4_ExpectAndReturn(GPIO_PIN_RESET);
    HAL_Read_B5_ExpectAndReturn(GPIO_PIN_RESET);
    ProcesarEntradas(params);

    // Configurar mocks para simular:
    // - B3 no presionado (RESET)
    // - B4 no presionado (RESET)
    // - B5 presionado (SET) con flanco de bajada
    HAL_Read_B3_ExpectAndReturn(GPIO_PIN_RESET);
    HAL_Read_B4_ExpectAndReturn(GPIO_PIN_RESET);
    HAL_Read_B5_ExpectAndReturn(GPIO_PIN_SET);
    OutputData result = ProcesarEntradas(params);

    // Verificar que el MenuIndex se incrementó correctamente
    TEST_ASSERT_EQUAL_INT8(0, result.MenuIndex);
    TEST_ASSERT_EQUAL_INT8(1, result.SelVal);
}

void test_SelVal_deberia_regresar_a_0_cuando_b5_es_presionado_3_veces(void) {
    InputParams params = {.MenuIndexMinVal = 0,
                          .MenuIndexMaxVal = 2,
                          .SelValMaxVal = 2,
                          // - .EnSel definido en (true) debe permitir que se escriba en SelVal
                          .EnSel = true};

    // Configurar mocks para simular:
    // - B3 no presionado (RESET)
    // - B4 no presionado (RESET)
    // - B5 presionado (SET) con flanco de bajada
    HAL_Read_B3_ExpectAndReturn(GPIO_PIN_RESET);
    HAL_Read_B4_ExpectAndReturn(GPIO_PIN_RESET);
    HAL_Read_B5_ExpectAndReturn(GPIO_PIN_RESET);
    ProcesarEntradas(params);

    // Configurar mocks para simular:
    // - B3 no presionado (RESET)
    // - B4 no presionado (RESET)
    // - B5 presionado (SET) con flanco de bajada
    HAL_Read_B3_ExpectAndReturn(GPIO_PIN_RESET);
    HAL_Read_B4_ExpectAndReturn(GPIO_PIN_RESET);
    HAL_Read_B5_ExpectAndReturn(GPIO_PIN_SET);
    ProcesarEntradas(params);

    // Configurar mocks para simular:
    // - B3 no presionado (RESET)
    // - B4 no presionado (RESET)
    // - B5 presionado (SET) con flanco de bajada
    HAL_Read_B3_ExpectAndReturn(GPIO_PIN_RESET);
    HAL_Read_B4_ExpectAndReturn(GPIO_PIN_RESET);
    HAL_Read_B5_ExpectAndReturn(GPIO_PIN_RESET);
    ProcesarEntradas(params);

    // Configurar mocks para simular:
    // - B3 no presionado (RESET)
    // - B4 no presionado (RESET)
    // - B5 presionado (SET) con flanco de bajada
    HAL_Read_B3_ExpectAndReturn(GPIO_PIN_RESET);
    HAL_Read_B4_ExpectAndReturn(GPIO_PIN_RESET);
    HAL_Read_B5_ExpectAndReturn(GPIO_PIN_SET);
    OutputData result = ProcesarEntradas(params);

    // Verificar que el MenuIndex se incrementó correctamente
    TEST_ASSERT_EQUAL_INT8(0, result.MenuIndex);
    TEST_ASSERT_EQUAL_INT8(0, result.SelVal);
}
