#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

ll const mod = 1e9 + 7 ;
ll const lim = 2e6 + 5 ;
ll dp[lim+5] ;

void precal() {
	dp[0] = dp[1] = 0 ;
	dp[2] = 4 ;
	for(ll i=3; i<=lim; i++) {
		ll w = dp[i-1] ;
		w += 2 * dp[i-2] + (i % 3 == 2) * 4 ;
		w %= mod ;
		dp[i] = w ;
	}
}

void solve() {
	ll n ; cin >> n ;
	cout << dp[n-1] % mod << endl ;
}  
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 	
 	precal() ;
    int t = 1, no = 0;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}