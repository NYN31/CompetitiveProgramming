#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n' 

void solve() {
	ll n ; cin >> n ;
	ll fact = 1 ;
	for(ll i=1; i<=n-1; i++) fact *= i ;
	fact = fact / (n / 2) ;
	cout << fact << endl ;
}  
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    int t = 1, no = 0;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

