#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
 
 
void solve() {
	ll n, k, dif ; cin >> n >> k;
	ll nw = n;
	if( k > n) {
		cout << "NO" << endl ;
		return ;
	}
	vector <ll> arr ;
	for(int i=1; i<k; i++) {
		arr.pb(1);
		nw -= 1;
	}
	if(nw & 1) {
		cout << "YES" << endl;
		for(int i=0; i<arr.size(); i++)
			cout << arr[i] << " " ;
		cout << nw << endl ;
	}
	else {
		ll dif = nw - arr.size() ;
		if(dif & 1 || dif <= 0) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			for(int i=0; i<k-1; i++)
				cout << 2 << " " ;
			cout << dif << endl;
		}
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