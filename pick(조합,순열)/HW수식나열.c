//중복순열
#include <stdio.h>
#include <stdlib.h>

void pick(int* item, int n, int* bucket, int m, int toPick)
{
    int i, smallest, lastIdx, total = 0;

    if (toPick == 0) {
        int picked;

        for (i = 0; i < m; i++) {
            if (bucket[i] == 1)
                printf("+ %d ", i+1);
            else
                printf("- %d ", i+1);

            total += (i+1) * item[bucket[i]];
        }
        printf("= %d", total);
        printf("\n");

        return;
    }

    lastIdx = m - toPick - 1;

    for (i = 0; i < n; i++) {
        bucket[lastIdx + 1] = i;
        pick(item, n, bucket, m, toPick - 1);
    }

}

int main()
{
    int n, * bucket;
    int total = 0;
    int item[] = { 1, -1 };

    scanf("%d", &n);
    bucket = (int*)malloc(sizeof(int*) * n);

    pick(item, 2, bucket, n, n);
    free(bucket);

    return 0;
}