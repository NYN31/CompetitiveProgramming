#include<stdio.h>

int main()
{
    int T, i, N, MSD, LSD, Sum;

    scanf("%d", &T);
    for(i = 1; i<= T; i++){
        scanf("%d", &N);

        LSD = N%10;
        while(N != 0)
        {
            MSD = N%10;
            Sum = MSD+LSD;
            N = N/10;
        }

        printf("Sum = %d\n", Sum);
    }

    return 0;
}

