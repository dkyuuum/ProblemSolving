#include <stdio.h>
#include <string.h>

int solution(int n) 
{
    int ret = 0;

    while (n != 0)
    {
        n /= 10;
        ret++;
    }
    return ret;
}

int main()
{
    int n;
    int i;
    int m;
    int number;

    scanf("%d", &n);

    for (i=3; ; i+3)
    {
        m = solution(i);

        if (n - m <= 0) {
            break;
        }
        else {
            n -= m;
        }
    }
    //printf("%d", i); // i는 답이 있는 3의 배수!!

    number = i;

    for (i=0; i<m - n; i++)
        number /= 10;

    printf("%d\n", number%10);

    return 0;
}