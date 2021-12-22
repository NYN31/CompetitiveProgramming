#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back


void solve() {
	ll n, ans = 0 ; cin >> n ;
	if(n <= 1) {
		cout << 0 << endl ;
		return ; 
	}
	ll sq = sqrt( (double)(n) ) ;
	if(sq * sq != n) sq += 1 ;
	ans = n / sq + (n % sq != 0) ;
	ans += sq - 2 ;
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

