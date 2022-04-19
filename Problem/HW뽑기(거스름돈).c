//중복조합!!
#include <stdio.h>
#include <stdlib.h>

void pick(int *item, int n, int *picked, int m, int toPick, int target, int current_money) 
{
    int i, lastIdx, smallest;
    //int sum = 0;
    int pickedIdx;

    lastIdx = m - toPick - 1;

    /*for (i=0; i<lastIdx + 1; i++) {
        pickedIdx = picked[i];
        /um = sum + item[pickedIdx];
    }*/

    if (current_money == target) {
        for (i=0; i<=lastIdx; i++) {
            pickedIdx = picked[i];

            if (item[pickedIdx] != 0)
                printf("%d ", item[pickedIdx]);
            //sum = sum + item[pickedIdx];
        }
        printf("\n");
        return;
    }
    if (current_money > target || toPick == 0)
        return;
    
    if (m == toPick)
        smallest = 0;
    else
        smallest = picked[lastIdx]; //(조합이면 + 1)

    for (i=smallest; i<n; i++) {
        picked[lastIdx+1] = i; //item[i] -> 돈의 액수

        picked(item, n, picked, m, toPick-1, current_money+item[i]); 
    }

}
int main()
{
    int item[] = {1000, 5000, 10000, 0}; //10, 50, 100...
    int money;
    int n;
    int *picked;

    scanf("%d", &money);

    n = money/item[0];
    picked = (int *) malloc(sizeof(int *) * n);

    pick(item, sizeof(item)/sizeof(item[0]), picked, n, n, money);
    return 0;
}