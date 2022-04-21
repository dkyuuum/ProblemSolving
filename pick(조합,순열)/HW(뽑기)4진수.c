//중복순열
#include <stdio.h>
#include <stdlib.h>

void pick(int *item, int n, int *bucket, int m, int toPick)
{
    int i, lastIdx;

    if (toPick == 0) {
        int pickedIdx;

        for (i=0; i<m; i++) {
            pickedIdx = bucket[i];
            printf("%d", item[pickedIdx]);
        }
        printf("\n");
        return;
    }
    lastIdx = m - toPick - 1;

    for (i=0; i<n; i++) {
        bucket[lastIdx+1] = i;
        pick(item, n, bucket, m, toPick-1);
    }
}

int main()
{
    int item[] = {0, 1, 2, 3};
    int n;
    int *bucket;

    scanf("%d", &n);
    bucket = (int*) malloc(sizeof(int*) * n);

    pick(item, 4, bucket, n, n);
    free(bucket);

    return 0;
}