#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void solve() {
	ll n ; cin >> n ;
	vector <ll> arr (n+1) ;
	vector <ll> a, b, ans; 
	for(int i=1; i<=n; i++) cin >> arr[i] ;

	sort(arr.begin(), arr.end()) ;
	for(int i=1; i<(n+1)/2; i++) a.pb(arr[i]) ;
	for(int i=((n+1)/2)+1; i<=n-(n%2==0); i++) b.pb(arr[i]) ;

	
	deque <ll> dq ;
	dq.push_back(arr[(n+1)/2]) ;
	for(int i=0; i<a.size(); i+=2) {
		dq.push_front(a[i]) ;
		if(i+1 < a.size()) dq.push_back(a[i+1]) ;
		dq.push_front(b[i]) ;
		if(i+1 < b.size()) dq.push_back(b[i+1]) ;
	} 
	if(n % 2 == 0) dq.push_back(arr[n]) ;
	cout << (n-1)/2 << endl ;
	while(!dq.empty()) {
		ll val = dq.front() ;
		dq.pop_front() ;
		cout << val <<  " "  ;
	}
	cout << endl ;
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

