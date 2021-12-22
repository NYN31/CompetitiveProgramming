#include<stdio.h>

int main()
{
    char ch;
    scanf("%s", &ch);

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

    return 0;
}
