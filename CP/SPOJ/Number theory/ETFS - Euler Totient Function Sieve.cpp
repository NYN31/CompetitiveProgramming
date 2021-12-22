#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 10001000
#define BeatMeScanf ios_base::sync_with_stdio(false)
#define sz 100100

vector<ll>prime;
bool isprime[MAX+10];
ll phi[sz];
ll segmark[sz];
void sieve()
{
    for(ll i=0;i<MAX;i++) isprime[i]=true;
    for(ll i=2;i<MAX;i+=2) isprime[i]=false;
    isprime[0]=isprime[1]=false;
    for(ll i=3;i*i<=MAX;i+=2){
        if(isprime[i]){
            for(ll j=i*i;j<=MAX;j+=i)
                isprime[j]=false;
        }
    }
    prime.push_back(2);
    for(int i=3;i<MAX;i+=2) if(isprime[i]) prime.push_back(i);
}

void SegSieve(ll l, ll r)
{
    for(ll i=l;i<=r;i++) phi[i-l]=i, segmark[i-l]=i;
    for(ll i=0;i<prime.size() && prime[i]<=r;i++){
        ll p=prime[i];
        //ll j=p;
        //if(j<l) j=((l+p-1)/p)*p;
        ll j=(l/p)*p;
        if(j<l) j+=p;
        for(;j<=r;j+=p){
            while(segmark[j-l]%p==0)
                segmark[j-l]/=p;
            phi[j-l]=(phi[j-l]/p)*(p-1);
        }
    }
    for(ll i=l;i<=r;i++){
        if(segmark[i-l]>1)
            phi[i-l]=(phi[i-l]/segmark[i-l])*(segmark[i-l]-1);
    }
}


int main()
{
    sieve();
    ll l,r;
    scanf("%lld %lld", &l,&r);
    SegSieve(l,r);
    for(ll i=l;i<=r;i++) cout<<phi[i-l]<<endl;
    return 0;
}
