#include <stdio.h>

int main()
{
    int i, j, w, h, s;
    char ladder[100][100] = {0,};

    scanf("%d %d", &w, &h);
    scanf("%d", &s);

    for (i = 0; i < h; i++)
        scanf("%s", ladder[i]);

    for (i=0; i<h; i++)
    {
        /*if (s == 0) {
            if (ladder[i][s] == '1')
                s++;
        }
        else if (s == w - 1) {
            if  (ladder[i][s-1] == '1')
                s--;
        }
        else {
            if (ladder[i][s] == '1')
                s++;
            else if (ladder[i][s-1] == '1')
                s--;
        }*/
        
        if (s != w-1 && ladder[i][s] == '1')
            s++;
        else if (s != 0 && ladder[i][s-1] == '1')
            s--;
    }
    printf("%d\n", s);
    
    return 0;
}