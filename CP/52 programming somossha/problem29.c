#include<stdio.h>

int main()
{
    int T, i;
    char ch;
    scanf("%d", &T);
    for(i = 1; i<=T; i++)
    {
        scanf("%s", ch);

        if(ch>='a' && ch<='z'){
            printf("Lowercase character\n");
        }
        else if(ch>='A' && ch<='Z'){
            printf("Uppercase character\n");
        }
        else if(ch>='0' && ch<='9'){
            printf("Numerical Digit\n");
        }
        else{
            printf("Special character\n");
        }
    }
    return 0;
}
