#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void matrixAdd(int** a, int** b, int** x, int r, int c, int l)
{
    int i, j, k;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            x[i][j] = 0;

            for (k = 0; k < l; k++)
                x[i][j] += a[i][k] * b[k][j];
        }
}

void printMatrix(int** a, int r, int c)
{
    int i, j;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%5d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}

void readMatrix(int** a, int r, int c)
{
    int i, j;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
    printf("\n");
}

int main(void)
{
    int** A = { 0, }, **C = { 0, };
    int** X = { 0, }, ** Z = { 0, };
    int aRow, aCol, cRow, cCol;
    int i;

    printf("Enter ��� A�� ��� ���� ����:\n");
    scanf("%d %d", &aRow, &aCol);

    printf("Enter ��� C�� ��� ���� ���� <c�� ���� 4 �̻�>: ");
    scanf("%d %d", &cRow, &cCol);

    A = (int**)malloc(sizeof(int*) * aRow);
    for (i = 0; i < aRow; i++) {
        A[i] = (int*)malloc(sizeof(int) * aCol);
    }

    C = (int**)malloc(sizeof(int*) * cRow);
    for (i = 0; i < cRow; i++) {
        C[i] = (int*)malloc(sizeof(int) * cCol);
    }

    X = (int**)malloc(sizeof(int*) * aRow);
    for (i = 0; i < aRow; i++) {
        X[i] = (int*)malloc(sizeof(int) * cCol);
    }

    Z = (int**)malloc(sizeof(int*) * aCol);
    for (i = 0; i < aCol; i++) {
        Z[i] = (int*)malloc(sizeof(int) * aRow);
    }

    printf("%d x %d ��� A �Է�:\n", aRow, aCol);
    readMatrix(A, aRow, aCol);

    printf("%d x %d ��� C �Է�:\n", cRow, cCol);
    readMatrix(C, cRow, cCol);

    matrixAdd(A, C, X, aRow, cCol, cRow);

    printf("��İ�:\n");
    printMatrix(X, aRow, cCol);

    printf("��ġ���:\n");
    printMatrix(A, aCol, aRow);

    for (i = 0; i < aRow; i++)
        free(A[i]);

    for (i = 0; i < cRow; i++) {
        free(C[i]);
        free(X[i]);
    }

    for(i = 0; i < aCol; i++)
        free(Z[i]);

}