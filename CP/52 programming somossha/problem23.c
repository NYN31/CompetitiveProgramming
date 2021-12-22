#include<stdio.h>

int main()
{
    int T, i, j;
    char S[101];
    scanf("%d", &T);

    for(i = 1; i <= T; i++){
        scanf("%s", S);

        for(j = 0; S[j] != '\0'; j++){
            if(S[j]>='A' && S[j]<='Z'){
                printf("%d", S[j] - 64);
            }
        }
        printf("\n");
    }
    return 0;
}
