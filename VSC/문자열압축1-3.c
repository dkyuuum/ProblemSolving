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

    for (int nuit = 1; unit <= strlen(s); unit++)
    {
        char *temp_s = s;
        len = 1;
        int k = 0;

        strncpy(str1, temp_s, unit);
        str1[unit] = '\0';
        
        for (i = unit; i < strlen(s); i += unit)
        {
            temp_s += unit;
            strncpy(str2, &s[i], unit);
            str1[unit] = '\0';

            if (strncmp(str1, str2, unit) == 0) //2ĭ ��
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
        }
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