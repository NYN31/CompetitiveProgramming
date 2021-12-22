#include<stdio.h>

int main()
{
    int T, i, j, n;
    int N[100];

    scanf("%d", &n);
        for(j = 0; j<n; j++){
            scanf("%d", &N[j]);
        }
        for(j = 0; j<n; j+=2){
            printf("%d", N[j]);
        }
        printf("\n");

    return 0;
}
