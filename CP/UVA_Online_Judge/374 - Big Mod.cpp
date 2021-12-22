#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll binpow(ll a, ll p, ll m){
    if(p==0) return 1;
    ll res = binpow(a, p/2, m);
    if(p%2==0) return (res*res)%m;
    else return (a*(res*res)%m)%m;
}

int main()
{
    BeatMeScanf;
    ll a,p,m;
    while(cin>>a>>p>>m){
        ll ans=binpow(a,p,m);
        cout<<ans<<endl;
    }
    return 0;
}



/*#include<stdio.h>
long long int bigmod(long long int a, long long int b, long long int c)
{
    if(b == 0) return 1;
    else if(b == 1)  return a%c;
    else if(b%2 == 0){
        long long int v = bigmod(a, b/2, c);
        return (v*v)%c;
    }
    else if(b%2 == 1){
        long long int x, y;

        y = bigmod(a, b-1, c);
        return (a*y)%c;
    }
}

int main()
{
    long long int a, b, c;
    while(scanf("%lld %lld %lld", &a, &b, &c)!=EOF)
    {
        printf("%lld\n", bigmod(a, b, c));
    }
    return 0;
}*/
