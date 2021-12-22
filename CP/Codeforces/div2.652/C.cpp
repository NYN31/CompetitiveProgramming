#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back


void solve() {
	ll n, k, cnta = 0 ; cin >> n >> k;
	vector <ll> arr , wg ;
	for(int i=0; i<n; i++) {
		ll a ; cin >> a ;
		arr.pb(a) ;
	}
	for(int i=0; i<k; i++) {
		ll a ; cin >> a ;
		if(a != 1) wg.pb(a) ;
		if(a == 1)  cnta += 1;
	}
	sort(arr.begin(), arr.end()) ;
	sort(wg.begin(), wg.end(), greater<ll>() ) ;
	reverse(wg.begin(), wg.end()) ;
	for(int i=0; i<cnta; i++) wg.pb(1) ;
	reverse(wg.begin(), wg.end()) ;

	ll lo = 0, hi = n-1, sum = 0;
	for(int i=0; i<wg.size(); i++) {
		if(wg[i] == 1) {
			sum += (arr[hi] + arr[hi]) ;
			hi -= 1 ;
		}
		else {
			sum += (arr[hi] + arr[lo]) ;
			hi -= 1, lo += wg[i] - 1;
		}
	}
	cout << sum << endl ;
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