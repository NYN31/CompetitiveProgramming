#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
 
 
void solve() {
	ll n ; cin >> n; 
	ll pos[n + 5], nag[n + 5] ;
	for(int i=0; i<n; i++) {
		ll a ;  cin >> a ;
		if(a >= 0) {
			pos[i] = a ;
			nag[i] = 0 ;
		}
		else {
			pos[i] = 0 ;
			nag[i] = a ;
		}
	}
	for(int i=1; i<n; i++) nag[i] += nag[i-1] ;
	for(int i=1; i<n; i++) pos[i] += pos[i-1] ;
	for(int i=0; i<n; i++) nag[i] = (-1) * nag[i] ;
 
	ll ans = 0;
	for(int i=0; i<n-1; i++) {
		if(pos[i] >= nag[i+1]) continue ;
		ans = max(ans, abs(pos[i]-nag[i+1]));
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