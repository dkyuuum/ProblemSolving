#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int insertion(int *p, int n)
{
    int i, j, tmp, k;

    for (i=1; i<n; i++) 
    {
        for (j=0; j<i; j++)
            if (p[j] > p[i]) 
                break;
        
        tmp = p[i];
        p[j] = tmp;
    }
}

int main()
{
    int n;
    int i, *p;

    scanf("%d", &n);
    p = (int*) malloc(sizeof(int)*n);

    srand(time(NULL));

    for (i=0; i<n; i++) 
        p[i] = rand() % 999;

    insertion(p, n);

    return 0;
}