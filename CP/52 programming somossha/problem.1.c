#include<stdio.h>

int main()
{
    int T, j, i, k;
    char S[1002], word[1002];
    scanf("%d", &T);

    for(i = 1; i<=T; i++){
        scanf(" %[^\n]", S);

        for(j = 0, k = 0; j < strlen(S); j++){
            if(S[j] != ' '){
                word[k] = S[j];
                k++;
            }
            else if(k>0){
                word[k] = '\0';
                printf("%s ", word);
                k = 0;
            }
        }
        if(k>0){
            word[k] = '\0';
            printf("%s", word);
        }
    }
    return 0;
}
