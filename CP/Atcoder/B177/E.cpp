#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back
 
int const lim = 1e6+5 ;
bool flag = false;
bool isprime[lim+5];
vector<ll>primes;
int factor[lim+5] ;
 
void sieve(){
    for(ll i=0;i<lim;i++) isprime[i]=true;
    for(ll i=4;i<lim;i+=2) isprime[i]=false;
    isprime[0]=isprime[1]=0;
	primes.pb(2);
    for(ll i=3;i<lim;i++) {
        if(isprime[i]) {
            primes.pb(i);
            for(ll j=i*i;j<lim;j+=i)
                isprime[j]=false;
        }
    }
}
void fq(int num) {
	if(isprime[num]) {
		factor[num] += 1;
		if(factor[num] > 1 && num != 1) flag = true;
	}
	else{
		for(int i=0;i<primes.size() && primes[i]*primes[i]<=num;i++) {
			int p = primes[i] , cnt = 0;
			if(num % p != 0) continue;
			while(num % p == 0) {
				num /= p;
				cnt += 1;
			}
			factor[p] += 1;
			if(factor[p] > 1) {
				flag = true;
				return ;
			}
		}
		if(num > 1) {
			factor[num] += 1;
			if(factor[num] > 1) flag = true;
		}
	}
	
}
 
void solve() {
	int n; cin >> n;
	int arr[n + 5] ;
 
	for(int i=1; i<=n; i++) {
		cin>>arr[i];
	}
	int gcd = arr[1] ;
	for(int i=1;i<=n;i++) gcd = __gcd(gcd, arr[i]);
	if(gcd != 1) cout<<"not coprime"<<endl;
	else {
		for(int i=1;i<=n;i++) {
			fq(arr[i]);
			if(flag) break;
		}
		if(flag) cout<<"setwise coprime"<<endl;
		else cout<<"pairwise coprime"<<endl;
	}
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 	
 	sieve() ;
    int t = 1, no = 0;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}