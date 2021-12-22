#include<stdio.h>

int main()
{
    int T, i;
    char S[10000];

        scanf("%[^\n]", S);

        int count;
        count = 0;
        for(i = 0; S[i] != '\0'; i++){
            if(S[i] == ' '){
                count++;
            }
        }
        printf("Count = %d", count+1);

    return 0;
}

