#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

ll go(vector <ll> & a) {
	ll mx = 0, val = 0 ;
	for(ll x : a) {
		val = max(x+val, 0LL) ;
		mx = max(mx, val) ;
	}
	return mx ;
}

void solve() {
	int n ; cin >> n;
	ll arr[n+5] , ev_sum = 0;
	for(int i=0; i<n; i++) {
		cin >> arr[i] ;
		if(i & 1^1) ev_sum += arr[i] ;
	}
	vector <ll> odd, even ;
	for(int i=0; i<n-1; i+=2) even.pb(arr[i+1] - arr[i]) ;
	for(int i=1; i<n-1; i+=2) odd.pb(arr[i] - arr[i+1]) ;
	ll ans = max({0LL, go(odd), go(even)}) + ev_sum ;
	cout << ans << endl ;
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