#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back
 
ll const lim1 = 1e15 ;
 
ll binpow(ll a, ll p) {
	if(p == 0) return 1LL ;
	else if(p%2 == 0) {
		ll ret = binpow(a, p/2);
		return ret*ret ;
	}
	else {
		ll ret = binpow(a, p-1);
		return a*ret;
	}
}
 
void solve() {
	ll n ; cin >> n;
	ll arr[ n+5 ] , sum = 0, diff = 0, mn=0 , pw;
	for(ll i=0; i<n; i++) cin >> arr[i] ;
 
	sort(arr, arr+n) ;
 
	for(int i=0;i<n;i++) {
		mn += abs(arr[i] - 1) ;
	}
	ll val ;
	for(ll i=2; i<=100000; i++) {
		bool flag = false;
		diff = 0;
		for(ll j=0;j<n;j++) {
			pw = binpow(i, j) ; // i = value, j = power ;
			sum += pw ;
			if(sum > lim1) {
				flag = true ;
				break ;
			}
			diff += abs(arr[j] - pw) ;
		}
		if(!flag) mn = min(mn , diff) ;
	}
	cout << mn << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    int t = 1, no = 0;
   // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}