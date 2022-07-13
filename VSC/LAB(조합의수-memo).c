#include <stdio.h>
#include <stdlib.h>

int comb(int n, int r)
{
    if (r == 0 || r == 1)
        return 1;
    else
        return comb(n-1, r-1) + comb(n-1, r);
}

int main()
{
    int c;
    C = comb(4, 2);

    printf("%d\n", C);
    return 0;

}