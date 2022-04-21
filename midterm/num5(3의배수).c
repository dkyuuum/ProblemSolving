#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int solution(int n)
{
    int ret = 0;

    while (n > 0)
    {
        n /= 10;
        ret++;
    }
    return ret;
}
int main()
{
    int i, n;
    int m, num;

    scanf("%d", &n);

    for (i = 3; ; i+=3)
    {
        m = solution(i);

        if (n - m <= 0) break;
        else n -= m;
    }
    num = i;

    for (i = 0; i < m - n; i++)
        num /= 10;

    printf("%d\n", num % 10);

    return 0;
}