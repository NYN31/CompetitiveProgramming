#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

const ull mod = 4294967296 ;
const ll sz = 1e8+100 ;
const ll lim = (sz/64)+100 ;

ll setBit(ll n,ll pos){ return n |= ((ll)1<<pos); }
bool check(ll n,ll pos){ return (bool) (n & ((ll)1<<pos)); }

ll mark[lim] ;
unsigned primes[5761558];
unsigned int dp[5761558];
int cnt ;

void sieve(){
    int sq = sqrt(1e8+5) ;
    primes[cnt++] = 2 ;
    for(int i=4; i<sz; i+=2)
        mark[i/64] = setBit(mark[i/64],i%64) ;
    for(int i=3; i<sz; i+=2){
        if(!check(mark[i/64],i%64)){
            primes[cnt++] = i;
            if(i<=sq){
                for(int j=i*i; j<sz; j+=2*i)
                    mark[j/64] = setBit(mark[j/64],j%64) ;
            }
        }
    }
}

ll tot_lcm(ll n){
    ull lcm=1;
    for(int i=0;i<cnt && primes[i]*primes[i]<=n;i++){
        ull temp=n;
        temp/=primes[i];
        while(temp>=primes[i]){
            lcm=(lcm*primes[i])%mod;
            temp/=primes[i];
        }
    }
    return lcm;
}

int main(){
    sieve();
    dp[0]=2;
    for(int i=1;i<cnt;i++)
        dp[i]=(dp[i-1]*(ull)primes[i])%mod;
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        ll ans=tot_lcm(n);
        int up=upper_bound(primes,primes+cnt,n)-primes;
        up--;
        ans=(ans*dp[up])%mod;
        printf("Case %d: ",++no);
        cout<<ans<<endl;
    }
    return 0;
}
