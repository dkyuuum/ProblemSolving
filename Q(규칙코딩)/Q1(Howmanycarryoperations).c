#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int solution(int n)
{
    int len = 0;

    while (n > 0) {
        n /= 10;
        len++;
    }
    return len;

}

int main()
{
    int n, m, carry = 0, count = 0;

    scanf("%d %d", &n, &m);

    int len1 = solution(n);
    int len2 = solution(m);

    int len = len1 > len2 ? len1 : len2;

    for (int i = 0; i < len; i++) {
        int t1 = n % 10;
        int t2 = m % 10;
        int t3 = t1 + t2 + carry;

        if (t3 > 9) {
            carry = 1;
            count++;
        }

        n /= 10;
        m /= 10;
    }
    printf("%d\n", count);

}
