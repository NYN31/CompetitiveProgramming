 #include<stdio.h>

int main()
{
    int T, i, j;
    char S[1001];
    scanf("%[^\n]", S);
    int count;
    count = 0;

    for(i = 0; i<strlen(S); i++){
        if(S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u'){
            count++;
        }
    }
    printf("Number of vowels = %d", count);
    return 0;
}
