#include<stdio.h>

int main()
{
    int T, i, j;
    char S[10001];
    scanf("%d", &T);

    for(i = 1; i<=T; i++){
        scanf(" %[^\n]", S);

        for(j = 0; S[j] != '\0'; j++){
            if(S[j] == 'a' || S[j] == 'e' || S[j] == 'i' || S[j] == 'o' || S[j] == 'u'){
                printf("%c", S[j]);
            }
        }
        printf("\n");

        for(j = 0; S[j] != '\0'; j++){
            if(S[j] != 'a' && S[j] != 'e' && S[j] != 'i' && S[j] != 'o' && S[j] != 'u' && S[j] != ' '){
                printf("%c", S[j]);
            }
        }
         printf("\n");
    }
    return 0;
}
