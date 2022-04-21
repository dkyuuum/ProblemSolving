#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int searchC(int a)
{
    int i = 1, z = 0, count = 1;

    while (1)
    {
        if (i % a == 0)
            return count;
        else
        {
            i = (i * 10 ^ z) + 1;
            count++;
        }
    }
}

int main()
{
    int num;

    scanf("%d", &num);
    printf("%d\n", searchC(num));

}