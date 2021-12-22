#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n' 

void solve() {
	int n, mx = 0, idx = -1 ; cin >> n ;
	vector <int> arr(n) ;
	for(int i=0; i<n; i++) {
		cin >> arr[i] ;
		mx = max(arr[i], mx) ;
	}

	for(int i=0; i<n; i++) {
		if(i == 0 && arr[i] == mx) {
			if(arr[i] > arr[i+1]) {
				idx = i + 1;
				break ;
			}
		}
		else if(i == n-1 && arr[n-1] == mx) {
			if(arr[i-1] < arr[i]) {
				idx = i + 1;
				break ;
			}
		}
		else if(arr[i] == mx) {
			if(arr[i-1] < arr[i] || arr[i] > arr[i+1]) {
				idx = i + 1;
				break ;
			}
		}
	}
	cout << idx << nl ;

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

