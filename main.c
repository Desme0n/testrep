#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "load.h"
#define ADD_PREFIX_AND_SUFFIX(input) ("" #input ".dll")

void inputArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        A[i] = rand() % 101 - 50;
    }
}

void printArray(int A[], int size) {
    printf("\nArray:\n");
    for (int i = 0; i < size; i++) {
        printf("%4d ", A[i]);
    }
    printf("\n");
}

void inputMatrix(int B[][6], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            B[i][j] = rand() % 101 - 50;
        }
    }
}

void printMatrix(int B[][6], int rows, int cols) {
    printf("\nMatrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", B[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int A[20], B[5][6];
    int menu = 1;
    void*l1;
    void*l2;
    MatrixFunction f1 = (MatrixFunction)Load(ADD_PREFIX_AND_SUFFIX(libMAT),&l1,"squareMatrix");
    ArrayFunction f2 = (ArrayFunction)Load(ADD_PREFIX_AND_SUFFIX(libARR),&l2,"squareArray");
    do {
		system ("cls");
        printf("1. Square elements of the array\n2. Square elements of the matrix \n0. Exit \n Enter a value: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
				system ("cls");
                inputArray(A, 20);
                printArray(A, 20);
                f2(A,20);
                //squareArray(A, 20);
                printArray(A, 20);
				system("pause");
                closeLib(l2);
                break;
            case 2:
				system ("cls");
                inputMatrix(B, 5, 6);
                printMatrix(B, 5, 6);
                f1(B,5,6);
                //squareMatrix(B, 5, 6);
                printMatrix(B, 5, 6);
				system("pause");
                closeLib(l1);
                break;
            case 0:
				system ("cls");
                printf("Exit.\n");
                break;
            default:
                printf("error.\n");
                break;
        }
    } while (menu != 0);
	system("pause");
    return 0;
}
