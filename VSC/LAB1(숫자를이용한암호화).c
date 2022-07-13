#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int dist = 0, i;
    char alpha[27] = "";
    char encode[27] = "";
    char sen[81] = "";
    char encode2[81] = "";

    printf("Enter a distance for encoding: ");
    scanf("%d", &dist);
    
    for (i = 0; i < 26; i++)
        alpha[i] = 'A' + i;

    for (i = 0; i < 26; i++) {
        encode[i] = alpha[i] + dist;

        if (encode[i] > 'Z')
            encode[i] = encode[i] - 26;
    }

    printf("-------------------------------------------------------\n");
    printf("alphabet:\t\t");
    for (i = 0; i < 26; i++)
        printf("%c", alpha[i]);

    printf("\n");

    printf("encoded:\t\t");
    for (i = 0; i < 26; i++)
        printf("%c", encode[i]);
    printf("\n-------------------------------------------------------\n");

    //문장 입력
    printf("Enter a sentence to encode: ");
    fgets(sen, 80, stdin); 
    fgets(sen, 80, stdin);

    int len = strlen(sen);
    
    for (i = 0; i < len; i++) {
        if (sen[i] >= 'A' && sen[i] <= 'Z') {
            int idx = sen[i] - 'A';
            encode2[i] = encode[idx];
        }
        else
            encode2[i] = sen[i];
    }

    printf("\noriginal sentence: ");
    for (i = 0; i < len; i++)
        printf("%c", sen[i]);
    
    printf("encoded sentence: ");
    for (i = 0; i < len; i++)
        printf("%c", encode2[i]);
    printf("\n");

}