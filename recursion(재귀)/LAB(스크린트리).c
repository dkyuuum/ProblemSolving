#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_LEVEL 5
#define MAX_WIDTH 70

char screen[MAX_LEVEL][MAX_WIDTH];

void draw_tree(int row, int left, int right)
{
    int mid;

    if (right - left < 2) return;
    mid = (right+left) / 2;

    screen[row][mid] = 'X';
}
int main() 
{
    int n;

    printf("Enter a width(<=70) of a screen: ");
    scanf("%d", &n);


    return 0;
}