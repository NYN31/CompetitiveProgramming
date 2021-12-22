#include<stdio.h>

int main()
{
    int T, i, j, n;
    int num[101];
    scanf("%d", &T);
    for(i = 1; i<=T; i++){
        scanf("%d", &n);
        for(j = 0; j<n; j++){
            scanf("%d", &num[j]);
        }
        for(j = 0; j<n; j+=2){
            printf("%d ", num[j]);
        }
        printf("\n");
    }
    return 0;
}

