#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "../src/matrix/matrix.h"

#define EPS 1e-6

int doubleCompare(MATRIX_TYPE a, MATRIX_TYPE b) {
    return fabs(a - b) < 1e-6;
}

Matrix *createTestMatrix(int rows, int cols, MATRIX_TYPE data[]) {
    Matrix *m = matrixCreate(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m->data[i][j] = data[i * cols + j];
        }
    }
    return m;
}

void testDeterminant(void) {
    MATRIX_TYPE data1[] = {5};
    MATRIX_TYPE data2[] = {1, 2, 3, 4};
    MATRIX_TYPE data3[] = {2, 3, 1, 1, 2, 3, 3, 1, 2};

    Matrix *m1 = createTestMatrix(1, 1, data1);
    Matrix *m2 = createTestMatrix(2, 2, data2);
    Matrix *m3 = createTestMatrix(3, 3, data3);

    CU_ASSERT_DOUBLE_EQUAL(getDeterminant(m1), 5.0, EPS);
    CU_ASSERT_DOUBLE_EQUAL(getDeterminant(m2), -2.0, EPS);
    CU_ASSERT_DOUBLE_EQUAL(getDeterminant(m3), 18.0, EPS);

    matrixFree(m1);
    matrixFree(m2);
    matrixFree(m3);
}

void testMatrixMul(void) {
    MATRIX_TYPE a[] = {1, 2, 3, 4};
    MATRIX_TYPE b[] = {5, 6, 7, 8};
    MATRIX_TYPE expected[] = {19, 22, 43, 50};

    Matrix *m1 = createTestMatrix(2, 2, a);
    Matrix *m2 = createTestMatrix(2, 2, b);
    Matrix *result = matrixMul(m1, m2);

    CU_ASSERT_PTR_NOT_NULL(result);

    for (int i = 0; i < 4; i++) {
        CU_ASSERT_TRUE(doubleCompare(result->data[i / 2][i % 2], expected[i]));
    }
    matrixFree(m1);
    matrixFree(m2);
    matrixFree(result);
}

void testTranspose(void) {
    MATRIX_TYPE data[] = {1, 2, 3, 4, 5, 6};
    Matrix *m = createTestMatrix(2, 3, data);
    Matrix *transposed = matrixTranspose(m);
    CU_ASSERT_EQUAL(transposed->rows, 3);
    CU_ASSERT_EQUAL(transposed->cols, 2);
    CU_ASSERT_TRUE(doubleCompare(transposed->data[0][0], 1));
    CU_ASSERT_TRUE(doubleCompare(transposed->data[1][1], 5));

    matrixFree(m);
    matrixFree(transposed);
}

void testLoadFromFile(void) {
    const char filename[] = "test_matrix.txt";
    FILE *f = fopen(filename, "w");
    fprintf(f, "2 3\n1.5 2.5 3.5\n4.5 5.5 6.5\n");
    fclose(f);

    Matrix *m = matrixLoadFromFile(filename);
    CU_ASSERT_PTR_NOT_NULL(m);
    CU_ASSERT_EQUAL(m->rows, 2);
    CU_ASSERT_EQUAL(m->cols, 3);
    CU_ASSERT_TRUE(doubleCompare(m->data[1][2], 6.5));

    matrixFree(m);
}

void testMatrixSum(void) {
    MATRIX_TYPE a[] = {1, 2, 3, 4};
    MATRIX_TYPE b[] = {5, 6, 7, 8};
    MATRIX_TYPE expected[] = {6, 8, 10, 12};

    Matrix *m1 = createTestMatrix(2, 2, a);
    Matrix *m2 = createTestMatrix(2, 2, b);
    Matrix *result = matrixSum(m1, m2);

    CU_ASSERT_PTR_NOT_NULL(result);
    for (int i = 0; i < 4; i++) {
        CU_ASSERT_TRUE(doubleCompare(result->data[i / 2][i % 2], expected[i]));
    }

    matrixFree(m1);
    matrixFree(m2);
    matrixFree(result);
}

void testMatrixCopy(void) {
    MATRIX_TYPE data[] = {1, 2, 3, 4};
    Matrix *orig = createTestMatrix(2, 2, data);
    Matrix *copy = matrixCopy(orig);

    CU_ASSERT_EQUAL(copy->rows, orig->rows);
    CU_ASSERT_EQUAL(copy->cols, orig->cols);
    CU_ASSERT_TRUE(doubleCompare(copy->data[0][0], 1));
    CU_ASSERT_TRUE(doubleCompare(copy->data[1][1], 4));

    matrixFree(orig);
    matrixFree(copy);
}
