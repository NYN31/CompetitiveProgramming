#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back


void solve() {
	ll n ; cin >> n ;
	ll arr[n+5] ;
	for(ll i=1; i<=n; i++) cin >> arr[i] ;

	cout << 1 << " " << 1 << endl ;
	cout << - arr[1] << endl; 
	arr[1] = 0 ; 

	if( n == 1) {
		cout << 1 << " " << 1 << endl ;
		cout << 0 << endl;
	}
	else {
		cout << 2 << " " << n << endl ;
		for(ll i=2; i<=n; i++) {
			ll x = arr[i] % n ;
			cout << (n - 1) * x <<" " ;
			arr[i] += (n-1) * x ;
		}
		cout << endl ;
	}
	cout << 1 << " " << n << endl ;
	for(ll i=1; i<=n; i++) cout << -arr[i] << " " ;
	cout << endl ;
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