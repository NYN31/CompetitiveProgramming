#include<stdio.h>
#include<stdlib.h>

int main()
{
    int T, N, i;
    char line[100000];
    char *p, *e;
    long input;
    int count = 0;
    p = line;

    for(i = 1; i <= T; i++){
        scanf(" %[^\n]", line);

        for(p= line; ; p = e)
        {
            input = strtol(p, &e, 10);
            if(p == e)
            {
                break;
            }
            count++;
        }
        printf("%ld\n", count);
    }
    return 0;
}
