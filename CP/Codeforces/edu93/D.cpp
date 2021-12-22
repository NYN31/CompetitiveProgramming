#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define ff first
#define ss second
#define pb push_back

ll r, b, g;
ll dp[205][205][205] ;
ll red[205], blue[205], green[205] ;

ll go(ll R, ll G, ll B) {
	if(R > r || G > g || B > b) return 0;
	ll &ret = dp[R][G][B] ;
	if(ret != -1) return ret ;
	ll ans = 0;
	ans = go(R+1, G+1, B) + (red[R] * green[G]) ;
	ans = max(ans, go(R+1, G, B+1) + (red[R] * blue[B])) ;
	ans = max(ans, go(R, G+1, B+1) + (green[G] * blue[B])) ;
	ret = ans ;
	return ans ;
}

void solve() {
	cin >> r >> g >> b;
	for(int i=0; i<r; i++) cin >> red[i] ;
	for(int i=0; i<g; i++) cin >> green[i] ;
	for(int i=0; i<b; i++) cin >> blue[i] ;

	sort(red, red+r) , sort(green, green+g) , sort(blue, blue+b) ;
	reverse(red, red+r), reverse(green, green+g), reverse(blue, blue+b) ;

	memset(dp, -1, sizeof dp) ;
	ll ans = go(0, 0, 0) ;
	cout << ans << endl ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t = 1, no = 0;
    // cin >> t ;
    while(t--) {
        solve();
    }
    return 0;
}
