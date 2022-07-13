#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encode(char code[], char s[], char e[])
{
    int i;
    int len = strlen(s);

    for (i = 0; i < len; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            int idx = s[i] - 'A';
            e[i] = code[idx];
        }
        else
            e[i] = s[i];
    }
    e[i] = '\0';
}
int main()
{
    FILE* fp1;
    FILE* fp2;
    
    int dist = 0, i;
    char alpha[27] = "";
    char code[27] = "";
    int len;
    
    char plain_text[81] = "";
    char encoded_text[81] = "";


    for (i = 0; i < 26; i++)
        alpha[i] = 'A' + i;

    printf("Enter a distance for encoding: ");
    scanf("%d", &dist);

    for (i = 0; i < 26; i++) {
        code[i] = alpha[i] + dist;

        if (code[i] > 'Z')
            code[i] = code[i] - 26;
    }

    printf("-------------------------------------------------------\n");
    printf("alphabet:\t\t");
    for (i = 0; i < 26; i++)
        printf("%c", alpha[i]);
    printf("\n");

    printf("encoded:\t\t");
    for (i = 0; i < 26; i++)
        printf("%c", code[i]);
    printf("\n-------------------------------------------------------\n");

    if ((fp1 = fopen("original.txt", "rt")) == NULL) {
        printf("파일 오픈 에러1"); 
        exit(1);
    }

    if ((fp2 = fopen("encoded.txt", "wt")) == NULL) {
        printf("파일 오픈 에러2"); 
        exit(1);
    }

    while (fgets(plain_text, sizeof(plain_text), fp1) != NULL) {
        encode(code, plain_text, encoded_text);
        fputs(encoded_text, fp2);
    }
    fclose(fp1); fclose(fp2);
}