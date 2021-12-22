#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void solve() {
	ll n, cnt = 0 ; cin >> n ;
	vector <ll> arr(n) ;
	for(int i=0; i<n; i++) cin >> arr[i] ;
	sort(arr.begin(), arr.end()) ;
	vector <ll> ans ;
	for(int i=n/2, j=0; i<n; i++, j++) {
		ans.pb(arr[i]) ; 
		if(j < n/2) ans.pb(arr[j]) ;
	}
	for(int i=1; i+1<n; i++) {
		cnt += (ans[i] < ans[i-1]) && (ans[i] < ans[i+1]) ;
	}
	cout << cnt << endl ;
	for(int i=0; i<ans.size(); i++) cout << ans[i] << " " ;
	cout << '\n' ;

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