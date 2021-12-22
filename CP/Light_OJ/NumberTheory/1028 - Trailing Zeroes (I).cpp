#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000500

bool isprime[sz];
vector<ll>primes;

void sieve(){
    for(int i=2;i<sz;i++) isprime[i]=true;
    isprime[0]=isprime[1]=false;
    for(int i=4;i<sz;i+=2) isprime[i]=false;
    for(int i=3;i*i<sz;i+=2){
        if(isprime[i]){
            for(int j=i*i;j<sz;j+=i)
                isprime[j]=false;
        }
    }
    for(int i=2;i<sz-300;i++) if(isprime[i]) primes.push_back((ll)i);
}

ll factor(ll n){
    ll ans=1;
    for(int i=0;i<primes.size() && primes[i]*primes[i]<=n;i++){
        int p=primes[i];
        if(n%p != 0) continue;
        ll cnt=0;
        while(n%p==0){
            cnt++;
            n/=p;
        }
        ans*=(cnt+1);
    }
    if(n>1) ans*=2;
    return ans-1;
}

int main(){
    sieve();
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        ll ans=factor(n);
        printf("Case %d: %lld\n",++no,ans);
    }
    return 0;
}
