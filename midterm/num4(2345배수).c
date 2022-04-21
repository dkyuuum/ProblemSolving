#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    char n[52] = { 0, };
    int sum = 0;
    int t1;

    scanf("%s", n);

    int len = strlen(n);

    for (i = 0; i < len; i++) {
        sum += n[i] - '0';
    }

    if (len >= 2)
        t1 = (n[len - 2] - '0')*10;
    t1 += n[len - 1] - '0';
    
    printf("%d%d%d%d\n", t1 % 2 == 0 ? 1 : 0, sum % 3 == 0 ? 1 : 0, t1 % 4 == 0 ? 1 : 0, t1 % 5 == 0 ? 1 : 0);

    return 0;
}