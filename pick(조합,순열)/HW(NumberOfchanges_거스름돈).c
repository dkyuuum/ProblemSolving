#include <stdio.h>
#include <stdlib.h>

int pick(int *item, int n, int *bucket, int m, int toPick, int target, int total)
{
    int i, smallest, lastIdx, ret;
    
    lastIdx = m - toPick - 1;

    if  (target == total) {
        for (i=0; i<= lastIdx; i++) {
            if (item[bucket[i]] != 0)
                return 1;
        }
    }

    if (total > target || toPick == 0)
        return 0;
    
    if (m == toPick)
        smallest = 0;
    else
        smallest = bucket[lastIdx];
    
    for (i=smallest; i<n; i++) {
        bucket[lastIdx+1] = i;
        ret = ret + pick(item, n, bucket, m, toPick-1, target, total+item[i]);
    }
    return ret;
    

}

int main()
{
    int money, n, total = 0;
    int *bucket;
    int item[] = {10, 50, 100, 500};

    scanf("%d", &money);
    n = money / item[0];

    bucket = (int *) malloc(sizeof(int *) * n);

    int ret = pick(item, 4, bucket, n, n, money, total);

    printf("%d\n", ret);
    free(bucket);

    return 0;
}