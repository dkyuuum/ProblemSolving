#define _CRT_SECURE_NO_WARNINGS
#define WIDTH 10
#define HEIGHT 10
#include <stdio.h>

int count = 0;
int screen[WIDTH][HEIGHT] = {
0, 0, 0,-1,-1,-1,-1,-1,-1,-1,
-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,
-1, 0, 0, 0, 0, 0, 0,-1,-1,-1,
-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
-1,-1, 0, 0, 0,-1, 0, 0, 0,-1,
-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
-1,-1,-1,-1, 0,-1, 0,-1, 0,-1,
-1,-1,-1,-1, 0,-1,-1,-1, 0,-1,
-1,-1,-1,-1, 0, 0, 0, 0, 0, 0
};

int floodFillCount(int x, int y, int count)
{
    if (screen[x][y] == 0 && x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
    {
        screen[x][y] = ++count;

        count = floodFillCount(x, y + 1, count);
        count = floodFillCount(x + 1, y, count);
        count = floodFillCount(x, y - 1, count);
        count = floodFillCount(x - 1, y, count);

        return count;
    }
    return count;
}

void printScreen()
{
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
            printf("%3d", screen[i][j]);
        printf("\n");
    }
}

void main()
{
    static int count = 0;

    printf("미로:\n");
    printScreen();
    printf("\n");
    
    printf("시작점을 <0, 0>으로 한 미로 방문(순서표기): \n");
    floodFillCount(0, 0, 0);
    printScreen();
}