#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int get_cycle_number(int n)
{
    printf("%d ", n);

    if (n == 1)
        return 1; 
    else if (n % 2 == 0)
        return get_cycle_number(n / 2) + 1;
    else
        return get_cycle_number(n * 3 + 1) + 1;
}

int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", get_cycle_number(n));

    return 0;
}