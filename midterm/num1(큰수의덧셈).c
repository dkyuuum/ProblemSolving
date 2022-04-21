#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char n1[], char n2[])
{
    int i;
    int len = strlen(n1);

    for (i = 0; i < len; i++)
        n2[i] = n1[len - i - 1];
}

int main()
{
    char n1[101] = { 0, };
    char n2[101] = { 0, };
    char m1[101] = { 0, };
    char m2[101] = { 0, };
    int carry = 0, count = 0;

    scanf("%s %s", n1, n2);

    reverse(n1, m1);
    reverse(n2, m2);

    int len = strlen(m1) > strlen(m2) ? strlen(m1) : strlen(m2);

    for (int i = 0; i < len; i++) {
        int t1 = (m1[i] == 0) ? 0 : m1[i] - '0';
        int t2 = (m2[i] == 0) ? 0 : m2[i] - '0';
        int t3 = t1 + t2 + carry;

        if (t3 > 9) {
            carry = 1;
            count++;
        }
        else
            carry = 0;
    }
    printf("%d\n", count);

    return 0;
}