#include<stdio.h>

int main()
{
    int T, i, j;
    char S[1001];
    int count[26];
    scanf("%d", &T);

    for(i = 1; i <= T; i++){
        scanf(" %[^\n]", S);

        for(j = 0; j<26; j++){
            count[j] = 0;
        }

        for(j = 0; j<strlen(S); j++){
            if(S[j] >= 'a' && S[j] <= 'z'){
                count[S[j]-'a']++;
            }
        }
        for(j = 0; j<26; j++){
            if(count[j] != 0){
                printf("%c = %d\n", 'a'+j, count[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
