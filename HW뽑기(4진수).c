#include <stdio.h>
#include <string.h>

void pick(int *item, int n, int *picked, int m, int toPick)
{
    int i, lastIdx;

    if (toPick == 0) {
        int pickedIdx;

        for (i=0; i<m; i++) {
            pickedIdx = picked[i];
            printf("%d", item[pickedIdx]);
        }
        printf("\n");
        
        return;
    }
    lastIdx = m - toPick - 1;

    for (i=0; i<n; i++) {
        picked[lastIdx+1] = i;
        pick(item, n. picked, m, topick-1);
    }

}

int main()
{
    int item = {0, 1, 2, 3};
    int n;
    int *picked;

    scnaf("%d", &n);
    picked = (int*) malloc(sizeof(int*) * n);

    pick(item, 4, picked, n, n);
    free(picked);

    return 0;
}