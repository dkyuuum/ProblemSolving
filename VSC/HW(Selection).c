#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int *A, int p, int r)
{
    int i, j;
    i = p-1;

    //p는 왼쪽, r은 오른쪽
    for (j=p; j<r; j++) {
        if (A[j] < A[r]) { //정렬하지 않은 맨 왼쪽 원소가 맨 오른쪽 원소보다 작다면
            i++;

            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    i++;

    t = A[i];
    A[i] = A[r];
    A[r] = t;

    return i;
}
//A[p...r]
int selection(int *A, int p, int r, int i)
{
    int q; // pivot의 index
    int rank;

    q = partition(A, p, r);
    rank = q - p + 1;

    if (i == rank)
        return A[q];
    else if (i < rank)
        return select(A, p, q-1, i);
    else //i > rank
        return select(A, q+1, r, i-rank);
}

int main()
{
    int *A;
    int num, rank; 
    int i;

    printf("Enter the number of numbers: ");
    scanf("%d", &num);

    A = (int *)malloc(sizeof(int)*num);

    printf("몇 번째로 작은 수?: ");
    scanf("%d", &rank);

    srand(time(NULL));

    for (i=0; i<num; i++) {
        A[i] = rand() % 1000;
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("%d\n", selection(A, 0, n-1, rank));
    free(A);

    return 0;

}