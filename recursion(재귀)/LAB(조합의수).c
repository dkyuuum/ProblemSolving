#include <stdio.h>
#include <stdlib.h>

int comb(int n, int r)
{
    if (r == 0 || r == n)
        return 1;
    else 
        return comb(n-1, r-1) + comb(n-1, r);
}

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);
    
    printf("%d\n", comb(n, m));

    return 0;
}