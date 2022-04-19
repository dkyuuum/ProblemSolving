//중복조합!!
#include <stdio.h>
#include <stdlib.h>

//int count = 0; 지역변수 사용은 지양하기!!

int pick(int *item, int n, int *picked, int m, int toPick, int target, int current_money) 
{
    int i, lastIdx, smallest;
    //int sum = 0;
    int pickedIdx;

    lastIdx = m - toPick - 1;

    if (current_money == target) {
        return 1;
    }
    if (current_money > target || toPick == 0)
        return 0;
    
    if (m == toPick)
        smallest = 0;
    else
        smallest = picked[lastIdx]; //(조합이면 + 1)

    for (i=smallest; i<n; i++) {
        int ret;

        picked[lastIdx+1] = i; //item[i] -> 돈의 액수

        ret = ret + picked(item, n, picked, m, toPick-1, current_money+item[i]); 
    }
    return ret;

}
int main()
{
    int item[] = {10,50,100,500}; //10, 50, 100...
    int money;
    int n;
    int *picked;

    scanf("%d", &money);

    n = money/item[0];
    picked = (int *) malloc(sizeof(int *) * n);

    pick(item, sizeof(item)/sizeof(item[0]), picked, n, n, money);
    printf("%d\n", ret);
    
    free(picked);
    return 0;
}