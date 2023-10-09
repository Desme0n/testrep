
//файл с функцией для массива
#include "arrayHead.h"

void squareArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        A[i] *= A[i];
    }
}


