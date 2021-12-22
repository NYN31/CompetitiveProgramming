#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back


void solve() {
	ll n; cin >> n;
	if( n <= 30 ) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		ll a, b, c, d ;
		a = 14, b = 10, c = 6, d = n - 30 ;
		if(a == d || b == d || c == d) d--, a++ ;
		cout << a << " " << b << " " << c << " " << d << endl;
	}
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
