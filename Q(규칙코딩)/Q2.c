#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int reverse = 0;

int calculateReverse(int n)
{
    int rest = 0;

    if (n == 0)
        return reverse;
    else
    {
        rest = n % 10;
        reverse = reverse * 10 + rest;
        n /= 10;

        return calculateReverse(n);
    }
}

int main()
{
    int n, sum, rvr, count = 0;

    scanf("%d", &n);

    sum = n;

    while (1)
    {
        rvr = calculateReverse(sum);
        reverse = 0;

        if (sum == rvr)
        {
            if (count < 100)
                printf("%d %d\n", count, sum);
            else
                printf("NaN\n");
            break;
        }
        else
        {
            sum += rvr;
            count++;
        }
    }
}