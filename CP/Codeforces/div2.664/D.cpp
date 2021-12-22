#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back


void solve() {
	ll n, d, m , sum = 0; cin >> n >> d >> m ;
	vector <ll> small, big, joint, ano;
	for(int i=1; i<=n; i++) {
		ll a; cin >> a ;
		if(a <= m) small.pb(a) ;
		else big.pb(a) ;
	}
	ll b = big.size(), s = small.size() ;
	sort(small.begin(), small.end(), greater<ll>()) ;
	sort(big.begin(), big.end(), greater<ll>()) ;

	vector <ll> Spref(s+1, 0), Bpref(b+1, 0) ;
	for(int i=0; i<s; i++) Spref[i+1] = Spref[i] + small[i] ;
	for(int i=0; i<b; i++) Bpref[i+1] = Bpref[i] + big[i] ;

	ll ans = 0; 
	for(int i=0; i<=s; i++) {
		int pos = min( (n - i + d) / (d + 1) , b ) ;
		ll val = Spref[i] + Bpref[pos] ;
		ans = max(ans, val) ;
	}
	cout << ans << endl;
}
  
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    int t = 1, no = 0;
   // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}