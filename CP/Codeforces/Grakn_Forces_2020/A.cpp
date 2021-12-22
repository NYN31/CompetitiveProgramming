#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back


void solve() {
	int n ; cin >> n;
	int arr[n+5], brr[n+5], crr[n+5] ;
	for(int i=1; i<=n; i++) cin >> arr[i] ;
	for(int i=1; i<=n; i++) cin >> brr[i] ;
	for(int i=1; i<=n; i++) cin >> crr[i] ;

	int prev = arr[1] ;
	vector <int> ans ;
	ans.pb(prev) ;
	for(int i=2; i<=n; i++) {
		if(i == n) {
			int a, b, c ;
			a = arr[n], b = brr[n], c = crr[n] ;
			if(a != prev && a != arr[1]) ans.pb(a) ;
			else if(b != prev && b != arr[1]) ans.pb(b) ;
			else if(c != prev && c != arr[1]) ans.pb(c) ;
		}
		else if(arr[i] != prev) {
			ans.pb(arr[i]) ;
			prev = arr[i] ;
		}
		else if(brr[i] != prev) {
			ans.pb(brr[i]) ;
			prev = brr[i] ;
		}
		else if(crr[i] != prev) {
			ans.pb(crr[i]) ;
			prev = crr[i] ;
		}
	}

	for(int i=0; i<ans.size(); i++) cout << ans[i] << " " ; cout << endl ;
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

