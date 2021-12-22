#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back


void solve() {
	string str ; cin >> str ;
	ll lstr = str.size() ;
	ll cum_sum[lstr+5] = {0} ;
	for(int i=0; i<lstr; i++) {
		if(str[i] == '+') cum_sum[i] = -1;
		else cum_sum[i] = 1 ;
	}
	for(int i=1; i<lstr; i++) {
		cum_sum[i] += cum_sum[i-1] ;
	}
	ll ans = 0, mx = 0 ;
	for(int i=0; i<lstr; i++) {
		ans += 1 ;
		if(cum_sum[i] > mx) {
			ans += (i + 1) ;
			mx = cum_sum[i] ;
		}
	}
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