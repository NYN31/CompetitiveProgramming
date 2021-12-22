##include<stdio.h>

int main()
{
    int T, i, n1, n2, n3, temp;
    scanf("%d", &T);

    while(T--)
    {
        scanf("%d%d%d", &n1, &n2, &n3);

        if(n1<n2)
        {
            temp = n2;
            n2 = n1;
            n1 = temp;
        }
        if(n1<n3)
        {
            temp = n3;
            n3 = n1;
            n1 = temp;
        }
        if(n2<n3)
        {
            temp = n3;
            n3 = n2;
            n2 = temp;
        }

        printf("%d %d %d", n1, n2, n3);
    }
    return 0;
}
