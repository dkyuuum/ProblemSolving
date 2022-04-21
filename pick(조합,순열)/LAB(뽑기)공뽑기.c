//а╤гу
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(char* n, int len, int* bucket, int bucketSize, int k)
{
    int i, lastIndex, smallest, item;

    if (k == 0)
    {
        for (i = 0; i < bucketSize; i++) { 
            printf("%c ", n[bucket[i]]);
        }
        printf("\n");
        return;
    }
    else
    {
        lastIndex = bucketSize - k - 1;

        if (bucketSize == k)
            smallest = 0;
        else
            smallest = bucket[lastIndex] + 1;

        for (item = smallest; item < len; item++)
        {
            bucket[lastIndex + 1] = item;
            pick(n, len, bucket, bucketSize, k - 1);
        }
    }
}

int main()
{
    char alp[8] = { 'A','B','C','D','E','F','G' };
    int bucket[3];

    pick(alp, 7, bucket, 3, 3);
}