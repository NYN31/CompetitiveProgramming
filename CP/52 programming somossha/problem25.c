#include<stdio.h>

int main()
{
    int T, x, y, i, temp, GCD, LCM;
    scanf("%d", &T);
    for(i = 1; i<=T; i++){
        scanf("%d %d", &x, &y);
        int a, b;
        a = x;
        b = y;
        while(y!=0)
        {
            temp = y;
            y = x%y;
            x = temp;
        }
        //printf("GCD = %d\n", x);
        GCD = x;
        LCM = (a*b)/GCD;
        printf("LCM = %d\n", LCM);
    }


    return 0;
}
