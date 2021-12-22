/*
  Using Little Farmats theory
  
  a^(p-1) % p = 1
  here p is a prime number and also a and p are co-prime.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000100
#define mod 1000003
 
ll fact[sz];
void solve(){
    fact[0]=fact[1]=1;
    for(ll i=2;i<=sz;i++)
        fact[i]=(i*fact[i-1])%mod;
}
ll bmod(ll a, ll p, ll m=mod){
    if(p==0) return 1;
    ll res = bmod(a, p/2, m);
    if(p%2==0) return (res*res)%m;
    else return (a*(res*res)%m)%m;
}
int main(){
    solve();
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        ll n,r,ncr=0;
        scanf("%lld %lld",&n,&r);
        ncr=(fact[n]*bmod(fact[r],mod-2))%mod;
        ncr=(ncr*bmod(fact[n-r],mod-2))%mod;
        printf("Case %d: %lld\n",++no,ncr);
    }
    return 0;
}
