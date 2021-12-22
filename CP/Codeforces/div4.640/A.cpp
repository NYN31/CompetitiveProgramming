#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back


void solve() {
	ll n , k = 1, rem; cin >> n ;
	vector <ll> vec ;
	while(n > 0) {
		rem = n % 10 ;
		n = n / 10 ;
		if(rem*k !=0 ) vec.pb( rem * k) ;
		k *= 10; 
	}
	cout << vec.size() << endl;
	for(int i=0; i<vec.size(); i++) 
		cout << vec[i] << " " ;
	cout << endl;
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