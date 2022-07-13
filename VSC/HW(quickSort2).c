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

int partition(struct Attribute* A, int p, int r, int choice)
{
    int i, j;

    i = p - 1;

    for (j = p; j < r; j++) {
        if ((choice == 1 && A[j].korean < A[r].korean) ||
            (choice == 2 && A[j].english < A[r].english) ||
            (choice == 3 && A[j].math < A[r].math) ||
            (choice == 4 && A[j].id > A[r].id)) {

            i++;

            swap(&A[i], &A[j]);
        }
    }
    i++;
    swap(&A[i], &A[r]);

    return i;
}

void quickSort(struct student* std, int p, int r, int choice)
{
    int q;

    if (p < r) {
        q = partition(std, p, r, choice);
        quickSort(std, p, q - 1, choice);
        quickSort(std, q + 1, r, choice);
    }
}

void printArr(struct Attribute* std, int n)
{
    for (int i = 0; i < n; i++)
        printf("학번 : %2d \t영어 : %2d\t수학 : %2d\t국어 : %2d\n", std[i].id, std[i].english, std[i].math, std[i].korean);
}

int main()
{
    int n;
    struct Attribute* std;
    int choice;

    printf("학생 수를 입력하세요: ");
    scanf("%d", &n);
    std = (struct Attribute*)malloc(sizeof(struct Attribute) * n);

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        std[i].id = i + 1;

        std[i].english = rand() % 101;
        std[i].korean = rand() % 101;
        std[i].math = rand() % 101;
    }

    while (1)
    {
        printf("정렬 기준 선택 1. 국어 2. 영어 3. 수학 4. ID(오름차순): ");
        scanf("%d", &choice);


        if (choice != 0) {
            quickSort(std, 0, n-1, choice);
            printArr(std, n);
        }
        else
            break;
    }
    free(std);

    return 0;
}