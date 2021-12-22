#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back


void solve() {
	ll n, x , ans = 1; cin >> n >> x ;
	if(n <= 2 ) {
		cout << 1 << endl ;
		return ;
	}
	n -= 2 ; 
	ans += ( n/x + (n%x!=0)) ;
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

