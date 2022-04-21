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
void bubble(struct Attribute* std, int n, int choice)
{
    int i, maxIdx = 0, j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i -1; j++) {
            if ((choice == 1 && std[j].korean < std[j + 1].korean) ||
                (choice == 2 && std[j].english < std[j + 1].english) ||
                (choice == 3 && std[j].math < std[j + 1].math) ||
                (choice == 4 && std[j].id > std[j + 1].id))
                swap(&(std[j]), &(std[j + 1]));
        }
    }
}

void printArr(struct Attribute* std, int n)
{
    for (int i = 0; i < n; i++)
        printf("%3d %3d %3d %3d\n", std[i].id, std[i].korean, std[i].english, std[i].math);
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
            bubble(std, n, choice);
            printArr(std, n);
        }
        else
            break;
    }
    free(std);

    return 0;
}