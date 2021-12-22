#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back


void solve() {
	ll n ; cin >> n;
	if(n % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl ;
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