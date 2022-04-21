#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    int m;
    int i;
    char num[101] = { 0, };
    int len = 0;

    scanf("%d", &n);
    m = n * 9;
    int k = m;

    while (k > 0)
    {
        k /= 10;
        len++;
    }

    for (i = 0; i < len; i++) {
        num[i] = m % 10;
        m /= 10;
    }
    for (i=len-1; i>=0; i--)
        printf("%d ", num[i]);

    return 0;
}