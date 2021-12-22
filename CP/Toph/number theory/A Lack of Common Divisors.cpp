#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back

int const lim1 = 3500;

bool isprime[lim1];
vector<int>primes;
void sieve() {
	for(int i=0;i<lim1;i++) isprime[i]=true;
	for(int i=4;i<lim1;i+=2) isprime[i]=false;
	isprime[0] = isprime[1] = false;
	primes.pb(2);
	for(ll i=3;i<lim1;i+=2){
		if(isprime[i]){
			primes.pb(i);
			for(ll j=i*i;j<lim1;j+=2*i)
				isprime[j] = false;
		}
	}
}

ll factorize(ll n) {
	ll ans = n;
	for(int i=0;i<primes.size() && primes[i]*primes[i]<=n;i++) {
		ll p = primes[i];
		if(n % p != 0) continue;
		while(n % p == 0) n /= p;
		ans -= (ans / p) ;
	}
	if(n > 1) ans -= (ans / n);
	return ans;
}

void solve(){
	ll n ; cin>>n;
	ll ans = factorize(n);
	cout<<ans<<endl;
}
int main() {
    sieve();
    int t = 1, no = 0;
    //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
