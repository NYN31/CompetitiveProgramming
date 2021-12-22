/*
My Solution
*/
 
ll const mod = 1000000007;
ll const N = 10000007;
bool isprime[N+5];
vector<int>primes;
int lpf[N+5];
void sieve() {
    for(ll i=0;i<N;i++) isprime[i] = true;
    for(ll i=4;i<N;i+=2) isprime[i] = false;
    isprime[0]=isprime[1]=false;
    primes.pb(2);
    for(ll i=3;i*i<N;i++){
        if(isprime[i]){
            for(ll j=i*i;j<N;j+=i)
                isprime[j]=false;
        }
    }
    for(ll i=3;i<N;i++)  if(isprime[i]) primes.pb(i);
    for(ll i=0;i<primes.size();i++){
        for(ll j=primes[i];j<N;j+=primes[i]){
            lpf[j] = primes[i];
        }
    }
}
 
ll bigMod(ll a,ll b){
    a %= mod ;
    ll res = 1 ;
    while(b>0){
        if(b&1) res = (res * a) % mod ;
        a = (a * a) % mod ;
        b >>= 1 ;
    }
    return res ;
}
 
 
int main() {
    sieve();
    ll n; scanf("%lld", &n);
    n--;
    ll m; scanf("%lld", &m);
    map<ll,ll>count1;
    for(int i=0;i<m;i++) {
        ll num; scanf("%lld",&num);
        while(num > 1) {
            count1[ lpf[num] ]++;
            num /= lpf[num];
        }
    }
    while(n--) {
        ll m ; scanf("%lld",&m);
        map<ll,ll>count2;
        while(m--) {
            ll num; scanf("%lld",&num);
            while(num > 1) {
                count2[ lpf[num] ]++;
                num /= lpf[num];
            }
        }
 
        map<ll,ll>::iterator it;
        for(it=count1.begin();it!=count1.end();it++) {
            ll x1 = it->ss;
            ll x2 = count2[it->ff];
            count1[it->ff]=min(x1, x2);
        }
        count2.clear();
    }
    //for(auto x : count1) cout<<x.ff<<" "<<x.ss<<endl;
    ll ans = 1;
    for(auto x : count1) {
        ans = (ans * bigMod(x.ff, x.ss)) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}  


/*
others solution but exactly same logic
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ss second
#define ff first
 
ll const mod = 1000000007;
ll const N = 10000007;
bool isprime[N+5];
vector<int>primes;
int lpf[N+5];
void sieve() {
    for(ll i=0;i<N;i++) isprime[i] = true;
    for(ll i=4;i<N;i+=2) isprime[i] = false;
    isprime[0]=isprime[1]=false;
    primes.pb(2);
    for(ll i=3;i<N;i+=2){
        if(isprime[i]){
            primes.pb(i);
            for(ll j=i*i;j<N;j+=i)
                isprime[j]=false;
        }
    }
    for(ll i=0;i<primes.size();i++){
        for(ll j=primes[i];j<N;j+=primes[i]){
            lpf[j] = primes[i];
        }
    }
}
 
map<ll,ll>ans, temp;
 
ll bigMod(ll a,ll b){
    if(b == 0) return 1;
    else if(b%2==0) {
        ll ret = bigMod(a,b/2);
        return (ret*ret)%mod;
    }else{
        ll ret = bigMod(a,b-1);
        return (a*ret)%mod;
    }
}
 
int main() {
    sieve();
    ll n, m; scanf("%lld", &n);
    for(int i=0;i<n;i++) {
        scanf("%lld",&m);
        temp.clear();
        while(m--) {
            ll num; scanf("%lld",&num);
            while(num > 1) {
                temp[ lpf[num] ]++;
                num /= lpf[num];
            }
        }
        if(i) {
            for(auto x : ans) ans[x.ff] = min(x.ss, temp[x.ff]);
        } else{
            for(auto x : temp) ans[x.ff] = x.ss;
        }
    }
    ll res = 1;
    for(auto x : ans) {
        res = (res * bigMod(x.ff, x.ss)) % mod;
    }
    printf("%lld\n", res);
    return 0;
} 
