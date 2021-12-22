#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back


void solve() {
	int n , mx = 0, idx = 0; cin >> n;
	vector <int> arr , ans ;
	vector <int> taken(n, 0) ;
	for(int i=0; i<n; i++) {
		int a ; cin >> a ;
		arr.pb(a) ;
		if(mx < a) idx = i , mx = a;
	}
 	int mxgcd = mx, x, val; 
 	taken[idx] = 1;
 	ans.pb(mx) ;

 	while(true) {
 		if(ans.size() == n) break ;
 		int pos;
 		x = mxgcd, val = 1;
 		for(int j=0; j<n; j++) {
 			if(taken[j]) continue ;
 			if(__gcd(x, arr[j]) >= val) {
 				pos = j ;
 				val = (mxgcd, __gcd(x, arr[j])) ;
 			}
 		}
 		ans.pb(arr[pos]) ;
 		taken[pos] = 1;
 		mxgcd = val ;
 	}
 

	for(int i=0; i<ans.size(); i++)
		cout << ans[i] << " " ;
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