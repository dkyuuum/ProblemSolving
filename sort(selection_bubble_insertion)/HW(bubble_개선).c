#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArr(int* arr, int n)
{
    static int i = 0;
    int j;

    printf("i = %d: ", i);
    for (j = 0; j < n; j++)
        printf("%4d", arr[j]);
    printf("\n");

    i++;
}

void bubble(int* p, int n)
{
    int i, j, tmp = 0;
    int flag = 0;

    for (i = 0; i < n - 1; i++) {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
            if (p[j] > p[j + 1]) {
                tmp = p[j];
                p[j] = p[j+1];
                p[j+1] = tmp;
                
                flag = 1;
            }
        if (flag == 0)
            break;
        printArr(p, n);

    }
}

int main()
{
    int n, i;
    int* p;
    int choice;

    printf("Enter a num: ");
    scanf("%d", &n);
    p = (int*)malloc(sizeof(int) * n);

    srand(time(NULL));

    for (i = 0; i < n; i++)
        p[i] = rand() % 99;

    bubble(p, n);
    free(p);

    return 0;
}