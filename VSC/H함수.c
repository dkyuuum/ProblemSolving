#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long hFunction(long long n, long long* m)
{
    if (n == 1)
        return 1;

    if (m[n] != 0)
        return m[n];
    else {
        for (int i = 0; i < n; i++)
            m[n] += (i+1) * hFunction(n - i - 1, m);
    }
    return m[n];
}

int main()
{
    long long n;
    long long* m = { 0, };

    scanf("%lld", &n);
    m = (long long*)malloc(sizeof(long long*) * (n+1));

    for (int i = 0; i < n+1; i++)
        m[i] = 0;

    printf("%lld\n", hFunction(n, m));
}