#include "test_matrix.c"

int doubleCompare(MATRIX_TYPE a, MATRIX_TYPE b) {
    return fabs(a - b) < 1e-6;
}

Matrix *createTestMatrix(int rows, int cols, MATRIX_TYPE data[]) {
    Matrix *m = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m->data[i][j] = data[i * cols + j];
        }
    }
    return m;
}

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