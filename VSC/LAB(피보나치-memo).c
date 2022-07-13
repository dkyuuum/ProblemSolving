#include <stdio.h>
#include <stdlib.h>

/*int fibo(int n, int *A)
{
    if (n<=2) 
        return 1;
    else {
        if (A[n-1] == 0)
            A[n-1] = fibo(n-1, A);

        if (A[n-2] == 0)
            A[n-2] = fibo(n-2, A);

        return A[n-1] + A[n-2];

    }
}*/
int fibo(int n, int *A)
{
    if (n<=2) 
        return 1;
    else {
        if (A[n] == 0)
            A[n] = fibo(n-1, A) + fibo(n-2, A);

        return A[n];
    }
}

int main()
{
    int num;
    int *A;

    printf("몇 번째까지의 피보나치 수열: ");
    scanf("%d", &num);

    A = (int*)malloc(sizeof(int)*(num+1));

    for  (int i=0; i<num+1; i++)
        A[i] = 0; // 계산이 안 되어 있다는 의미!

    fibo(num, A);
}