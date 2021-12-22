#include<stdio.h>

void print_reverse(char str[])
{
    int i;
    for(i = strlen(str)-1; i>=0; i--){
        printf("%c", str[i]);
    }
    printf(" ");
}

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
                //printf("%s\n", word);
                print_reverse(word);
                k = 0;
            }
        }
        if(k>0){
            word[k] = '\0';
            print_reverse(word);
            printf("\n");
        }
    }
    return 0;
}
