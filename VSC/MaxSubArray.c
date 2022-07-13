#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int left_max_sum(int* A, int left, int right)
{
    int i, sum = 0, sum_max = A[right];

    for (i = right; i >= left; i--)
    {
        sum += A[i];

        if (sum_max < sum)
            sum_max = sum;
    }
    return sum_max;
}

int right_max_sum(int* A, int left, int right)
{
    int i, sum = 0, sum_max = A[left];

    for (i = left; i <= right; i++)
    {
        sum += A[i];

        if (sum_max < sum)
            sum_max = sum;
    }
    return sum_max;
}

int max_subarray(int* A, int left, int right)
{
    int mid, a, b, c;
    int sum = 0, max = A[left];

    mid = (left + right) / 2;

    if (left == right)
        return A[left];

    a = left_max_sum(A, left, mid);
    b = right_max_sum(A, mid + 1, right);
    c = a + b;

    if (a > b)
        max = a;
    else
        max = b;
    
    if (c > max)
        max = c;

    return max;
}

int main()
{
    int size, max, i;
    int* A;

    scanf("%d", &size);

    A = (int*)malloc(sizeof(int) * size);

    for (i = 0; i < size; i++)
        scanf("%d", &A[i]);

    max = max_subarray(A, 0, size - 1);
    printf("%d\n", max);

    free(A);
    return 0;
}