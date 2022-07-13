#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int encoding(int* a, int n)
{
    int i, j, total = 1, max = -999;

    for (i = 0; i < n; i++)
        a[i] = i + 1;

    for (i = 0; i < n; i++) {
        a[i] = a[i] + 1;

        for (j = 0; j < n; j++)
            total *= a[j];

        if (max < total)
            max = total;

        a[i] = a[i] - 1;
        total = 0;
    }
    return max;
}

int main()
{
    int n;
    int *a = { 0, };

    scanf("%d", &n);
    a = (int*)malloc(sizeof(int) * n);

    printf("%d\n", encoding(a, n));
}