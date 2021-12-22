#include<stdio.h>

int main()
{
    int T, i, n1, n2, n3, temp;
    scanf("%d", &T);

    for(i = 1; i<=T; i++)
    {
        scanf("%d %d %d", &n1, &n2, &n3);
        printf("Case %d: ", i);

        if(n1 < n2)
        {
            if(n1 < n3)
            {
                if(n2 < n3)
                {
                    printf("%d %d %d\n", n1, n2, n3);
                }
                else
                {
                    printf("%d %d %d\n", n1, n3, n2);
                }
            }
            else
            {
                printf("%d %d %d\n", n3, n1, n2);
            }
        }
        else //n1 > n2
        {
            if(n1<n3)
            {
                printf("d %d %d\n", n2, n1, n3);
            }
            else // n1 > n3
            {
                if(n2 < n3)
                {
                    printf("%d %d %d\n", n2, n3, n1);
                }
                else
                {
                    printf("%d %d %d\n", n3, n2, n1);
                }
            }
        }
    }


    return 0;
}
