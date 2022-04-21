//����
#include <stdio.h>
#include <stdlib.h>

void pick(char *item[], int n, int *bucket, int m, int toPick) 
{
    int i, lastIdx, smallest;

    if (toPick == 0) {
        for (i=0; i<m; i++) {
            printf("\t%d", bucket[i]);
        }
        printf("\n");
        return;
    }
    lastIdx = m - toPick - 1;

    if (m == toPick)
        smallest = 0;
    else
        smallest = bucket[lastIdx] + 1;

    for  (i=smallest; i<n; i++) {
        bucket[lastIdx+1] = i;
        pick(item, n, bucket, m, toPick-1);
    }
}

int main() 
{
    char* list[] = { "����", "�����", "���߱�", "����", "����" };
    int num;
    int *bucket;

    printf("����� �� ��? ");
    scanf("%d", &num);

    if (num < 0) return 0;
    bucket = (int*)malloc(sizeof(int) * num);

    if (!bucket) {
        printf("�޸𸮸� �Ҵ��� �� �����ϴ�.");
        return 0;
    }

    pick(list, 5, bucket, num, num);

    free(bucket);
    return 0;
}