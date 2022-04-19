#include <stdio.h>
#include <stdlib.h>

void pick(int *item, int n, int *picked, int m, int toPick)
{
    int i, lastIdx, sum = 0;

    if (toPick == 0) {
        int pickedIdx;

        for (i=0; i<m; i++) {
            pickedIdx = item[i];
            //printf("%d ", item[pickedIdx]);

            if (item[pickedIdx] == 1) {
                printf("+ %d ", i + 1);
                //sum = sum + (i+1);

            }
            else {
                printf("- %d ", i + 1);
                //sum = sum - (i+1);
            }
            sum = sum + item[pickedIdx] * (i+1);
        }
        printf("= %d\n", sum);
        return;
    }
    lastIdx = m - toPick - 1;

    for (i=0; i<n; i++) {
        picked[lastIdx+1] = i;
        pick(item, n, picked, m, toPick-1);
    }

}

int main() 
{
    int item[] = {1, -1};
    int n;
    int *picked;

    scanf("%d", &n);
    picked = (int*) malloc(sizeof(int*)*n);

    picked(item, 2, picked, n, n);
    free(picked);

    return 0;
}