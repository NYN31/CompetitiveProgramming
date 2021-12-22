#include<stdio.h>

int main()
{
    int T, p, q, c;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d", &p, &q, &c);
        int i, rem = 0, mult = 1;
        for(i = 1; i<=q/2; i++){
            mult = ((mult * p)*(mult * p))%c;
        }

        printf("Result = %d\n", mult);
    }
    return 0;
}
