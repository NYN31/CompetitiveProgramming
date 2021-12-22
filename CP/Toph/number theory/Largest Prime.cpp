#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back

int const lim1 = 10005;

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
void solve(){
	int l, r; cin>>l>>r;
	auto pos = lower_bound(primes.begin(), primes.end(), r) - primes.begin();
	if(isprime[primes[pos]] && primes[pos]<=r && primes[pos]>=l) cout<<primes[pos]<<endl;
	else {
		pos--;
		if(pos>=0 && isprime[primes[pos]] && primes[pos]<=r && primes[pos]>=l) cout<<primes[pos]<<endl;
		else cout<<-1<<endl;
	}
	return ;
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
