#include<stdio.h>

int main()
{
    int T, N, i, j;

    scanf("%d", &T);

    for(i = 1; i <= T; i++){
        scanf("%d", &N);

        long int fact, i;
        fact = 1;
        int count;
        count = 0;
        for(j = 2; j<=N; j++){
            fact = fact * j;
            while(fact>0){
                if(fact%10 == 0){
                    count++;
                }
                else{
                    break;
                }
                fact = fact/10;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
