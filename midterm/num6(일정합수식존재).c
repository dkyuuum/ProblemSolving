#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int pick(int* item, int n, int* bucket, int m, int toPick, int key)
{
    int i, lastIdx, total, ret;
    if (toPick == 0)
    {
        total = 0;
        for (i = 0; i < m; i++) 
            total += item[bucket[i]] * (i+1);

        if (total == key)
            return 1;
        return 0;
    }
    lastIdx = m - toPick - 1;
    
    ret = 0;
    
    for (i = 0; i < n; i++) {
        bucket[lastIdx + 1] = i;
        ret = ret + pick(item, n, bucket, m, toPick - 1, key);
    }
    return ret;
}

int main()
{
    int n, m;
    int item[] = { 1, -1 };
    int* bucket;
    int count = 0;

    scanf("%d %d", &n, &m);
    bucket = (int*)malloc(sizeof(int) * n);

    int ret = pick(item, 2, bucket, n, n, m);
    
    printf("%d\n", ret);
    free(bucket);
    return 0;
}