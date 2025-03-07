#include "matrix.h"

Matrix matrixCreate(int rows, int cols){
    if (rows <= 0 || cols <= 0) {
        return NULL;
    }

    Matrix *result = (Matrix *)malloc(sizeof(Matrix));
    if (result == NULL) {
        return NULL;
    }

    result->rows = rows;
    result->cols = cols;

    result->data = (MATRIX_TYPE **)calloc(rows, sizeof(MATRIX_TYPE *));
    if (result->data == NULL) {
        free(result);
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        result->data[i] = (MATRIX_TYPE *)calloc(cols, sizeof(MATRIX_TYPE));
        if (result->data[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(result->data[j]);
            }
            free(result->data);
            free(result);
            return NULL;
        }
    }

    return result;
}

void matrixFree(Matrix *matrix){
    if (matrix) {
        if (matrix->data) {
            for (int i = 0; i < matrix->rows; i++) {
                free(matrix->data[i]);
            }
            free(matrix->data);
        }
        free(matrix);
    }
}

Matrix matrixLoadFromFile(const char *filename){
    FILE *file = fopen(filename, "r");
    int rows = 0, cols = 0;
    Matrix *res;

    if (file && fscanf(file, "%d%d", &rows, &cols) == 2) {
        res = create_matrix(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                fscanf(file, "%lf", &(res->data[i][j]));
        fclose(file);
    } else
        res = NULL;

    return res;
}

Matrix *matrixCopy(const Matrix *source){
    Matrix *result = matrixCreate(source->row, source->cols);

    for (int i = 0; i < source->rows; i++)
        for (int j = 0; j < source->cols; j++)
            result->data[i][j] = source->data[i][j];

    return result;
}

Matrix *matrixSum(const Matrix *A, const Matrix *B){
    Matrix *result = NULL;
    if (A->rows == B->rows && A->cols == B->cols) {
        result = matrixCreate(A->rows, A->cols);

        for (int i = 0; i < A->rows; i++)
            for (int j = 0; j < A->cols; j++)
                result->data[i][j] = A->data[i][j] + B->data[i][j];
    }
    return result;
}

Matrix *matrixDiff(const Matrix *A, const Matrix *B){
    Matrix *result = NULL;
    if (A->rows == B->rows && A->cols == B->cols) {
        result = matrixCreate(A->rows, A->cols);

        for (int i = 0; i < A->rows; i++)
            for (int j = 0; j < A->cols; j++)
                result->data[i][j] = A->data[i][j] - B->data[i][j];
    }
    return result;
}

Matrix *matrixMul(const Matrix *A, const Matrix *B){
    Matrix *result = NULL;
    if (A->cols == B->rows) {
        result = matrixCreate(A->rows, A->cols);

        for (int i = 0; i < A->rows; i++)
            for (int j = 0; j < B->cols; j++)
                for (int k = 0; k < A->cols; k++)
                    result->data[i][j] += A->data[i][k] * B->data[k][j];
    }
    return result;
}

Matrix *matrixTranspose(const Matrix *matrix){
    Matrix *result = NULL;

    result = matrixCreate(matrix->cols, matrix->rows);
    result->cols = matrix->rows;
    result->rows = matrix->cols;
    for (int i = 0; i < matrix->rows; i++)
        for (int j = 0; j < matrix->cols; j++)
            result->data[j][i] = matrix->data[i][j];

    return result;
}

MATRIX_TYPE getDeterminant(const Matrix *A) {
    MATRIX_TYPE det = 0;

    if (!A || A->rows != A->cols)
        det = NAN;
    else {
        if (A->rows == 1)
            det = A->data[0][0];
        else if (A->rows == 2)
            det = A->data[0][0] * A->data[1][1] - A->data[0][1] * A->data[1][0];
        else
            for (int k = 0; k < A->cols; k++) {
                Matrix *minor = getMinorMatrix(A, 0, k);
                det += pow(-1, k) * A->data[0][k] * determinant(minor);
                free_matrix(minor);
            }
    }
    return det;
}