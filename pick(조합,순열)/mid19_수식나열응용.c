#include <stdio.h>
#include <stdlib.h>

int pick(int *item, int n, int *bucket, int m, int toPick, int key)
{
    int i, smallest, lastIdx, total = 0;

    if (toPick == 0)
    {
        int pickedIdx;

        for (i=0; i<m; i++) {
            picked = item[bucket[i]] * (i+1);
            total += picked;

            if (total == key)
                return 1;
        }
        return 0;
    }
    lastIdx = m - toPick - 1;

    for (i=0; i<n; i++)
    {
        bucket[lastIdx+1] = i;
        ret = ret + pick(item, n, bucket, m, toPick-1, key);
    }
    return ret;
}

int main()
{
    int n, * bucket, key;
    int item[] = { 1, -1 };

    scanf("%d %d", &n, &key);
    bucket = (int*)malloc(sizeof(int*) * n);

    pick(item, 2, bucket, n, n, key);
    free(bucket);

    return 0;
}