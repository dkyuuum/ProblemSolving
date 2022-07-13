#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length(char word[])
{
    int len = 0, i;

    for (i=0; word[i] != '\0'; i++)
        len++;

    return len;
}

int main()
{
    char word[1000] = { 0, };
    int count = 0, total = 0;

    scanf("%s", word);

    int len = length(word);

    for (int i = 0; i < len; i++) {
        count++;

        if (word[i] != word[i + 1])
        {
            if (count != 1) {
                printf("%d%c", count, word[i]);
                total++;
            }
            else
                printf("%c", word[i]);

            total++;
            count = 0;
        }
    }
    printf("\n%d\n", total);
}
