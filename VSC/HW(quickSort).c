#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Attribute
{
    int id;
    int korean, english, math;
};

void swap(struct Attribute* n, struct Attribute* m)
{
    struct Attribute tmp;

    tmp = *n;
    *n = *m;
    *m = tmp;
}

int partition(struct Attribute* A, int p, int r)
{
    int i, j;

    i = p - 1;

    for (j = p; j < r; j++) {
        if (A[j].korean < A[r].korean) {
            i++;

            swap(&A[i], &A[j]);
        }
    }
    i++;
    swap(&A[i], &A[r]);

    return i;
}

void quickSort(struct Attribute* std, int p, int r)
{
    int q;

    if (p < r) {
        q = partition(std, p, r);
        quickSort(std, p, q - 1);
        quickSort(std, q + 1, r);
    }
}

void printArr(struct Attribute* std, int n)
{
    for (int i = 0; i < n; i++)
        printf("%3d %3d %3d %3d\n", std[i].id, std[i].english, std[i].math, std[i].korean);
}

int main()
{
    int n;
    struct Attribute* std;

    scanf("%d", &n);
    std = (struct Attribute*)malloc(sizeof(struct Attribute) * n);

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        std[i].id = i + 1;

        std[i].english = rand() % 101;
        std[i].korean = rand() % 101;
        std[i].math = rand() % 101;
    }
    quickSort(std, 0, n-1);
    printArr(std, n);
    free(std);

    return 0;
}