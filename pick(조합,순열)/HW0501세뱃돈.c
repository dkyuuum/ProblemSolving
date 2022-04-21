//중복조합
#include <stdio.h>
#include <stdlib.h>

void pick(int *item, int n, int *bucket, int m, int toPick, int target, int total)
{
    int i, lastIdx, smallest;

    lastIdx = m - toPick - 1;
    
    if (total == target) {
        for (i=0; i<=lastIdx; i++) {
            if (item[bucket[i]] != 0)
                printf("%d ", bucket[i]);
        }
        printf("\n");
        return;
    }
    
    if (total > target || toPick == 0)
        return;

    if (m == toPick)
        smallest = 0;
    else
        smallest = bucket[lastIdx];

    for (i=smallest; i<n; i++) {
        bucket[lastIdx+1] = i;
        pick(item, n, bucket, m, toPick-1, target, total+item[i]);
    }
}

int main()
{
    int item[] = {1000, 5000, 10000};
    int *bucket;
    int money;
    int total = 0;

    scanf("%d", &money);

    int n = money/item[0];
    bucket = (int*)malloc(sizeof(int*)*money);

    pick(item, sizeof(item)/sizeof(item[0]), bucket, n, n, money, total);
    free(bucket);

    return 0;
}