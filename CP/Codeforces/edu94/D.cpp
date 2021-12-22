#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back

ll const lim = 3030 ;
ll dp[lim+5][lim+5] ;
ll arr[lim+5] ;
void solve() {
	ll n , ans = 0; cin >> n;
	for(int i=1; i<=n; i++) cin >> arr[i] ;
	memset(dp, 0, sizeof dp) ;
	
	for(ll i=n; i>=1; --i) {
		ll k = i+1;
		for(ll j=k+1; j<=n; j++)
			dp[arr[k]][arr[j]] += 1;
		for(ll j=1; j<i; j++)
			ans += dp[arr[j]][arr[i]];
	}
	cout << ans << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    int t = 1, no = 0;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}