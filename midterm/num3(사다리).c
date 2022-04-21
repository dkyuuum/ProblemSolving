#include <stdio.h>
#include <stdlib.h>

int main()
{
    int w, h, s, *p;
    char shape[1000][1000] = {0,};

    scanf("%d %d", &w, &h);
    scanf("%d", &s);

    for (int i=0; i<h; i++)
        scanf("%s", shape[i]);

    for (int i=0; i<h; i++) {
        if (s != w-1 && shape[i][j] == '1')
            s++;
        else if (s != 0 && shape[i][j-1] == '1')
            s--;
        
    }
    printf("%d\n", s);
    return 0;
}