#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int* A, int p, int r)
{
    int i, j, t;

    i = p - 1;

    for (j = p; j < r; j++) { 
        if (A[j] < A[r]) {
            i++;
        
            t = A[i];
            A[i] = A[j];
            A[j] = t;
            //swap!!
        }
    }
    i++;

    t = A[i];
    A[i] = A[r];
    A[r] = t;

    return i;
}

void quickSort(int* A, int p, int r)
{
    int q;
    
    if (p < r) {
        q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main()
{
    int* A;
    int n;

    scanf("%d", &n);

    A = (int*)malloc(sizeof(int) * n);

    srand(time(NULL));
    for (int i = 0; i < n; i++)
        A[i] = rand() % 100000 + 1;

    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    quickSort(A, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    free(A);
    return 0;
}