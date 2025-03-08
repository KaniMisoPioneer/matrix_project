#include "test_matrix.c"

/* Главная функция для запуска тестов */
int main() {
    CU_pSuite suite = NULL;

    if (CU_initialize_registry() != CUE_SUCCESS)
        return CU_get_error();

    suite = CU_add_suite("Matrix Tests", NULL, NULL);
    if (!suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Добавляем тесты
    CU_add_test(suite, "Matrix Copy", testMatrixCopy);
    CU_add_test(suite, "Matrix Addition", testMatrixSum);
    CU_add_test(suite, "Matrix Multiplication", testMatrixMul);
    CU_add_test(suite, "Determinant Calculation", testDeterminant);
    CU_add_test(suite, "Matrix Transpose", testTranspose);
    CU_add_test(suite, "Load from File", testLoadFromFile);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}