#include<stdio.h>
#include<string.h>
 
int main()
{
    int T, k = 0;
    long long int sum, b, rem;
    scanf("%d", &T);
    while(T--){
        rem = 0, sum = 0;
        char a[10000];
        int i;
        scanf("%s", a);
        scanf("%lld", &b);
        if(b<0)
            b = (-1)*b;
 
        int len = strlen(a);
        for(i=0;i<len;i++)
        {
            if(a[i] == '-') continue;
            sum=rem*10+(a[i]-'0');
            rem=sum%b;
        }
        if(rem == 0){
            printf("Case %d: divisible\n", ++k);
        }
        else
            printf("Case %d: not divisible\n", ++k);
    }
    return 0;
}
