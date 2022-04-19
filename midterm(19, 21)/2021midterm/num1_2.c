#include <stdio.h>
#include <string.h>

void reverse(char src_s[], char s[])
{
    int len = strlen(src_s);

    for (int i = 0; i < len; i++)
        s[i] = src_s[len - i - 1];
}

int main(void)
{
    char n1[101] = {0,};
    char n2[101] = {0,};
    char rev_n1[101] = {0,};
    char rev_n2[101] = {0,};
    int i;

    int len_n1;
    int len_n2;
    int carry = 0;
    int carry_count = 0;
    int max_len;

    scanf("%s", n1);
    scanf("%s", n2);

    len_n1 = strlen(n1);
    len_n2 = strlen(n2);

    for (i=0; i<len_n1; i++)
        rev_n1[i] = n1[len_n1 - i - 1];

    for (i=0; i<len_n2; i++)
        rev_n2[i] = n2[len_n2 - i - 1];

    max_len = (len_n1> len_n2) ? len_n1 : len_n2; // if...

    for (i=0; i<max_len; i++)
    {
        int t1 = (rev_n1[i] == 0 /*NULL_맨 처음에 0으로 초기화*/) ? 0 : rev_n1[i] - '0';
        int t2 = rev_n2[i] - '0';
        int t3 = t1 + t2 + carry;
        
        if (t > 9)
        {
            carry = 1;
            carry_count++;
        }
        else
            carry = 0;
    }
    printf("%d\n", carry_count);

    return 0;
}