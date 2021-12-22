#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back


void solve() {
	ll n , k , ans = 0 ; cin >> n >> k;
	if( n >= k ) {
		if( (n&1) == (k&1) ) ans = 0;
		else ans = 1;
	}
	else ans = abs(n-k) ;
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