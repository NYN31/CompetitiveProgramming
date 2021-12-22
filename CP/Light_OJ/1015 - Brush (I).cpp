#include<stdio.h>
 
int main()
{
    int T, i = 0, total, N, j, dust;
    scanf("%d", &T);
 
    while(T--){
        scanf("%d", &N);
        total = 0;
        for(j = 1; j<=N; j++){
            scanf("%d", &dust);
            if(dust < 0)
                dust = 0;
        total = total + dust;
        }
 
        printf("Case %d: %d\n", ++i, total);
    }
    return 0;
}
