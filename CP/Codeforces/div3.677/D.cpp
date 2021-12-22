#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'
#define ff first
#define ss second

void solve() {
	ll n; cin >> n;
	vector <pair<ll, ll> > arr ;
	for(ll i=1; i<=n; i++) {
		ll a ; cin >> a ;
		arr.pb({a, i}) ;
	}
	sort(arr.begin(), arr.end()) ;
	if(arr[0].ff == arr[arr.size()-1].ff) {
		cout << "NO" << nl ;
		return ;
	}
	cout << "YES" << nl ;
	ll lo = 0, hi = n-1 ;
	while(arr[lo].ff != arr[hi].ff) {
		cout << arr[lo].ss << " " << arr[hi].ss << nl ;
		hi -= 1 ;
	}
	if(lo == hi) return ;
	hi += 1 ;
	for(ll i=1; ; i++) {
		if(i == hi) break ;
		cout << arr[i].ss << " " << arr[hi].ss << nl ;
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

