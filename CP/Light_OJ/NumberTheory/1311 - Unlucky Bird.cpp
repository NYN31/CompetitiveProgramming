#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1500
int main()
{
    int t,no=0;
    scanf("%d",&t);
    while(t--)
    {
        double v1,v2,v3,a1,a2,d,t1,t2,birddst;
        scanf("%lf %lf %lf %lf %lf",&v1,&v2,&v3,&a1,&a2);
        t1=v1/a1;
        t2=v2/a2;
        if(t1>t2) birddst = v3*t1;
        else birddst = v3*t2;
        d = ((v1*v1)/(2*a1)) + ((v2*v2)/(2*a2));
        printf("Case %d: %0.8lf %0.8lf\n",++no,d,birddst);
    }
    return 0;
}
