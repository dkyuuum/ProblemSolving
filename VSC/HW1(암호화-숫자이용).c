#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void makeCode(char code[], int dist)
{
    char alpha[27];

    for (int i = 0; i < 26; i++)
        alpha[i] = 'A' + i;

    for (int i = 0; i < 26; i++) {
        code[i] = alpha[i] + dist;

        if (code[i] > 'Z') 
            code[i] = code[i] - 26;
    }
}

void printCode(char code[])
{
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < 26; i++)
        printf("%c", code[i]);
    printf("\n");
    printf("-------------------------------------------------------\n");

}

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
}

void decode(char code[], char e[], char d[])
{
    int i;
    int len = strlen(e);

    for (i = 0; i < len; i++) {
        if (e[i] >= 'A' && e[i] <= 'Z') {
            int idx = e[i] - 'A';
            d[i] = code[idx];
        }
        else
            d[i] = e[i];
    }
}

void reMakeCode(char code[], int dist)
{
    char alpha[27];

    for (int i = 0; i < 26; i++)
        alpha[i] = 'A' + i;

    for (int i = 0; i < 26; i++) {
        code[i] = alpha[i] - dist;

        if (code[i] < 'A')
            code[i] = code[i] + 26;
    }
}
int main(void)
{
    char code[26] = { 0, }; // code[0]부터 'A'의 암호화문자를 넣음
    int distance;
    char sentence[80] = { 0, };
    char encodedSentence[80] = { 0, };
    char decodedSentence[80] = { 0, };

    printf("Enter a distance for encoding:");
    scanf("%d", &distance);

    makeCode(code, distance);
    printCode(code);

    fflush(stdin);
    printf("Enter a sentence to encode:");
    fgets(sentence, sizeof(sentence), stdin);
    fgets(sentence, sizeof(sentence), stdin);

    encode(code, sentence, encodedSentence);
    printf("original sentence:\t");
    puts(sentence);

    printf("encoded sentence:\t");
    puts(encodedSentence);

    reMakeCode(code, distance);
    decode(code, encodedSentence, decodedSentence);
    printf("decoded sentence:\t");
    puts(decodedSentence);
}
