#include<stdio.h>
 
int main()
{
    int T, i=0, a, b, c;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &a, &b, &c);
        printf("Case %d: ", ++i);
 
        if(a+b>c && b+c>a && c+a>b){
            if((a*a)+(b*b)==(c*c) || (c*c)+(b*b)==(a*a) || (a*a)+(c*c)==(b*b))
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}
