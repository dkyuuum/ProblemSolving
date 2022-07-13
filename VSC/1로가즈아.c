int calculate(int num, int *m)
{
    int i;

    if (num == 1)
        return 0;

    for (i = 2; i < num+1; i++) {
        m[i] = m[i-1] + 1;

        if (i % 3 == 0 && m[i] > m[i / 3] + 1) 
            m[i] = m[i / 3] + 1;

        if (i % 2 == 0 && m[i] > m[i / 2] + 1)
            m[i] = m[i / 2] + 1;
    }
    return m[num];
}

int main()
{
    int num;
    int* m;

    scanf("%d", &num);
    m = (int*)malloc(sizeof(int) * (num + 1));

    for (int i = 0; i < num + 1; i++)
        m[i] = 0;

    int ans = calculate(num, m);
    printf("%d\n", ans);

    free(m);

}