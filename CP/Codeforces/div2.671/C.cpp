#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void solve() {
	int n, x ; cin >> n >> x ;
	int sum = 0, infected = 0 ;
	for(int i=1; i<=n; i++) {
		int val ; cin >> val ;
		sum += val ;
		infected += (val == x) ;
	}
	if(infected == n) cout << 0 << '\n' ;
	else if(infected > 0 || n * x == sum) cout << 1 << '\n' ;
	else cout << 2 << '\n' ;
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

