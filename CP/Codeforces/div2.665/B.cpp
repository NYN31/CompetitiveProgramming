#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back


void solve() {
	ll zero1, zero2, one1, one2, two1, two2;
	cin >> zero1 >> one1 >> two1 ;
	cin >> zero2 >> one2 >> two2 ;

	ll temp , ans = 0;

	temp = min(two1, one2) ;
	two1 -= temp , one2 -= temp;
	ans += ( (2*1) * temp );

	temp = min(two1, two2) ;
	two1 -= temp, two2 -= temp;

	temp = min(two1, zero2) ;
	two1 -= temp, zero2 -= temp ;

	temp = min(one1, one2) ;
	one1 -= temp , one2 -= temp ;

	temp = min(one1, zero2) ;
	one1 -= temp, zero2 -= temp ;

	temp = min(one1, two2) ;
	one1 -= temp , two2 -= temp;
	ans -= ( (2 * 1) * temp ) ;

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