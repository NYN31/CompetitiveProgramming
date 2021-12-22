#include<stdio.h>
 
int main()
{
    int T, n, a, b;
    scanf("%d", &T);
    while(T--){
        scanf("%d",&n);
 
        if(n>10){
            a = n-10;
            b = 10;
            printf("%d %d\n", a, b);
        }
        else{
            a = 0;
            b = n;
            printf("%d %d\n", a, b);
        }
    }
    return 0;
}
