#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
 
 
void solve() {
	ll a, b , c , d ;
	cin >> a >> b >> c ;
	d = min({a, b, c}) + max({a, b, c}) ;
	cout << d << endl ;
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