#include<stdio.h>

int main()
{
    int T, N, a, i, j;
    scanf("%d", &T);

    for(a = 1; a<=T; a++){
        scanf("%d", &N);

        for(i=1; i<=N; i++){
            for(j=1; j<=N; j++){
                printf("*");
            }
            printf("\n");
        }
        printf("\n\n");
    }
    return 0;
}
