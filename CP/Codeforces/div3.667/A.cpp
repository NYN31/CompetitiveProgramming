#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back


void solve() {
	ll a, b ; cin >> a >> b ; 
	ll diff = abs(a - b) ;
	ll ans = diff / 10 + (diff % 10 != 0) ;
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