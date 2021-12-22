#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n' 


void solve() {
	ll n , ans = 0; cin >> n; 

	for(int i=1; i<=9; i++) {
		int cnt = 0 ;
		if(n%10 == i) {
			while(n) {
				n /= 10 ;
				cnt += 1 ;
			}
			if(cnt == 1) ans += 1 ;
			if(cnt == 2) ans += 3 ;
			if(cnt == 3) ans += 6 ;
			if(cnt == 4) ans += 10 ;
			break ;
		}
		else ans += 10 ;
	}
	cout << ans << nl ;
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

