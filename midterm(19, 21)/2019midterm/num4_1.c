#include <stdio.h>
#include <stdlib.h>

//int count = 0;
int pick(int *item, int n, int *picked, int m, int toPick, int target)
{
    int i = 0, ret;

    if (toPick == 0)
    {
        int pickedIdx;

        for (i=0; i<m; i++)
        {
            pickedIdx = picked[i];
            //printf("%c * %d", item[pickedIdx] == 1? '+' : '-', (i + 1));

            sum = sum + item[pickedIdx] * (i+1);
        }
        //printf("= %d\n", sum);

        if (sum == target)
        {
            //count++;
            return 1;
        }
        return 0;
    }

    lastIdx = m - toPick - 1;
    ret = 0;
    
    for (i=0; i<n; i++)
    {
        picked[lastIdx+1] = i;
        ret = ret + pick(item, n, picked, m, toPick - 1, target);
    }
    return ret;
}

int main()
{
    int n1, n2;
    int item[] = {1, -1}; // char item[] = {'+', '-'};
    int *picked;
    int count;

    scanf("%d %d", &n1, &n2);

    picked = (int*) malloc(sizeof(int*) * n1);

    pick(item, 2, picked, n1, n1, n2);
    printf("%d\n", count);

    free(picked);
    return 0;
}