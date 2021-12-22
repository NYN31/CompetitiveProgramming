
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back


void solve() {
	ll n ; cin >> n;
	string str, ano, ans ;
	for(int i=1; i<=n; i++) {
		str += "1001" ;
	}
	for(int i=0; i<str.size()-n; i++) {
		ano.pb(str[i]) ;
	}
	ll l = ano.size() / 4 ;
	for(int i=1; i<=l; i++) ans.pb('9') ;
	for(int i=1; i<=n-l; i++) ans.pb('8') ;
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
