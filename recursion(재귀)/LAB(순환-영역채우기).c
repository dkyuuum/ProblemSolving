#define _CRT_SECURE_NO_WARNINGS
#define WIDTH 10
#define HEIGHT 10
#include <stdio.h>

int screen[WIDTH][HEIGHT] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1, 0, 0,-1,-1,-1, 0,-1,-1,
-1,-1,-1, 0, 0, 0, 0, 0,-1,-1,
-1,-1,-1, 0,-1,-1,-1,-1,-1,-1,
-1,-1,-1, 0, 0, 0, 0, 0,-1,-1,
-1,-1,-1, 0,-1, 0,-1,-1,-1,-1,
-1,-1,-1, 0,-1, 0,-1,-1,-1,-1,
-1,-1,-1, 0,-1, 0, 0, 0,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
};

int floodFillCount(int x, int y, int count)
{
    if (screen[x][y] == 0)
    {
        screen[x][y] = ++count;

        count = floodFillCount(x + 1, y, count);
        count = floodFillCount(x, y + 1, count);
        count = floodFillCount(x - 1, y, count);
        count = floodFillCount(x, y - 1, count);

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

    printScreen();
    printf("\n");
    floodFillCount(4, 3, 0);
    printScreen();
}