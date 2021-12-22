//Chinise Reminder Theorem

#include<stdio.h>
 
long long int value(long long int x, long long int y)
{
    long long int i;
    for(i = 1; i<y; i++)
        if((x*i)%y==1){
            return i;
        }
}
 
int main()
{
    int T, Case=0;
    scanf("%d", &T);
    while(T--)
    {
        long long int n, p[400], r[400], M[400], y[400], i, j, mul = 1, result=0;
        scanf("%lld", &n);
        for(i = 0, j = 0; i<n; i++, j++)
            scanf("%lld %lld", &p[i], &r[j]);
        for(i = 0; i<n; i++)
            mul*=p[i];
 
        for(i = 0; i<n; i++)
            M[i] = (mul/p[i]);
 
        for(i = 0; i<n; i++)
            result = (result + (r[i] * M[i] * value(M[i], p[i])));
 
        printf("Case %d: %lld\n",++Case,result%mul);
    }
    return 0;
}
