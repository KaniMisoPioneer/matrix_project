#include "output.h"

int printFunc(const Matrix *matrix, FILE *stream){
    int returnCode = 0;

    if (!matrix || !stream)
        returnCode = -1;

    for (int i = 0; !returnCode && i < matrix->rows; i++) {
        for (int j = 0; !returnCode && j < matrix->cols; j++) {
            int result = fprintf(stream, "%.2lf", matrix->data[i][j]);
            if (result < 0)
                returnCode = 1;
            fprintf(stream, " ");
        }
        if (fprintf(stream, "\n") < 0)
            returnCode = -1;
    }
    return returnCode;
}