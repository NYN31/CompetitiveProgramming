#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back


void solve() {
	int n, zero = 0, odd = 0, even = 0; cin >> n;
	vector <int> arr;
	vector <int> ans ;
	for(int i=0; i<n; i++) {
		int a ; cin >> a ;
		arr.pb(a) ;
		if(a == 0) { zero++; continue ; }
		if(i%2 == 0) even++;
		else odd++;
	}
	if( (even + odd) <= zero) {
		for(int i=0; i<arr.size(); i++) {
			if(arr[i] == 0) ans.pb(arr[i]) ;
		}
	}else{
		if((even+odd) % 2 == 0) {
			for(int i=0; i<arr.size(); i++) {
				if(arr[i] == 1) ans.pb(arr[i]);
		}
		}else{
			int k=0;
			for(int i=0; i<arr.size(); i++) {
				if(arr[i] == 0) continue ;
				if(arr[i] == 1 && k) ans.pb(arr[i]) ;
				k = 1;
			} 
		}

	}
	cout << ans.size() << endl ;
	for(int i=0; i<ans.size(); i++) cout << ans[i] << " " ;
	cout << endl ;
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