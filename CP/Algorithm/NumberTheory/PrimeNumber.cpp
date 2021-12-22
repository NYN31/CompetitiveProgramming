#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

ll const lim = 1e8+5;
/*
problem 1: A naive solution finding a number is a prime or not
        complexity : O( sqrt(n) ); (1<=n<=10^16)
problem 2: sieve method (general)
        complexity : O(N * log(N)) (1<=N<=10^7)
problem 3: sieve method ( useing bitset)
        complexity : O(N * log(N)) (1<=N<=10^8)
problem 4: segment sieve 
problem 5: bitwise sieve (1<=N<=10^8)
problem 6: sieve with wheel factorization (For faster calculation)
*/

/*
problem 1: A naive solution finding a number is a prime or not
*/
int main() {
    ll n; cin>>n;
    bool flag = true;
    for(ll i=2;i*i<n;i++) {
        if(n % i == 0){
            flag = false;
            break;
        }
    }

    if(flag) cout<<n<<" is a prime number\n";
    else cout<<n<<" is not a prime number\n";
    return 0;
}

/*
problem 2: sieve method (general)
*/

bool isprime[lim+5];
vector<ll>primes;

void sieve(){
    for(ll i=0;i<lim;i++) isprime[i]=true;
    for(ll i=4;i<lim;i+=2) isprime[i]=false;
    isprime[0]=isprime[1]=0;
    for(ll i=3;i<lim;i+=2) {
        if(isprime[i]) {
            primes.pb(i);
            for(ll j=i*i;j<lim;j+=i)
                isprime[j]=false;
        }
    }
}

/*
problem 3: Sieve method (Using bitset)
*/

bitset<lim>isprime;
vector<ll>primes;

void bitsieve(){
    isprime.set();
    for(ll i=2;i<lim;i++) {
        if(isprime[i]) {
            primes.pb(i);
            for(ll j=i;j<lim;j+=i)
                isprime[j]=0;
        }
    }
}

/*
problem 4: segment sieve
*/

#define MAX 46345
vector<ll>prime;
void sieve()
{
    bool isPrime[MAX];
    for(ll i=0;i<MAX;i++) isPrime[i]=true;

    for(ll i=3;i*i<=MAX;i+=2){
        if(isPrime[i]){
            for(ll j=i*i;j<=MAX;j+=i)
                isPrime[j]=false;
        }
    }
    prime.push_back(2);
    for(int i=3;i<MAX;i+=2) if(isPrime[i]) prime.push_back(i);
}

void SegSieve(ll l, ll r)
{
    bool isPrime[r-l+50];
    for(ll i=0;i<r-l+1;i++) isPrime[i]=true;
    if(l==1) isPrime[0]=false;
    for(ll i=0;prime[i]*prime[i]<=r;i++){
        ll currentPrime=prime[i];
        ll base =(l/currentPrime)*currentPrime;
        if(base<l) base+=currentPrime;
        for(ll j=base;j<=r;j+=currentPrime)
            isPrime[j-l]=false;
        if(base==currentPrime) isPrime[base-l]=true;
    }
    for(ll i=0;i<r-l+1;i++)
        if(isPrime[i]) printf("%lld\n", i+l);

}

/*
problem 5: bitwise sieve (1<=N<=10^8)
*/
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
        for(ll j=i*i; j<lim1; j+=2*i)
            mark[j/64LL] = setBit(mark[j/64LL], j%64LL) ;
    }
}

/*
problem 6: sieve with wheel factorization
*/

vector<int> sieve_with_wheel(int n) {
    if(n <= 32) {
        vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
        vector<int> ans;
        for(int i = 0; i < primes.size(); i++) {
            if(n < primes[i]) {
                return ans;
            }
            ans.push_back(primes[i]);
        }
        return primes;
    }
    int u = n + 32;
    double lu = log(u);
    vector<int> ret (u / lu + u / lu / lu * 1.5, 0);
    ret[0] = 2;
    int pos = 1;
    vector<int> isp ((n + 1) / 32 / 2 + 1, 0);
    int sup = (n + 1) / 32 / 2 + 1;

    vector<int> tprimes = { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    for(int tp : tprimes) {
        ret[pos++] = tp;
        vector<int> ptn(tp);
        for(int i = (tp - 3) / 2; i < tp << 5; i += tp)
            ptn[i >> 5] |= 1 << (i & 31);
        for(int i = 0; i < tp; i++) {
            for(int j = i; j < sup; j += tp)
                isp[j] |= ptn[i];
        }
    }
    vector<int> magic = { 0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4,
                          13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14
                        };
    int h = n / 2;
    for(int i = 0; i < sup; i++) {
        for(int j = ~isp[i]; j != 0; j &= j - 1) {
            int pp = i << 5 | magic[(1u*(j & -j) * 0x076be629 >> 27)]; //magic[x] = __builtin_clzll(x)
            int p = 2 * pp + 3;
            if(p > n)
                break;
            ret[pos++] = p;
            for(int q = pp; q <= h; q += p)
                isp[q >> 5] |= 1 << (q & 31);
        }
    }
    ret.resize(pos);
    return ret;
}
