#include <stdio.h>
#include <string.h>

int reverse(int n)
{
    int ret = 0;

    while (n != 0)
    {
        ret = ret * 10 + n % 10;
        n /= 10;
    }
    return ret;
}

int main()
{
    int n;
    int rev_n;

    scanf("%d", &n);

    n = n * 9;

    rev_n = reverse(n);

    while (rev_n != 0) {
        printf("%d ", rev_n % 10);
        rev_n = rev_n / 10;
    }
    printf("%d\n", rev_n);

    return 0;
}