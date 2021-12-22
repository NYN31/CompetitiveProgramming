#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll 
#define u unsigned
#define pb push_back
#define ss second
#define ff first
 
const ll lim1 = 1e8+5 ;
const ll lim2 = 1e5+5 ;
 
ll mark[ (lim1/64)+5 ] ;
vector<int> primes ;
 
inline ll   setBit(ll num, ll pos){ return num = (num | (1LL<<pos)); }
inline bool getBit(ll num, ll pos){ return (bool)(num & (1LL<<pos)); }
 
void sieve(){
    primes.pb(2) ;
    for(ll i=4; i<lim1; i+=2) mark[i/64LL] = setBit(mark[i/64LL], i%64LL) ;
    for(ll i=3; i<lim1; i+=2){
        if(getBit(mark[i/64LL], i%64LL)) continue ;
        primes.pb(i) ;
        for(ll j=i*i; j<lim1; j+=i)
            mark[j/64LL] = setBit(mark[j/64LL], j%64LL) ;
    }
}
/*
/// We may use this portion instead of bitwise sieve portion
const ll lim1 = 1e8+5 ;
bitset<lim1>mark;
vector<int> primes ;
 
void sieve(){
    mark.set();
    mark[0]=mark[1]=0;
    for(ll i=2;i<lim1;i++){
        if(mark[i]){
            primes.pb(i);
            for(ll j=i*i;j<lim1;j+=i)
                mark[j]=0;
        }
    }
}
*/
 
ll binpow(ll a, ll p) {
    if(p == 0) return 1LL;
    else if(p%2 == 0) {
        ll ret = binpow(a, p/2);
        return ret*ret;
    }else {
        ll ret = binpow(a, p-1);
        return a*ret;
    }
}
 
ll factorization(ll n) {
    ll ans = 1;
    for(ll i=0;i<primes.size() && primes[i]*primes[i]<=n;i++){
        ll p = primes[i], power=0;
        if(n%p != 0) continue;
        while(n%p == 0) {
            power++;
            n /= p;
        }
        ll temp = 0;
        for(ll i=0;i<=power;i++){
            temp += binpow(p, i);
        }
        ans *= temp;
      /// ans *= ( (binpow(p, power+1)-1 ) / (p-1); /// This formula will must be TLE
    }
    if(n > 1) {
        ans *= (1 + n);
    }
    return ans;
}
 
int main() {
    sieve();
    int t, x = 0; scanf("%d",&t);
    while(t--) {
        ll n; scanf("%lld",&n);
        ll ans = factorization(n)-n;
        cout<<ans<<endl;
    }
    return 0;
} 
