#include<stdio.h>

int main()
{
    int T, n, mult, temp, rem;
    scanf("%d", &T);

    while(T--)
    {
        scanf("%d", &n);
        temp = n;
        mult = 0;

        while(temp!=0)
        {
            rem = temp%10;
            mult = mult + (rem*rem*rem);
            temp = temp/10;
        }
        if(mult == n)
        {
            printf("%d is an armstrong number!\n", n);
        }
        else
        {
            printf("%d is not an armstrong number!\n", n);
        }
    }
    return 0;
}
