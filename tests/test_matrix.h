#ifndef TEST_MATRIX_H
#define TEST_MATRIX_H

#include <CUnit/CUnit.h>
#include "../src/matrix/matrix.h"

// Helper functions
int doubleCompare(MATRIX_TYPE a, MATRIX_TYPE b);
Matrix* createTestMatrix(int rows, int cols, MATRIX_TYPE data[]);

// Test functions
void testDeterminant(void);
void testMatrixMul(void);
void testTranspose(void);
void testLoadFromFile(void);
void testMatrixSum(void);
void testMatrixCopy(void);

#endif