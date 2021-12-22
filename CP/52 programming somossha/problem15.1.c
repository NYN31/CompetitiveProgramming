#include<stdio.h>

int main()
{
    int count[26], i, j;
    char S[1001];
    scanf("%s", S);
    for(i = 0; i<26; i++){
        count[i] = 0;
    }

    for(i = 0; i<strlen(S); i++){
        if(S[i] >= 'a' && S[i] <= 'z'){
            count[S[i]-'a']++;
        }
    }
    for(i = 0; i<26; i++){
        if(count[i] != 0){
            printf("%c = %d\n", 'a'+i, count[i]);
        }
    }
    return 0;
}
/*for(j = 0; j<26; j++){
            if(count[j] != 0){
                printf("%c = %d\n", 'a'+j, count[j]);
            }
        }*/
