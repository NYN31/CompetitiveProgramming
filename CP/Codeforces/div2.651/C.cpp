#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back


void solve() {
	int n, cnt2 = 0, cntodd = 0; cin >> n;
	vector <int> fact ;
	for(int i=2; i*i<=n; i++){
		if(n%i != 0) continue ;
		while(n%i == 0) {
			if(i == 2) cnt2 += 1;
			if(i > 2) cntodd += 1;
			fact.pb(i) ;
			n /= i ;
		}
	}
	if(n > 1) {
		if(n!=2) cntodd += 1;
		fact.pb(n) ;
	}
	
	if(fact.size() == 0) cout << "FastestFinger" << endl ;
	else if(cnt2 == 0 && fact.size() >= 1) cout << "Ashishgup" << endl ;
	else if((cnt2 == 1 && cntodd == 1) || (cnt2 > 1 && cntodd == 0)) cout << "FastestFinger" << endl ;
	else cout << "Ashishgup" << endl ;


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