#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back


void solve() {
	int n ; cin >> n;
	int arr[n+5] , brr[n+5] ;
	for(int i=1; i<=n; i++) {
		cin >> arr[i] ;
		brr[i] = arr[i] ;
	}
	sort(brr+1, brr+1+n) ;
	int mn = brr[1] ;

	bool flag = true ;
	for(int i=1; i<=n; i++) {
		if(arr[i] == brr[i]) continue;
		else {
			if(arr[i] % mn != 0) {
				flag = false;
				break;
			}
		}
	}
	if(flag) cout << "YES" << endl; 
	else cout << "NO" << endl;
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