#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back


void solve() {
	ll a , req ; cin >> a >> req ;
	ll x = a, y = req;

	ll sum = 0 , digit = 0 ;
	vector <int> arr ;
	while(a > 0) {
		sum += (a % 10) ;
		arr.pb(a % 10) ;
		a = a / 10 ;
		digit += 1;
	}
	reverse(arr.begin(), arr.end()) ;
	a = x ;
	if(sum <= req) cout << 0 << endl ;
	else {
		bool flag = false ;
		ll dig = 0 ;
		for(int i=0; i<arr.size(); i++) {
			if(dig + arr[i] < req) {
				dig += arr[i] ;
			}
			else {
				int j = i-1;
				while(j>=0) {
					if(arr[j] < 9) {
						arr[j] += 1 ;
						flag = true ;
						break ;
					}
					j-- ;
				}
				if(flag == true ) {
					int k = j+1;
					while(k<arr.size()) {
						arr[k] = 0;
						++k ;
					}
					break;
				}
				break ;
			}
		}
		ll val = 0, k;
		if(flag == false) {
			val = 1;
			for(int i=1;i<=digit;i++) {
				val *= 10;
			}
		}
		else {
			val = 0 , k = 1;
			for(int i=arr.size()-1; i>=0; --i) {
				val = val + (arr[i] * k) ;
				k *= 10;
			}
		}
		ll ans = val - a ;
		cout << ans << endl;
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

/*
2
217871987498122 2128012501878
100000000000000001 899999999999999999
*/