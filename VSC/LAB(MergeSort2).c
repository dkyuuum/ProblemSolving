#include <stdio.h>
#include <string.h>
#include <time.h>

//A[p...q] ... A[q+1...r]
void merge(int *A, int p, int q, int r, int *B)
{
    int i, j, t;

    t = 0;

    while (i <= q && j <= r) {
        if (A[i] < A[j]) {
            B[t] = A[i];
            i++;
        }
        else {
            B[t] = A[j];
            j++;
        }
    }

    if (i > q) {
        for (; j<=r; j++, t++) 
            B[t] = A[j];
    }

}
void mergeSort(int *A, int q, int r)
{
    int q;

    if (q<r) {
        q = (p+r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int main()
{
    int *A, *B;
    int n;

    scanf("%d", &n);

    A = (int *) malloc(sizeof(int) * n);
    B = (int *) malloc(sizeof(int) * n);

    srand(time(NULL));
    for (int i=0; i<n; i++)
        A[i] = rand() % 1000;

    for (int i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");

    mergeSort(A, 0, n-1, B);

    for (int i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");

    free(A); free(B);
    return 0;
}