#include<stdio.h>

int gcd(int a, int b)
{
    int temp;
    while(b!=0)
    {
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

int main()
{
    int T, x, y,a, b, i, temp, GCD, LCM;
    scanf("%d", &T);
    for(i = 1; i<=T; i++){
        scanf("%d %d", &x, &y);
        a = x;
        b = y;
        GCD = gcd(x, y);

        LCM = (a*b)/GCD;
        printf("LCM = %d\n", LCM);
        }


    return 0;
}

