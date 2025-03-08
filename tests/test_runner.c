#include <CUnit/CUnit.h>

#include "../src/matrix/matrix.h"

void testCreateAndFree(void) {
    Matrix *m = matrixCreate(3, 4);
    CU_ASSERT_PTR_NOT_NULL(m);
    CU_ASSERT_EQUAL(m->rows, 3);
    CU_ASSERT_EQUAL(m->cols, 4);
    matrixFree(m);

    Matrix *invalid = matrixCreate(-1, 5);
    CU_ASSERT_PTR_NULL(invalid);
}