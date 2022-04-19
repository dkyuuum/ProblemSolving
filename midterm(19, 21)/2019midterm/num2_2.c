#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[52] = { 0, };
    int sum = 0;
    int n = 0;
    int i = 0;

    scanf("%s", s);

    for (i=0; i<strlen(s); i++)
    {
        sum += s[i]; 
        // '1' '2' '3' != 1 2 3
        // '1' - '0' = 1
    }

    if (strlen(s) > 2) // 여기 부분 중요! corner case
    {
        n = (s[strlen(s) - 2 - '0'] * 10);
    }
    n = n + s[strlen(s) - 1 - '0'];
    // n <- s % 100

    printf("%d", n % 2 == 0? 1:0); //참이면 1, 거짓이면 0
    printf("%d", sum % 3 == 0? 1:0); //참이면 1, 거짓이면 0
    printf("%d", n % 4 == 0? 1:0); //참이면 1, 거짓이면 0
    printf("%d", n % 5 == 0? 1:0); //참이면 1, 거짓이면 0


    return 0;
}