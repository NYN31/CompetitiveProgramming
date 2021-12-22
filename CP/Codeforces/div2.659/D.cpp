#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void solve() {
	ll n , xr = 0 ; cin >> n;
	vector <ll> arr ;
	for(int i=0; i<n; i++) {
		ll a ; cin >> a ; 
		arr.pb(a) ;
		xr = xr ^ a ;
	}
	if(xr == 0) {
		cout << "DRAW" << endl ;
		return ;
	}
	for(int i=30; i>=0; --i) {
		if(!(xr >> i & 1)) continue ;
		int cnt[2]={0} ;
		for(auto &val : arr) ++cnt[(val >> i) & 1] ;
		if(cnt[1] % 4 == 3 && cnt[0]%2 == 0) 
			cout << "LOSE" << endl ;
		else cout << "WIN" << endl ;
		break ;
	}
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