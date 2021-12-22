solution 1:
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll totient(ll n){
	ll res=n;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			res=res/i*(i-1);
			while(n%i==0)n=n/i;
		}
	}
	if(n>1)res=res/n*(n-1);
	return res;
}
int main()
 {
	int t;cin>>t;
	while(t--){
		ll n,k;cin>>n>>k;
		cout<<totient(n)*(k-1)<<"\n";
	}
  return 0;
  }
  
  
  
  solution 2:
  #include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back

ll const lim = 10000100;
ll const mod = 10000007;
bool isprime[lim+5];
vector<ll>primes;
vector<ll>factor;

void sieve() {
    for(int i=0;i<=lim;i++) isprime[i] = true;
    for(int i=4;i<=lim;i+=2) isprime[i] = false;
    isprime[0] = isprime[1] = false;
    primes.pb(2);
    for(ll i=3;i<=lim;i+=2) {
        if(isprime[i]) {
            primes.pb(i);
            for(ll j=i*i;j<=lim;j+=2*i)
                isprime[j] = false;
        }
    }
}

void factorize(ll n) {
    for(int i=0;i<primes.size() && primes[i]*primes[i]<=n;i++) {
        ll p = primes[i];
        if(n % p != 0) continue;
        while(n % p == 0) n /= p;
        factor.pb(p);
    }
    if(n > 1) factor.pb(n);
}

ll phi(ll n) {
    ll ans = n;
    for(auto p : factor) {
        ans /= p;
        ans *= (p-1);
    }
    return ans;
}

void solve() {
    factor.clear();
    ll n, k ; cin>>n>>k;
    factorize(n);
    ll ans = phi(n*k)-phi(n);
    cout<<ans<<endl;
}

int main() {
    sieve();
    int t = 1, no = 0;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
