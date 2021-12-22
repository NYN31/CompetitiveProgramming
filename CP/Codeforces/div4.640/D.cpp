#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
 
 
void solve() {
	ll n ; cin >> n;
	deque <ll> dq ;
	for(int i=0; i<n; i++) {
		ll a ; cin >> a ;
		dq.push_back( a ) ;
	}
	ll alice = 0, bob = 0, turn = 0, preva = 0, prevb = 0;
 
	while(1) {
		turn += 1;
		preva = 0;
		while(1) {
			ll u = dq.front() ;
			dq.pop_front() ;
			preva += u;
			alice += u ;
			if(preva > prevb || dq.empty()) {
				break ;
			}
		}
		if(dq.empty()) break ;
		turn += 1, prevb = 0;
		while(1) {
			ll u = dq.back() ;
			dq.pop_back() ;
			prevb += u ;
			bob += u ;
			if(prevb > preva || dq.empty()) {
				break ;
			}
		}
		if(dq.empty()) break ;
	}
	cout << turn << " " << alice << " " << bob << endl ;
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