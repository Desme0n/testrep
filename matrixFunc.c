#include "matrixHead.h"

void squareMatrix(int B[][6], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            B[i][j] *= B[i][j];
        }
    }
}