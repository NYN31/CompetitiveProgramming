#include<stdio.h>

int main()
{
    int T, i, N, rem, LSD, MSD;
    scanf("%d", &T);

    for(i = 1; i<=T; i++)
    {
        scanf("%d", &N);

        LSD = N%10;

        while(N != 0)
        {
            rem = N%10;
            N = N/10;
            MSD = rem;
        }
        printf("Sum = %d\n", LSD+MSD);

    }
    return 0;
}
