//조합
#include <stdio.h>
#include <stdlib.h>

void pick(char *item[], int n, int *bucket, int m, int toPick)
{
    int i, lastIdx, smallest;

    if (toPick == 0) {
        for (i=0; i<m; i++) {
            printf("%s ", item[bucket[i]]);
        }
        printf("\n");
        return;
    }
    lastIdx = m - toPick - 1;

    if (m == toPick) 
        smallest = 0;
    else {
        smallest = bucket[lastIdx] + 1;
    }
    for (i=smallest; i<n; i++)
    {
        bucket[lastIdx+1] = i;
        pick(item, n, bucket, m, toPick-1);
    }
}

int main()
{
    int n;
    char *item[] = {"공유", "김수현", "송중기", "지성", "현빈"};
    int *bucket;

    scanf("%d", &n);
    bucket = (int *)malloc(sizeof(int *)*n);

    pick(item, 5, bucket, n, n);
    free(bucket);
    return 0;
}