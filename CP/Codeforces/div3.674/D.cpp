#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back


void solve() {
	ll n ; cin >> n; 
	map <ll, ll> mp ;
	ll ans = 0, sum = 0 ;
	mp[0] += 1 ;
	for(int i=1; i<=n; i++) {
		ll val ; cin >> val ;
		sum += val ;
		if(mp[sum] != 0) {
			ans += 1 ;
			mp.clear() ;
			mp[0] += 1 ;
			mp[val] += 1 ;
			sum = val ;
		}
		else mp[sum] += 1 ;
	}
	cout << ans << endl ;
}  
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    int t = 1, no = 0;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

