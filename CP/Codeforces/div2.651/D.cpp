#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int const lim = 2e5+5 ;
int n, k ;
int arr[lim+5] ;

bool odd(ll x) {
	int cnt = 0 ;
	for(int i=0; i<n; i++) {
		if(cnt%2 == 1) cnt += 1;
		else if(arr[i] <= x) cnt += 1;
	}
	return cnt >= k ;
}

bool even(ll x) {
	int cnt = 0 ;
	for(int i=0; i<n; i++) {
		if(cnt%2 == 0) cnt += 1;
		else if(arr[i] <= x) cnt += 1;
	}
	return cnt >= k ;
}
void solve() {
	cin >> n >> k ;
	for(int i=0; i<n; i++) cin >> arr[i] ;

	ll lo = 1, hi = 1e14, mid, ans = 0 ;
	while( lo <= hi ) {
		mid = lo + (hi - lo) / 2LL ;
		if(even(mid) || odd(mid)) {
			ans = mid ;
			hi = mid - 1 ;
		}
		else lo = mid + 1 ;
	}
	cout << ans << endl ;
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