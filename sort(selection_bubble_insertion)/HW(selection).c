#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Attribute
{
    int id;
    int korean, english, math;
};

void selection(struct Attribute* std, int n)
{
    int i, maxIdx = 0, j;
    struct Attribute tmp;

    for (i = 0; i < n - 1; i++) {
        for (j = 1; j < n - i; j++) {
            if (std[maxIdx].korean < std[j].korean) {
                maxIdx = j;
            }
            tmp = std[maxIdx];
            std[maxIdx] = std[n - i - 1];
            std[n - i - 1] = tmp;
        }
    }
}

void printArr(struct Attribute* std, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d %d %d %d\n", std[i].id, std[i].korean, std[i].english, std[i].math);
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
    selection(std, n);
    printArr(std, n);
    free(std);

    return 0;
}