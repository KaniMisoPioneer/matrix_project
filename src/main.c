#include "matrix/matrix.h"
#include "output/output.h"

int main(){
    Matrix *A = matrixLoadFromFile("matrices/A.txt");
    Matrix *B = matrixLoadFromFile("matrices/B.txt");
    Matrix *C = matrixLoadFromFile("matrices/C.txt");
    Matrix *D = matrixLoadFromFile("matrices/D.txt");

    //D^T
    Matrix *step1 = matrixTranspose(D);

    //C*D^T
    Matrix *step2 = matrixMul(C, step1);

    //A - B
    Matrix *step3 = matrixDiff(A, B);

    //(A-B) + (C*D^T)
    Matrix *res = matrixSum(step3, step2);

    matrixPrint(res);

    matrixFree(A);
    matrixFree(B);
    matrixFree(C);
    matrixFree(D);

    matrixFree(step1);
    matrixFree(step2);
    matrixFree(step3);
    matrixFree(res);

    return 0;
}