#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(char* s)
{
    int i, j = 0;
    int len = 1;
    char temp[1000] = "";
    char str1[500] = "", str2[500] = ""; //�ݺ��ǰ� �ִ� ����, ���� ����
    char numStr[1000];

    
    strncpy(str1, s, 2); //2�ڸ� ����
    str1[2] = '\0';
    i = 2;

    while (i < strlen(s))
    {
        //s += 2; //�ּ� 2ĭ �̵�
        strncpy(str2, &s[i], 2);

        if (strncmp(str1, str2, 2) == 0) //2ĭ ��
            len++;
        else
        {
            if (len > 1)
            {
                sprintf(numStr, "%d", len); //len�� 10�̸� numStr�� '1''0'
                strcat(temp, numStr); //temp ���� numStr �ֱ�
            }
            strcat(temp, str1);
            strcpy(str1, str2);
            len = 1;
        }
        i += 2; //2ĭ��
    }
    if (len > 1) {
        sprintf(numStr, "%d", len); //len�� 10�̸� numStr�� '1''0'
        strcat(temp, numStr); //temp ���� numStr �ֱ�
    }
    strcat(temp, str1);

    printf("%s\n", temp);

    return strlen(temp);
}

int main()
{
    char s[1001];

    scanf("%s", s);
    printf("%d\n", solution(s));
}