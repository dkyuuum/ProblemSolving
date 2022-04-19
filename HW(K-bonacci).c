#include <stdio.h>
#include <stdlib.h>

int Kbonacci(int n, int k)
{
    int i;

    if  (n >= 1 && n <= k)
        return 1;
    
    for (i=1; i<=k; i++) 
        //kbonacci(n-i-1, k); i=0 부터 시작할 때!
        ret = ret + Kbonacci(n - i, k);
    return ret;
}

int main()
{
    int n, k;

    scanf("%d %d", &k, &n);
    printf("%d\n", Kbonacci(n, k));

    return 0;
}