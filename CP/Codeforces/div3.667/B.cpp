#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back

ll go(ll a, ll b, ll x, ll y, ll n) {
	ll tm1 = max(x, a - n) ;
	n = n - (a - tm1) ;
	ll tm2 = max(y, b - n) ;
	return tm1 * tm2 ;
}

void solve() {
	ll a, b, x, y, n; 
	cin >> a >> b >> x >> y >> n ;
	cout << min(go(a, b, x, y, n), go(b, a, y, x, n)) << endl;
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