#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back


void solve() {
	ll n ; cin >> n;
	vector <int> arr ;
	for(int i=1; i<=n; i++) {
		ll a ; cin >> a ;
		arr.pb(a) ;
	}
	ll a, b , c;
	a = arr[0] , b = arr[1] , c = arr[n-1] ;
	if(a + b <= c) cout << 1 << " " << 2 << " " << n << endl;
	else cout << -1 << endl;
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